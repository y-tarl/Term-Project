import torch
import torch.nn as nn


def position_embedding(data,
                       input_length, num_of_vertices, embedding_size,
                       temporal=True, spatial=True):
    '''
    位置编码
    :param data: tensor shape is (B,T,N,C)
    :param input_length: int, length of time series, T
    :param num_of_vertices: int, N
    :param embedding_size: int, C
    :param temporal: bool, whether equip this type of embeddings
    :param spatial: bool, whether equip this type of embeddings
    :return:
    data: output shape is (B, T, N, C)
    '''
    temporal_emb = None
    spatial_emb = None

    if temporal:
        # shape is (1, T, 1, C')
        temporal_emb = torch.empty(1, input_length, 1, embedding_size).to(torch.device("cuda:0"))
        torch.nn.init.xavier_uniform_(temporal_emb, gain=0.0003)
    if spatial:
        # shape is (1, 1, N, C')
        spatial_emb = torch.empty(1, 1, num_of_vertices, embedding_size).to(torch.device("cuda:0"))
        torch.nn.init.xavier_uniform_(spatial_emb, gain=0.0003)

    if temporal_emb is not None:
        data = torch.add(data, temporal_emb)
    if spatial_emb is not None:
        data = torch.add(data, spatial_emb)

    return data


class gcn_operation(nn.Module):
    def __init__(self, adj, num_of_filter, num_of_features, num_of_vertices,
                 activation):
        '''
        GCN操作
       :param adj: tensor shape is (3N, 3N)
       :param num_of_filter: int, C'
       :param num_of_features: int, C
       :param num_of_vertices: int, N
       :param activation: str, {'GLU','relu'}
        '''
        super().__init__()
        assert activation in {'GLU', 'relu'}

        self.activation = activation
        self.num_of_features = num_of_features
        self.num_of_filter = num_of_filter
        self.adj = adj

        if activation == 'GLU':
            self.Liner = nn.Linear(num_of_features, 2 * num_of_filter)


        elif activation == 'relu':
            self.Liner = nn.Linear(num_of_features, num_of_filter)

    def forward(self, data):
        '''

        :param data: tensor, shape is(3N, B, C)
        :return:
        output shape is (3N, B, C')
        '''
        data=torch.einsum('nm, mbc->nbc', self.adj.to(data.device), data)


        if self.activation == 'GLU':
            # shape is (3N, B, 2C')
            data = self.Liner(data)

            # shape is (3N, B, C') , (3N, B, C')
            lhs, rhs = torch.split(data, split_size_or_sections=self.num_of_filter, dim=-1)

            # shape is (3N, B, C')
            return lhs * torch.sigmoid(rhs)

        elif self.activation == 'relu':
            # shape is (3N, B, C')
            data = self.Liner(data)

            # shape is (3N, B, C')
            return torch.relu(data)


class stsgcm(nn.Module):
    def __init__(self, adj, filters, num_of_features, num_of_vertices,
                 activation):
        '''
        STSGCM, multiple stacked gcn layers with cropping and max operation
        :param adj: tensor, shape is (3N, 3N)
        :param filters: list[int], list of C'
        :param num_of_features: int , C
        :param num_of_vertices: int , N
        :param activation: str, {'GLU', 'relu'}
        '''
        super().__init__()
        self.adj = adj
        self.filters = filters
        self.num_of_vertices = num_of_vertices
        feture = [filters[i] for i in range(len(filters) - 1)]
        feture.insert(0, num_of_features)
        self.gcn_operation = nn.ModuleList([gcn_operation(adj, filters[i], feture[i], num_of_vertices, activation)
                                            for i in range(len(filters))])

    def forward(self, data):
        '''
        :param data: tensor, shape is (3N, B, C)
        :return: output shape is (3N, B, C')
        '''
        need_concat = []
        # shape of each element is (3N,B,C')
        # 逐层卷积gcn操作
        for layer in self.gcn_operation:
            data = layer(data)
            need_concat.append(data)

        # shape of each element is (1, N, B, C')
        need_concat = [
            torch.unsqueeze(i[self.num_of_vertices:2 * self.num_of_vertices, :, :],
                            dim=0)
            for i in need_concat
        ]

        # shape is (N, B, C')
        result = torch.max(torch.cat(need_concat, dim=0), dim=0).values

        return result


class stsgcl(nn.Module):
    def __init__(self, adj, T, num_of_vertices, num_of_features, filters,
                 module_type, activation, temporal_emb=True, spatial_emb=True):
        '''
        :param adj: tensor, shape is (3N, 3N)
        :param T: int, length of time series, T
        :param num_of_vertices: int, N
        :param num_of_features: int, C
        :param filters: list[int], list of C'
        :param module_type: str, {'sharing', 'individual'}
        :param activation: str, {'GLU', 'relu'}
        :param temporal_emb: bool
        :param spatial_emb: bool
        '''
        super(stsgcl, self).__init__()

        assert module_type in {'sharing', 'individual'}
        self.adj = adj
        if module_type == 'sharing':
            self.layer = sthgcn_layer_sharing(
                adj, T, num_of_vertices, num_of_features, filters,
                activation, temporal_emb, spatial_emb
            )
        elif module_type == 'individual':
            self.layer = sthgcn_layer_individual(
                adj, T, num_of_vertices, num_of_features, filters,
                activation, temporal_emb, spatial_emb
            )

    def forward(self, data):
        '''
        :param data: tensor, shape is (B, T, N, C)
        :param adj: tensor, shape is (3N, 3N)
        :return: output shape is (B, T-2, N, C')
        '''
        return self.layer(data)


class sthgcn_layer_individual(nn.Module):
    def __init__(self, adj, T, num_of_vertices, num_of_features, filters,
                 activation, temporal_emb=True, spatial_emb=True):
        '''
        :param adj: tensor, shape is (3N, 3N)
        :param data: tensor , shape is (B, T, N, C)
        :param adj:tensor , shape is (3N, 3N)
        :param T: int, length of time series, T
        :param num_of_vertices: int, N
        :param num_of_features: int, C
        :param filters: list[int], list of C'
        :param activation:str, {'GLU', 'relu'}
        :param temporal_emb: bool
        :param spatial_emb: bool
        '''
        super(sthgcn_layer_individual, self).__init__()
        self.temporal_emb = temporal_emb
        self.adj = adj
        self.spatial_emb = spatial_emb
        self.num_of_vertices = num_of_vertices
        self.num_of_features = num_of_features
        self.filters = filters
        self.activation = activation
        self.T = T
        self.stsgcm = stsgcm(adj, filters, num_of_features, num_of_vertices, activation)

    def forward(self, data):
        '''
        :param data: tensor, shape is (B, T, N, C)
        :return: output shape is (B, T-2, N, C')
        '''
        #shape is (B, T, N, C')
        data = position_embedding(data, self.T, self.num_of_vertices, self.num_of_features,
                                  self.temporal_emb, self.spatial_emb)
        need_concat = []
        for i in range(self.T - 2):
            # shape is (B, 3, N, C)
            t = data[:, i: i + 3, :, :]

            # shape is (B, 3*N, C)
            t = torch.reshape(t, (-1, 3 * self.num_of_vertices, self.num_of_features))

            # shape is (3*N, B, C)
            t = t.permute(1, 0, 2)

            # shape is (N, B, C')  完成卷积操作+剪裁中间时间+取最大值
            t = self.stsgcm(t)

            # shape is (B, N, C')
            t = t.permute(1, 0, 2)

            # shape is (B, 1, N, C')
            need_concat.append(torch.unsqueeze(t, dim=1))

        # shape is (B, T-2, N, C')
        return torch.cat(need_concat, dim=1)


class sthgcn_layer_sharing(nn.Module):
    def __init__(self, adj, T, num_of_vertices, num_of_features, filters,
                 activation, temporal_emb=True, spatial_emb=True):
        '''
        STSGCL, multiple a sharing STSGCM
        :param adj: tensor, shape is (3N, 3N)
        :param T: int, length of time series, T
        :param num_of_vertices: int, N
        :param num_of_features: int, C
        :param filters: list[int], list of C'
        :param activation: str, {'GLU', 'relu'}
        :param temporal_emb: bool
        :param spatial_emb: bool
        '''
        super(sthgcn_layer_sharing, self).__init__()
        self.adj = adj
        self.temporal_emb = temporal_emb
        self.spatial_emb = spatial_emb
        self.num_of_vertices = num_of_vertices
        self.num_of_features = num_of_features
        self.filters = filters
        self.activation = activation
        self.T = T
        self.stsgcm = stsgcm(filters, num_of_features, num_of_vertices, activation)

    def forward(self, data):
        '''
        :param data: tensor,shape is (B, T, N, C)
        :return: output shape is (B, T-2, N, C')
        '''
        data = position_embedding(data, self.T, self.num_of_vertices, self.num_of_features,
                                  self.temporal_emb, self.spatial_emb)
        need_concat = []
        for i in range(self.T - 2):
            # shape is (B, 3, N, C)
            t = data[:, i: i + 3, :, :]

            # shape is (B, 3*N, C)
            t = torch.reshape(t, (-1, 3 * self.num_of_vertices, self.num_of_features))

            # shape is (3*N, B, C)
            t = t.permute(1, 0, 2)
            need_concat.append(t)

        # shape is (3*N, (T-2)*B, C)
        t = torch.cat(need_concat, dim=1)

        # shape is (N, (T-2)*B, C')
        t = self.stsgcm(t, self.adj)

        # shape is (N, T - 2, B, C)
        t = t.reshape((self.num_of_vertices, self.T - 2, -1, filters[-1]))

        # shape is (B, T - 2, N, C)
        return t.permute(2, 1, 0, 3)


class output_layer(nn.Module):
    def __init__(self, num_of_vertices, input_length, num_of_features,
                 num_of_filters=128, predict_length=12):
        '''

        :param num_of_vertices: int, N
        :param input_length: int, length of time series, T
        :param num_of_features: int, C
        :param num_of_filters: int, C'
        :param predict_length: int, T'
        '''
        super(output_layer, self).__init__()
        self.num_of_vertices = num_of_vertices
        self.input_length = input_length
        self.num_of_features = num_of_features
        self.num_of_filters = num_of_filters
        self.predict_length = predict_length
        self.layer1 = nn.Linear(num_of_features * input_length, num_of_filters)
        self.layer2 = nn.Linear(num_of_filters, predict_length)

    def forward(self, data):
        '''
        :param data: tensor, shape is (B, T, N, C)
        :return: output shape is (B, T', N)
        '''
        # data shape is (B, N, T, C)
        data = data.permute(0, 2, 1, 3)

        # data shape is (B, N, T * C)
        data = data.reshape(-1, self.num_of_vertices, self.input_length * self.num_of_features)

        # data shape is (B, N, C')
        data = torch.relu(self.layer1(data))

        # data shape is (B, N, T')
        data = self.layer2(data)

        # data shape is (B, T', N)
        data = data.permute(0, 2, 1)

        return data


def huber_loss(data, label, rho=1.0):
    '''

    :param data: tensor, shape is (B, T', N)
    :param label: tensor, shape is (B, T', N)
    :param rho: float
    :return:  loss: tensor, shape is (B, T', N)
    '''
    loss = torch.abs(data - label)
    loss = torch.where(loss > rho, loss - 0.5 * rho, (0.5 / rho) * torch.square(loss))
    loss.requires_grad_()
    return loss


def weighted_loss(data, label, input_length, rho=1.0):
    '''
    :param data: tensor,shape is (B, T', N)
    :param label: tensor,shape is (B, T', N)
    :param input_length: int, T
    :param rho: float
    :return: tensor
    '''

    # weight shape is (1, T', 1)
    weight = torch.unsqueeze(
        torch.unsqueeze(
            torch.flip(
                torch.arange(1, input_length + 1), dims=[0]
            ), dim=0
        ), dim=-1
    )

    agg_loss = torch.mul(
        huber_loss(data, label, rho),
        weight
    )
    return agg_loss


class stsgcn(nn.Module):
    def __init__(self, adj, input_length, num_of_vertices, num_of_features,
                 filter_list, module_type, activation,
                 use_mask=True, mask_init_value=None,
                 temporal_emb=True, spatial_emb=True, rho=1, predict_length=12):
        '''
        stsgcn
        :param adj: tensor, shape is (3N, 3N)
        :param input_length: int T
        :param num_of_vertices: int, N
        :param num_of_features: int, C
        :param filter_list: list[int][int], list of C'
        :param module_type: str, {'sharing', 'individual'}
        :param activation: str, {'GLU', 'relu'}
        :param use_mask: bool
        :param mask_init_value: float
        :param temporal_emb: bool
        :param spatial_emb: bool
        :param rho: float
        :param predict_length: int T'
        '''
        super(stsgcn, self).__init__()

        self.adj=adj
        self.filter_list = filter_list
        self.predict_length = predict_length
        self.rho = rho
        T = [input_length - 2 * i for i in range(len(filter_list))]
        features = [filter_list[i][-1] for i in range(len(filter_list) - 1)]
        features.insert(0, num_of_features)

        self.stsgcl = nn.ModuleList([stsgcl(adj, T[i], num_of_vertices, features[i],
                                            filter_list[i], module_type, activation, temporal_emb, spatial_emb) for i in
                                     range(len(filter_list))])
        # self.output = output_layer(num_of_vertices, input_length-2*len(filter_list), num_of_features, 128, 1)
        self.output = nn.ModuleList([output_layer(num_of_vertices, input_length-2*len(filter_list), num_of_features, 128, 1)for i in
                                     range(predict_length)])

        # mask shape is (3N, 3N)
        if use_mask:
            if mask_init_value is None:
                raise ValueError("mask init value is None!")
            self.mask = torch.empty(3 * num_of_vertices, 3 * num_of_vertices)
            self.mask = mask_init_value
            self.mask=nn.Parameter(self.mask)

    def forward(self, data):
        '''
        :param data: tensor, shape is (B, T, N, C)
        :param label: shape is (B, T, N)
        :return: output, loss
        '''

        # shape is (3N, 3N)
        if self.mask is not None:
            self.adj = self.adj * self.mask

        for layer in self.stsgcl:
        # :param data: tensor, shape is (B, T, N, C)
        # :return: output shape is (B, T-2, N, C')
            data = layer(data)
        
        # shape is (B, 1, N)
        need_concat = []
        for i in range(self.predict_length):
            need_concat.append(self.output[i](data))

        # shape is (B, T, N)
        data = torch.cat(need_concat, dim=1)

        return data


if __name__ == '__main__':
    # test position_embedding
    data = torch.randn(1, 10, 10, 10)
    output = position_embedding(data, 10, 10, 10, temporal=True, spatial=True)
    print(output.shape)

    # test gcn_operation
    num_of_filter = 64
    num_of_features = 32
    num_of_vertices = 10
    activation = 'relu'
    adj = torch.rand(3 * num_of_vertices, 3 * num_of_vertices)
    gcn = gcn_operation(adj, num_of_filter, num_of_features, num_of_vertices, activation)
    data = torch.rand(3 * num_of_vertices, 5, num_of_features)
    output = gcn(data)
    print(output.shape)

    # test stsgcm
    filters = [64, 64, 64]
    num_of_features = 32
    num_of_vertices = 10
    activation = 'GLU'
    adj = torch.randn(3 * num_of_vertices, 3 * num_of_vertices)
    stsgcm = stsgcm(adj, filters, num_of_features, num_of_vertices, activation)
    data = torch.randn(3 * num_of_vertices, 4, num_of_features)
    output = stsgcm(data)
    print(output.shape)

    # test huber_loss and weighted_loss
    data = torch.rand(3 * num_of_vertices, 5, num_of_features)
    label = torch.rand(3 * num_of_vertices, 5, num_of_features)
    # loss = huber_loss(data, label)
    loss = weighted_loss(data, label, 5, 0.5)
    print(loss.shape)

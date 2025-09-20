import torch
from torch.utils.data import Dataset, DataLoader
class CustomDataset(Dataset):
    def __init__(self, mxnet_data_iter):
        self.data_iter = mxnet_data_iter
        self.num_samples = len(mxnet_data_iter.data)

    def __len__(self):
        return self.num_samples

    def __getitem__(self, idx):
        # 在这里实现根据索引返回对应的数据样本的逻辑
        data = self.data_iter.data[idx].asnumpy()
        label = self.data_iter.label[idx].asnumpy()
        return torch.from_numpy(data), torch.from_numpy(label)
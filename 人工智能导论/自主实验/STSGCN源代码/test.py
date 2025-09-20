import time
import json
import argparse
import matplotlib.pyplot as plt
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import hiddenlayer as h
import torch.nn.functional as F
from torchviz import make_dot
from torch.utils.tensorboard import SummaryWriter
import seaborn as sns
import utils
from utils import (construct_model, generate_data)

parser = argparse.ArgumentParser()
parser.add_argument('--config', type=str, default='configuration file')
parser.add_argument('--test', action="store_true", help='test program')
parser.add_argument("--plot", action="store_true", help="plot network graph")
parser.add_argument("--save", action="store_true", help="save model")
args = parser.parse_args()
config_filename = args.config

with open(config_filename, 'r') as f:
    config = json.loads(f.read())

print(json.dumps(config, sort_keys=True, indent=4))

net = construct_model(config)

batch_size = config['batch_size']
num_of_vertices = config['num_of_vertices']
graph_signal_matrix_filename = config['graph_signal_matrix_filename']
if isinstance(config['ctx'], list):
    print("sorry, I do not wirte about distributed, so you only can use one GPU to train")
    pass
elif isinstance(config['ctx'], int):
    ctx = torch.device("cuda:" + str(config['ctx']))

loaders = []
true_values = {"mean":[], "std": []}
for idx, (x, y, mean, std) in enumerate(generate_data(graph_signal_matrix_filename)):
    if args.test:
        x = x[: 100]
        y = y[: 100]
    y = y.squeeze(axis=-1)
    print(x.shape, y.shape)
    x = torch.from_numpy(x).float()
    y = torch.from_numpy(y).float()
    if idx == 0:
        loaders.append(torch.utils.data.DataLoader(torch.utils.data.TensorDataset(x, y),
                                               batch_size=batch_size, shuffle=True))
    else:
        loaders.append(torch.utils.data.DataLoader(torch.utils.data.TensorDataset(x, y),
                                                   batch_size=batch_size, shuffle=False))
    true_values["mean"].append(mean)
    true_values["std"].append(std)
    training_samples = x.shape[0]

train_loader, val_loader, test_loader = loaders
train_mean, val_mean, test_mean = true_values["mean"]
train_std, val_std, test_std = true_values["std"]

mod = net.to(ctx)

#取最好的进行相关的测试
net.load_state_dict(torch.load("save/PEMS04/PEMS04_exp_55_27.08.pth"))
test_mae = []
test_mape = []
test_rmse = []
net.eval()
with torch.no_grad():
    for idx, data in enumerate(test_loader):
        x,y = data
        x = x.to(ctx)
        output = net(x).cpu()
        output = output * test_std + test_mean
        tmae = utils.masked_mae(output, y ).item()
        tmape = utils.masked_mape(output, y , 0.0).item()
        trmse = utils.masked_rmse(output, y , 0.0).item()

        test_mae.append(tmae)
        test_mape.append(tmape)
        test_rmse.append(trmse)

mtest_mae = np.mean(test_mae)
mtest_mape = np.mean(test_mape)
mtest_rmse = np.mean(test_rmse)

print(f"The result of the Test is:\n"
      f"Test MAE: {mtest_mae}, "
      f"Test MAPE: {mtest_mape}, Test RMSE: {mtest_rmse}")

#热力图
mask = net.mask.detach().cpu().numpy()
plt.subplots(figsize=(20, 20))  # 设置画面大小
sns.heatmap(mask[0:20, 0:20], annot=True, vmax=0.00005, square=True, cmap="RdBu")
plt.show()
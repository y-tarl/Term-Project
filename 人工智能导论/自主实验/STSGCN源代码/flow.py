import networkx as nx
import csv
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec

def flow_graph(graph_signal_matrix_filename, All=True):
    if All:
        data = np.load(graph_signal_matrix_filename)
        fig = plt.figure(figsize=(10, 8))
        gs = gridspec.GridSpec(1, 1, left=0.1, right=0.9, bottom=0.1, top=0.9)  # 使用GridSpec定义子图布局
        ax = fig.add_subplot(gs[0, 0], projection='3d')
        data = data['data'][:100, :, 0:1]
        T, N, C = data.shape
        T = np.arange(1, T + 1)
        for i in range(N):
            C = data[:, i, 0].reshape(-1)
            ax.plot(T, C, zs=i, zdir='x')
        ax.set_xlabel('num')
        ax.set_ylabel('time')
        ax.set_zlabel('flow')
        ax.legend()
        plt.show()
    else:
        data = np.load(graph_signal_matrix_filename)
        data = data['data'][:100, 0:1, 0:1]
        T = np.arange(1, 101)
        C = data.reshape(-1)
        plt.plot(T, C)
        plt.xlabel('time')
        plt.ylabel('flow')
        plt.title("the first detector's flow")
        plt.legend()
        plt.show()
        
    fig.savefig("output.png")  # 保存图形

if __name__ == '__main__':
    # %%
    graph_signal_matrix_filename="data/PEMS08/PEMS08.npz"
    flow_graph(graph_signal_matrix_filename,All=True)

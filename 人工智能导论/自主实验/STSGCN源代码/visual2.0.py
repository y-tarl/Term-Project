import networkx as nx
import csv
import matplotlib.pyplot as plt


def load_graph(file_path, id_filename=None):
    G = nx.Graph()
    if id_filename:
        with open(id_filename, 'r') as f:
            id_dict = {int(i): idx
                       for idx, i in enumerate(f.read().strip().split('\n'))}
        with open(file_path, 'r') as f:
            f.readline()
            reader = csv.reader(f)
            for row in reader:
                if len(row)!= 3 or row[0] == '' or row[1] == '' or row[2] == '':
                    continue
                i, j, distance = int(row[0]), int(row[1]), float(row[2])
                G.add_edge(id_dict[i], id_dict[j], weight=distance)
        return G
    else:
        with open(file_path, 'r') as f:
            f.readline()
            reader = csv.reader(f)
            for row in reader:
                if len(row)!= 3 or row[0] == '' or row[1] == '' or row[2] == '':
                    continue
                i, j, distance = int(row[0]), int(row[1]), float(row[2])
                G.add_edge(i, j, weight=distance)
        return G


if __name__ == '__main__':
    file_path = "data/PEMS08/PEMS08.csv"
    graph_signal_matrix_filename = "data/PEMS08/PEMS08.npz"

    G = load_graph(file_path)

    # pos = nx.spring_layout(G)

# %%

    pos = nx.spring_layout(G, k=15, iterations=130)

    # 根据节点度设置节点大小和颜色
    node_sizes = [G.degree(node) * 50 for node in G.nodes()]
    max_degree = max([G.degree(n) for n in G.nodes()])
    limit_degree = min(max_degree, 10)
    fig = plt.figure(figsize=(10, 8))
    node_colors = [plt.cm.Blues(G.degree(node) / max([G.degree(n) for n in G.nodes()]), alpha=0.5) for node in G.nodes()]

    # 根据边的权重设置边的颜色和宽度
    edge_weights = [G[u][v]['weight'] for u, v in G.edges()]
    max_weight = max(edge_weights)
    edge_colors = [(0, 0, 0, weight / max_weight) for weight in edge_weights]

    nx.draw(G, pos, with_labels=True, node_color=node_colors, node_size=node_sizes, edge_color=edge_colors,
            linewidths=0.2, font_size=5)

    plt.show()
    fig.savefig("network.png")  # 保存图形


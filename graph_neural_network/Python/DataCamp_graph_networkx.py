import networkx as nx
H = nx.DiGraph()

###
# Graphs with NetworkX
###

# adding nodes
H.add_nodes_from([
  (0, {"color": "blue", "size": 250}),
  (1, {"color": "yellow", "size": 400}),
  (2, {"color": "orange", "size": 150}),
  (3, {"color": "red", "size": 600})
])

# adding edges
H.add_edges_from([
  (0, 1),
  (1, 2),
  (1, 0),
  (1, 3),
  (2, 3),
  (3,0)
])
node_colors = nx.get_node_attributes(H, "colors").values()
colors = list(node_colors)
node_sizes = nx.get_node_attributes(H, "size").values()
sizes = list(node_sizes)

# plot graph
nx.draw(H, with_labels = True, node_color = colors, node_size = sizes)

# convert to undirected graph
G = H.to_undirected()
nx.draw(G, with_labels = True, node_color = colors, node_size = sizes)

###
# Planetoid Cora Dataset
###

import os
import torch
os.environ['TORCH'] = torch.__version__
os.environ['PYTHONWARNINGS'] = "ignore"

from torch_geometric.datasets import Planetoid
from torch_geometric.transforms import NormalizeFeatures

dataset = Planetoid(root='data/Planetoid', name='Cora', transform=NormalizeFeatures())

print(f'Dataset: {dataset}:')
print('======================')
print(f'Number of graphs: {len(dataset)}')
print(f'Number of features: {dataset.num_features}')
print(f'Number of classes: {dataset.num_classes}')

data = dataset[0]  # Get the first graph object.
print(data)

###
# node classification with GNN
###

from torch_geometric.nn import GCNConv
import torch.nn.functional as F

class GCN(torch.nn.Module):
    def __init__(self, hidden_channels):
        super().__init__()
        torch.manual_seed(1234567)
        self.conv1 = GCNConv(dataset.num_features, hidden_channels)
        self.conv2 = GCNConv(hidden_channels, dataset.num_classes)

    def forward(self, x, edge_index):
        x = self.conv1(x, edge_index)
        x = x.relu()
        x = F.dropout(x, p = 0.5, training = self.training)
        x = self.conv2(x, edge_index)
        return x

model = GCN(hidden_channels = 16)
print(model)

'''
>>> GCN(
    (conv1): GCNConv(1433, 16)
    (conv2): GCNConv(16, 7)
  )
'''

###
# visualize untrained GCN network
###

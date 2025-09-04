from torch_geometric.datasets import FacebookPagePage # import FacebookPagePage class from PyTorch Geometric

dataset = FacebookPagePage(root = ".")
data = dataset[0] # store graph in a dedicated data variable

# print information about dataset in general
print(f'Dataset: {dataset}')
print('-----------------------')
print(f'Number of graphs: {len(dataset)}')
print(f'Number of nodes: {data.x.shape[0]}')
print(f'Number of features: {dataset.num_features}')
print(f'Number of classes: {dataset.num_classes}')

'''
Dataset: FacebookPagePage()
-----------------------
Number of graphs: 1
Number of nodes: 22470
Number of features: 128
Number of classes: 4
'''

print(f'\nGraph:')
print('------')
print(f'Edges are directed: {data.is_directed()}')
print(f'Graph has isolated nodes: {data.has_isolated_nodes()}')
print(f'Graph has loops: {data.has_self_loops()}')

'''
Graph:
------
Edges are directed: False
Graph has isolated nodes: False
Graph has loops: True
'''

data.train_mask = range(18000)
data.val_mask = range(18001, 20000)
data.test_mask = range(20001, 22470)

# Alternatively, PyTorch Geometric offers a transform function to calculate random masks when dataset is loaded
import torch_geometric.transforms as T
dataset = Planetoid(root = ".", name = "Cora")
data = dataset[0]
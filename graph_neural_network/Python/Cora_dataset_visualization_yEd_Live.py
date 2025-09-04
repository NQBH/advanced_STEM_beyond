from torch_geometric.datasets import Planetoid # import Planetoid class from PyTorch Geometric

dataset = Planetoid(root=".", name="Cora") # download
data = dataset[0] # Cora only has 1 graph we can store in a dedicated data variable

# print information about dataset in general
print(f'Dataset: {dataset}')
print('---------------')
print(f'Number of graphs: {len(dataset)}')
print(f'Number of nodes: {data.x.shape[0]}')
print(f'Number of features: {dataset.num_features}')
print(f'Number of classes: {dataset.num_classes}')

'''
Dataset: Cora()
---------------
Number of graphs: 1
Number of nodes: 2708
Number of features: 1433
Number of classes: 7
'''
# can also get detailed information thanks to dedicated functions from PyTorch Geometric
print(f'Graph:')
print('------')
print(f'Edges are directed: {data.is_directed()}')
print(f'Graph has isolated nodes: {data.has_isolated_nodes()}')
print(f'Graph has loops: {data.has_self_loops()}')

'''
Graph:
------
Edges are directed: False
Graph has isolated nodes: False
Graph has loops: False
'''
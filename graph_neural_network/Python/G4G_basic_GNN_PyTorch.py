# !pip install torch-scatter torch-sparse torch-cluster torch-spline-conv torch-geometric
import torch
print("torch version: ", torch.__version__)
from torch_geometric.datasets import Planetoid # from torch_geometric.data import Planetoid
import torch.nn.functional as F
from torch_geometric.nn import GCNConv

# load Cora dataset
dataset = Planetoid(root = 'data/Planetoid', name = 'Cora') # load CORA dataset
dataset = Planetoid(root='/tmp/Cora', name='Cora')

# define a GNN model using PyTorch
class customGNN(torch.nn.Module):
	def __init__(self, input_dim, hidden_dim, output_dim):
		super(customGNN, self).__init__()
		self.layer1 = GCNConv(input_dim, hidden_dim)
		self.layer2 = GCNConv(hidden_dim, output_dim)

	def forward(self, feature_data, edge_info):
		# 1st GCN layer
		x = self.layer1(feature_data, edge_info)
		x = F.relu(x)
		x = F.dropout(x, p = 0.5, training = self.training)
		# 2nd GCN layer
		x = self.layer2(x, edge_info)
		return F.log_softmax(x, dim = 1)
# initialize GNN model
input_features = dataset.num_node_features
num_classes = dataset.num_classes
model = customGNN(input_features, 16, num_classes)

optimizer = torch.optim.Adam(model.parameters(), lr = 0.01, weight_decay = 5e-4)
graph_data = dataset[0] # get graph data

# traing GNN model on CORA dataset
def traing_model():
	model.train()
	optimizer.zero_grad()
	output = model(graph_data.x, graph_data.edge_index)
	loss = F.nll_loss(output[graph_data.train_mask], graph_data.y[graph_data.train_mask])
	loss.backward()
	optimizer.step()
	return loss.item()

for epoch in range(200):
	loss_value = traing_model()
	print(f'Epoch: {epoch+1:03d}, Loss: {loss_value:.4f}')

# evaluate model's performance
def evaluate_model():
	model.eval()
	with torch.no_grad():
		predictions = model(graph_data.x, graph_data.edge_index).argmax(dim = 1)
		correct = (predictions[graph_data.test_mask] == graph_data.y[graph_data.test_mask]).sum()
		acc = int(correct) / int(graph_data.test_mask.sum())
	return acc

accuracy = evaluate_model()
print(f'Test Accuracy: {accuracy:.4f}')
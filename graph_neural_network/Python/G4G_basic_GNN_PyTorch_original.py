!pip install torch-scatter torch-sparse torch-cluster torch-spline-conv torch-geometric

import torch
from torch_geometric.data import Planetoid
import torch.nn.functional as F
from torch_geometric.nn import GCNConv

# Loading the Cora dataset
dataset = Planetoid(root='data/Planetoid', name='Cora')
dataset = Planetoid(root='/tmp/Cora', name='Cora')

import torch
import torch.nn.functional as F
from torch_geometric.nn import GCNConv

class CustomGNN(torch.nn.Module):
    def __init__(self, input_dim, hidden_dim, output_dim):
        super(CustomGNN, self).__init__()
        self.layer1 = GCNConv(input_dim, hidden_dim)
        self.layer2 = GCNConv(hidden_dim, output_dim)

    def forward(self, feature_data, edge_info):
        # First GCN layer
        x = self.layer1(feature_data, edge_info)
        x = F.relu(x)
        x = F.dropout(x, p=0.5, training=self.training)
        # Second GCN layer
        x = self.layer2(x, edge_info)
        return F.log_softmax(x, dim=1)

# Initialize the GNN model
input_features = dataset.num_node_features
num_classes = dataset.num_classes
model = CustomGNN(input_features, 16, num_classes)

optimizer = torch.optim.Adam(model.parameters(), lr=0.01, weight_decay=5e-4)

graph_data = dataset[0]  # Get the graph data

def train_model():
    model.train()
    optimizer.zero_grad()
    output = model(graph_data.x, graph_data.edge_index)
    loss = F.nll_loss(output[graph_data.train_mask], graph_data.y[graph_data.train_mask])
    loss.backward()
    optimizer.step()
    return loss.item()

for epoch in range(200):
    loss_value = train_model()
    print(f'Epoch: {epoch+1:03d}, Loss: {loss_value:.4f}')

def evaluate_model():
    model.eval()
    with torch.no_grad():
        predictions = model(graph_data.x, graph_data.edge_index).argmax(dim=1)
        correct = (predictions[graph_data.test_mask] == graph_data.y[graph_data.test_mask]).sum()
        acc = int(correct) / int(graph_data.test_mask.sum())
    return acc

accuracy = evaluate_model()
print(f'Test Accuracy: {accuracy:.4f}')
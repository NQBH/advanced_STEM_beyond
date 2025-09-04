import torch_geometric.transforms as T
dataset = Planetoid(root=".", name="Cora")
data = dataset[0]

import pandas as pd
df_x = pd.DataFrame(data.x.numpy())
df_x['label'] = pd.DataFrame(data.y)

# define metric as the fraction of correct predictions
def accuracy(y_pred, y_true):
	return torch.sum(y_pred == y_true) / len(y_true)


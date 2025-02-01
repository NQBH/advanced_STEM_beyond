import sys
from python_environment_check import check_packages
import torch
import numpy as np

d = {
    'numpy': '1.21.2',
    'matplotlib': '3.4.3',
    'torch': '1.9.0',
}
check_packages(d)

print('PyTorch version:', torch.__version__)

np.set_printoptions(precision=3)

# ### Creating tensors in PyTorch

a = [1, 2, 3]
b = np.array([4, 5, 6], dtype=np.int32)

t_a = torch.tensor(a)
t_b = torch.from_numpy(b)

print(t_a)
print(t_b)

torch.is_tensor(a), torch.is_tensor(t_a)

t_ones = torch.ones(2, 3)

t_ones.shape

print(t_ones)

rand_tensor = torch.rand(2,3)

print(rand_tensor)

# ### Manipulating the data type and shape of a tensor

t_a_new = t_a.to(torch.int64)

print(t_a_new.dtype)

t = torch.rand(3, 5)

t_tr = torch.transpose(t, 0, 1)
print(t.shape, ' --> ', t_tr.shape)

t = torch.zeros(30)

t_reshape = t.reshape(5, 6)

print(t_reshape.shape)

t = torch.zeros(1, 2, 1, 4, 1)

t_sqz = torch.squeeze(t, 2)

print(t.shape, ' --> ', t_sqz.shape)

# ### Applying mathematical operations to tensors

torch.manual_seed(1)

t1 = 2 * torch.rand(5, 2) - 1
t2 = torch.normal(mean=0, std=1, size=(5, 2))

t3 = torch.multiply(t1, t2)
print(t3)

t4 = torch.mean(t1, axis=0)
print(t4)

t5 = torch.matmul(t1, torch.transpose(t2, 0, 1))

print(t5)

t6 = torch.matmul(torch.transpose(t1, 0, 1), t2)

print(t6)

norm_t1 = torch.linalg.norm(t1, ord=2, dim=1)

print(norm_t1)

np.sqrt(np.sum(np.square(t1.numpy()), axis=1))

# ### Split, stack, and concatenate tensors

torch.manual_seed(1)

t = torch.rand(6)

print(t)

t_splits = torch.chunk(t, 3)

[item.numpy() for item in t_splits]

torch.manual_seed(1)
t = torch.rand(5)

print(t)

t_splits = torch.split(t, split_size_or_sections=[3, 2])
 
[item.numpy() for item in t_splits]

A = torch.ones(3)
B = torch.zeros(2)

C = torch.cat([A, B], axis=0)
print(C)

A = torch.ones(3)
B = torch.zeros(3)

S = torch.stack([A, B], axis=1)
print(S)

# ## Building input pipelines in PyTorch

# ### Creating a PyTorch DataLoader from existing tensors

from torch.utils.data import DataLoader
t = torch.arange(6, dtype=torch.float32)
data_loader = DataLoader(t)

for item in data_loader:
    print(item)

data_loader = DataLoader(t, batch_size=3, drop_last=False)

for i, batch in enumerate(data_loader, 1):
    print(f'batch {i}:', batch)

# ### Combining two tensors into a joint dataset

from torch.utils.data import Dataset
class JointDataset(Dataset):
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __len__(self):
        return len(self.x)
    def __getitem__(self, idx):
        return self.x[idx], self.y[idx]

torch.manual_seed(1)

t_x = torch.rand([4, 3], dtype=torch.float32)
t_y = torch.arange(4)
joint_dataset = JointDataset(t_x, t_y)

# Or use TensorDataset directly
from torch.utils.data import TensorDataset
joint_dataset = TensorDataset(t_x, t_y)

for example in joint_dataset:
    print('  x: ', example[0], 
          '  y: ', example[1])
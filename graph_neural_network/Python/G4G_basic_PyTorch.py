import torch

# create a 1D tensor
x = torch.tensor([1.0, 2.0, 3.0])
print('1D Tensor: \n', x)

# create a 2D tensor
y = torch.zeros((3, 3))
print('2D Tensor: \n', y)

# operations on tensors
a = torch.tensor([1.0, 2.0])
b = torch.tensor([3.0, 4.0])
print('Element-wise addition of a & b: \n', a + b) # element-wise addition
print('Matrix multiplication of a & b: \n', torch.matmul(a.view(2, 1), b.view(1, 2))) # matrix multiplication

# reshaping & transposing tensors
t = torch.tensor([[1, 2, 3, 4],
                 [5, 6, 7, 8],
                 [9, 10, 11, 12]])
# reshaping
print("Reshaping")
print(t.reshape(6, 2))

# resizing (deprecated, use reshape)
print("\nResizing")
print(t.view(2, 6))

# transposing
print("\nTransposing")
print(t.transpose(0, 1))

# autograd & computational graphs
x = torch.tensor(2.0, requires_grad=True)
y = x ** 2
y.backward()
print(x.grad)  #(dy/dx = 2x = 4 when x=2)

# build neural networks in PyTorch
import torch
import torch.nn as nn

class neural_network(nn.Module):
	def __init__(self):
		super(neural_network, self).__init__()
		self.fc1 = nn.Linear(10, 16) # 1st layer
		self.fc2 = nn.Linear(16, 8) # 2nd layer
		self.fc3 = nn.Linear(8, 1) # output layer

	def forward(self, x):
		x = torch.relu(self.fc1(x))
		x = torch.relu(self.fc2(x))
		x = torch.sigmoid(self.fc3(x))
		return x

model = neural_network()
print(model)

# define loss function & optimizer
model = neural_network()
criterion = nn.BCELoss()
optimizer = torch.optim.Adam(model.parameters(),  lr = 0.01)

# train model
inputs = torch.randn((100, 10))
targets = torch.randint(0, 2, (100, 1)).float()
epochs = 20

for epoch in range(epochs):
	optimizer.zero_grad() # reset gradients
	outputs = model(inputs) # forward pass
	loss = criterion(outputs, targets) # compute loss
	loss.backward() # compute gradients
	optimizer.step() # update weights

	if (epoch + 1) % 5 == 0:
		print(f"Epoch [{epoch+1}/{epochs}], Loss: {loss.item():.4f}")

# understand torch.nn.parameter
import torch
import torch.nn as nn

class my_linear(nn.Module):
	def __init__(self, in_features, out_features):
		super(my_linear, self).__init__()
		# define weight & bias parameters
		self.weight = nn.Parameter(torch.randn(out_features, in_features))
		self.bias = nn.Parameter(torch.randn(out_features))

	def forward(self, x): # implement forward pass
		return torch.matmul(x, self.weight.t()) + self.bias

# training a model with torch.nn.Parameter in PyTorch
# import necessary libraries
import torch
import torch.nn as nn
import torch.optim as optim

# define neural network class
class simple_net(nn.Module):
	def __init__(self):
		super(simple_net, self).__init__()
		# define a parameter (weight) using torch.nn.Parameter
		self.weight = nn.Parameter(torch.randn(1, requires_grad = True))

	def forward(self, x): # apply weight to input
		return x * self.weight

# instantiate model
model = simple_net()
print("initial model parameters: ", list(model.parameters()))

# define a loss function & optimizer
criterion = nn.MSELoss()
optimizer = optim.SGD(model.parameters(), lr = 0.01)

# prepare training data: sample input & target
input_tensor = torch.tensor([2.0])
target_tensor = torch.tensor([4.0])

# train model

# training loop
for epoch in range(100):
	optimizer.zero_grad() # zero gradients
	output = model(input_tensor) # forward pass
	loss = criterion(output, target_tensor) # compute loss
	loss.backward() # backpropagation
	optimizer.step() # update parameters

	if epoch % 10 == 0:
		print(f'Epoch {epoch}, Loss: {loss.item()}, Weight: {model.weight.item()}')

# display final model parameters
print("Final Model Parameters:", list(model.parameters()))
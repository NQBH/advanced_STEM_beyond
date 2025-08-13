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

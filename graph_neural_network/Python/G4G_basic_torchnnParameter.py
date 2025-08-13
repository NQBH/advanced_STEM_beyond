import torch
import torch.nn as nn
import torch.optim as optim

# Define a custom neural network module
class SimpleNet(nn.Module):
    def __init__(self):
        super(SimpleNet, self).__init__()
        # Define a parameter (weight) using torch.nn.Parameter
        self.weight = nn.Parameter(torch.randn(1, requires_grad=True))
        
    def forward(self, x):
        # Apply the weight to the input
        return x * self.weight

# Instantiate the model
model = SimpleNet()
print("Initial Model Parameters:", list(model.parameters()))

# Define a loss function and optimizer
criterion = nn.MSELoss()
optimizer = optim.SGD(model.parameters(), lr=0.01)

# Sample input and target
input_tensor = torch.tensor([2.0])
target_tensor = torch.tensor([4.0])

# Training loop
for epoch in range(100):
    optimizer.zero_grad()  # Zero the gradients
    output = model(input_tensor)  # Forward pass
    loss = criterion(output, target_tensor)  # Compute loss
    loss.backward()  # Backpropagation
    optimizer.step()  # Update parameters

    if epoch % 10 == 0:
        print(f'Epoch {epoch}, Loss: {loss.item()}, Weight: {model.weight.item()}')

print("Final Model Parameters:", list(model.parameters()))
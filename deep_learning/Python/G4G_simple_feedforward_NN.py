import numpy as np
import pandas as pd
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense

# create & load dataset
data = {
    'feature1': [0.1, 0.2, 0.3, 0.4, 0.5],
    'feature2': [0.5, 0.4, 0.3, 0.2, 0.1],
    'label': [0, 0, 1, 1, 1]
}

df = pd.DataFrame(data)
X = df[['feature1', 'feature2']].values
y = df['label'].values

# create a neural network
model = Sequential()
model.add(Dense(8, input_dim = 2, activation = 'relu')) # hidden layer
model.add(Dense(1, activation = 'sigmoid')) # output layer

# compile model
model.compile(loss = 'binary_crossentropy', optimizer = 'adam', metrics = ['accuracy'])

# train model
model.fit(X, y, epochs = 100, batch_size = 1, verbose = 1)

# make predictions
test_data = np.array([[0.2, 0.4]])
prediction = model.predict(test_data)
predicted_label = (prediction > 0.5).astype(int)
print(predicted_label)
from __future__ import print_function
import numpy as np
from sklearn import neighbors, datasets
from sklearn.model_selection import train_test_split # for splitting data
from sklearn.metrics import accuracy_score			 # for evaluating results

iris = datasets.load_iris()
iris_X = iris.data
iris_y = iris.target

print('Labels:', np.unique(iris_y))

# split train & test
np.random.seed(7)
X_train, X_test, y_train, y_test = train_test_split(iris_X, iris_y, test_size = 130)
print('Training size:', X_train.shape[0], ', test size:', X_test.shape[0])

# 1NN
model = neighbors.KNeighborsClassifier(n_neighbors = 1, p = 2) # p = 2 for l2 norm, p = 1 for l1 norm
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Accuracy of 1NN: %.2f %%" %(100*accuracy_score(y_test, y_pred)))

# 7NN
model = neighbors.KNeighborsClassifier(n_neighbors = 7, p = 2) # p = 2 for l2 norm, p = 1 for l1 norm
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Accuracy of 7NN with major voting: %.2f %%" %(100*accuracy_score(y_test, y_pred)))

# mark weights for neigbored points
model = neighbors.KNeighborsClassifier(n_neighbors = 7, p = 2, weights = 'distance')
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Accuracy of 7NN (1/distance weights): %.2f %%" %(100*accuracy_score(y_test, y_pred)))

# KNN with self-defined weights
def myweight(distances):
	sigma2 = .4 # can change this number
	return np.exp(-distances**2/sigma2)

model = neighbors.KNeighborsClassifier(n_neighbors = 7, p = 2, weights = myweight)
model.fit(X_train, y_train)
y_pred = model.predict(X_test)
print("Accuracy of 7NN (customized weights): %.2f %%" %(100*accuracy_score(y_test, y_pred)))
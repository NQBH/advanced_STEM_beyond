# Chap. 1: Intro

# Chap. 11: ML

import random
from typing import TypeVar, List, Tuple
X = TypeVar('X') # generic type to represent a data point

# split dataset
def split_data(data: List[X], prob: float) -> Tuple[List[X], List[X]]:
	"""Split data into fractions [prob, 1 - prob]"""
	data = data[:] # make a shallow copy
	random.shuffle(data) # because shuffle modifies list
	cut = int(len(data) * prob) # use prob to find a cutoff
	return data[:cut], data[cut:] # split shuffled list there

data = [n for n in range(1000)]
train, test = split_data(data, 0.75)

# proportions should be correct
assert len(train) == 750
assert len(test) == 250

# original data should be preserved (in some order)
assert sorted(train + test) == data

Y = TypeVar('Y') # generic type to represent output variables
def train_test_split(xs: List[X], ys: List[Y], test_pct: float) -> Tuple[List[X], List[X], List[Y], List[Y]]:
	# generate indices & split them
	idxs = [i for i in range(len(xs))]
	train_idxs, test_idxs = split_data(idxs, 1 - test_pct)

	return ([xs[i] for i in train_idxs], [xs[i] for i in test_idxs], [ys[i] for i in train_idxs], [ys[i] for i in test_idxs]) # x_train, x_test, y_train, y_test

xs = [x for x in range(1000)] # xs are 1 ... 1000
ys = [2 * x for x in xs] # each y_i is twice x_i

x_train, x_test, y_train, y_test = train_test_split(xs, ys, 0.25)

# Check that the proportions are correct
assert len(x_train) == len(y_train) == 750
assert len(x_test) == len(y_test) == 250

# Check that the corresponding data points are paired correctly
assert all(y == 2 * x for x, y in zip(x_train, y_train))
assert all(y == 2 * x for x, y in zip(x_test, y_test))

'''
model = SomeKindOfModel() # insert SomeKindOfModel
x_train, x_test, y_train, y_test = train_test_split(xs, ys, 0.33)
model.train(x_train, y_train)
performance = model.test(x_test, y_test)
'''
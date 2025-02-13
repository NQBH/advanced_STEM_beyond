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
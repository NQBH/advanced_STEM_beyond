import networkx as nx
import random
random.seed(0)
import numpy as np
np.random.seed(0)

G = nx.erdos_renyi_graph(10, 0.3, seed = 1, directed = False)

def next_node(previous, current, p, q): # define next_node function with list of parameters
	neighbors = list(G.neighbors(current)) # retrieve list of neighboring nodes from current node
	alphas = [] # initialize a list of alpha values
	for neighbor in neighbors: # for each neighbor, calculate appropriate alpha value: 1 / p if this neighbor is previous node, 1 if this neighbor is connected to pprevious node, & 1 / q otherwise
		if neighbor == previous:
			alpha = 1 / p
		elif G.has_edge(neighbor, previous):
			alpha = 1
		else:
			alpha = 1 / q
		alphas.append(alpha)
		probs = [alpha / sum(alphas) for alpha in alphas] # normalize these values to create probabilities
	next = np.random.choice(neighbors, size = 1, p = probs) # randomly select next node based on transition probabilities calculateed in previous step using np.random.choice()
	return next

# new version of random walk function
def random_walk(start, length, p, q):
	walk = [start]
	for i in range(length):
		current = walk[-1]
		previous = walk[-2] if len(walk) > 1 else None
		next = next_node(previous, current, p, q)
		walk.append(next)
	return [str(x) for x in walk]

random_walk(0, 8, p = 1, q = 1)
random_walk(0, 8, p = 1, q = 10)
random_walk(0, 8, p = 10, q = 1)

'''
(node2vec) nqbh@nqbh:~/advanced_STEM_beyond/graph_neural_network/Python$ python biased_random_walk.py 
Traceback (most recent call last):
  File "/home/nqbh/advanced_STEM_beyond/graph_neural_network/Python/biased_random_walk.py", line 34, in <module>
    random_walk(0, 8, p = 1, q = 1)
  File "/home/nqbh/advanced_STEM_beyond/graph_neural_network/Python/biased_random_walk.py", line 30, in random_walk
    next = next_node(previous, current, p, q)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/nqbh/advanced_STEM_beyond/graph_neural_network/Python/biased_random_walk.py", line 10, in next_node
    neighbors = list(G.neighbors(current)) # retrieve list of neighboring nodes from current node
                     ^^^^^^^^^^^^^^^^^^^^
  File "/home/nqbh/anaconda3/envs/node2vec/lib/python3.12/site-packages/networkx/classes/graph.py", line 1372, in neighbors
    return iter(self._adj[n])
                ~~~~~~~~~^^^
TypeError: unhashable type: 'numpy.ndarray'
'''
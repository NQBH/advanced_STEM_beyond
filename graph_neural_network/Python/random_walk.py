import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import random
random.seed(0) # initialize random number generator for reproducibility

G = nx.erdos_renyi_graph(10, 0.3, seed = 1, directed = False) # generate a random graph thanks to erdos_renyi_graph function with a fixed number of nodes 10 & a predefined probability of creating an edge between 2 nodes: 0.3


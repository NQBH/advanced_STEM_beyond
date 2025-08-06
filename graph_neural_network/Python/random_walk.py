import networkx as nx
from gensim.models.word2vec import Word2Vec
import matplotlib.pyplot as plt
import numpy as np
import random
random.seed(0) # initialize random number generator for reproducibility

G = nx.erdos_renyi_graph(10, 0.3, seed = 1, directed = False) # generate a random graph thanks to erdos_renyi_graph function with a fixed number of nodes 10 & a predefined probability of creating an edge between 2 nodes: 0.3

# plot random graph
plt.figure(dpi = 300)
plt.axis('off')
nx.draw_networkx(G, pos = nx.spring_layout(G, seed = 0), node_size = 600, cmap = 'coolwarm', font_size = 14, font_color = 'white')
plt.show()

# implement random walks
def random_walk(start, length):
	walk = [str(start)] # starting node
	for i in range(length):
		neighbors = [node for node in G.neighbors(start)]
		next_node = np.random.choice(neighbors, 1)[0]
		walk.append(str(next_node))
		start = next_node
	return walk

print(random_walk(0, 10))

# implement DeepWalk
G = nx.karate_club_graph() # importa dataset
labels = []
for node in G.nodes: # convert string class labels into numerical values
	label = G.nodes[node]['club']
	labels.append(1 if label == 'Officer' else 0)

# plot Zachary's Karate Club graph using new labels
plt.figure(figsize = (12, 12), dpi = 300)
plt.axis('off')
nx.draw_networkx(G, pos = nx.spring_layout(G, seed = 0), node_color = labels, node_size = 500, cmap = 'coolwarm', font_size = 14, font_color = 'white')
plt.show()

# generate dataset: random walks
walks = []
for node in G.nodes:
	for _ in range(80):
		walks.append(random_walk(node, 10))
print(walks[0]) # print 1st walk generated

# implement Word2Vec: use skip-gram model with H-Softmax (can play with parameters to improve quality of embeddings)
model = Word2Vec(walks,
	hs = 1, # hierarchical softmax H-Softmax
	sg = 1, # skip-gram
	vector_size = 100,
	window = 10,
	workers = 2,
	seed = 0)

# train model on generated random walks
model.train(walks, total_examples = model.corpus_count, epochs = 30, report_delay = 1)
print('Nodes that are the most similar to node 0:')
for similarity in model.wv.most_similar(positive = ['0']):
	print(f'	{similarity}')

# similarity between 2 nodes
print(f"Similarity between node 0 & 4: {model.wv.similarity('0', '4')}")

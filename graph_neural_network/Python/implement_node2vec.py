import networkx as nx
from gensim.models.word2vec import Word2Vec
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

G = nx.karate_club_graph() # load Zachary's Karate Club dataset

# transform nodes' labels into numerical values 0 & 1
labels = []
for node in G.nodes:
	label = G.nodes[node]['club']
	labels.append(1 if label == 'Officer' else 0)
walks = []
for node in G.nodes:
	for _ in range(80):
		walks.append(random_walk(node, 10, 3, 2))
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
# create an instance of Word2Vec (a skip-gram model) with a hierarchical softmax function
node2vec = Word2Vec(walks,
	hs = 1, # hierarchical softmax
	sg = 1, # skip-gram
	vector_size = 100,
	window = 10,
	workers = 2,
	min_count = 1,
	seed = 0)
# train skip-gram model on sequences generated for 30 epochs
node2vec.train(walks, total_examples = node2vec.corpus_count, epochs = 30, report_delay = 1)

# create masks to train & test classifier
train_mask = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24]
train_mask_str = [str(x) for x in train_mask]
test_mask = [0, 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 26, 27, 28, 29, 30, 31, 32, 33]
test_mask_str = [str(x) for x in test_mask]
labels = np.array(labels)

# train Random Forest classifier on training data
clf = RandomForestClassifier(random_state = 0)
clf.fit(node2vec.wv[train_mask_str], labels[train_mask])

# evaluate it in terms of accuracy for test data
y_pred = clf.predict(node2vec.wv[test_mask_str])
acc = accuracy_score(y_pred, labels[test_mask])
print(f'Node2Vec accuracy = {acc * 100:.2f}%')
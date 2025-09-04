# preprocessing for semi-supervised problem
labels = []
for node, data in gml_graph.nodes(data = True): # extract labels & handle neural values
	if data['value'] == 'c':
		labels.append('right')
	elif data['value'] == 'l':
		labels.append('left')
	else:
		labels.append('neutral')
labels = np.array(labels)
random.seed(52) # random seed for reproducibility
indices = list(range(len(labels))) # indices of all nodes
labelled_percentage = 0.2 # 20% of data to keep as labeled
labelled_indices = random.sample(indices, int(labelled_percentage * len(labels))) # select a subset of indices to remain labeled

labelled_mask = np.zeros(len(labels), dtype = bool) # initialize masks for labeled & unlabeled data
unlabelled_mask = np.ones(len(labels), dtype = bool)

labelled_mask[labelled_indices] = True # update masks
unlabelled_mask[labelled_indices] = False

labelled_labels = labels[labelled_mask] # use masks to split dataset
unlabelled_mask = labels[unlabelled_mask]

label_mapping = {'left': 0, 'right': 1, 'neutral': 2} # transformed labels to numerical form
numeric_labels = np.array([label_mapping[label]] for label in labels)

# preprocessing: constructing training data
## for GNN embeddings
X_train_gnn = gnn_embeddings[labelled_mask]
y_train_gnn = numeric_labels[labelled_mask]

X_n2v = np.array([embeddings[str(node)] for node in gml_graph.nodes()]) # for N2V embeddings
## ensure N2V embeddings are in the same order as labels
X_train_n2v = X_n2v[labelled_mask]
y_train_n2v = numeric_labels[labelled_mask]

# preprocessing: constructing training data
clf_gnn = RandomForestClassifier() # classifier for GNN embeddings
clf_gnn.fit(X_train_gnn, y_train_gnn)

clf_n2v = RandomForestClassifier() # 
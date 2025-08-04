import NetworkX as nx
from Node2Vec import Node2Vec
book_graph = nx.read_gml('polbooks.gml')
node2vec = Node2Vec(book_graph, dimensions = 64, walk_length = 30, num_walks = 200, workers = 4)
model = node2vec.fit(window = 10, min_count = 1, batch_words = 4)
embeddings = {str(node) : model.wv[str(node)] for node in gml_graph.nodes()}
'''
nqbh@nqbh:~/advanced_STEM_beyond/graph_neural_network/Python$ python3 generate_N2V_embedding.py 
Traceback (most recent call last):
  File "/home/nqbh/advanced_STEM_beyond/graph_neural_network/Python/generate_N2V_embedding.py", line 1, in <module>
    import NetworkX as nx
ModuleNotFoundError: No module named 'NetworkX'
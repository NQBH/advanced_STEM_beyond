import networkx as nx

G = nx.Graph()
edges = [
    (1, 2), (1, 3), (1, 4), (2, 4), (2, 5), (1, 6),
    (3, 6), (4, 6), (4, 7), (5, 7), (6, 7), (2, 7)
]
G.add_edges_from(edges)

n_spanning_trees = nx.number_of_spanning_trees(G)
print(n_spanning_trees)

import networkx as nx

# create some types of graph using edge list data structure

## define an undirected graph
G = nx.Graph()
G.add_edges_from([('A', 'B'), ('A', 'C'), ('B', 'D'), ('B', 'E'), ('C', 'F'), ('C', 'G')])

## define a directed graph
DG = nx.DiGraph()
DG.add_edges_from([('A', 'B'), ('A', 'C'), ('B', 'D'), ('B', 'E'), ('C', 'F'), ('C', 'G')])

## define an weighted graph
WG = nx.Graph()
WG.add_edges_from([('A', 'B', {"weight": 10}), ('A', 'C', {"weight": 20}), ('B', 'D', {"weight": 30}), ('B', 'E', {"weight": 40}), ('C', 'F', {"weight": 50}), ('C', 'G', {"weight": 60})])
labels = nx.get_edge_attributes(WG, "weight")

# verify whether a graph is connected or disconnected
G1 = nx.Graph()
G1.add_edges_from([(1, 2), (2, 3), (3, 1), (4, 5)])
print(f"Is graph 1 connected? {nx.is_connected(G1)}")

G2 = nx.Graph()
G2.add_edges_from([(1, 2), (2, 3), (3, 1), (1, 4)])
print(f"Is graph 2 connected? {nx.is_connected(G2)}")

# calculate node degree, indegree, or outdegree
G = nx.Graph()
G.add_edges_from([('A', 'B'), ('A', 'C'), ('B', 'D'), ('B', 'E'), ('C', 'F'), ('C', 'G')])
print(f"deg(A) = {G.degree['A']}")

DG = nx.DiGraph()
DG.add_edges_from([('A', 'B'), ('A', 'C'), ('B', 'D'), ('B', 'E'), ('C', 'F'), ('C', 'G')])
print(f"deg^-(A) = {DG.in_degree['A']}")
print(f"deg^+(A) = {DG.out_degree['A']}")

# graph measures
print(f"Degree centrality = {nx.degree_centrality(G)}")
print(f"Closeness centrality = {nx.closeness_centrality(G)}")
print(f"Betweenness centrality = {nx.betweenness_centrality(G)}")

# adjacency matrix
adj = [[0,1,1,0,0,0,0],
	   [1,0,0,1,1,0,0],
	   [1,0,0,0,0,1,1],
	   [0,1,0,0,0,0,0],
	   [0,1,0,0,0,0,0],
	   [0,0,1,0,0,0,0],
	   [0,0,1,0,0,0,0]]

# edge list
edge_list = [(0, 1), (0, 2), (1, 3), (1, 4), (2, 5), (2, 6)]
# adjacency list
adj_list = {
    0: [1, 2],
    1: [0, 3, 4],
    2: [0, 5, 6],
    3: [1],
    4: [1],
    5: [2],
    6: [2]
}

# graph traversals

## BFS: time complexity O(|V| + |E|)
G = nx.Graph()
G.add_edges_from([('A', 'B'), ('A', 'C'), ('B', 'D'), ('B', 'E'), ('C', 'F'), ('C', 'G')])
def bfs(graph, node):
	visited, queue = [node], [node]
	while queue:
		node = queue.pop(0)
		for neighbor in graph[node]:
			if neighbor not in visited:
				visited.append(neighbor)
				queue.append(neighbor)
	return visited # function returns the list of visited nodes in the order in which they were visited

print(bfs(G, 'A'))

## DFS: time complexity O(|V| + |E|)
visited = []
def dfs(visited, graph, node):
	if node not in visited:
		visited.append(node)
		for neighbor in graph[node]:
			visited = dfs(visited, graph, neighbor)
	return visited

print(dfs(visited, G, 'A'))
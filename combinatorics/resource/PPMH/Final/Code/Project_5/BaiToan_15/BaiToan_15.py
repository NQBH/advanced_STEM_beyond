import heapq
from collections import defaultdict

def dijkstra_multigraph(graph, start):
    dist = {}
    pq = [(0, start)]  

    while pq:
        d, u = heapq.heappop(pq)
        if u in dist:
            continue
        dist[u] = d
        for v, weight in graph[u]:
            if v not in dist:
                heapq.heappush(pq, (d + weight, v))
    return dist

graph = defaultdict(list)
graph['A'].append(('B', 4))
graph['A'].append(('B', 2))  
graph['A'].append(('C', 5))
graph['B'].append(('C', 1))
graph['C'].append(('D', 3))

distances = dijkstra_multigraph(graph, 'A')
for node in sorted(distances):
    print(f"Khoảng cách ngắn nhất từ A đến {node}: {distances[node]}")
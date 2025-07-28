import heapq
from collections import defaultdict
import math

def dijkstra(graph, start):
    distances = {node: math.inf for node in graph}
    distances[start] = 0
    
    predecessors = {node: None for node in graph}
    
    pq = [(0, start)]
    
    visited = set()
    
    while pq:
        current_distance, current_node = heapq.heappop(pq)
        
        if current_node in visited:
            continue
            
        visited.add(current_node)
        
        for neighbor, weight in graph[current_node].items():
            if neighbor not in visited:
                distance = current_distance + weight
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    predecessors[neighbor] = current_node
                    heapq.heappush(pq, (distance, neighbor))
    
    return distances, predecessors

def get_path(predecessors, end):
    path = []
    current = end
    while current is not None:
        path.append(current)
        current = predecessors[current]
    return path[::-1] 

#Example
if __name__ == "__main__":
    graph = {
        'A': {'B': 4, 'C': 2},
        'B': {'A': 4, 'C': 1, 'D': 5},
        'C': {'A': 2, 'B': 1, 'D': 8, 'E': 10},
        'D': {'B': 5, 'C': 8, 'E': 2},
        'E': {'C': 10, 'D': 2}
    }
    
    start_node = 'A'
    distances, predecessors = dijkstra(graph, start_node)
    
    print("Shortest distances from node", start_node)
    for node, distance in distances.items():
        print(f"To {node}: {distance}")
    
    end_node = 'E'
    path = get_path(predecessors, end_node)
    print(f"\nShortest path to {end_node}: {' -> '.join(path)}")
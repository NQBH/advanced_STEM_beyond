#!/usr/bin/env python3
"""
Dijkstra's Algorithm for Multigraphs
Supports multiple edges but no self-loops
"""

import heapq
import sys
from typing import List, Tuple

INFINITY_DISTANCE = float('inf')
INPUT_FILE = "input.txt"

class DijkstraResult:
    """Result class containing distances and parent information"""
    def __init__(self, distances: List[int], parents: List[int]):
        self.distances = distances
        self.parents = parents

def calculateShortestPaths(numberOfVertices: int, adjacencyList: List[List[Tuple[int, int]]], sourceVertex: int) -> DijkstraResult:
    """
    Applies Dijkstra's algorithm to find shortest paths from source vertex in multigraph
    
    Args:
        numberOfVertices: Number of vertices in the graph (0-indexed)
        adjacencyList: Adjacency list where adj[u] = list of tuples (v, w) for each edge u-v with weight w
        sourceVertex: Source vertex to start from
        
    Returns:
        DijkstraResult containing distances and parent information
    """
    distances = [INFINITY_DISTANCE] * numberOfVertices
    parents = [-1] * numberOfVertices
    priorityQueue = []
    distances[sourceVertex] = 0
    heapq.heappush(priorityQueue, (0, sourceVertex))
    
    while priorityQueue:
        currentDistance, currentVertex = heapq.heappop(priorityQueue)
        if currentDistance > distances[currentVertex]:
            continue
        
        for neighborVertex, edgeWeight in adjacencyList[currentVertex]:
            if distances[neighborVertex] > distances[currentVertex] + edgeWeight:
                distances[neighborVertex] = distances[currentVertex] + edgeWeight
                parents[neighborVertex] = currentVertex
                heapq.heappush(priorityQueue, (distances[neighborVertex], neighborVertex))
    
    return DijkstraResult(distances, parents)

def reconstructPath(parents: List[int], targetVertex: int, sourceVertex: int) -> str:
    """
    Reconstructs the shortest path from source to target vertex
    
    Args:
        parents: Parent array from Dijkstra algorithm
        targetVertex: Target vertex to find path to
        sourceVertex: Source vertex
        
    Returns:
        String representation of the path
    """
    if parents[targetVertex] == -1 and targetVertex != sourceVertex:
        return "No path"
    
    path = []
    currentVertex = targetVertex
    while currentVertex != -1:
        path.append(currentVertex)
        currentVertex = parents[currentVertex]
    
    path.reverse()
    return " -> ".join(map(str, path))

def isValidEdgeForMultigraph(firstVertex: int, secondVertex: int) -> bool:
    """
    Validates that edge is not a loop (not allowed in multigraph)
    
    Args:
        firstVertex: First vertex of the edge
        secondVertex: Second vertex of the edge
        
    Returns:
        True if edge is valid (not a loop)
    """
    return firstVertex != secondVertex

def readMultigraphInput() -> Tuple[List[List[Tuple[int, int]]], int, int, int]:
    """
    Reads graph input from file with loop validation for multigraph
    
    Returns:
        Tuple containing (adjacencyList, numberOfVertices, numberOfEdges, sourceVertex)
    """
    try:
        with open(INPUT_FILE, 'r') as inputFile:
            numberOfVertices, numberOfEdges = map(int, inputFile.readline().strip().split())
            adjacencyList = [[] for _ in range(numberOfVertices)]
            validEdges = 0
            
            for _ in range(numberOfEdges):
                firstVertex, secondVertex, weight = map(int, inputFile.readline().strip().split())
                if not isValidEdgeForMultigraph(firstVertex, secondVertex):
                    print(f"Warning: Loops are not allowed in multigraph. Skipping edge ({firstVertex}, {secondVertex}).")
                    continue
                
                adjacencyList[firstVertex].append((secondVertex, weight))
                adjacencyList[secondVertex].append((firstVertex, weight))
                validEdges += 1
            
            sourceVertex = int(inputFile.readline().strip())
            return adjacencyList, numberOfVertices, validEdges, sourceVertex
            
    except FileNotFoundError:
        print(f"Error: Cannot open file {INPUT_FILE}")
        sys.exit(1)
    except (ValueError, IndexError) as e:
        print(f"Error reading file: {e}")
        sys.exit(1)

def displayResults(result: DijkstraResult, sourceVertex: int) -> None:
    """
    Displays the shortest distances and paths in table format
    
    Args:
        result: DijkstraResult containing distances and parents
        sourceVertex: Source vertex index
    """
    print(f"Shortest paths from vertex {sourceVertex} (Multigraph - no loops, multiple edges allowed):")
    print("+" + "-" * 8 + "+" + "-" * 12 + "+" + "-" * 30 + "+")
    print("| Vertex | Distance   | Path                         |")
    print("+" + "-" * 8 + "+" + "-" * 12 + "+" + "-" * 30 + "+")
    
    for i in range(len(result.distances)):
        distanceStr = "INF" if result.distances[i] == INFINITY_DISTANCE else str(result.distances[i])
        pathStr = reconstructPath(result.parents, i, sourceVertex)
        
        if len(pathStr) > 28:
            pathStr = pathStr[:25] + "..."
        
        print(f"| {i:>6} | {distanceStr:>10} | {pathStr:<28} |")
    
    print("+" + "-" * 8 + "+" + "-" * 12 + "+" + "-" * 30 + "+")

def main() -> None:
    """Main function"""
    adjacencyList, numberOfVertices, numberOfEdges, sourceVertex = readMultigraphInput()
    result = calculateShortestPaths(numberOfVertices, adjacencyList, sourceVertex)
    displayResults(result, sourceVertex)

if __name__ == "__main__":
    main() 
#!/usr/bin/env python3
"""
Dijkstra's Algorithm for Simple Graphs
No self-loops and no multiple edges allowed
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
    Applies Dijkstra's algorithm to find shortest paths from source vertex in simple graph
    
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

def isValidEdgeForSimpleGraph(firstVertex: int, secondVertex: int) -> bool:
    """
    Validates that edge is valid for simple graph (no loops)
    
    Args:
        firstVertex: First vertex of the edge
        secondVertex: Second vertex of the edge
        
    Returns:
        True if edge is valid for simple graph
    """
    return firstVertex != secondVertex

def doesEdgeExist(adjacencyList: List[List[Tuple[int, int]]], firstVertex: int, secondVertex: int) -> bool:
    """
    Checks if edge already exists in adjacency list
    
    Args:
        adjacencyList: Current adjacency list
        firstVertex: First vertex of the edge
        secondVertex: Second vertex of the edge
        
    Returns:
        True if edge already exists
    """
    for neighborVertex, _ in adjacencyList[firstVertex]:
        if neighborVertex == secondVertex:
            return True
    return False

def readSimpleGraphInput() -> Tuple[List[List[Tuple[int, int]]], int, int, int]:
    """
    Reads graph input from file with validation for simple graph
    
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
                if not isValidEdgeForSimpleGraph(firstVertex, secondVertex):
                    print(f"Warning: Self-loops are not allowed in simple graph. Skipping edge ({firstVertex}, {secondVertex}).")
                    continue
                
                if (doesEdgeExist(adjacencyList, firstVertex, secondVertex) or 
                    doesEdgeExist(adjacencyList, secondVertex, firstVertex)):
                    print(f"Warning: Multiple edges are not allowed in simple graph. Skipping duplicate edge ({firstVertex}, {secondVertex}).")
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
    print(f"Shortest paths from vertex {sourceVertex} (Simple Graph - no loops, no multiple edges):")
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
    adjacencyList, numberOfVertices, numberOfEdges, sourceVertex = readSimpleGraphInput()
    result = calculateShortestPaths(numberOfVertices, adjacencyList, sourceVertex)
    displayResults(result, sourceVertex)

if __name__ == "__main__":
    main() 
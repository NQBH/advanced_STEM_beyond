/**
 * @file bfs_multigraph.cpp
 * @brief Breadth-First Search implementation for Multi Graph
 * @details Supports graphs with parallel edges but NO self-loops using adjacency list representation
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Represents a multi graph with BFS traversal capabilities
 */
class MultiGraph {
private:
    vector<vector<int>> adjacencyList;
    int numberOfVertices;
    vector<bool> visitedVertices;
    vector<int> traversalOrder;
    vector<int> distances;
    vector<int> parents;
    
    /**
     * @brief Resets visited status and other tracking arrays
     */
    void resetTraversalStatus() {
        fill(visitedVertices.begin(), visitedVertices.end(), false);
        traversalOrder.clear();
        fill(distances.begin(), distances.end(), -1);
        fill(parents.begin(), parents.end(), -1);
    }
    
    /**
     * @brief Validates that vertices are within valid range
     * @param vertex Vertex to validate
     * @return True if vertex is valid
     */
    bool isValidVertex(int vertex) const {
        return vertex >= 0 && vertex < numberOfVertices;
    }

public:
    /**
     * @brief Constructs a multi graph with specified number of vertices
     * @param vertexCount Number of vertices in the graph
     */
    explicit MultiGraph(int vertexCount) : numberOfVertices(vertexCount) {
        adjacencyList.resize(vertexCount);
        visitedVertices.resize(vertexCount, false);
        distances.resize(vertexCount, -1);
        parents.resize(vertexCount, -1);
    }
    
    /**
     * @brief Adds an edge to the multi graph with validation
     * @param sourceVertex Source vertex of the edge
     * @param targetVertex Target vertex of the edge
     * @return True if edge was added successfully
     */
    bool addEdge(int sourceVertex, int targetVertex) {
        if (!isValidVertex(sourceVertex) || !isValidVertex(targetVertex)) {
            cerr << "Warning: Invalid vertex index (" << sourceVertex 
                 << ", " << targetVertex << "). Vertices must be in range [0, " 
                 << numberOfVertices - 1 << "]\n";
            return false;
        }
        
        if (sourceVertex == targetVertex) {
            cerr << "Warning: Self-loop detected (" << sourceVertex 
                 << " -> " << targetVertex << "). Multi graphs do not support self-loops. Edge ignored.\n";
            return false;
        }
        
        // Multi graphs allow parallel edges but not self-loops
        adjacencyList[sourceVertex].push_back(targetVertex);
        adjacencyList[targetVertex].push_back(sourceVertex);
        return true;
    }
    
    /**
     * @brief Executes BFS traversal using queue-based approach
     * @param startVertex Starting vertex for traversal
     * @return Vector containing vertices in BFS order
     */
    vector<int> executeBFS(int startVertex) {
        if (!isValidVertex(startVertex)) {
            cerr << "Error: Invalid starting vertex " << startVertex << "\n";
            return vector<int>();
        }
        
        resetTraversalStatus();
        queue<int> bfsQueue;
        
        visitedVertices[startVertex] = true;
        distances[startVertex] = 0;
        bfsQueue.push(startVertex);
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            traversalOrder.push_back(currentVertex);
            
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visitedVertices[neighbor]) {
                    visitedVertices[neighbor] = true;
                    distances[neighbor] = distances[currentVertex] + 1;
                    parents[neighbor] = currentVertex;
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        return traversalOrder;
    }
    
    /**
     * @brief Finds all connected components using BFS
     * @return Vector of vectors, each containing vertices of a connected component
     */
    vector<vector<int>> findConnectedComponents() {
        vector<vector<int>> components;
        resetTraversalStatus();
        
        for (int vertex = 0; vertex < numberOfVertices; ++vertex) {
            if (!visitedVertices[vertex]) {
                vector<int> component = executeBFSComponent(vertex);
                if (!component.empty()) {
                    components.push_back(component);
                }
            }
        }
        
        return components;
    }
    
    /**
     * @brief Gets the shortest distance to a vertex from last BFS start
     * @param vertex Target vertex
     * @return Distance to vertex, or -1 if unreachable
     */
    int getDistance(int vertex) const {
        if (!isValidVertex(vertex)) {
            return -1;
        }
        return distances[vertex];
    }
    
    /**
     * @brief Gets the parent of a vertex in BFS tree from last traversal
     * @param vertex Target vertex
     * @return Parent vertex, or -1 if no parent
     */
    int getParent(int vertex) const {
        if (!isValidVertex(vertex)) {
            return -1;
        }
        return parents[vertex];
    }
    
    /**
     * @brief Gets the shortest path from last BFS start to target vertex
     * @param targetVertex Target vertex
     * @return Vector containing path vertices, empty if no path exists
     */
    vector<int> getShortestPath(int targetVertex) const {
        if (!isValidVertex(targetVertex) || distances[targetVertex] == -1) {
            return vector<int>();
        }
        
        vector<int> path;
        int current = targetVertex;
        
        while (current != -1) {
            path.push_back(current);
            current = parents[current];
        }
        
        reverse(path.begin(), path.end());
        return path;
    }
    
    /**
     * @brief Gets the number of vertices in the graph
     * @return Number of vertices
     */
    int getVertexCount() const {
        return numberOfVertices;
    }
    
    /**
     * @brief Counts total number of edges including parallel edges
     * @return Total edge count
     */
    int getTotalEdgeCount() const {
        int totalEdges = 0;
        for (const auto& neighbors : adjacencyList) {
            totalEdges += static_cast<int>(neighbors.size());
        }
        return totalEdges / 2; // Each undirected edge counted twice (no self-loops in multi graph)
    }
    
    /**
     * @brief Displays the adjacency list representation with parallel edge indication
     */
    void displayGraph() const {
        cout << "\nMulti Graph - Adjacency List Representation:\n";
        cout << "Parallel edges allowed, NO self-loops\n";
        
        for (int vertex = 0; vertex < numberOfVertices; ++vertex) {
            cout << "Vertex " << vertex << ": ";
            if (!adjacencyList[vertex].empty()) {
                for (size_t i = 0; i < adjacencyList[vertex].size(); ++i) {
                    if (i > 0) cout << " -> ";
                    cout << adjacencyList[vertex][i];
                }
            }
            cout << "\n";
        }
        
        cout << "Total vertices: " << numberOfVertices << "\n";
        cout << "Total edges: " << getTotalEdgeCount() << "\n";
    }
    
    /**
     * @brief Displays parallel edge statistics
     */
    void displayParallelEdgeStatistics() const {
        map<pair<int, int>, int> edgeCount;
        
        for (int vertex = 0; vertex < numberOfVertices; ++vertex) {
            for (int neighbor : adjacencyList[vertex]) {
                if (vertex < neighbor) { // Count each edge only once
                    pair<int, int> edge = {vertex, neighbor};
                    edgeCount[edge]++;
                }
            }
        }
        
        cout << "\nParallel Edge Analysis:\n";
        bool hasParallelEdges = false;
        
        for (const auto& edgePair : edgeCount) {
            if (edgePair.second > 1) {
                hasParallelEdges = true;
                cout << "Edge (" << edgePair.first.first << ", " 
                     << edgePair.first.second << ") appears " 
                     << edgePair.second << " times\n";
            }
        }
        
        if (!hasParallelEdges) {
            cout << "No parallel edges detected in this multi graph.\n";
        }
    }
    
    /**
     * @brief Displays BFS tree information
     * @param startVertex Starting vertex of last BFS
     */
    void displayBFSTree(int startVertex) const {
        cout << "\nBFS Tree Information (from vertex " << startVertex << "):\n";
        cout << "Vertex | Distance | Parent\n";
        cout << "-------|----------|-------\n";
        
        for (int vertex = 0; vertex < numberOfVertices; ++vertex) {
            cout << setw(6) << vertex << " | ";
            if (distances[vertex] == -1) {
                cout << setw(8) << "INF" << " | ";
                cout << "N/A";
            } else {
                cout << setw(8) << distances[vertex] << " | ";
                if (parents[vertex] == -1) {
                    cout << "NIL";
                } else {
                    cout << parents[vertex];
                }
            }
            cout << "\n";
        }
    }

private:
    /**
     * @brief Helper function for finding connected components
     * @param startVertex Starting vertex for component search
     * @return Vector containing vertices in the component
     */
    vector<int> executeBFSComponent(int startVertex) {
        vector<int> component;
        queue<int> bfsQueue;
        
        visitedVertices[startVertex] = true;
        bfsQueue.push(startVertex);
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            component.push_back(currentVertex);
            
            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visitedVertices[neighbor]) {
                    visitedVertices[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        return component;
    }
};

/**
 * @brief Handles input operations for multi graph construction
 */
class MultiGraphInputHandler {
private:
    istream& inputStream;
    
public:
    /**
     * @brief Constructs input handler with specified stream
     * @param stream Input stream to read from
     */
    explicit MultiGraphInputHandler(istream& stream) : inputStream(stream) {}
    
    /**
     * @brief Reads graph data and constructs MultiGraph
     * @return Constructed MultiGraph instance
     */
    unique_ptr<MultiGraph> readGraphData() {
        int vertexCount, edgeCount;
        inputStream >> vertexCount >> edgeCount;
        
        auto graph = make_unique<MultiGraph>(vertexCount);
        int successfulEdges = 0;
        
        for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex) {
            int sourceVertex, targetVertex;
            inputStream >> sourceVertex >> targetVertex;
            if (graph->addEdge(sourceVertex, targetVertex)) {
                successfulEdges++;
            }
        }
        
        cout << "Successfully added " << successfulEdges 
             << " out of " << edgeCount << " edges to multi graph.\n";
        
        return graph;
    }
    
    /**
     * @brief Reads starting vertex for BFS traversal
     * @return Starting vertex index
     */
    int readStartingVertex() {
        int startVertex;
        inputStream >> startVertex;
        return startVertex;
    }
};

/**
 * @brief Handles output operations for BFS results
 */
class MultiGraphOutputHandler {
private:
    ostream& outputStream;
    
public:
    /**
     * @brief Constructs output handler with specified stream
     * @param stream Output stream to write to
     */
    explicit MultiGraphOutputHandler(ostream& stream) : outputStream(stream) {}
    
    /**
     * @brief Displays BFS traversal results
     * @param traversalResult Vector containing vertices in BFS order
     * @param startVertex Starting vertex
     */
    void displayTraversalResult(const vector<int>& traversalResult, int startVertex) {
        if (traversalResult.empty()) {
            outputStream << "BFS traversal: No traversal performed (invalid input)\n";
            return;
        }
        
        outputStream << "BFS traversal from vertex " << startVertex << ": ";
        for (size_t i = 0; i < traversalResult.size(); ++i) {
            if (i > 0) outputStream << " -> ";
            outputStream << traversalResult[i];
        }
        outputStream << "\n";
    }
    
    /**
     * @brief Displays connected components
     * @param components Vector of connected components
     */
    void displayConnectedComponents(const vector<vector<int>>& components) {
        outputStream << "\nConnected Components Analysis:\n";
        for (size_t i = 0; i < components.size(); ++i) {
            outputStream << "Component " << (i + 1) << ": ";
            for (size_t j = 0; j < components[i].size(); ++j) {
                if (j > 0) outputStream << " ";
                outputStream << components[i][j];
            }
            outputStream << "\n";
        }
        outputStream << "Total connected components: " << components.size() << "\n";
    }
    
    /**
     * @brief Displays shortest path information
     * @param graph Reference to the graph
     * @param startVertex Starting vertex
     * @param targetVertex Target vertex
     */
    void displayShortestPath(const MultiGraph& graph, int startVertex, int targetVertex) {
        vector<int> path = graph.getShortestPath(targetVertex);
        
        if (path.empty()) {
            outputStream << "No path exists from vertex " << startVertex 
                        << " to vertex " << targetVertex << "\n";
        } else {
            outputStream << "Shortest path from " << startVertex 
                        << " to " << targetVertex << ": ";
            for (size_t i = 0; i < path.size(); ++i) {
                if (i > 0) outputStream << " -> ";
                outputStream << path[i];
            }
            outputStream << " (distance: " << graph.getDistance(targetVertex) << ")\n";
        }
    }
    
    /**
     * @brief Displays program header information
     */
    void displayProgramHeader() {
        outputStream << "=== Breadth-First Search for Multi Graph ===\n";
        outputStream << "Supporting parallel edges, NO self-loops\n";
    }
};

/**
 * @brief Coordinates the Multi Graph BFS application workflow
 */
class MultiGraphBFSApplication {
private:
    unique_ptr<MultiGraph> graphInstance;
    unique_ptr<MultiGraphInputHandler> inputHandler;
    unique_ptr<MultiGraphOutputHandler> outputHandler;
    
public:
    /**
     * @brief Constructs BFS application with I/O streams
     * @param input Input stream for reading data
     * @param output Output stream for displaying results
     */
    MultiGraphBFSApplication(istream& input, ostream& output) {
        inputHandler = make_unique<MultiGraphInputHandler>(input);
        outputHandler = make_unique<MultiGraphOutputHandler>(output);
    }
    
    /**
     * @brief Executes the complete Multi Graph BFS application workflow
     */
    void executeApplication() {
        outputHandler->displayProgramHeader();
        graphInstance = inputHandler->readGraphData();
        int startingVertex = inputHandler->readStartingVertex();
        performBFSAnalysis(startingVertex);
    }

private:
    /**
     * @brief Performs comprehensive BFS analysis
     * @param startVertex Starting vertex for analysis
     */
    void performBFSAnalysis(int startVertex) {
        // Display graph structure
        graphInstance->displayGraph();
        graphInstance->displayParallelEdgeStatistics();
        
        // Perform BFS traversal
        vector<int> bfsResult = graphInstance->executeBFS(startVertex);
        outputHandler->displayTraversalResult(bfsResult, startVertex);
        
        // Display BFS tree information
        graphInstance->displayBFSTree(startVertex);
        
        // Find and display connected components
        vector<vector<int>> components = graphInstance->findConnectedComponents();
        outputHandler->displayConnectedComponents(components);
        
        // Display shortest path examples to all reachable vertices
        cout << "\nShortest Paths from vertex " << startVertex << ":\n";
        for (int target = 0; target < graphInstance->getVertexCount(); ++target) {
            if (target != startVertex && graphInstance->getDistance(target) != -1) {
                outputHandler->displayShortestPath(*graphInstance, startVertex, target);
            }
        }
    }
};

/**
 * @brief Main program entry point
 * @return Program exit status
 */
int main() {
    try {
        ifstream inputFile("input.txt");
        if (!inputFile.is_open()) {
            cerr << "Error: Cannot open input.txt file\n";
            return 1;
        }
        
        MultiGraphBFSApplication application(inputFile, cout);
        application.executeApplication();
        
        inputFile.close();
    } catch (const exception& error) {
        cerr << "Error occurred: " << error.what() << "\n";
        return 1;
    }
    return 0;
} 
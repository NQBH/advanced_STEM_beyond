/**
 * @file dfs_multigraph.cpp
 * @brief Depth-First Search implementation for Multi Graph
 * @details Supports graphs with parallel edges but NO self-loops using adjacency list representation
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Represents a multi graph with DFS traversal capabilities
 */
class MultiGraph {
private:
    vector<vector<int>> adjacencyList;
    int numberOfVertices;
    vector<bool> visitedVertices;
    vector<int> traversalOrder;
    
    /**
     * @brief Performs recursive DFS from given vertex
     * @param currentVertex Starting vertex for DFS
     */
    void performRecursiveDFS(int currentVertex) {
        visitedVertices[currentVertex] = true;
        traversalOrder.push_back(currentVertex);
        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visitedVertices[neighbor]) {
                performRecursiveDFS(neighbor);
            }
        }
    }
    
    /**
     * @brief Resets visited status for all vertices
     */
    void resetVisitedStatus() {
        fill(visitedVertices.begin(), visitedVertices.end(), false);
        traversalOrder.clear();
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
        
        adjacencyList[sourceVertex].push_back(targetVertex);
        adjacencyList[targetVertex].push_back(sourceVertex);
        return true;
    }
    
    /**
     * @brief Executes DFS traversal using recursive approach
     * @param startVertex Starting vertex for traversal
     * @return Vector containing vertices in DFS order
     */
    vector<int> executeRecursiveDFS(int startVertex) {
        if (!isValidVertex(startVertex)) {
            cerr << "Error: Invalid starting vertex " << startVertex << "\n";
            return vector<int>();
        }
        resetVisitedStatus();
        performRecursiveDFS(startVertex);
        return traversalOrder;
    }
    
    /**
     * @brief Executes DFS traversal using iterative approach with stack
     * @param startVertex Starting vertex for traversal
     * @return Vector containing vertices in DFS order
     */
    vector<int> executeIterativeDFS(int startVertex) {
        if (!isValidVertex(startVertex)) {
            cerr << "Error: Invalid starting vertex " << startVertex << "\n";
            return vector<int>();
        }
        
        resetVisitedStatus();
        stack<int> dfsStack;
        dfsStack.push(startVertex);
        
        while (!dfsStack.empty()) {
            int currentVertex = dfsStack.top();
            dfsStack.pop();
            if (!visitedVertices[currentVertex]) {
                visitedVertices[currentVertex] = true;
                traversalOrder.push_back(currentVertex);
                for (int i = static_cast<int>(adjacencyList[currentVertex].size()) - 1; i >= 0; --i) {
                    int neighbor = adjacencyList[currentVertex][i];
                    if (!visitedVertices[neighbor]) {
                        dfsStack.push(neighbor);
                    }
                }
            }
        }
        return traversalOrder;
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
        return totalEdges / 2; // Each undirected edge counted twice
    }
    
    /**
     * @brief Displays the adjacency list representation with parallel edge indication
     */
    void displayGraph() const {
        cout << "\nMulti Graph - Adjacency List Representation:\n";
        cout << "Parallel edges are shown as repeated connections\n";
        
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
        cout << "Total edges (including parallel): " << getTotalEdgeCount() << "\n";
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
             << " out of " << edgeCount << " edges.\n";
        
        return graph;
    }
    
    /**
     * @brief Reads starting vertex for DFS traversal
     * @return Starting vertex index
     */
    int readStartingVertex() {
        int startVertex;
        inputStream >> startVertex;
        return startVertex;
    }
};

/**
 * @brief Handles output operations for DFS results
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
     * @brief Displays DFS traversal results
     * @param traversalResult Vector containing vertices in DFS order
     * @param traversalType Description of traversal method
     */
    void displayTraversalResult(const vector<int>& traversalResult, const string& traversalType) {
        if (traversalResult.empty()) {
            outputStream << "DFS " << traversalType << ": No traversal performed (invalid input)\n";
            return;
        }
        
        outputStream << "DFS " << traversalType << ": ";
        for (size_t i = 0; i < traversalResult.size(); ++i) {
            if (i > 0) outputStream << " ";
            outputStream << traversalResult[i];
        }
        outputStream << "\n";
    }
    
    /**
     * @brief Displays program header information
     */
    void displayProgramHeader() {
        outputStream << "=== Depth-First Search for Multi Graph ===\n";
        outputStream << "Supporting parallel edges, NO self-loops\n";
    }
};

/**
 * @brief Coordinates the Multi Graph DFS application workflow
 */
class MultiGraphDFSApplication {
private:
    unique_ptr<MultiGraph> graphInstance;
    unique_ptr<MultiGraphInputHandler> inputHandler;
    unique_ptr<MultiGraphOutputHandler> outputHandler;
    
public:
    /**
     * @brief Constructs DFS application with I/O streams
     * @param input Input stream for reading data
     * @param output Output stream for displaying results
     */
    MultiGraphDFSApplication(istream& input, ostream& output) {
        inputHandler = make_unique<MultiGraphInputHandler>(input);
        outputHandler = make_unique<MultiGraphOutputHandler>(output);
    }
    
    /**
     * @brief Executes the complete Multi Graph DFS application workflow
     */
    void executeApplication() {
        outputHandler->displayProgramHeader();
        graphInstance = inputHandler->readGraphData();
        int startingVertex = inputHandler->readStartingVertex();
        performDFSAnalysis(startingVertex);
    }

private:
    /**
     * @brief Performs DFS analysis using both recursive and iterative methods
     * @param startVertex Starting vertex for analysis
     */
    void performDFSAnalysis(int startVertex) {
        graphInstance->displayGraph();
        graphInstance->displayParallelEdgeStatistics();
        
        vector<int> recursiveResult = graphInstance->executeRecursiveDFS(startVertex);
        outputHandler->displayTraversalResult(recursiveResult, "using recursion");
        
        vector<int> iterativeResult = graphInstance->executeIterativeDFS(startVertex);
        outputHandler->displayTraversalResult(iterativeResult, "using iteration");
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
        
        MultiGraphDFSApplication application(inputFile, cout);
        application.executeApplication();
        
        inputFile.close();
    } catch (const exception& error) {
        cerr << "Error occurred: " << error.what() << "\n";
        return 1;
    }
    return 0;
}

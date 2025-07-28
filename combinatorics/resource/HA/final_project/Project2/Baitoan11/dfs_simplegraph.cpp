/**
 * @file dfs_simplegraph.cpp
 * @brief Depth-First Search implementation for Simple Graph
 * @details Supports graphs with NO self-loops and NO parallel edges using adjacency list representation
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Represents a simple graph with DFS traversal capabilities
 */
class SimpleGraph {
private:
    vector<vector<int>> adjacencyList;
    int numberOfVertices;
    vector<bool> visitedVertices;
    vector<int> traversalOrder;
    set<pair<int, int>> existingEdges; // Track edges to prevent duplicates
    
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
    
    /**
     * @brief Checks if edge already exists in the simple graph
     * @param sourceVertex Source vertex
     * @param targetVertex Target vertex
     * @return True if edge already exists
     */
    bool edgeExists(int sourceVertex, int targetVertex) const {
        pair<int, int> edge = {min(sourceVertex, targetVertex), max(sourceVertex, targetVertex)};
        return existingEdges.find(edge) != existingEdges.end();
    }

public:
    /**
     * @brief Constructs a simple graph with specified number of vertices
     * @param vertexCount Number of vertices in the graph
     */
    explicit SimpleGraph(int vertexCount) : numberOfVertices(vertexCount) {
        adjacencyList.resize(vertexCount);
        visitedVertices.resize(vertexCount, false);
    }
    
    /**
     * @brief Adds an edge to the simple graph with validation
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
                 << " -> " << targetVertex << "). Simple graphs do not support self-loops. Edge ignored.\n";
            return false;
        }
        
        if (edgeExists(sourceVertex, targetVertex)) {
            cerr << "Warning: Parallel edge detected (" << sourceVertex 
                 << " <-> " << targetVertex << "). Simple graphs do not support parallel edges. Edge ignored.\n";
            return false;
        }
        
        // Add edge to adjacency list
        adjacencyList[sourceVertex].push_back(targetVertex);
        adjacencyList[targetVertex].push_back(sourceVertex);
        
        // Record edge in set to prevent duplicates
        pair<int, int> edge = {min(sourceVertex, targetVertex), max(sourceVertex, targetVertex)};
        existingEdges.insert(edge);
        
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
     * @brief Gets the number of edges in the simple graph
     * @return Number of edges
     */
    int getEdgeCount() const {
        return static_cast<int>(existingEdges.size());
    }
    
    /**
     * @brief Displays the adjacency list representation
     */
    void displayGraph() const {
        cout << "\nSimple Graph - Adjacency List Representation:\n";
        cout << "No self-loops, no parallel edges\n";
        
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
        cout << "Total edges: " << getEdgeCount() << "\n";
    }
    
    /**
     * @brief Displays simple graph validation statistics
     */
    void displayGraphValidation() const {
        cout << "\nSimple Graph Validation:\n";
        cout << "* No self-loops allowed\n";
        cout << "* No parallel edges allowed\n";
        cout << "* Maximum possible edges: " << (numberOfVertices * (numberOfVertices - 1)) / 2 << "\n";
        cout << "* Current edges: " << getEdgeCount() << "\n";
        
        if (getEdgeCount() == (numberOfVertices * (numberOfVertices - 1)) / 2) {
            cout << "* This is a complete simple graph!\n";
        }
    }
};

/**
 * @brief Handles input operations for simple graph construction
 */
class SimpleGraphInputHandler {
private:
    istream& inputStream;
    
public:
    /**
     * @brief Constructs input handler with specified stream
     * @param stream Input stream to read from
     */
    explicit SimpleGraphInputHandler(istream& stream) : inputStream(stream) {}
    
    /**
     * @brief Reads graph data and constructs SimpleGraph
     * @return Constructed SimpleGraph instance
     */
    unique_ptr<SimpleGraph> readGraphData() {
        int vertexCount, edgeCount;
        inputStream >> vertexCount >> edgeCount;
        
        auto graph = make_unique<SimpleGraph>(vertexCount);
        int successfulEdges = 0;
        
        for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex) {
            int sourceVertex, targetVertex;
            inputStream >> sourceVertex >> targetVertex;
            if (graph->addEdge(sourceVertex, targetVertex)) {
                successfulEdges++;
            }
        }
        
        cout << "Successfully added " << successfulEdges 
             << " out of " << edgeCount << " edges to simple graph.\n";
        
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
class SimpleGraphOutputHandler {
private:
    ostream& outputStream;
    
public:
    /**
     * @brief Constructs output handler with specified stream
     * @param stream Output stream to write to
     */
    explicit SimpleGraphOutputHandler(ostream& stream) : outputStream(stream) {}
    
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
        outputStream << "=== Depth-First Search for Simple Graph ===\n";
        outputStream << "NO self-loops, NO parallel edges\n";
    }
};

/**
 * @brief Coordinates the Simple Graph DFS application workflow
 */
class SimpleGraphDFSApplication {
private:
    unique_ptr<SimpleGraph> graphInstance;
    unique_ptr<SimpleGraphInputHandler> inputHandler;
    unique_ptr<SimpleGraphOutputHandler> outputHandler;
    
public:
    /**
     * @brief Constructs DFS application with I/O streams
     * @param input Input stream for reading data
     * @param output Output stream for displaying results
     */
    SimpleGraphDFSApplication(istream& input, ostream& output) {
        inputHandler = make_unique<SimpleGraphInputHandler>(input);
        outputHandler = make_unique<SimpleGraphOutputHandler>(output);
    }
    
    /**
     * @brief Executes the complete Simple Graph DFS application workflow
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
        graphInstance->displayGraphValidation();
        
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
        
        SimpleGraphDFSApplication application(inputFile, cout);
        application.executeApplication();
        
        inputFile.close();
    } catch (const exception& error) {
        cerr << "Error occurred: " << error.what() << "\n";
        return 1;
    }
    return 0;
} 
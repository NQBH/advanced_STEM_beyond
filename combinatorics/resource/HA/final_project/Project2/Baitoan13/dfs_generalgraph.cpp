/**
 * @file dfs_generalgraph.cpp
 * @brief Depth-First Search implementation for General Graph
 * @details Supports graphs with self-loops and parallel edges using adjacency list representation

 */

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Represents a general graph with DFS traversal capabilities
 */
class GeneralGraph {
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

public:
    /**
     * @brief Constructs a general graph with specified number of vertices
     * @param vertexCount Number of vertices in the graph
     */
    explicit GeneralGraph(int vertexCount) : numberOfVertices(vertexCount) {
        adjacencyList.resize(vertexCount);
        visitedVertices.resize(vertexCount, false);
    }
    
    /**
     * @brief Adds an edge to the graph
     * @param sourceVertex Source vertex of the edge
     * @param targetVertex Target vertex of the edge
     */
    void addEdge(int sourceVertex, int targetVertex) {
        adjacencyList[sourceVertex].push_back(targetVertex);
        adjacencyList[targetVertex].push_back(sourceVertex);
    }
    
    /**
     * @brief Executes DFS traversal using recursive approach
     * @param startVertex Starting vertex for traversal
     * @return Vector containing vertices in DFS order
     */
    vector<int> executeRecursiveDFS(int startVertex) {
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
     * @brief Displays the adjacency list representation
     */
    void displayGraph() const {
        cout << "\nAdjacency List Representation:\n";
        for (int vertex = 0; vertex < numberOfVertices; ++vertex) {
            cout << "Vertex " << vertex << ": ";
            for (size_t i = 0; i < adjacencyList[vertex].size(); ++i) {
                if (i > 0) cout << " -> ";
                cout << adjacencyList[vertex][i];
            }
            cout << "\n";
        }
    }
};

/**
 * @brief Handles input operations for graph construction
 */
class GraphInputHandler {
private:
    istream& inputStream;
    
public:
    /**
     * @brief Constructs input handler with specified stream
     * @param stream Input stream to read from
     */
    explicit GraphInputHandler(istream& stream) : inputStream(stream) {}
    
    /**
     * @brief Reads graph data and constructs GeneralGraph
     * @return Constructed GeneralGraph instance
     */
    unique_ptr<GeneralGraph> readGraphData() {
        int vertexCount, edgeCount;
        inputStream >> vertexCount >> edgeCount;
        auto graph = make_unique<GeneralGraph>(vertexCount);
        for (int edgeIndex = 0; edgeIndex < edgeCount; ++edgeIndex) {
            int sourceVertex, targetVertex;
            inputStream >> sourceVertex >> targetVertex;
            graph->addEdge(sourceVertex, targetVertex);
        }
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
class DFSOutputHandler {
private:
    ostream& outputStream;
    
public:
    /**
     * @brief Constructs output handler with specified stream
     * @param stream Output stream to write to
     */
    explicit DFSOutputHandler(ostream& stream) : outputStream(stream) {}
    
    /**
     * @brief Displays DFS traversal results
     * @param traversalResult Vector containing vertices in DFS order
     * @param traversalType Description of traversal method
     */
    void displayTraversalResult(const vector<int>& traversalResult, const string& traversalType) {
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
        outputStream << "=== Depth-First Search for General Graph ===\n";
        outputStream << "Supporting self-loops and parallel edges\n";
    }
};

/**
 * @brief Coordinates the DFS application workflow
 */
class DFSApplication {
private:
    unique_ptr<GeneralGraph> graphInstance;
    unique_ptr<GraphInputHandler> inputHandler;
    unique_ptr<DFSOutputHandler> outputHandler;
    
public:
    /**
     * @brief Constructs DFS application with I/O streams
     * @param input Input stream for reading data
     * @param output Output stream for displaying results
     */
    DFSApplication(istream& input, ostream& output) {
        inputHandler = make_unique<GraphInputHandler>(input);
        outputHandler = make_unique<DFSOutputHandler>(output);
    }
    
    /**
     * @brief Executes the complete DFS application workflow
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
        
        DFSApplication application(inputFile, cout);
        application.executeApplication();
        
        inputFile.close();
    } catch (const exception& error) {
        cerr << "Error occurred: " << error.what() << "\n";
        return 1;
    }
    return 0;
}

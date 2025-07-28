#include <bits/stdc++.h>

using namespace std;

using DistanceVertexPair = pair<int, int>; // (distance, vertex)

const int INFINITY_DISTANCE = numeric_limits<int>::max();
const string INPUT_FILE = "input.txt";

struct DijkstraResult {
    vector<int> distances;
    vector<int> parents;
};

/**
 * @brief Applies Dijkstra's algorithm to find shortest paths from source vertex in simple graph
 * @param numberOfVertices Number of vertices in the graph (0-indexed)
 * @param adjacencyList Adjacency list where adj[u] = vector of pairs (v, w) for each edge u-v with weight w
 * @param sourceVertex Source vertex to start from
 * @return DijkstraResult containing distances and parent information
 */
DijkstraResult calculateShortestPaths(int numberOfVertices, const vector<vector<DistanceVertexPair>>& adjacencyList, int sourceVertex) {
    vector<int> distances(numberOfVertices, INFINITY_DISTANCE);
    vector<int> parents(numberOfVertices, -1);
    priority_queue<DistanceVertexPair, vector<DistanceVertexPair>, greater<DistanceVertexPair>> priorityQueue;
    distances[sourceVertex] = 0;
    priorityQueue.push({0, sourceVertex});
    while (!priorityQueue.empty()) {
        int currentDistance = priorityQueue.top().first;
        int currentVertex = priorityQueue.top().second;
        priorityQueue.pop();
        if (currentDistance > distances[currentVertex]) continue;
        for (const auto& edge : adjacencyList[currentVertex]) {
            int neighborVertex = edge.first;
            int edgeWeight = edge.second;
            if (distances[neighborVertex] > distances[currentVertex] + edgeWeight) {
                distances[neighborVertex] = distances[currentVertex] + edgeWeight;
                parents[neighborVertex] = currentVertex;
                priorityQueue.push({distances[neighborVertex], neighborVertex});
            }
        }
    }
    return {distances, parents};
}

/**
 * @brief Reconstructs the shortest path from source to target vertex
 * @param parents Parent array from Dijkstra algorithm
 * @param targetVertex Target vertex to find path to
 * @param sourceVertex Source vertex
 * @return String representation of the path
 */
string reconstructPath(const vector<int>& parents, int targetVertex, int sourceVertex) {
    if (parents[targetVertex] == -1 && targetVertex != sourceVertex) {
        return "No path";
    }
    vector<int> path;
    int currentVertex = targetVertex;
    while (currentVertex != -1) {
        path.push_back(currentVertex);
        currentVertex = parents[currentVertex];
    }
    reverse(path.begin(), path.end());
    string pathString = "";
    for (int i = 0; i < path.size(); ++i) {
        if (i > 0) pathString += " -> ";
        pathString += to_string(path[i]);
    }
    return pathString;
}

/**
 * @brief Validates that edge is valid for simple graph (no loops, no multiple edges)
 * @param firstVertex First vertex of the edge
 * @param secondVertex Second vertex of the edge
 * @return True if edge is valid for simple graph
 */
bool isValidEdgeForSimpleGraph(int firstVertex, int secondVertex) {
    return firstVertex != secondVertex;
}

/**
 * @brief Checks if edge already exists in adjacency list
 * @param adjacencyList Current adjacency list
 * @param firstVertex First vertex of the edge
 * @param secondVertex Second vertex of the edge
 * @return True if edge already exists
 */
bool doesEdgeExist(const vector<vector<DistanceVertexPair>>& adjacencyList, int firstVertex, int secondVertex) {
    for (const auto& edge : adjacencyList[firstVertex]) {
        if (edge.first == secondVertex) {
            return true;
        }
    }
    return false;
}

/**
 * @brief Reads graph input from file with validation for simple graph
 * @param inputFile Input file stream
 * @param numberOfVertices Reference to store number of vertices
 * @param numberOfEdges Reference to store number of edges
 * @return Adjacency list representation of the simple graph
 */
vector<vector<DistanceVertexPair>> readSimpleGraphInput(ifstream& inputFile, int& numberOfVertices, int& numberOfEdges) {
    inputFile >> numberOfVertices >> numberOfEdges;
    vector<vector<DistanceVertexPair>> adjacencyList(numberOfVertices);
    int validEdges = 0;
    for (int i = 0; i < numberOfEdges; ++i) {
        int firstVertex, secondVertex, weight;
        inputFile >> firstVertex >> secondVertex >> weight;
        if (!isValidEdgeForSimpleGraph(firstVertex, secondVertex)) {
            cout << "Warning: Self-loops are not allowed in simple graph. Skipping edge (" 
                 << firstVertex << ", " << secondVertex << ").\n";
            continue;
        }
        if (doesEdgeExist(adjacencyList, firstVertex, secondVertex) || 
            doesEdgeExist(adjacencyList, secondVertex, firstVertex)) {
            cout << "Warning: Multiple edges are not allowed in simple graph. Skipping duplicate edge (" 
                 << firstVertex << ", " << secondVertex << ").\n";
            continue;
        }
        adjacencyList[firstVertex].push_back({secondVertex, weight});
        adjacencyList[secondVertex].push_back({firstVertex, weight});
        validEdges++;
    }
    numberOfEdges = validEdges;
    return adjacencyList;
}

/**
 * @brief Reads source vertex from file
 * @param inputFile Input file stream
 * @return Source vertex index
 */
int readSourceVertex(ifstream& inputFile) {
    int sourceVertex;
    inputFile >> sourceVertex;
    return sourceVertex;
}

/**
 * @brief Displays the shortest distances and paths in table format
 * @param result DijkstraResult containing distances and parents
 * @param sourceVertex Source vertex index
 */
void displayResults(const DijkstraResult& result, int sourceVertex) {
    cout << "Shortest paths from vertex " << sourceVertex << " (Simple Graph - no loops, no multiple edges):\n";
    cout << "+" << string(8, '-') << "+" << string(12, '-') << "+" << string(30, '-') << "+\n";
    cout << "| Vertex | Distance   | Path                         |\n";
    cout << "+" << string(8, '-') << "+" << string(12, '-') << "+" << string(30, '-') << "+\n";
    for (int i = 0; i < result.distances.size(); ++i) {
        string distanceStr = (result.distances[i] == INFINITY_DISTANCE) ? "INF" : to_string(result.distances[i]);
        string pathStr = reconstructPath(result.parents, i, sourceVertex);
        if (pathStr.length() > 28) {
            pathStr = pathStr.substr(0, 25) + "...";
        }
        cout << "| " << setw(6) << i << " | " << setw(10) << distanceStr << " | " << setw(28) << left << pathStr << " |\n";
    }
    cout << "+" << string(8, '-') << "+" << string(12, '-') << "+" << string(30, '-') << "+\n";
}

/**
 * @brief Opens input file and handles errors
 * @return Input file stream
 */
ifstream openInputFile() {
    ifstream inputFile(INPUT_FILE);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open file " << INPUT_FILE << endl;
        exit(1);
    }
    return inputFile;
}

int main() {
    ifstream inputFile = openInputFile();
    int numberOfVertices, numberOfEdges;
    vector<vector<DistanceVertexPair>> adjacencyList = readSimpleGraphInput(inputFile, numberOfVertices, numberOfEdges);
    int sourceVertex = readSourceVertex(inputFile);
    inputFile.close();
    DijkstraResult result = calculateShortestPaths(numberOfVertices, adjacencyList, sourceVertex);
    displayResults(result, sourceVertex);
    return 0;
} 
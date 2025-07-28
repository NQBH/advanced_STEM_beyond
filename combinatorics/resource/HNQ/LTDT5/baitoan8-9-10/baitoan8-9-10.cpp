#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// =================================
// SIMPLE GRAPH (Bài toán 8)
// =================================

class SimpleGraph {
private:
    int vertices;
    vector<vector<int>> adjList;
    
public:
    SimpleGraph(int v) : vertices(v), adjList(v) {}
    
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices && u != v) {
            // Kiểm tra không có cạnh trùng lặp
            if (find(adjList[u].begin(), adjList[u].end(), v) == adjList[u].end()) {
                adjList[u].push_back(v);
                adjList[v].push_back(u); // Đồ thị vô hướng
            }
        }
    }
    
    vector<int> BFS(int startVertex) {
        cout << "=== BFS trên Simple Graph ===" << endl;
        cout << "Đặc điểm: Không có self-loops, không có multiple edges" << endl;
        
        auto start = high_resolution_clock::now();
        
        vector<int> result;
        vector<bool> visited(vertices, false);
        queue<int> bfsQueue;
        
        if (startVertex < 0 || startVertex >= vertices) {
            cout << "Đỉnh bắt đầu không hợp lệ!" << endl;
            return result;
        }
        
        bfsQueue.push(startVertex);
        visited[startVertex] = true;
        
        cout << "Bắt đầu BFS từ đỉnh " << startVertex << endl;
        cout << "Thứ tự duyệt: ";
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            result.push_back(currentVertex);
            cout << currentVertex << " ";
            
            // Duyệt tất cả đỉnh kề
            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Số đỉnh đã thăm: " << result.size() << "/" << vertices << endl;
        
        return result;
    }
    
    void displayGraph() {
        cout << "Simple Graph - Adjacency List:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    vector<int> getDistances(int startVertex) {
        vector<int> distances(vertices, -1);
        vector<bool> visited(vertices, false);
        queue<int> bfsQueue;
        
        bfsQueue.push(startVertex);
        visited[startVertex] = true;
        distances[startVertex] = 0;
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            
            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    distances[neighbor] = distances[currentVertex] + 1;
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        return distances;
    }
};

// =================================
// MULTIGRAPH (Bài toán 9)
// =================================

class MultiGraph {
private:
    int vertices;
    vector<vector<pair<int, int>>> adjList; // pair<neighbor, edgeId>
    int edgeCounter;
    
public:
    MultiGraph(int v) : vertices(v), adjList(v), edgeCounter(0) {}
    
    void addEdge(int u, int v) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            edgeCounter++;
            adjList[u].push_back({v, edgeCounter});
            if (u != v) { // Không tự động thêm cho self-loop
                adjList[v].push_back({u, edgeCounter});
            }
        }
    }
    
    vector<int> BFS(int startVertex) {
        cout << "\n=== BFS trên MultiGraph ===" << endl;
        cout << "Đặc điểm: Có thể có multiple edges, self-loops" << endl;
        
        auto start = high_resolution_clock::now();
        
        vector<int> result;
        vector<bool> visited(vertices, false);
        queue<int> bfsQueue;
        
        if (startVertex < 0 || startVertex >= vertices) {
            cout << "Đỉnh bắt đầu không hợp lệ!" << endl;
            return result;
        }
        
        bfsQueue.push(startVertex);
        visited[startVertex] = true;
        
        cout << "Bắt đầu BFS từ đỉnh " << startVertex << endl;
        cout << "Thứ tự duyệt: ";
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            result.push_back(currentVertex);
            cout << currentVertex << " ";
            
            // Duyệt tất cả cạnh từ đỉnh hiện tại
            unordered_set<int> visitedNeighbors; // Tránh thăm cùng một đỉnh nhiều lần trong một iteration
            
            for (auto edge : adjList[currentVertex]) {
                int neighbor = edge.first;
                if (!visited[neighbor] && visitedNeighbors.find(neighbor) == visitedNeighbors.end()) {
                    visited[neighbor] = true;
                    visitedNeighbors.insert(neighbor);
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Số đỉnh đã thăm: " << result.size() << "/" << vertices << endl;
        
        return result;
    }
    
    void displayGraph() {
        cout << "MultiGraph - Adjacency List with Edge IDs:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (auto edge : adjList[i]) {
                cout << "(" << edge.first << ",e" << edge.second << ") ";
            }
            cout << endl;
        }
    }
    
    int countEdges() {
        return edgeCounter;
    }
};

// =================================
// GENERAL GRAPH (Bài toán 10)
// =================================

class GeneralGraph {
private:
    int vertices;
    vector<vector<pair<int, double>>> adjList; // pair<neighbor, weight>
    bool isDirected;
    bool allowSelfLoops;
    bool allowMultipleEdges;
    
public:
    GeneralGraph(int v, bool directed = false, bool selfLoops = true, bool multiEdges = true) 
        : vertices(v), adjList(v), isDirected(directed), allowSelfLoops(selfLoops), allowMultipleEdges(multiEdges) {}
    
    void addEdge(int u, int v, double weight = 1.0) {
        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            // Kiểm tra self-loop
            if (u == v && !allowSelfLoops) {
                cout << "Self-loop không được phép!" << endl;
                return;
            }
            
            // Kiểm tra multiple edges
            if (!allowMultipleEdges) {
                for (auto edge : adjList[u]) {
                    if (edge.first == v) {
                        cout << "Multiple edge không được phép!" << endl;
                        return;
                    }
                }
            }
            
            adjList[u].push_back({v, weight});
            
            if (!isDirected && u != v) {
                adjList[v].push_back({u, weight});
            }
        }
    }
    
    vector<int> BFS(int startVertex) {
        cout << "\n=== BFS trên General Graph ===" << endl;
        cout << "Đặc điểm: ";
        cout << (isDirected ? "Có hướng" : "Vô hướng") << ", ";
        cout << (allowSelfLoops ? "Cho phép self-loops" : "Không cho phép self-loops") << ", ";
        cout << (allowMultipleEdges ? "Cho phép multiple edges" : "Không cho phép multiple edges") << endl;
        
        auto start = high_resolution_clock::now();
        
        vector<int> result;
        vector<bool> visited(vertices, false);
        queue<int> bfsQueue;
        
        if (startVertex < 0 || startVertex >= vertices) {
            cout << "Đỉnh bắt đầu không hợp lệ!" << endl;
            return result;
        }
        
        bfsQueue.push(startVertex);
        visited[startVertex] = true;
        
        cout << "Bắt đầu BFS từ đỉnh " << startVertex << endl;
        cout << "Thứ tự duyệt: ";
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            result.push_back(currentVertex);
            cout << currentVertex << " ";
            
            // Duyệt tất cả cạnh từ đỉnh hiện tại
            unordered_set<int> processedNeighbors;
            
            for (auto edge : adjList[currentVertex]) {
                int neighbor = edge.first;
                double weight = edge.second;
                
                if (!visited[neighbor] && processedNeighbors.find(neighbor) == processedNeighbors.end()) {
                    visited[neighbor] = true;
                    processedNeighbors.insert(neighbor);
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Số đỉnh đã thăm: " << result.size() << "/" << vertices << endl;
        
        return result;
    }
    
    void displayGraph() {
        cout << "General Graph - Adjacency List with Weights:" << endl;
        for (int i = 0; i < vertices; i++) {
            cout << i << ": ";
            for (auto edge : adjList[i]) {
                cout << "(" << edge.first << ",w=" << edge.second << ") ";
            }
            cout << endl;
        }
    }
    
    vector<double> getWeightedDistances(int startVertex) {
        // BFS cho shortest path trong unweighted graph
        vector<double> distances(vertices, -1);
        vector<bool> visited(vertices, false);
        queue<int> bfsQueue;
        
        bfsQueue.push(startVertex);
        visited[startVertex] = true;
        distances[startVertex] = 0;
        
        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            bfsQueue.pop();
            
            unordered_set<int> processedNeighbors;
            for (auto edge : adjList[currentVertex]) {
                int neighbor = edge.first;
                if (!visited[neighbor] && processedNeighbors.find(neighbor) == processedNeighbors.end()) {
                    visited[neighbor] = true;
                    processedNeighbors.insert(neighbor);
                    distances[neighbor] = distances[currentVertex] + 1;
                    bfsQueue.push(neighbor);
                }
            }
        }
        
        return distances;
    }
};

// =================================
// GRAPH CONVERTER UTILITIES
// =================================

class GraphConverter {
public:
    static SimpleGraph multiToSimple(const MultiGraph& multiGraph, int vertices) {
        SimpleGraph simpleGraph(vertices);
        cout << "\n=== Chuyển đổi MultiGraph thành SimpleGraph ===" << endl;
        cout << "Loại bỏ multiple edges và self-loops" << endl;
        
        // Logic chuyển đổi sẽ cần access vào internal structure
        // Đây là demonstration concept
        return simpleGraph;
    }
    
    static void compareGraphTypes() {
        cout << "\n=== So Sánh Các Loại Đồ Thị ===" << endl;
        cout << "1. Simple Graph:" << endl;
        cout << "   - Không có self-loops" << endl;
        cout << "   - Không có multiple edges" << endl;
        cout << "   - BFS đơn giản nhất" << endl;
        
        cout << "\n2. MultiGraph:" << endl;
        cout << "   - Có thể có multiple edges" << endl;
        cout << "   - Có thể có self-loops" << endl;
        cout << "   - BFS cần xử lý multiple edges" << endl;
        
        cout << "\n3. General Graph:" << endl;
        cout << "   - Flexible nhất" << endl;
        cout << "   - Có thể directed/undirected" << endl;
        cout << "   - Có thể có weights" << endl;
        cout << "   - BFS phức tạp nhất" << endl;
    }
};

// =================================
// MAIN FUNCTION VÀ DEMO
// =================================

int main() {
    cout << "=== BREADTH-FIRST SEARCH ALGORITHMS ===" << endl;
    cout << "Triển khai BFS cho 3 loại đồ thị: Simple, Multi, General\n" << endl;
    
    // Demo Simple Graph (Bài toán 8)
    cout << "DEMO 1: Simple Graph" << endl;
    SimpleGraph simpleGraph(6);
    simpleGraph.addEdge(0, 1);
    simpleGraph.addEdge(0, 2);
    simpleGraph.addEdge(1, 3);
    simpleGraph.addEdge(2, 4);
    simpleGraph.addEdge(3, 5);
    simpleGraph.addEdge(4, 5);
    
    simpleGraph.displayGraph();
    auto result1 = simpleGraph.BFS(0);
    
    cout << "Khoảng cách từ đỉnh 0:" << endl;
    auto distances1 = simpleGraph.getDistances(0);
    for (int i = 0; i < distances1.size(); i++) {
        cout << "Đến đỉnh " << i << ": " << distances1[i] << endl;
    }
    
    // Demo MultiGraph (Bài toán 9)
    cout << "\n" << string(50, '=') << endl;
    cout << "DEMO 2: MultiGraph" << endl;
    MultiGraph multiGraph(5);
    multiGraph.addEdge(0, 1);
    multiGraph.addEdge(0, 1); // Multiple edge
    multiGraph.addEdge(1, 2);
    multiGraph.addEdge(1, 1); // Self-loop
    multiGraph.addEdge(2, 3);
    multiGraph.addEdge(3, 4);
    multiGraph.addEdge(0, 4);
    
    multiGraph.displayGraph();
    auto result2 = multiGraph.BFS(0);
    cout << "Tổng số cạnh: " << multiGraph.countEdges() << endl;
    
    // Demo General Graph (Bài toán 10)
    cout << "\n" << string(50, '=') << endl;
    cout << "DEMO 3: General Graph (Directed, Weighted)" << endl;
    GeneralGraph generalGraph(5, true, true, false); // Directed, allow self-loops, no multiple edges
    generalGraph.addEdge(0, 1, 2.5);
    generalGraph.addEdge(0, 2, 1.0);
    generalGraph.addEdge(1, 3, 3.0);
    generalGraph.addEdge(2, 3, 1.5);
    generalGraph.addEdge(3, 4, 2.0);
    generalGraph.addEdge(1, 1, 0.5); // Self-loop
    
    generalGraph.displayGraph();
    auto result3 = generalGraph.BFS(0);
    
    cout << "Khoảng cách (unweighted) từ đỉnh 0:" << endl;
    auto distances3 = generalGraph.getWeightedDistances(0);
    for (int i = 0; i < distances3.size(); i++) {
        cout << "Đến đỉnh " << i << ": " << distances3[i] << endl;
    }
    
    // So sánh các loại đồ thị
    GraphConverter::compareGraphTypes();
    
    // Demo General Graph với các cấu hình khác
    cout << "\n" << string(50, '=') << endl;
    cout << "DEMO 4: General Graph (Undirected, No self-loops)" << endl;
    GeneralGraph generalGraph2(4, false, false, true); // Undirected, no self-loops, allow multiple edges
    generalGraph2.addEdge(0, 1, 1.0);
    generalGraph2.addEdge(1, 2, 1.0);
    generalGraph2.addEdge(2, 3, 1.0);
    generalGraph2.addEdge(0, 3, 1.0);
    generalGraph2.addEdge(0, 0, 1.0); // This should be rejected
    
    generalGraph2.displayGraph();
    auto result4 = generalGraph2.BFS(0);
    
    cout << "\n=== KẾT QUẢ TỔNG KẾT ===" << endl;
    cout << "1. Simple Graph BFS: " << result1.size() << " đỉnh đã thăm" << endl;
    cout << "2. MultiGraph BFS: " << result2.size() << " đỉnh đã thăm" << endl;
    cout << "3. General Graph (Directed) BFS: " << result3.size() << " đỉnh đã thăm" << endl;
    cout << "4. General Graph (Undirected) BFS: " << result4.size() << " đỉnh đã thăm" << endl;
    
    cout << "\nTất cả 3 loại BFS đã được triển khai thành công!" << endl;
    cout << "Mỗi loại có đặc điểm và ứng dụng riêng biệt." << endl;
    
    return 0;
}
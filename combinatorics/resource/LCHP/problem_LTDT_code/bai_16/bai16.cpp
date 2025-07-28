#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <algorithm>

using namespace std;

struct GeneralEdge {
    int from, to;
    int weight;
    int id;
    string type; // "normal", "self-loop", "parallel"
    
    GeneralEdge(int f, int t, int w, int i, string ty = "normal") 
        : from(f), to(t), weight(w), id(i), type(ty) {}
};

struct GraphStatistics {
    int numVertices;
    int numEdges; 
    int numSelfLoops;
    int numParallelEdges;
    bool isDirected;
    bool isConnected;
    vector<vector<int>> components;
    unordered_map<string, int> edgeTypeCount;
    
    GraphStatistics() : numVertices(0), numEdges(0), numSelfLoops(0), 
                       numParallelEdges(0), isDirected(false), isConnected(false) {}
};

class GeneralDijkstra {
private:
    int numVertices;
    bool isDirected;
    vector<vector<GeneralEdge>> adjList;
    vector<int> dist;
    vector<int> parent;
    vector<int> parentEdgeId;
    vector<bool> visited;
    vector<bool> inCurrentComponent;
    
    int edgeIdCounter;
    GraphStatistics stats;
    unordered_map<string, int> edgeKeyCount; // Đếm cạnh song song
    
public:
    GeneralDijkstra(int n, bool directed = false) 
        : numVertices(n), isDirected(directed), edgeIdCounter(0) {
        adjList.resize(n);
        stats.numVertices = n;
        stats.isDirected = directed;
        reset();
    }
    
    void reset() {
        dist.assign(numVertices, INT_MAX);
        parent.assign(numVertices, -1);
        parentEdgeId.assign(numVertices, -1);
        visited.assign(numVertices, false);
        inCurrentComponent.assign(numVertices, false);
    }
    
    void addEdge(int u, int v, int weight) {
        string edgeKey = to_string(min(u, v)) + "-" + to_string(max(u, v));
        edgeKeyCount[edgeKey]++;
        
        string edgeType = "normal";
        if (u == v) {
            edgeType = "self-loop";
            stats.numSelfLoops++;
        } else if (edgeKeyCount[edgeKey] > 1) {
            edgeType = "parallel";
            stats.numParallelEdges++;
        }
        
        // Thêm cạnh từ u đến v
        adjList[u].push_back(GeneralEdge(u, v, weight, edgeIdCounter, edgeType));
        
        // Nếu là đồ thị vô hướng và không phải vòng lặp
        if (!isDirected && u != v) {
            adjList[v].push_back(GeneralEdge(v, u, weight, edgeIdCounter, edgeType));
        }
        
        stats.numEdges++;
        stats.edgeTypeCount[edgeType]++;
        
        cout << "Thêm cạnh " << (isDirected ? "có hướng " : "") 
             << u << " -> " << v << " (trọng số: " << weight 
             << ", loại: " << edgeType << ", ID: " << edgeIdCounter << ")" << endl;
        
        edgeIdCounter++;
    }
    
    void dijkstraGeneral(int source) {
        reset();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
                      greater<pair<int, int>>> pq;
        
        dist[source] = 0;
        pq.push({0, source});
        
        cout << "\nDijkstra tổng quát từ đỉnh " << source 
             << " trên đồ thị " << (isDirected ? "có hướng:" : "vô hướng:") << endl;
        
        int processedVertices = 0;
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            inCurrentComponent[u] = true;
            processedVertices++;
            
            cout << "Bước " << processedVertices << ": Xử lý đỉnh " << u 
                 << " (khoảng cách: " << d << ")" << endl;
            
            // Xử lý tất cả các cạnh từ u
            for (const GeneralEdge& edge : adjList[u]) {
                int v = edge.to;
                int weight = edge.weight;
                
                cout << "  Kiểm tra cạnh " << u << " -> " << v 
                     << " (trọng số: " << weight << ", loại: " << edge.type << ")";
                
                // Xử lý đặc biệt cho vòng lặp
                if (edge.type == "self-loop") {
                    cout << " [Vòng lặp - bỏ qua]" << endl;
                    continue;
                }
                
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    parentEdgeId[v] = edge.id;
                    pq.push({dist[v], v});
                    
                    cout << " [Cập nhật dist[" << v << "] = " << dist[v] << "]" << endl;
                } else {
                    cout << " [Không cập nhật]" << endl;
                }
            }
        }
        
        cout << "Đã xử lý " << processedVertices << "/" << numVertices << " đỉnh" << endl;
    }
    
    void analyzeConnectivity() {
        stats.components.clear();
        vector<bool> globalVisited(numVertices, false);
        
        for (int i = 0; i < numVertices; i++) {
            if (!globalVisited[i]) {
                vector<int> component;
                dfsComponent(i, globalVisited, component);
                stats.components.push_back(component);
            }
        }
        
        stats.isConnected = (stats.components.size() == 1);
        
        cout << "\nPhân tích tính liên thông:" << endl;
        cout << "Số thành phần liên thông: " << stats.components.size() << endl;
        
        for (int i = 0; i < stats.components.size(); i++) {
            cout << "Thành phần " << i + 1 << ": {";
            for (int j = 0; j < stats.components[i].size(); j++) {
                cout << stats.components[i][j];
                if (j < stats.components[i].size() - 1) cout << ", ";
            }
            cout << "}" << endl;
        }
    }
    
private:
    void dfsComponent(int u, vector<bool>& globalVisited, vector<int>& component) {
        globalVisited[u] = true;
        component.push_back(u);
        
        for (const GeneralEdge& edge : adjList[u]) {
            int v = edge.to;
            if (!globalVisited[v]) {
                dfsComponent(v, globalVisited, component);
            }
        }
    }
    
public:
    void printGeneralGraph() {
        cout << "\nĐồ thị tổng quát (" << (isDirected ? "có hướng" : "vô hướng") << "):" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << "Đỉnh " << i << ": ";
            
            // Nhóm cạnh theo đích và loại
            unordered_map<int, vector<GeneralEdge>> edgeGroups;
            for (const GeneralEdge& edge : adjList[i]) {
                edgeGroups[edge.to].push_back(edge);
            }
            
            for (const auto& group : edgeGroups) {
                int dest = group.first;
                const vector<GeneralEdge>& edges = group.second;
                
                cout << dest;
                if (edges.size() > 1 || edges[0].type != "normal") {
                    cout << "[";
                    for (int j = 0; j < edges.size(); j++) {
                        cout << edges[j].weight;
                        if (edges[j].type == "self-loop") cout << "L";
                        if (edges[j].type == "parallel" && edges.size() > 1) cout << "P";
                        if (j < edges.size() - 1) cout << ",";
                    }
                    cout << "]";
                } else {
                    cout << "(" << edges[0].weight << ")";
                }
                cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    void printDetailedResults(int source) {
        cout << "\n=== KẾT QUẢ CHI TIẾT DIJKSTRA ===" << endl;
        cout << "Nguồn: " << source << " | Đồ thị: " 
             << (isDirected ? "có hướng" : "vô hướng") << endl;
        cout << string(70, '-') << endl;
        
        cout << left << setw(6) << "Đỉnh" 
             << setw(12) << "Khoảng cách"
             << setw(8) << "Cha"
             << setw(10) << "Cạnh ID" 
             << setw(15) << "Đường đi"
             << setw(15) << "Trạng thái" << endl;
        cout << string(70, '-') << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << left << setw(6) << i;
            
            if (dist[i] == INT_MAX) {
                cout << setw(12) << "∞"
                     << setw(8) << "-" 
                     << setw(10) << "-"
                     << setw(15) << "Không đạt được"
                     << setw(15) << "Không liên thông";
            } else {
                cout << setw(12) << dist[i]
                     << setw(8) << (parent[i] == -1 ? "-" : to_string(parent[i]))
                     << setw(10) << (parentEdgeId[i] == -1 ? "-" : to_string(parentEdgeId[i]));
                
                string pathStr = getPathString(source, i);
                cout << setw(15) << pathStr;
                
                string status = (i == source) ? "Nguồn" : "Đạt được";
                cout << setw(15) << status;
            }
            cout << endl;
        }
        cout << string(70, '-') << endl;
    }
    
    string getPathString(int source, int dest) {
        if (dest == source) return to_string(dest);
        if (parent[dest] == -1) return "N/A";
        
        vector<int> path;
        int current = dest;
        
        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        reverse(path.begin(), path.end());
        
        string result;
        for (int i = 0; i < path.size(); i++) {
            result += to_string(path[i]);
            if (i < path.size() - 1) result += "→";
        }
        
        return result;
    }
    
    void printGraphStatistics() {
        cout << "\n=== THỐNG KÊ ĐỒ THỊ ===" << endl;
        cout << "Số đỉnh: " << stats.numVertices << endl;
        cout << "Số cạnh: " << stats.numEdges << endl;
        cout << "Loại đồ thị: " << (stats.isDirected ? "Có hướng" : "Vô hướng") << endl;
        cout << "Liên thông: " << (stats.isConnected ? "Có" : "Không") << endl;
        cout << "Số thành phần liên thông: " << stats.components.size() << endl;
        
        cout << "\nThống kê loại cạnh:" << endl;
        for (const auto& pair : stats.edgeTypeCount) {
            cout << "  " << pair.first << ": " << pair.second << endl;
        }
        
        if (stats.numSelfLoops > 0) {
            cout << "Có " << stats.numSelfLoops << " vòng lặp" << endl;
        }
        
        if (stats.numParallelEdges > 0) {
            cout << "Có cạnh song song" << endl;
        }
        
        cout << endl;
    }
    
    void runCompleteAnalysis(int source) {
        cout << "=== PHÂN TÍCH HOÀN CHỈNH ĐỒ THỊ ===" << endl;
        
        // 1. In đồ thị
        printGeneralGraph();
        
        // 2. Thống kê đồ thị  
        printGraphStatistics();
        
        // 3. Phân tích tình liên thông
        analyzeConnectivity();
        
        // 4. Chạy Dijkstra
        dijkstraGeneral(source);
        
        // 5. In kết quả chi tiết
        printDetailedResults(source);
        
        // 6. Phân tích các trường hợp đặc biệt
        analyzeSpecialCases(source);
    }
    
    void analyzeSpecialCases(int source) {
        cout << "\n=== PHÂN TÍCH TRƯỜNG HỢP ĐẶC BIỆT ===" << endl;
        
        // Đỉnh không đạt được
        vector<int> unreachable;
        for (int i = 0; i < numVertices; i++) {
            if (dist[i] == INT_MAX) {
                unreachable.push_back(i);
            }
        }
        
        if (!unreachable.empty()) {
            cout << "Đỉnh không đạt được từ " << source << ": ";
            for (int i = 0; i < unreachable.size(); i++) {
                cout << unreachable[i];
                if (i < unreachable.size() - 1) cout << ", ";
            }
            cout << endl;
        }
        
        // Đường đi dài nhất
        int maxDist = 0;
        int farthestVertex = -1;
        for (int i = 0; i < numVertices; i++) {
            if (dist[i] != INT_MAX && dist[i] > maxDist) {
                maxDist = dist[i];
                farthestVertex = i;
            }
        }
        
        if (farthestVertex != -1) {
            cout << "Đỉnh xa nhất từ " << source << ": " << farthestVertex 
                 << " (khoảng cách: " << maxDist << ")" << endl;
        }
        
        // Số đỉnh trong cùng thành phần liên thông
        int reachableCount = 0;
        for (int i = 0; i < numVertices; i++) {
            if (dist[i] != INT_MAX) reachableCount++;
        }
        
        cout << "Đỉnh đạt được: " << reachableCount << "/" << numVertices 
             << " (" << (100.0 * reachableCount / numVertices) << "%)" << endl;
        
        cout << endl;
    }
    
    // Chạy Dijkstra từ tất cả đỉnh (All-Pairs Shortest Path)
    void allPairsShortestPath() {
        cout << "=== TẤT CẢ CẶP ĐƯỜNG ĐI NGẮN NHẤT ===" << endl;
        
        vector<vector<int>> allDist(numVertices, vector<int>(numVertices, INT_MAX));
        
        for (int source = 0; source < numVertices; source++) {
            dijkstraGeneral(source);
            
            for (int dest = 0; dest < numVertices; dest++) {
                allDist[source][dest] = dist[dest];
            }
        }
        
        // In ma trận khoảng cách
        cout << "\nMa trận khoảng cách ngắn nhất:" << endl;
        cout << setw(6) << "";
        for (int j = 0; j < numVertices; j++) {
            cout << setw(6) << j;
        }
        cout << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << setw(6) << i;
            for (int j = 0; j < numVertices; j++) {
                if (allDist[i][j] == INT_MAX) {
                    cout << setw(6) << "∞";
                } else {
                    cout << setw(6) << allDist[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

void demonstrateGeneralDijkstra() {
    cout << "=== DEMO DIJKSTRA CHO ĐỒ THỊ TỔNG QUÁT ===\n" << endl;
    
    // Test case 1: Đồ thị vô hướng với cạnh song song
    cout << ">>> TEST CASE 1: Đồ thị vô hướng với cạnh song song <<<" << endl;
    GeneralDijkstra graph1(5, false);
    
    graph1.addEdge(0, 1, 4);
    graph1.addEdge(0, 1, 2);  // Cạnh song song
    graph1.addEdge(0, 2, 3);
    graph1.addEdge(1, 3, 1);
    graph1.addEdge(2, 3, 5);
    graph1.addEdge(3, 4, 2);
    graph1.addEdge(1, 1, 3);  // Vòng lặp
    
    graph1.runCompleteAnalysis(0);
    
    cout << "\n" << string(60, '=') << "\n" << endl;
    
    // Test case 2: Đồ thị có hướng không liên thông
    cout << ">>> TEST CASE 2: Đồ thị có hướng không liên thông <<<" << endl;
    GeneralDijkstra graph2(6, true);
    
    graph2.addEdge(0, 1, 2);
    graph2.addEdge(1, 2, 3);
    graph2.addEdge(3, 4, 1);
    graph2.addEdge(4, 5, 4);
    graph2.addEdge(2, 2, 1);  // Vòng lặp
    
    graph2.runCompleteAnalysis(0);
    graph2.allPairsShortestPath();
}

int main() {
    demonstrateGeneralDijkstra();
    return 0;
}
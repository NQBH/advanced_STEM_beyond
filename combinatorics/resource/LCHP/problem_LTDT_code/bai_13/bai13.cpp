#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    bool isDirected;  // true = có hướng, false = vô hướng
    int id;          // ID duy nhất của cạnh
    
    Edge(int t, bool dir, int i) : to(t), isDirected(dir), id(i) {}
};

class GeneralGraphDFS {
private:
    int numVertices;
    vector<vector<Edge>> adjList;
    map<pair<int,int>, vector<Edge>> edgeMap;  // (u,v) -> list of edges
    
    vector<bool> visited;
    vector<int> startTime;
    vector<int> finishTime;
    vector<int> parent;
    vector<int> dfsOrder;
    int timeCounter;
    int edgeIdCounter;
    
    // Thông tin chi tiết về cạnh
    struct EdgeInfo {
        int from, to, id;
        bool isDirected;
        string type;
        bool isSelfLoop;
        
        EdgeInfo(int f, int t, int i, bool dir, string typ, bool self) 
            : from(f), to(t), id(i), isDirected(dir), type(typ), isSelfLoop(self) {}
    };
    
    vector<EdgeInfo> edgeInfoList;
    
    // Đếm số khuyên tại mỗi đỉnh
    vector<int> selfLoopCount;
    
public:
    GeneralGraphDFS(int n) : numVertices(n), timeCounter(0), edgeIdCounter(0) {
        adjList.resize(n);
        selfLoopCount.resize(n, 0);
        resetArrays();
    }
    
    void resetArrays() {
        visited.assign(numVertices, false);
        startTime.assign(numVertices, 0);
        finishTime.assign(numVertices, 0);
        parent.assign(numVertices, -1);
        dfsOrder.clear();
        edgeInfoList.clear();
        timeCounter = 0;
    }
    
    void addEdge(int u, int v, bool isDirected = false) {
        Edge edge(v, isDirected, edgeIdCounter++);
        adjList[u].push_back(edge);
        
        // Xử lý khuyên
        if (u == v) {
            selfLoopCount[u]++;
            cout << "Thêm khuyên tại đỉnh " << u << " (ID: " << edge.id << ")" << endl;
        } else {
            // Cạnh thường - thêm vào cả 2 chiều nếu vô hướng
            if (!isDirected) {
                Edge reverseEdge(u, false, edgeIdCounter++);
                adjList[v].push_back(reverseEdge);
            }
            
            cout << "Thêm cạnh " << u << " -> " << v 
                 << (isDirected ? " (có hướng)" : " (vô hướng)") 
                 << " (ID: " << edge.id << ")" << endl;
        }
        
        // Cập nhật bản đồ cạnh
        pair<int,int> edgeKey = {u, v};
        edgeMap[edgeKey].push_back(edge);
    }
    
    // DFS cho đồ thị tổng quát
    void dfsRecursive(int u) {
        visited[u] = true;
        startTime[u] = ++timeCounter;
        dfsOrder.push_back(u);
        
        cout << "Thăm đỉnh " << u << " (start: " << startTime[u] << ")" << endl;
        
        // Xử lý khuyên trước
        if (selfLoopCount[u] > 0) {
            cout << "  Phát hiện " << selfLoopCount[u] << " khuyên tại đỉnh " << u << endl;
            // Khuyên luôn được coi là cạnh đặc biệt
            edgeInfoList.push_back(EdgeInfo(u, u, -1, true, "SELF_LOOP", true));
        }
        
        // Duyệt các cạnh thường
        for (const Edge& edge : adjList[u]) {
            int v = edge.to;
            bool isDirected = edge.isDirected;
            
            // Bỏ qua khuyên (đã xử lý ở trên)
            if (u == v) continue;
            
            if (!visited[v]) {
                parent[v] = u;
                edgeInfoList.push_back(EdgeInfo(u, v, edge.id, isDirected, "TREE", false));
                cout << "  Cạnh cây: " << u << " -> " << v 
                     << (isDirected ? " (có hướng)" : " (vô hướng)") << endl;
                dfsRecursive(v);
            } else {
                // Phân loại cạnh phức tạp
                string edgeType = classifyEdge(u, v, isDirected);
                edgeInfoList.push_back(EdgeInfo(u, v, edge.id, isDirected, edgeType, false));
                
                cout << "  Cạnh " << edgeType << ": " << u << " -> " << v 
                     << (isDirected ? " (có hướng)" : " (vô hướng)");
                
                if (edgeType == "BACK") {
                    cout << " (chu trình!)";
                }
                cout << endl;
            }
        }
        
        finishTime[u] = ++timeCounter;
        cout << "Kết thúc đỉnh " << u << " (finish: " << finishTime[u] << ")" << endl;
    }
    
private:
    string classifyEdge(int u, int v, bool isDirected) {
        // Phân loại cạnh dựa trên thời gian và hướng
        if (startTime[v] < startTime[u] && finishTime[v] == 0) {
            return "BACK";  // Cạnh ngược - tạo chu trình
        }
        
        if (startTime[v] > startTime[u]) {
            return "FORWARD";  // Cạnh xuôi
        }
        
        if (finishTime[v] < startTime[u]) {
            return "CROSS";  // Cạnh chéo
        }
        
        // Trường hợp đặc biệt cho cạnh vô hướng
        if (!isDirected && parent[u] == v) {
            return "PARENT";  // Cạnh về cha (không tính chu trình)
        }
        
        return "UNKNOWN";
    }
    
public:
    void dfsComplete() {
        resetArrays();
        
        cout << "DFS toàn bộ đồ thị tổng quát:" << endl;
        int componentCount = 0;
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                componentCount++;
                cout << "\nThành phần liên thông " << componentCount << ":" << endl;
                dfsRecursive(i);
            }
        }
        
        cout << "\nTổng số thành phần liên thông: " << componentCount << endl;
        analyzeComplexGraph();
    }
    
    void analyzeComplexGraph() {
        cout << "\nPhân tích đồ thị tổng quát:" << endl;
        
        int treeEdges = 0, backEdges = 0, forwardEdges = 0, crossEdges = 0;
        int selfLoops = 0, directedEdges = 0, undirectedEdges = 0;
        bool hasCycle = false;
        
        for (const EdgeInfo& info : edgeInfoList) {
            if (info.isSelfLoop) {
                selfLoops++;
                continue;
            }
            
            if (info.isDirected) {
                directedEdges++;
            } else {
                undirectedEdges++;
            }
            
            if (info.type == "TREE") treeEdges++;
            else if (info.type == "BACK") { backEdges++; hasCycle = true; }
            else if (info.type == "FORWARD") forwardEdges++;
            else if (info.type == "CROSS") crossEdges++;
        }
        
        cout << "Thống kê cạnh:" << endl;
        cout << "- Cạnh cây: " << treeEdges << endl;
        cout << "- Cạnh ngược: " << backEdges << endl;
        cout << "- Cạnh xuôi: " << forwardEdges << endl;
        cout << "- Cạnh chéo: " << crossEdges << endl;
        cout << "- Khuyên: " << selfLoops << endl;
        cout << "- Cạnh có hướng: " << directedEdges << endl;
        cout << "- Cạnh vô hướng: " << undirectedEdges << endl;
        
        cout << "\nĐồ thị có chu trình: " << (hasCycle ? "Có" : "Không") << endl;
        
        // Phân tích tính chất đặc biệt
        analyzeSpecialProperties();
    }
    
    void analyzeSpecialProperties() {
        cout << "\nPhân tích tính chất đặc biệt:" << endl;
        
        // Kiểm tra đồ thị Euler
        bool isEulerian = checkEulerian();
        cout << "Đồ thị Euler: " << (isEulerian ? "Có" : "Không") << endl;
        
        // Kiểm tra tính liên thông mạnh (cho phần có hướng)
        bool isStronglyConnected = checkStrongConnectivity();
        cout << "Liên thông mạnh: " << (isStronglyConnected ? "Có" : "Không") << endl;
        
        // Đếm số bậc của mỗi đỉnh
        printDegreeInformation();
    }
    
    bool checkEulerian() {
        // Đơn giản hóa: kiểm tra bậc chẵn cho tất cả đỉnh
        for (int i = 0; i < numVertices; i++) {
            int degree = adjList[i].size() + selfLoopCount[i];
            if (degree % 2 != 0) {
                return false;
            }
        }
        return true;
    }
    
    bool checkStrongConnectivity() {
        // Kiểm tra đơn giản: tất cả đỉnh có thể đến được từ đỉnh 0
        resetArrays();
        dfsRecursive(0);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
    
    void printDegreeInformation() {
        cout << "\nThông tin bậc đỉnh:" << endl;
        cout << "Đỉnh\tBậc vào\tBậc ra\tKhuyên" << endl;
        cout << "----\t-------\t------\t------" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            int inDegree = 0, outDegree = 0;
            
            // Tính bậc ra
            outDegree = adjList[i].size();
            
            // Tính bậc vào
            for (int j = 0; j < numVertices; j++) {
                for (const Edge& edge : adjList[j]) {
                    if (edge.to == i && j != i) {
                        inDegree++;
                    }
                }
            }
            
            cout << i << "\t" << inDegree << "\t" << outDegree 
                 << "\t" << selfLoopCount[i] << endl;
        }
    }
    
    void printGeneralGraph() {
        cout << "Biểu diễn đồ thị tổng quát:" << endl;
        
        for (int i = 0; i < numVertices; i++) {
            cout << "Đỉnh " << i << ":" << endl;
            
            if (selfLoopCount[i] > 0) {
                cout << "  Khuyên: " << selfLoopCount[i] << endl;
            }
            
            cout << "  Kề: ";
            for (const Edge& edge : adjList[i]) {
                if (edge.to != i) {  // Không in khuyên ở đây
                    cout << edge.to << (edge.isDirected ? "(→)" : "(↔)") << " ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Tìm tất cả chu trình trong đồ thị tổng quát
    void findAllCycles() {
        cout << "Tìm tất cả chu trình trong đồ thị:" << endl;
        
        vector<vector<int>> cycles;
        vector<int> currentPath;
        vector<bool> inPath(numVertices, false);
        
        for (int i = 0; i < numVertices; i++) {
            findCyclesFromVertex(i, currentPath, inPath, cycles);
        }
        
        if (cycles.empty()) {
            cout << "Không có chu trình" << endl;
        } else {
            cout << "Tìm thấy " << cycles.size() << " chu trình:" << endl;
            for (int i = 0; i < cycles.size(); i++) {
                cout << "Chu trình " << i + 1 << ": ";
                for (int j = 0; j < cycles[i].size(); j++) {
                    cout << cycles[i][j];
                    if (j < cycles[i].size() - 1) cout << " -> ";
                }
                cout << " -> " << cycles[i][0] << endl;
            }
        }
    }
    
private:
    void findCyclesFromVertex(int start, vector<int>& path, 
                             vector<bool>& inPath, vector<vector<int>>& cycles) {
        path.push_back(start);
        inPath[start] = true;
        
        for (const Edge& edge : adjList[start]) {
            int next = edge.to;
            
            if (next == start) continue;  // Bỏ qua khuyên
            
            if (inPath[next]) {
                // Tìm thấy chu trình
                auto it = find(path.begin(), path.end(), next);
                if (it != path.end()) {
                    vector<int> cycle(it, path.end());
                    cycles.push_back(cycle);
                }
            } else if (find(path.begin(), path.end(), next) == path.end()) {
                findCyclesFromVertex(next, path, inPath, cycles);
            }
        }
        
        path.pop_back();
        inPath[start] = false;
    }
};

// Demo cho đồ thị tổng quát
void demonstrateGeneralGraphDFS() {
    cout << "=== DEMO DFS CHO ĐỒ THỊ TỔNG QUÁT ===" << endl << endl;
    
    GeneralGraphDFS graph(6);
    
    // Tạo đồ thị tổng quát phức tạp
    cout << "Tạo đồ thị tổng quát:" << endl;
    
    // Cạnh vô hướng
    graph.addEdge(0, 1, false);
    graph.addEdge(1, 2, false);
    
    // Cạnh có hướng
    graph.addEdge(2, 3, true);
    graph.addEdge(3, 4, true);
    
    // Cạnh bội
    graph.addEdge(0, 1, false);  // Cạnh bội vô hướng
    graph.addEdge(2, 3, true);   // Cạnh bội có hướng
    
    // Khuyên
    graph.addEdge(4, 4, true);   // Khuyên có hướng
    graph.addEdge(5, 5, false);  // Khuyên vô hướng
    
    // Cạnh tạo chu trình
    graph.addEdge(4, 1, true);   // Chu trình có hướng
    graph.addEdge(3, 0, false);  // Chu trình hỗn hợp
    
    cout << endl;
    graph.printGeneralGraph();
    
    // DFS trên đồ thị tổng quát
    graph.dfsComplete();
    
    // Tìm chu trình
    graph.findAllCycles();
}

int main() {
    demonstrateGeneralGraphDFS();
    return 0;
}
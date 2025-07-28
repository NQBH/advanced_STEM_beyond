#include <iostream>
#include <vector>   
#include <list>     
#include <map>      
#include <set>      
#include <unordered_map>
#include <unordered_set> 
#include <queue>    
#include <algorithm> 
#include <functional>
#include <cassert>

using namespace std;

class GraphConverter {
private:
    int numVertices; // Số đỉnh của đồ thị, lưu trữ kích thước đồ thị
    
public:
    // Định nghĩa các kiểu dữ liệu cho các dạng biểu diễn đồ thị
    typedef vector<vector<int>> AdjMatrix; // Ma trận kề: vector 2 chiều lưu trữ các cạnh (0/1 hoặc trọng số)
    typedef vector<list<int>> AdjList;     // Danh sách kề: vector chứa danh sách liên kết các đỉnh kề
    typedef vector<list<pair<int, int>>> ExtendedAdjList; // Danh sách kề mở rộng: lưu cặp (đỉnh kề, trọng số)
    typedef unordered_map<int, set<int>> AdjMap; // Ma trận đồ thị: ánh xạ từ đỉnh sang tập hợp các đỉnh kề
    
    // Constructor khởi tạo số đỉnh của đồ thị
    GraphConverter(int n) : numVertices(n) {}
    
    // Chuyển đổi từ Ma trận kề sang Danh sách kề
    AdjList matrixToList(const AdjMatrix& matrix) {
        AdjList adjList(numVertices); // Khởi tạo danh sách kề với numVertices danh sách rỗng
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (int j = 0; j < numVertices; j++) { // Duyệt qua từng đỉnh j
                if (matrix[i][j] != 0) { // Nếu có cạnh từ i đến j
                    adjList[i].push_back(j); // Thêm j vào danh sách kề của i
                }
            }
        }
        
        return adjList; // Trả về danh sách kề
    }
    
    // Chuyển đổi từ Danh sách kề sang Ma trận kề
    AdjMatrix listToMatrix(const AdjList& adjList) {
        AdjMatrix matrix(numVertices, vector<int>(numVertices, 0)); // Khởi tạo ma trận kề toàn 0
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (int neighbor : adjList[i]) { // Duyệt qua các đỉnh kề của i
                matrix[i][neighbor] = 1; // Đánh dấu cạnh từ i đến neighbor trong ma trận
            }
        }
        
        return matrix; // Trả về ma trận kề
    }
    
    // Chuyển đổi từ Danh sách kề sang Danh sách kề mở rộng (có trọng số)
    ExtendedAdjList listToExtended(const AdjList& adjList, 
                                   const vector<vector<int>>& weights = {}) {
        ExtendedAdjList extList(numVertices); // Khởi tạo danh sách kề mở rộng
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (int neighbor : adjList[i]) { // Duyệt qua các đỉnh kề của i
                // Gán trọng số: nếu không có ma trận trọng số thì mặc định là 1
                int weight = (weights.empty()) ? 1 : weights[i][neighbor];
                extList[i].push_back({neighbor, weight}); // Thêm cặp (đỉnh kề, trọng số)
            }
        }
        
        return extList; // Trả về danh sách kề mở rộng
    }
    
    // Chuyển đổi từ Danh sách kề mở rộng sang Danh sách kề (bỏ trọng số)
    AdjList extendedToList(const ExtendedAdjList& extList) {
        AdjList adjList(numVertices); // Khởi tạo danh sách kề
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (const auto& edge : extList[i]) { // Duyệt qua các cạnh trong danh sách mở rộng
                adjList[i].push_back(edge.first); // Chỉ lấy đỉnh kề, bỏ trọng số
            }
        }
        
        return adjList; // Trả về danh sách kề
    }
    
    // Chuyển đổi từ Danh sách kề sang Ma trận đồ thị (dùng unordered_map và set)
    AdjMap listToMap(const AdjList& adjList) {
        AdjMap adjMap; // Khởi tạo ma trận đồ thị
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (int neighbor : adjList[i]) { // Duyệt qua các đỉnh kề của i
                adjMap[i].insert(neighbor); // Thêm đỉnh kề vào tập hợp của i
            }
        }
        
        return adjMap; // Trả về ma trận đồ thị
    }
    
    // Chuyển đổi từ Ma trận đồ thị sang Danh sách kề
    AdjList mapToList(const AdjMap& adjMap) {
        AdjList adjList(numVertices); // Khởi tạo danh sách kề
        
        for (const auto& vertex : adjMap) { // Duyệt qua các đỉnh trong ma trận đồ thị
            int u = vertex.first; // Lấy đỉnh u
            for (int v : vertex.second) { // Duyệt qua các đỉnh kề của u
                adjList[u].push_back(v); // Thêm v vào danh sách kề của u
            }
        }
        
        return adjList; // Trả về danh sách kề
    }
    
    // Xử lý đa đồ thị: Chuyển từ Ma trận kề sang Danh sách kề
    AdjList multigraphMatrixToList(const AdjMatrix& matrix) {
        AdjList adjList(numVertices); // Khởi tạo danh sách kề
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (int j = 0; j < numVertices; j++) { // Duyệt qua từng đỉnh j
                // Thêm j vào danh sách kề của i, matrix[i][j] lần (hỗ trợ đa đồ thị)
                for (int k = 0; k < matrix[i][j]; k++) {
                    adjList[i].push_back(j);
                }
            }
        }
        
        return adjList; // Trả về danh sách kề
    }
    
    // Xử lý đa đồ thị: Chuyển từ Danh sách kề sang Ma trận kề
    AdjMatrix multigraphListToMatrix(const AdjList& adjList) {
        AdjMatrix matrix(numVertices, vector<int>(numVertices, 0)); // Khởi tạo ma trận kề toàn 0
        
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh i
            for (int neighbor : adjList[i]) { // Duyệt qua các đỉnh kề của i
                matrix[i][neighbor]++; // Tăng số lượng cạnh từ i đến neighbor
            }
        }
        
        return matrix; // Trả về ma trận kề
    }
    
    // Kiểm tra xem đồ thị có phải là đơn đồ thị (không có khuyên, không có cạnh lặp)
    bool isSimpleGraph(const AdjMatrix& matrix) {
        for (int i = 0; i < numVertices; i++) {
            if (matrix[i][i] != 0) return false; // Kiểm tra có khuyên (vòng lặp tại đỉnh i)
            
            for (int j = i + 1; j < numVertices; j++) {
                // Kiểm tra tính đối xứng cho đồ thị vô hướng
                if (matrix[i][j] != matrix[j][i]) return false;
                // Kiểm tra không có cạnh lặp (giá trị lớn hơn 1)
                if (matrix[i][j] > 1) return false;
            }
        }
        return true; // Đồ thị là đơn đồ thị
    }
    
    // In ma trận kề
    void printMatrix(const AdjMatrix& matrix) {
        cout << "Ma trận kề:" << endl; // Tiêu đề
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng hàng
            for (int j = 0; j < numVertices; j++) { // Duyệt qua từng cột
                cout << matrix[i][j] << " "; // In giá trị
            }
            cout << endl; // Xuống dòng sau mỗi hàng
        }
        cout << endl; // Dòng trống để phân tách
    }
    
    // In danh sách kề
    void printList(const AdjList& adjList) {
        cout << "Danh sách kề:" << endl; // Tiêu đề
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh
            cout << i << ": "; // In đỉnh hiện tại
            for (int neighbor : adjList[i]) { // Duyệt qua các đỉnh kề
                cout << neighbor << " "; // In đỉnh kề
            }
            cout << endl; // Xuống dòng
        }
        cout << endl; // Dòng trống để phân tách
    }
    
    // In danh sách kề mở rộng
    void printExtended(const ExtendedAdjList& extList) {
        cout << "Danh sách kề mở rộng:" << endl; // Tiêu đề
        for (int i = 0; i < numVertices; i++) { // Duyệt qua từng đỉnh
            cout << i << ": "; // In đỉnh hiện tại
            for (const auto& edge : extList[i]) { // Duyệt qua các cạnh
                cout << "(" << edge.first << "," << edge.second << ") "; // In cặp (đỉnh kề, trọng số)
            }
            cout << endl; // Xuống dòng
        }
        cout << endl; // Dòng trống để phân tách
    }
    
    // In ma trận đồ thị
    void printMap(const AdjMap& adjMap) {
        cout << "Ma trận đồ thị:" << endl; // Tiêu đề
        for (const auto& vertex : adjMap) { // Duyệt qua các đỉnh
            cout << vertex.first << ": "; // In đỉnh hiện tại
            for (int neighbor : vertex.second) { // Duyệt qua các đỉnh kề
                cout << neighbor << " "; // In đỉnh kề
            }
            cout << endl; // Xuống dòng
        }
        cout << endl; // Dòng trống để phân tách
    }
};

class TreeConverter {
private:
    int numNodes; // Số nút của cây
    
public:
    // Constructor khởi tạo số nút của cây
    TreeConverter(int n) : numNodes(n) {}
    
    // Chuyển từ mảng cha sang biểu diễn first-child next-sibling
    pair<vector<int>, vector<int>> parentToFCNS(const vector<int>& parent) {
        vector<int> firstChild(numNodes, -1); // Mảng lưu con đầu tiên của mỗi nút
        vector<int> nextSibling(numNodes, -1); // Mảng lưu anh em tiếp theo của mỗi nút
        vector<vector<int>> children(numNodes); // Danh sách tạm thời lưu con của mỗi nút
        
        // Xây dựng danh sách con
        for (int i = 0; i < numNodes; i++) {
            if (parent[i] != -1) { // Nếu nút i có cha
                children[parent[i]].push_back(i); // Thêm i vào danh sách con của cha
            }
        }
        
        // Thiết lập firstChild và nextSibling
        for (int i = 0; i < numNodes; i++) {
            if (!children[i].empty()) { // Nếu nút i có con
                firstChild[i] = children[i][0]; // Gán con đầu tiên
                for (int j = 0; j < (int)children[i].size() - 1; j++) { // Thiết lập nextSibling
                    nextSibling[children[i][j]] = children[i][j + 1]; // Gán anh em tiếp theo
                }
            }
        }
        
        return {firstChild, nextSibling}; // Trả về cặp firstChild và nextSibling
    }
    
    // Chuyển từ biểu diễn first-child next-sibling sang mảng cha
    vector<int> FCNSToParent(const vector<int>& firstChild, 
                            const vector<int>& nextSibling) {
        vector<int> parent(numNodes, -1); // Mảng cha, mặc định không có cha
        
        // Hàm DFS để xây dựng mảng cha
        function<void(int, int)> dfs = [&](int node, int par) {
            parent[node] = par; // Gán cha của node
            
            int child = firstChild[node]; // Lấy con đầu tiên
            while (child != -1) { // Duyệt qua tất cả con
                dfs(child, node); // Gọi đệ quy với con
                child = nextSibling[child]; // Chuyển sang anh em tiếp theo
            }
        };
        
        // Tìm gốc (nút không có cha)
        int root = -1;
        for (int i = 0; i < numNodes; i++) {
            bool hasParent = false;
            for (int j = 0; j < numNodes; j++) {
                if (firstChild[j] == i) { // Nếu i là con đầu tiên của j
                    hasParent = true;
                    break;
                }
                int sibling = firstChild[j];
                while (sibling != -1) { // Kiểm tra trong danh sách anh em
                    if (nextSibling[sibling] == i) {
                        hasParent = true;
                        break;
                    }
                    sibling = nextSibling[sibling];
                }
                if (hasParent) break;
            }
            if (!hasParent) { // Nếu không có cha, i là gốc
                root = i;
                break;
            }
        }
        
        if (root != -1) {
            dfs(root, -1); // Bắt đầu DFS từ gốc
        }
        
        return parent; // Trả về mảng cha
    }
    
    // Chuyển từ mảng cha sang danh sách kề
    vector<vector<int>> parentToAdjList(const vector<int>& parent) {
        vector<vector<int>> adjList(numNodes); // Khởi tạo danh sách kề
        
        for (int i = 0; i < numNodes; i++) {
            if (parent[i] != -1) { // Nếu nút i có cha
                adjList[parent[i]].push_back(i); // Thêm cạnh từ cha đến con
                adjList[i].push_back(parent[i]); // Thêm cạnh từ con đến cha (cây vô hướng)
            }
        }
        
        return adjList; // Trả về danh sách kề
    }
    
    // Chuyển từ danh sách kề sang mảng cha
    vector<int> adjListToParent(const vector<vector<int>>& adjList, int root = 0) {
        vector<int> parent(numNodes, -1); // Mảng cha, mặc định không có cha
        vector<bool> visited(numNodes, false); // Mảng đánh dấu nút đã thăm
        
        // Hàm DFS để xây dựng mảng cha
        function<void(int)> dfs = [&](int node) {
            visited[node] = true; // Đánh dấu nút đã thăm
            for (int neighbor : adjList[node]) { // Duyệt qua các nút kề
                if (!visited[neighbor]) { // Nếu chưa thăm
                    parent[neighbor] = node; // Gán cha của neighbor là node
                    dfs(neighbor); // Gọi đệ quy
                }
            }
        };
        
        dfs(root); // Bắt đầu DFS từ gốc
        return parent; // Trả về mảng cha
    }
    
    // In mảng cha
    void printParentArray(const vector<int>& parent) {
        cout << "Mảng cha: "; // Tiêu đề
        for (int i = 0; i < numNodes; i++) {
            cout << parent[i] << " "; // In giá trị cha của nút i
        }
        cout << endl; // Xuống dòng
    }
    
    // In biểu diễn first-child next-sibling
    void printFCNS(const vector<int>& firstChild, const vector<int>& nextSibling) {
        cout << "First Child: "; // Tiêu đề
        for (int i = 0; i < numNodes; i++) {
            cout << firstChild[i] << " "; // In con đầu tiên của nút i
        }
        cout << endl;
        
        cout << "Next Sibling: "; // Tiêu đề
        for (int i = 0; i < numNodes; i++) {
            cout << nextSibling[i] << " "; // In anh em tiếp theo của nút i
        }
        cout << endl;
    }
    
    // In cây theo dạng phân cấp (hierarchical)
    void printTree(const vector<int>& parent, int root = -1) {
        if (root == -1) { // Nếu không cung cấp gốc
            for (int i = 0; i < numNodes; i++) {
                if (parent[i] == -1) { // Tìm nút không có cha
                    root = i;
                    break;
                }
            }
        }
        
        vector<vector<int>> children(numNodes); // Danh sách con của mỗi nút
        for (int i = 0; i < numNodes; i++) {
            if (parent[i] != -1) { // Nếu nút i có cha
                children[parent[i]].push_back(i); // Thêm i vào danh sách con của cha
            }
        }
        
        // Hàm in nút theo dạng phân cấp
        function<void(int, string)> printNode = [&](int node, string indent) {
            cout << indent << node << endl; // In nút với thụt đầu dòng
            for (int child : children[node]) { // Duyệt qua các con
                printNode(child, indent + "  "); // In con với thụt đầu dòng tăng lên
            }

        };
        
        cout << "Cây hierarchy:" << endl; // Tiêu đề
        printNode(root, ""); // Bắt đầu in từ gốc
    }
};

// Hàm kiểm tra các chức năng chuyển đổi đồ thị
void testGraphConverter() {
    cout << "=== TEST GRAPH CONVERTER ===" << endl; // Tiêu đề
    
    int n = 4; // Số đỉnh
    GraphConverter converter(n); // Khởi tạo đối tượng GraphConverter
    
    // Ma trận kề mẫu
    GraphConverter::AdjMatrix matrix = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    
    // Ma trận trọng số
    vector<vector<int>> weights = {
        {0, 2, 3, 0},
        {2, 0, 1, 4},
        {3, 1, 0, 2},
        {0, 4, 2, 0}
    };
    
    cout << "=== CHUYỂN ĐỔI GIỮA CÁC DẠNG BIỂU DIỄN ĐỒ THỊ ===" << endl; // Tiêu đề
    
    // Thực hiện các chuyển đổi và in kết quả
    converter.printMatrix(matrix); // In ma trận kề
    
    auto adjList = converter.matrixToList(matrix); // Chuyển sang danh sách kề
    converter.printList(adjList); // In danh sách kề
    
    auto extList = converter.listToExtended(adjList, weights); // Chuyển sang danh sách kề mở rộng
    converter.printExtended(extList); // In danh sách kề mở rộng
    
    auto adjMap = converter.listToMap(adjList); // Chuyển sang ma trận đồ thị
    converter.printMap(adjMap); // In ma trận đồ thị
    
    // Kiểm tra tính đúng đắn
    auto matrixBack = converter.listToMatrix(adjList); // Chuyển ngược lại ma trận kề
    cout << "Ma trận sau khi chuyển đổi ngược lại:" << endl; // Tiêu đề
    converter.printMatrix(matrixBack); // In ma trận
    
    // Test đa đồ thị
    cout << "=== TEST ĐA ĐỒ THỊ ===" << endl; // Tiêu đề
    GraphConverter::AdjMatrix multigraph = {
        {0, 2, 1, 0},
        {2, 1, 3, 1},
        {1, 3, 0, 2},
        {0, 1, 2, 0}
    };
    
    cout << "Ma trận đa đồ thị:" << endl; // Tiêu đề
    converter.printMatrix(multigraph); // In ma trận đa đồ thị
    
    auto multiList = converter.multigraphMatrixToList(multigraph); // Chuyển sang danh sách kề
    cout << "Danh sách kề đa đồ thị:" << endl; // Tiêu đề
    converter.printList(multiList); // In danh sách kề
    
    auto multiMatrixBack = converter.multigraphListToMatrix(multiList); // Chuyển ngược lại ma trận
    cout << "Ma trận đa đồ thị sau chuyển đổi:" << endl; // Tiêu đề
    converter.printMatrix(multiMatrixBack); // In ma trận
}

// Hàm kiểm tra các chức năng chuyển đổi cây
void testTreeConverter() {
    cout << "=== TEST TREE CONVERTER ===" << endl; // Tiêu đề
    
    int n = 6; // Số nút
    TreeConverter treeConverter(n); // Khởi tạo đối tượng TreeConverter
    
    // Mảng cha mẫu: cây có gốc là 0
    vector<int> parent = {-1, 0, 0, 1, 1, 2}; // 0 là gốc, 1,2 là con của 0, 3,4 là con của 1, 5 là con của 2
    
    cout << "=== CHUYỂN ĐỔI GIỮA CÁC DẠNG BIỂU DIỄN CÂY ===" << endl; // Tiêu đề
    
    treeConverter.printParentArray(parent); // In mảng cha
    
    // Chuyển sang danh sách kề
    auto adjList = treeConverter.parentToAdjList(parent); // Chuyển mảng cha sang danh sách kề
    cout << "Danh sách kề của cây:" << endl; // Tiêu đề
    for (int i = 0; i < n; i++) { // In danh sách kề
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Chuyển ngược lại mảng cha
    auto parentBack = treeConverter.adjListToParent(adjList, 0); // Chuyển danh sách kề sang mảng cha
    cout << "Mảng cha sau khi chuyển đổi ngược lại: "; // Tiêu đề
    for (int p : parentBack) {
        cout << p << " "; // In mảng cha
    }
    cout << endl << endl;
    
    // Chuyển sang biểu diễn first-child next-sibling
    auto [firstChild, nextSibling] = treeConverter.parentToFCNS(parent); // Chuyển mảng cha sang FCNS
    treeConverter.printFCNS(firstChild, nextSibling); // In FCNS
    
    // In cây theo dạng phân cấp
    treeConverter.printTree(parent); // In cây dạng hierarchy
}

int main() {
    cout << "  CHƯƠNG TRÌNH CHUYỂN ĐỔI BIỂU DIỄN" << endl;
    cout << "        ĐỒ THỊ VÀ CÂY" << endl;
    
    testGraphConverter(); // Gọi hàm kiểm tra chuyển đổi đồ thị
    cout << endl;
    testTreeConverter(); // Gọi hàm kiểm tra chuyển đổi cây
    
    return 0;
}
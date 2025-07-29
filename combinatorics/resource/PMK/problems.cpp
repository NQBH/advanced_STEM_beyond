#include "problems.h" // Thêm tệp header khai báo các hàm giải bài toán.
#include "utils.h"    // Thêm tệp header chứa các hàm tiện ích.
#include "graph.h"    // Thêm tệp header chứa các lớp và cấu trúc đồ thị.

// --- Bài toán 1 ---
void find_partitions(int n, int k, int max_val, std::vector<int>& p) { // Hàm đệ quy tìm phân hoạch n thành k phần.
    if (k == 0) { // Điều kiện dừng: nếu đã tìm đủ k phần.
        if (n == 0) { // Nếu tổng các phần đúng bằng n.
            std::cout << "Phan hoach: "; // In tiêu đề.
            for (size_t i = 0; i < p.size(); ++i) { // Lặp qua các phần tử trong phân hoạch.
                std::cout << p[i] << (i == p.size() - 1 ? "" : " + "); // In phần tử và dấu cộng.
            }
            std::cout << std::endl; // Xuống dòng.
            print_diagram(p, "- Bieu do Ferrers (F)"); // In biểu đồ Ferrers.
            std::vector<int> t = get_transpose(p); // Tính phân hoạch chuyển vị.
            print_diagram(t, "- Bieu do chuyen vi (F^T)"); // In biểu đồ chuyển vị.
            std::cout << "----------------------------------------" << std::endl; // In dòng phân cách.
        }
        return; // Kết thúc nhánh đệ quy.
    }
    for (int i = std::min(n, max_val); i >= 1; --i) { // Lặp thử các giá trị cho phần tử hiện tại.
        if (n - i >= k - 1) { // Điều kiện cắt tỉa để tối ưu.
            p.push_back(i); // Thêm i vào phân hoạch hiện tại.
            find_partitions(n - i, k - 1, i, p); // Gọi đệ quy cho phần còn lại.
            p.pop_back(); // Quay lui, xóa i để thử giá trị khác.
        }
    }
}
void solve_problem_1() { // Hàm chính cho bài toán 1.
    int n, k; // Khai báo biến n và k.
    std::cout << "--- Bai toan 1: In bieu do Ferrers & chuyen vi ---" << std::endl; // In tiêu đề bài toán.
    std::cout << "Nhap n: "; // Yêu cầu nhập n.
    std::cin >> n; // Đọc n.
    std::cout << "Nhap k: "; // Yêu cầu nhập k.
    std::cin >> k; // Đọc k.
    if (n > 0 && k > 0 && n >= k) { // Kiểm tra điều kiện hợp lệ.
        std::vector<int> current_partition; // Vector lưu phân hoạch tạm thời.
        find_partitions(n, k, n - k + 1, current_partition); // Bắt đầu tìm kiếm phân hoạch.
    } else {
        std::cout << "Khong co phan hoach nao hop le." << std::endl; // In thông báo lỗi.
    }
}

// --- Bài toán 2 ---
int countPartitions(int n, int k) { // Hàm tính số phân hoạch của n thành k phần.
    if (k <= 0 || n <= 0 || k > n) return 0; // Điều kiện cơ bản, không hợp lệ.
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0)); // Bảng quy hoạch động.
    for (int i = 1; i <= n; ++i) { // Lặp qua các tổng từ 1 đến n.
        for (int j = 1; j <= k; ++j) { // Lặp qua số phần từ 1 đến k.
            if (i < j) dp[i][j] = 0; // Không thể chia i thành j phần nếu i < j.
            else if (i == j) dp[i][j] = 1; // Chỉ có 1 cách: 1 + ... + 1.
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j]; // Công thức truy hồi.
        }
    }
    return dp[n][k]; // Trả về kết quả.
}
void solve_problem_2() { // Hàm chính cho bài toán 2.
    int n, k; // Khai báo biến.
    std::cout << "\n--- Bai toan 2: So sanh p_k(n) va p_max(n,k) ---" << std::endl; // In tiêu đề.
    std::cout << "Nhap so n: "; // Yêu cầu nhập n.
    std::cin >> n; // Đọc n.
    std::cout << "Nhap so k: "; // Yêu cầu nhập k.
    std::cin >> k; // Đọc k.
    int p_k_n = countPartitions(n, k); // Tính số phân hoạch.
    std::cout << "So phan hoach cua " << n << " thanh " << k << " phan (p_k(n)): " << p_k_n << std::endl; // In kết quả 1.
    std::cout << "So phan hoach cua " << n << " co phan tu lon nhat la " << k << " (p_max(n,k)): " << p_k_n << std::endl; // In kết quả 2 (chứng minh định lý).
}

// --- Bài toán 3 ---
bool is_self_conjugate(const std::vector<int>& p) {
    if (p.empty()) return true;
    std::vector<int> transpose = get_transpose(p);
    return p == transpose;
}
void find_sc_partitions_k_parts(int n, int k, int max_val, std::vector<int>& p, int& count) {
    if (k == 0) {
        if (n == 0) {
            if (is_self_conjugate(p)) {
                count++;
                std::cout << "  - ";
                for(size_t i = 0; i < p.size(); ++i) std::cout << p[i] << (i == p.size()-1 ? "" : "+");
                std::cout << std::endl;
            }
        }
        return;
    }
    for (int i = std::min(n, max_val); i >= 1; --i) {
        if (n - i >= k - 1) {
            p.push_back(i);
            find_sc_partitions_k_parts(n - i, k - 1, i, p, count);
            p.pop_back();
        }
    }
}
void find_odd_length_partitions(int n, int max_val, std::vector<int>& p, int& count) {
     if (n == 0) {
        if (p.size() % 2 != 0) {
            count++;
        }
        return;
    }
    if (n < 0) return;
    for (int i = std::min(n, max_val); i >= 1; --i) {
        p.push_back(i);
        find_odd_length_partitions(n - i, i, p, count);
        p.pop_back();
    }
}
void find_odd_distinct_partitions(int n, int max_odd, std::vector<int>& p, int& count) {
    if (n == 0) {
        count++;
        return;
    }
    if (n < 0 || max_odd <= 0) return;
    for (int i = max_odd; i >= 1; i -= 2) {
        if (n - i >= 0) {
            p.push_back(i);
            find_odd_distinct_partitions(n - i, i - 2, p, count);
            p.pop_back();
        }
    }
}
void solve_problem_3() {
    int n, k;
    std::cout << "\n--- Bai toan 3: Phan hoach tu lien hop ---" << std::endl;
    std::cout << "Nhap n: ";
    std::cin >> n;
    std::cout << "Nhap k: ";
    std::cin >> k;
    std::cout << "(a) Cac phan hoach tu lien hop cua " << n << " co " << k << " phan:" << std::endl;
    int sc_k_count = 0;
    std::vector<int> p1;
    find_sc_partitions_k_parts(n, k, n - k + 1, p1, sc_k_count);
    if(sc_k_count == 0) std::cout << "  (khong co)" << std::endl;
    std::cout << "=> Tong so: " << sc_k_count << std::endl;
    std::cout << "\n(b) So sanh:" << std::endl;
    int odd_len_count = 0;
    std::vector<int> p2;
    find_odd_length_partitions(n, n, p2, odd_len_count);
    std::cout << "  - So phan hoach tu lien hop cua " << n << " co " << k << " phan: " << sc_k_count << std::endl;
    std::cout << "  - So phan hoach cua " << n << " thanh so le cac phan: " << odd_len_count << std::endl;
    std::cout << "\n(c) So phan hoach tu lien hop (theo dinh ly):" << std::endl;
    int odd_distinct_count = 0;
    std::vector<int> p3;
    find_odd_distinct_partitions(n, n % 2 == 0 ? n - 1 : n, p3, odd_distinct_count);
    std::cout << "  So phan hoach cua " << n << " thanh cac phan tu le va phan biet la: " << odd_distinct_count << std::endl;
}


// --- Bài toán 4 ---
using AdjacencyMatrix = std::vector<std::vector<int>>; // Định nghĩa kiểu cho ma trận kề.
using AdjacencyList = std::vector<std::list<int>>;     // Định nghĩa kiểu cho danh sách kề.
AdjacencyList matrixToList(const AdjacencyMatrix& matrix, bool is_multigraph = false) { // Hàm chuyển đổi ma trận kề sang danh sách kề.
    int V = matrix.size(); // Lấy số đỉnh.
    AdjacencyList adjList(V); // Khởi tạo danh sách kề.
    for (int i = 0; i < V; ++i) { // Lặp qua các hàng (đỉnh nguồn).
        for (int j = 0; j < V; ++j) { // Lặp qua các cột (đỉnh đích).
            if (matrix[i][j] > 0) { // Nếu có cạnh nối.
                if(is_multigraph){ // Nếu là đa đồ thị.
                    for(int k=0; k < matrix[i][j]; ++k){ // Thêm j vào k lần.
                        adjList[i].push_back(j);
                    }
                } else { // Nếu là đơn đồ thị.
                    adjList[i].push_back(j); // Thêm j vào 1 lần.
                }
            }
        }
    }
    return adjList; // Trả về danh sách kề.
}
void printAdjList(const AdjacencyList& list, const std::string& title) { // Hàm in danh sách kề.
    std::cout << title << ":" << std::endl; // In tiêu đề.
    for (size_t i = 0; i < list.size(); ++i) { // Lặp qua từng đỉnh.
        std::cout << "  adj[" << i << "] -> "; // In chỉ số đỉnh.
        for (int node : list[i]) { // Lặp qua các đỉnh kề.
            std::cout << node << " "; // In đỉnh kề.
        }
        std::cout << std::endl; // Xuống dòng.
    }
}
void printAdjMatrix(const AdjacencyMatrix& matrix, const std::string& title) { // Hàm in ma trận kề.
    std::cout << title << ":" << std::endl; // In tiêu đề.
    for (const auto& row : matrix) { // Lặp qua từng hàng.
        std::cout << "  "; // Căn lề.
        for (int val : row) { // Lặp qua từng giá trị trong hàng.
            std::cout << val << " "; // In giá trị.
        }
        std::cout << std::endl; // Xuống dòng.
    }
}
void solve_problem_4() { // Hàm chính cho bài toán 4.
    std::cout << "\n--- Bai toan 4: Chuyen doi bieu dien do thi ---" << std::endl; // In tiêu đề.
    std::cout << "\n** Truong hop Don do thi **" << std::endl; // Trường hợp 1.
    AdjacencyMatrix matrix_in = { // Ma trận kề mẫu cho đơn đồ thị.
        {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}
    };
    printAdjMatrix(matrix_in, "Ma tran ke ban dau:"); // In ma trận ban đầu.
    AdjacencyList list_out = matrixToList(matrix_in, false); // Chuyển đổi.
    printAdjList(list_out, "\nChuyen sang Danh sach ke:"); // In kết quả.
    
    std::cout << "\n** Truong hop Da do thi **" << std::endl; // Trường hợp 2.
    AdjacencyMatrix multi_matrix_in = { // Ma trận kề mẫu cho đa đồ thị.
        {0, 2, 0}, {2, 0, 3}, {0, 3, 0}
    };
    printAdjMatrix(multi_matrix_in, "Ma tran ke (da do thi) ban dau:"); // In ma trận ban đầu.
    AdjacencyList multi_list_out = matrixToList(multi_matrix_in, true); // Chuyển đổi.
    printAdjList(multi_list_out, "\nChuyen sang Danh sach ke:"); // In kết quả.
}

// --- Bài toán 5 ---
bool is_tree(const Graph& g) { // Hàm kiểm tra đồ thị có phải là cây không.
    int V = g.getV(); // Lấy số đỉnh.
    if (V == 0) return true; // Đồ thị rỗng là cây.
    std::vector<bool> visited(V, false); // Mảng đánh dấu đỉnh đã thăm.
    int edge_count = 0; // Biến đếm tổng bậc.
    int component_count = 0; // Biến đếm thành phần liên thông.
    for(int i = 0; i < V; ++i) { // Lặp qua các đỉnh.
        if(!visited[i]) { // Nếu đỉnh chưa được thăm.
            component_count++; // Tăng số thành phần liên thông.
            if(component_count > 1) return false; // Nếu > 1 thành phần -> không liên thông -> không phải cây.
            std::queue<int> q; // Dùng hàng đợi cho BFS.
            q.push(i); // Bắt đầu từ đỉnh i.
            visited[i] = true; // Đánh dấu đã thăm.
            while(!q.empty()){ // Khi hàng đợi còn phần tử.
                int u = q.front(); // Lấy đỉnh đầu hàng đợi.
                q.pop(); // Xóa đỉnh khỏi hàng đợi.
                for(const auto& edge : g.getAdj(u)){ // Lặp qua các đỉnh kề.
                    edge_count++; // Tăng tổng bậc.
                    int v = edge.first; // Lấy đỉnh kề.
                    if(!visited[v]){ // Nếu đỉnh kề chưa thăm.
                        visited[v] = true; // Đánh dấu đã thăm.
                        q.push(v); // Thêm vào hàng đợi.
                    }
                }
            }
        }
    }
    edge_count /= 2; // Số cạnh = tổng bậc / 2.
    return (edge_count == V - 1); // Cây phải có V-1 cạnh và liên thông.
}
void solve_problem_5() { // Hàm chính cho bài toán 5.
    std::cout << "\n--- Bai toan 5: Lam bai tap trong sach [Val21] ---" << std::endl; // In tiêu đề.
    std::cout << "\n** Problem 1.6: Kiem tra mot do thi co phai la cay **" << std::endl; // Bài 1.6.
    Graph tree_graph(5); // Tạo đồ thị 5 đỉnh.
    tree_graph.addEdge(0, 1); tree_graph.addEdge(0, 2); tree_graph.addEdge(1, 3); tree_graph.addEdge(1, 4); // Thêm cạnh tạo thành cây.
    std::cout << "  Kiem tra do thi 1 (la cay): " << (is_tree(tree_graph) ? "Dung" : "Sai") << std::endl; // Kiểm tra và in.
    
    std::cout << "\n** Exercise 1.7: Sinh cay nhi phan hoan chinh **" << std::endl; // Bài 1.7.
    int n_nodes = 7; // Số đỉnh.
    Graph complete_binary_tree(n_nodes); // Tạo đồ thị.
    for(int i=0; i < n_nodes; ++i){ // Lặp qua các đỉnh.
        if (2*i + 1 < n_nodes) complete_binary_tree.addEdge(i, 2*i + 1); // Nối với con trái.
        if (2*i + 2 < n_nodes) complete_binary_tree.addEdge(i, 2*i + 2); // Nối với con phải.
    }
    std::cout << "  Cay nhi phan hoan chinh voi " << n_nodes << " dinh:" << std::endl; // In thông báo.
    complete_binary_tree.print(); // In danh sách kề của cây.
}

// --- Bài toán 6 ---
namespace Problem6 { // Namespace để tránh trùng tên biến toàn cục.
    std::vector<TED_Node*> postorder_nodes1, postorder_nodes2; // Danh sách nút duyệt sau của 2 cây.
    std::vector<std::vector<int>> tree_dist_memo; // Bảng DP.
}
void postorder_traverse_and_id(TED_Node* node, std::vector<TED_Node*>& nodes, int& counter) { // Hàm duyệt sau và gán ID.
    if (!node) return; // Nếu nút rỗng, dừng.
    for (TED_Node* child : node->children) { // Duyệt các con trước.
        postorder_traverse_and_id(child, nodes, counter);
    }
    node->postorder_id = counter++; // Gán ID cho nút hiện tại.
    nodes.push_back(node); // Thêm nút vào danh sách.
}
int calculate_tree_edit_distance(TED_Node* root1, TED_Node* root2) { // Hàm tính khoảng cách sửa cây.
    using namespace Problem6; // Sử dụng namespace.
    postorder_nodes1.clear(); postorder_nodes2.clear(); // Xóa dữ liệu cũ.
    int counter = 0; // Reset biến đếm.
    postorder_traverse_and_id(root1, postorder_nodes1, counter); // Lấy danh sách nút cây 1.
    counter = 0; // Reset biến đếm.
    postorder_traverse_and_id(root2, postorder_nodes2, counter); // Lấy danh sách nút cây 2.
    int n1 = postorder_nodes1.size(); // Số nút cây 1.
    int n2 = postorder_nodes2.size(); // Số nút cây 2.
    tree_dist_memo.assign(n1 + 1, std::vector<int>(n2 + 1, 0)); // Khởi tạo bảng DP.
    for (int i = 1; i <= n1; i++) tree_dist_memo[i][0] = i; // Khởi tạo cột đầu tiên (xóa).
    for (int j = 1; j <= n2; j++) tree_dist_memo[0][j] = j; // Khởi tạo hàng đầu tiên (chèn).
    for (int i = 1; i <= n1; i++) { // Lặp qua các nút cây 1.
        for (int j = 1; j <= n2; j++) { // Lặp qua các nút cây 2.
            int cost_sub = (postorder_nodes1[i-1]->label == postorder_nodes2[j-1]->label) ? 0 : 1; // Chi phí thay thế.
            int cost_del = tree_dist_memo[i - 1][j] + 1; // Chi phí xóa.
            int cost_ins = tree_dist_memo[i][j - 1] + 1; // Chi phí chèn.
            int cost_replace = tree_dist_memo[i - 1][j - 1] + cost_sub; // Chi phí thay thế.
            tree_dist_memo[i][j] = std::min({cost_del, cost_ins, cost_replace}); // Lấy chi phí nhỏ nhất.
        }
    }
    return tree_dist_memo[n1][n2]; // Trả về kết quả cuối cùng.
}
void solve_problem_6() { // Hàm chính bài toán 6.
    std::cout << "\n--- Bai toan 6: Tree Edit Distance ---" << std::endl; // In tiêu đề.
    TED_Node* t1_a = new TED_Node("a"); TED_Node* t1_c = new TED_Node("c"); // Tạo các nút lá cây 1.
    TED_Node* t1_f = new TED_Node("f", {t1_a, t1_c}); // Tạo gốc cây 1.
    TED_Node* t2_b = new TED_Node("b"); TED_Node* t2_c = new TED_Node("c"); // Tạo các nút lá cây 2.
    TED_Node* t2_f = new TED_Node("f", {t2_b, t2_c}); // Tạo gốc cây 2.
    int distance = calculate_tree_edit_distance(t1_f, t2_f); // Tính khoảng cách.
    std::cout << "Khoang cach sua cay giua T1(f(a,c)) va T2(f(b,c)) la: " << distance << std::endl; // In kết quả.
}

// --- Bài toán 7 ---
void preorder_traversal(TreeNode* root) { // Duyệt tiền thứ tự (Gốc-Trái-Phải).
    if (root == nullptr) return; // Nếu nút rỗng, dừng.
    std::cout << root->val << " "; // Thăm gốc.
    preorder_traversal(root->left); // Duyệt cây con trái.
    preorder_traversal(root->right); // Duyệt cây con phải.
}
void inorder_traversal(TreeNode* root) { // Duyệt trung thứ tự (Trái-Gốc-Phải).
    if (root == nullptr) return; // Nếu nút rỗng, dừng.
    inorder_traversal(root->left); // Duyệt cây con trái.
    std::cout << root->val << " "; // Thăm gốc.
    inorder_traversal(root->right); // Duyệt cây con phải.
}
void postorder_traversal(TreeNode* root) { // Duyệt hậu thứ tự (Trái-Phải-Gốc).
    if (root == nullptr) return; // Nếu nút rỗng, dừng.
    postorder_traversal(root->left); // Duyệt cây con trái.
    postorder_traversal(root->right); // Duyệt cây con phải.
    std::cout << root->val << " "; // Thăm gốc.
}
void solve_problem_7() { // Hàm chính bài toán 7.
    std::cout << "\n--- Bai toan 7: Duyet Cay ---" << std::endl; // In tiêu đề.
    TreeNode* root = new TreeNode(1); // Tạo gốc.
    root->left = new TreeNode(2); root->right = new TreeNode(3); // Tạo con cấp 1.
    root->left->left = new TreeNode(4); root->left->right = new TreeNode(5); // Tạo con cấp 2.
    std::cout << "Cay nhi phan mau: (Goc 1, con trai (2 -> 4,5), con phai 3)" << std::endl; // Mô tả cây.
    std::cout << "Pre-order: "; preorder_traversal(root); std::cout << std::endl; // In duyệt tiền thứ tự.
    std::cout << "In-order:  "; inorder_traversal(root); std::cout << std::endl; // In duyệt trung thứ tự.
    std::cout << "Post-order:"; postorder_traversal(root); std::cout << std::endl; // In duyệt hậu thứ tự.
}

// --- Bài toán 8 ---
void solve_problem_8() { // Hàm chính bài toán 8.
    std::cout << "\n--- Bai toan 8: BFS tren Do thi don ---" << std::endl; // In tiêu đề.
    Graph g(4); g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 3); // Tạo đồ thị đơn.
    g.analyzeGraph(); g.BFS(0); // In đồ thị và chạy BFS.
}

// --- Bài toán 9 ---
void solve_problem_9() { // Hàm chính bài toán 9.
    std::cout << "\n--- Bai toan 9: BFS tren Da do thi ---" << std::endl; // In tiêu đề.
    Graph g(3); g.addEdge(0, 1); g.addEdge(0, 1); g.addEdge(1, 2); // Tạo đa đồ thị.
    g.analyzeGraph(); g.BFS(0); // In đồ thị và chạy BFS.
}

// --- Bài toán 10 ---
void solve_problem_10() { // Hàm chính bài toán 10.
    std::cout << "\n--- Bai toan 10: BFS tren Do thi tong quat ---" << std::endl; // In tiêu đề.
    Graph g(3); g.addEdge(0, 1); g.addEdge(1, 1); g.addEdge(1, 2); // Tạo đồ thị có khuyên.
    g.analyzeGraph(); g.BFS(0); // In đồ thị và chạy BFS.
}

// --- Bài toán 11 ---
void solve_problem_11() { // Hàm chính bài toán 11.
    std::cout << "\n--- Bai toan 11: DFS tren Do thi don ---" << std::endl; // In tiêu đề.
    Graph g(4); g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 3); // Tạo đồ thị đơn.
    g.analyzeGraph(); g.DFS(0); // In đồ thị và chạy DFS.
}

// --- Bài toán 12 ---
void solve_problem_12() { // Hàm chính bài toán 12.
    std::cout << "\n--- Bai toan 12: DFS tren Da do thi ---" << std::endl; // In tiêu đề.
    Graph g(3); g.addEdge(0, 1); g.addEdge(0, 1); g.addEdge(1, 2); // Tạo đa đồ thị.
    g.analyzeGraph(); g.DFS(0); // In đồ thị và chạy DFS.
}

// --- Bài toán 13 ---
void solve_problem_13() { // Hàm chính bài toán 13.
    std::cout << "\n--- Bai toan 13: DFS tren Do thi tong quat ---" << std::endl; // In tiêu đề.
    Graph g(3); g.addEdge(0, 1); g.addEdge(1, 1); g.addEdge(1, 2); // Tạo đồ thị có khuyên.
    g.analyzeGraph(); g.DFS(0); // In đồ thị và chạy DFS.
}

// --- Bài toán 14 ---
void solve_problem_14() {
    std::cout << "\n--- Bai toan 14: Dijkstra tren Do thi don ---" << std::endl; // In tiêu đề bài toán.
    Graph g(9); // Tạo một đồ thị có 9 đỉnh (từ 0 đến 8).

    // Thêm các cạnh có trọng số vào đồ thị để tạo thành một đồ thị đơn.
    g.addEdge(0, 1, 4); g.addEdge(0, 7, 8); // Thêm cạnh (0,1) trọng số 4, (0,7) trọng số 8.
    g.addEdge(1, 2, 8); g.addEdge(1, 7, 11); // Thêm cạnh (1,2) trọng số 8, (1,7) trọng số 11.
    g.addEdge(2, 3, 7); g.addEdge(2, 5, 4); g.addEdge(2, 8, 2); // ...
    g.addEdge(3, 4, 9); g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1); g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.analyzeGraph(); // Phân tích và in thông tin cơ bản của đồ thị.
    g.dijkstra(0); // Chạy thuật toán Dijkstra tìm đường đi ngắn nhất từ đỉnh 0.
}

// --- Bài toán 15 ---
void solve_problem_15() {
    std::cout << "\n--- Bai toan 15: Dijkstra tren Da do thi ---" << std::endl; // In tiêu đề bài toán.
    Graph g(3); // Tạo đồ thị có 3 đỉnh.
    g.addEdge(0, 1, 5); // Thêm cạnh (0,1) với trọng số 5.
    g.addEdge(0, 1, 10); // Thêm một cạnh (0,1) nữa với trọng số 10 (tạo đa đồ thị).
    g.addEdge(1, 2, 2); // Thêm cạnh (1,2) với trọng số 2.
    g.analyzeGraph(); // Phân tích và in thông tin đồ thị.
    g.dijkstra(0); // Chạy Dijkstra (sẽ tự động chọn cạnh (0,1) có trọng số nhỏ hơn là 5).
}

// --- Bài toán 16 ---
void solve_problem_16() {
    std::cout << "\n--- Bai toan 16: Dijkstra tren Do thi tong quat ---" << std::endl; // In tiêu đề bài toán.
    Graph g(3); // Tạo đồ thị có 3 đỉnh.
    g.addEdge(0, 1, 5); // Thêm cạnh (0,1) với trọng số 5.
    g.addEdge(1, 1, 10); // Thêm một khuyên (cạnh nối đỉnh 1 với chính nó) trọng số 10.
    g.addEdge(1, 2, 2); // Thêm cạnh (1,2) với trọng số 2.
    g.analyzeGraph(); // Phân tích và in thông tin đồ thị.
    g.dijkstra(0); // Chạy Dijkstra (khuyên thường không ảnh hưởng đến đường đi ngắn nhất).
}
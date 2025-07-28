#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// Cấu trúc của một nút trong cây
struct Node {
    char label;
    vector<Node*> children;
};

// --- Các biến và hàm trợ giúp ---
// Các biến này được dùng chung trong quá trình tính toán
vector<Node*> nodes1, nodes2;
vector<int> l1, l2; // Mảng lưu chỉ số lá trái nhất

// Hàm duyệt sau để lấy thứ tự các nút và tìm lá trái nhất
void preprocess_tree(Node* node, vector<Node*>& nodes, vector<int>& leftmost_leaves) {
    if (node == nullptr) return;
    
    int leftmost_idx = nodes.size();
    for (Node* child : node->children) {
        preprocess_tree(child, nodes, leftmost_leaves);
    }
    nodes.push_back(node);
    leftmost_leaves.push_back(leftmost_idx);
}

// Hàm chính tính khoảng cách chỉnh sửa cây
int tree_edit_distance(Node* root1, Node* root2) {
    // Bước 1: Tiền xử lý, lấy các thông tin cần thiết từ cây
    nodes1.clear(); l1.clear();
    preprocess_tree(root1, nodes1, l1);
    
    nodes2.clear(); l2.clear();
    preprocess_tree(root2, nodes2, l2);

    int n1 = nodes1.size();
    int n2 = nodes2.size();

    if (n1 == 0) return n2;
    if (n2 == 0) return n1;

    // Bảng quy hoạch động để lưu khoảng cách giữa các cây con
    vector<vector<int>> treedist(n1, vector<int>(n2, 0));

    // Bước 2: Điền bảng quy hoạch động
    // Duyệt qua tất cả các cặp nút từ hai cây theo thứ tự duyệt sau
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            // Tính khoảng cách giữa các rừng con của nút i và j
            int i_start = l1[i];
            int j_start = l2[j];
            
            int fn = i - i_start;
            int fm = j - j_start;
            
            vector<vector<int>> forestdist(fn + 1, vector<int>(fm + 1, 0));

            for (int p = 1; p <= fn; ++p) forestdist[p][0] = p;
            for (int q = 1; q <= fm; ++q) forestdist[0][q] = q;

            for (int p = 1; p <= fn; ++p) {
                for (int q = 1; q <= fm; ++q) {
                    int i_p = i_start + p - 1;
                    int j_q = j_start + q - 1;
                    
                    int cost_del = forestdist[p - 1][q] + 1;
                    int cost_ins = forestdist[p][q - 1] + 1;
                    
                    int cost_match = forestdist[l1[i_p] - i_start][l2[j_q] - j_start] + treedist[i_p][j_q];
                    
                    forestdist[p][q] = min({cost_del, cost_ins, cost_match});
                }
            }
            
            int relabel_cost = (nodes1[i]->label == nodes2[j]->label) ? 0 : 1;
            treedist[i][j] = relabel_cost + (fn > 0 || fm > 0 ? forestdist[fn][fm] : 0);
        }
    }
    
    // Kết quả cuối cùng là khoảng cách giữa hai cây gốc
    return treedist[n1 - 1][n2 - 1];
}


int main() {
    // Xây dựng Cây 1: f( d(a,b), e )
    Node f_t1_a = {'a'};
    Node f_t1_b = {'b'};
    Node f_t1_d = {'d', {&f_t1_a, &f_t1_b}};
    Node f_t1_e = {'e'};
    Node f_t1 = {'f', {&f_t1_d, &f_t1_e}};

    // Xây dựng Cây 2: f( c, e(d(a,b)) )
    Node f_t2_a = {'a'};
    Node f_t2_b = {'b'};
    Node f_t2_d = {'d', {&f_t2_a, &f_t2_b}};
    Node f_t2_c = {'c'};
    Node f_t2_e = {'e', {&f_t2_d}};
    Node f_t2 = {'f', {&f_t2_c, &f_t2_e}};
    
    int distance = tree_edit_distance(&f_t1, &f_t2);
    cout << "Khoang cach chinh sua giua hai cay la: " << distance << endl;
    
    return 0;
}
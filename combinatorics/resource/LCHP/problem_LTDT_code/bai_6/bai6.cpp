#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;

// Cau truc bieu dien nut cay
struct TreeNode {
    string label;
    vector<TreeNode*> children;
    int id;  // ID duy nhat cho moi nut
    
    TreeNode(string lbl, int node_id) : label(lbl), id(node_id) {}
    
    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

class TreeEditDistance {
private:
    // Ham chi phi
    int cost_substitute(const string& a, const string& b) {
        return (a == b) ? 0 : 1;
    }
    
    int cost_delete(const string& a) {
        return 1;
    }
    
    int cost_insert(const string& b) {
        return 1;
    }
    
    // Chuyen cay thanh danh sach post-order
    void getPostOrder(TreeNode* root, vector<TreeNode*>& post_order) {
        if (!root) return;
        
        for (auto child : root->children) {
            getPostOrder(child, post_order);
        }
        post_order.push_back(root);
    }
    
    // Tinh kich thuoc cay con tai moi nut
    void computeSubtreeSizes(const vector<TreeNode*>& post_order, 
                           vector<int>& subtree_sizes) {
        subtree_sizes.resize(post_order.size());
        
        for (int i = 0; i < post_order.size(); i++) {
            subtree_sizes[i] = 1;  // Chu the nut hien tai
            
            for (auto child : post_order[i]->children) {
                for (int j = 0; j < i; j++) {
                    if (post_order[j] == child) {
                        subtree_sizes[i] += subtree_sizes[j];
                        break;
                    }
                }
            }
        }
    }

public:
    // 1. Phuong phap Backtracking
    int backtrackingTED(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return 0;
        if (!t1) return cost_insert(t2->label) + 
                       sumInsertCost(t2->children);
        if (!t2) return cost_delete(t1->label) + 
                       sumDeleteCost(t1->children);
        
        int min_cost = INT_MAX;
        
        // Thay the nut goc
        int substitute_cost = cost_substitute(t1->label, t2->label);
        substitute_cost += computeChildrenCost(t1->children, t2->children);
        min_cost = min(min_cost, substitute_cost);
        
        // Xoa nut goc cua t1
        int delete_cost = cost_delete(t1->label);
        for (auto child : t1->children) {
            delete_cost += backtrackingTED(child, t2);
        }
        min_cost = min(min_cost, delete_cost);
        
        // Chen nut goc cua t2
        int insert_cost = cost_insert(t2->label);
        for (auto child : t2->children) {
            insert_cost += backtrackingTED(t1, child);
        }
        min_cost = min(min_cost, insert_cost);
        
        return min_cost;
    }
    
    // 2. Phuong phap Branch-and-bound
    int branchBoundTED(TreeNode* t1, TreeNode* t2) {
        int best_cost = INT_MAX;
        branchBoundHelper(t1, t2, 0, best_cost);
        return best_cost;
    }
    
private:
    void branchBoundHelper(TreeNode* t1, TreeNode* t2, 
                          int current_cost, int& best_cost) {
        // Uoc luong lower bound
        int lower_bound = current_cost + estimateLowerBound(t1, t2);
        
        if (lower_bound >= best_cost) {
            return;  // Cat tia
        }
        
        if (!t1 && !t2) {
            best_cost = min(best_cost, current_cost);
            return;
        }
        
        if (!t1) {
            best_cost = min(best_cost, current_cost + sumInsertCost({t2}));
            return;
        }
        
        if (!t2) {
            best_cost = min(best_cost, current_cost + sumDeleteCost({t1}));
            return;
        }
        
        // Thu cac phep bien doi
        // Thay the
        int new_cost = current_cost + cost_substitute(t1->label, t2->label);
        branchBoundChildrenHelper(t1->children, t2->children, new_cost, best_cost);
        
        // Xoa
        for (auto child : t1->children) {
            branchBoundHelper(child, t2, current_cost + cost_delete(t1->label), best_cost);
        }
        
        // Chen
        for (auto child : t2->children) {
            branchBoundHelper(t1, child, current_cost + cost_insert(t2->label), best_cost);
        }
    }
    
    int estimateLowerBound(TreeNode* t1, TreeNode* t2) {
        int size1 = countNodes(t1);
        int size2 = countNodes(t2);
        return abs(size1 - size2);
    }
    
public:
    // 3. Phuong phap Divide-and-conquer  
    int divideConquerTED(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return 0;
        if (!t1) return sumInsertCost({t2});
        if (!t2) return sumDeleteCost({t1});
        
        int min_cost = INT_MAX;
        
        // Thay the goc
        int substitute_cost = cost_substitute(t1->label, t2->label);
        substitute_cost += computeChildrenCost(t1->children, t2->children);
        min_cost = min(min_cost, substitute_cost);
        
        // Xoa goc t1
        int delete_cost = cost_delete(t1->label);
        for (auto child : t1->children) {
            delete_cost += divideConquerTED(child, t2);
        }
        min_cost = min(min_cost, delete_cost);
        
        // Chen goc t2
        int insert_cost = cost_insert(t2->label);
        for (auto child : t2->children) {
            insert_cost += divideConquerTED(t1, child);
        }
        min_cost = min(min_cost, insert_cost);
        
        return min_cost;
    }
    
    // 4. Phuong phap Dynamic Programming (Zhang-Shasha)
    int dynamicProgrammingTED(TreeNode* t1, TreeNode* t2) {
        vector<TreeNode*> post1, post2;
        getPostOrder(t1, post1);
        getPostOrder(t2, post2);
        
        if (post1.empty() && post2.empty()) return 0;
        if (post1.empty()) return post2.size();
        if (post2.empty()) return post1.size();
        
        int n = post1.size();
        int m = post2.size();
        
        vector<int> size1, size2;
        computeSubtreeSizes(post1, size1);
        computeSubtreeSizes(post2, size2);
        
        // Bang DP chinh
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Khoi tao
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + cost_delete(post1[i-1]->label);
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j-1] + cost_insert(post2[j-1]->label);
        }
        
        // Dien bang DP
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Xoa
                dp[i][j] = dp[i-1][j] + cost_delete(post1[i-1]->label);
                
                // Chen
                dp[i][j] = min(dp[i][j], 
                              dp[i][j-1] + cost_insert(post2[j-1]->label));
                
                // Thay the (neu la cay con)
                if (isAncestor(post1[i-1], post1) && isAncestor(post2[j-1], post2)) {
                    dp[i][j] = min(dp[i][j], 
                                  dp[i-1][j-1] + cost_substitute(post1[i-1]->label, 
                                                                post2[j-1]->label));
                }
            }
        }
        
        return dp[n][m];
    }
    
private:
    // Cac ham ho tro
    int sumInsertCost(const vector<TreeNode*>& nodes) {
        int total = 0;
        for (auto node : nodes) {
            total += cost_insert(node->label);
            total += sumInsertCost(node->children);
        }
        return total;
    }
    
    int sumDeleteCost(const vector<TreeNode*>& nodes) {
        int total = 0;
        for (auto node : nodes) {
            total += cost_delete(node->label);
            total += sumDeleteCost(node->children);
        }
        return total;
    }
    
    int computeChildrenCost(const vector<TreeNode*>& children1, 
                          const vector<TreeNode*>& children2) {
        // Su dung quy hoach dong don gian cho danh sach cac cay con
        int n = children1.size();
        int m = children2.size();
        
        if (n == 0) return sumInsertCost(children2);
        if (m == 0) return sumDeleteCost(children1);
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + sumDeleteCost({children1[i-1]});
        }
        for (int j = 1; j <= m; j++) {
            dp[0][j] = dp[0][j-1] + sumInsertCost({children2[j-1]});
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = min({
                    dp[i-1][j] + sumDeleteCost({children1[i-1]}),
                    dp[i][j-1] + sumInsertCost({children2[j-1]}),
                    dp[i-1][j-1] + divideConquerTED(children1[i-1], children2[j-1])
                });
            }
        }
        
        return dp[n][m];
    }
    
    void branchBoundChildrenHelper(const vector<TreeNode*>& children1,
                                  const vector<TreeNode*>& children2,
                                  int current_cost, int& best_cost) {
        int children_cost = computeChildrenCost(children1, children2);
        best_cost = min(best_cost, current_cost + children_cost);
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int count = 1;
        for (auto child : root->children) {
            count += countNodes(child);
        }
        return count;
    }
    
    bool isAncestor(TreeNode* node, const vector<TreeNode*>& post_order) {
        // Kiem tra xem node co phai la to tien cua cac nut khac khong
        // Day la ham don gian hoa, can cai dat chinh xac hon
        return true;
    }

public:
    // Ham tao cay mau de test
    TreeNode* createSampleTree1() {
        TreeNode* root = new TreeNode("A", 1);
        TreeNode* b = new TreeNode("B", 2);
        TreeNode* c = new TreeNode("C", 3);
        TreeNode* d = new TreeNode("D", 4);
        TreeNode* e = new TreeNode("E", 5);
        
        root->children = {b, c};
        b->children = {d};
        c->children = {e};
        
        return root;
    }
    
    TreeNode* createSampleTree2() {
        TreeNode* root = new TreeNode("A", 1);
        TreeNode* c = new TreeNode("C", 2);
        TreeNode* b = new TreeNode("B", 3);
        TreeNode* e = new TreeNode("E", 4);
        TreeNode* f = new TreeNode("F", 5);
        
        root->children = {c, b};
        c->children = {e, f};
        
        return root;
    }
    
    // Ham in cay
    void printTree(TreeNode* root, string indent = "", bool isLast = true) {
        if (!root) return;
        
        cout << indent;
        if (isLast) {
            cout << "└── ";
            indent += "    ";
        } else {
            cout << "├── ";
            indent += "│   ";
        }
        cout << root->label << endl;
        
        for (int i = 0; i < root->children.size(); i++) {
            bool last = (i == root->children.size() - 1);
            printTree(root->children[i], indent, last);
        }
    }
};

// Ham main de test
int main() {
    TreeEditDistance ted;
    
    // Tao hai cay mau
    TreeNode* tree1 = ted.createSampleTree1();
    TreeNode* tree2 = ted.createSampleTree2();
    
    cout << "=== TREE EDIT DISTANCE DEMO ===" << endl << endl;
    
    cout << "Cây 1:" << endl;
    ted.printTree(tree1);
    cout << endl;
    
    cout << "Cây 2:" << endl;
    ted.printTree(tree2);
    cout << endl;
    
    // Test cac phuong phap
    cout << "=== KẾT QUẢ CÁC PHƯƠNG PHÁP ===" << endl;
    
    cout << "1. Backtracking: " << ted.backtrackingTED(tree1, tree2) << endl;
    cout << "2. Branch-and-bound: " << ted.branchBoundTED(tree1, tree2) << endl;
    cout << "3. Divide-and-conquer: " << ted.divideConquerTED(tree1, tree2) << endl;
    cout << "4. Dynamic Programming: " << ted.dynamicProgrammingTED(tree1, tree2) << endl;
    
    // Giai phong bo nho
    delete tree1;
    delete tree2;
    
    return 0;
}
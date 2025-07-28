#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// Cấu trúc node cho cây nhị phân
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Cấu trúc node cho cây tổng quát
struct GeneralTreeNode {
    int data;
    vector<GeneralTreeNode*> children;
    
    GeneralTreeNode(int val) : data(val) {}
};

class TreeTraversal {
public:
    // ===== PREORDER TRAVERSAL =====
    
    // Đệ quy
    void preorderRecursive(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        result.push_back(root->data);           // Thăm gốc
        preorderRecursive(root->left, result);  // Duyệt trái
        preorderRecursive(root->right, result); // Duyệt phải
    }
    
    // Không đệ quy
    vector<int> preorderIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            
            result.push_back(node->data);
            
            // Push phải trước, trái sau (vì stack là LIFO)
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
        
        return result;
    }
    
    // ===== POSTORDER TRAVERSAL =====
    
    // Đệ quy
    void postorderRecursive(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        postorderRecursive(root->left, result);  // Duyệt trái
        postorderRecursive(root->right, result); // Duyệt phải
        result.push_back(root->data);            // Thăm gốc
    }
    
    // Không đệ quy - Phương pháp 2 stack
    vector<int> postorderIterative(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<TreeNode*> stk1, stk2;
        stk1.push(root);
        
        // Stack 1: duyệt và đẩy vào stack 2
        while (!stk1.empty()) {
            TreeNode* node = stk1.top();
            stk1.pop();
            stk2.push(node);
            
            if (node->left) stk1.push(node->left);
            if (node->right) stk1.push(node->right);
        }
        
        // Stack 2: lấy ra theo thứ tự postorder
        while (!stk2.empty()) {
            result.push_back(stk2.top()->data);
            stk2.pop();
        }
        
        return result;
    }
    
    // Không đệ quy - Phương pháp 1 stack với flag
    vector<int> postorderIterativeSingleStack(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        stack<pair<TreeNode*, bool>> stk; // bool: đã xử lý con hay chưa
        stk.push({root, false});
        
        while (!stk.empty()) {
            auto [node, processed] = stk.top();
            stk.pop();
            
            if (processed) {
                result.push_back(node->data);
            } else {
                // Đánh dấu đã xử lý và push lại
                stk.push({node, true});
                // Push con phải trước, trái sau
                if (node->right) stk.push({node->right, false});
                if (node->left) stk.push({node->left, false});
            }
        }
        
        return result;
    }
    
    // ===== TOP-DOWN TRAVERSAL =====
    
    vector<vector<int>> topDownTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->data);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
    
    // Phiên bản chỉ trả về 1 vector
    vector<int> topDownFlat(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            result.push_back(node->data);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        
        return result;
    }
    
    // ===== BOTTOM-UP TRAVERSAL =====
    
    vector<vector<int>> bottomUpTraversal(TreeNode* root) {
        vector<vector<int>> levels = topDownTraversal(root);
        reverse(levels.begin(), levels.end());
        return levels;
    }
    
    vector<int> bottomUpFlat(TreeNode* root) {
        vector<int> result;
        
        // Chuyển đổi thành bottom-up bằng cách group theo level rồi reverse
        vector<vector<int>> levels = topDownTraversal(root);
        
        for (int i = levels.size() - 1; i >= 0; i--) {
            for (int val : levels[i]) {
                result.push_back(val);
            }
        }
        
        return result;
    }
    
    // ===== CÂY TỔNG QUÁT =====
    
    // Preorder cho cây tổng quát
    void preorderGeneral(GeneralTreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        result.push_back(root->data);
        for (GeneralTreeNode* child : root->children) {
            preorderGeneral(child, result);
        }
    }
    
    // Postorder cho cây tổng quát
    void postorderGeneral(GeneralTreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        
        for (GeneralTreeNode* child : root->children) {
            postorderGeneral(child, result);
        }
        result.push_back(root->data);
    }
    
    // Level order cho cây tổng quát
    vector<vector<int>> levelOrderGeneral(GeneralTreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        
        queue<GeneralTreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                GeneralTreeNode* node = q.front();
                q.pop();
                
                currentLevel.push_back(node->data);
                
                for (GeneralTreeNode* child : node->children) {
                    q.push(child);
                }
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
    
    // ===== UTILITY FUNCTIONS =====
    
    // Tạo cây mẫu
    TreeNode* createSampleTree() {
        /*
                1
               / \
              2   3
             / \   \
            4   5   6
        */
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->right = new TreeNode(6);
        return root;
    }
    
    GeneralTreeNode* createSampleGeneralTree() {
        /*
                1
              / | \
             2  3  4
            /|    |\
           5 6    7 8
        */
        GeneralTreeNode* root = new GeneralTreeNode(1);
        root->children.push_back(new GeneralTreeNode(2));
        root->children.push_back(new GeneralTreeNode(3));
        root->children.push_back(new GeneralTreeNode(4));
        
        root->children[0]->children.push_back(new GeneralTreeNode(5));
        root->children[0]->children.push_back(new GeneralTreeNode(6));
        
        root->children[2]->children.push_back(new GeneralTreeNode(7));
        root->children[2]->children.push_back(new GeneralTreeNode(8));
        
        return root;
    }
    
    // In kết quả
    void printVector(const vector<int>& vec, const string& name) {
        cout << name << ": ";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    void printLevels(const vector<vector<int>>& levels, const string& name) {
        cout << name << ":" << endl;
        for (int i = 0; i < levels.size(); i++) {
            cout << "Level " << i << ": ";
            for (int val : levels[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
    
    // Tính chiều cao cây
    int getHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    // Đếm số node
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Kiểm tra cây có cân bằng hay không
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
    
private:
    int checkBalance(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftHeight = checkBalance(root->left);
        if (leftHeight == -1) return -1;
        
        int rightHeight = checkBalance(root->right);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) return -1;
        
        return 1 + max(leftHeight, rightHeight);
    }
};

// Hàm test toàn bộ
int main() {
    TreeTraversal traverser;
    
    cout << "=== DEMO DUYỆT CÂY NHỊ PHÂN ===" << endl;
    
    // Tạo cây mẫu
    TreeNode* root = traverser.createSampleTree();
    
    cout << "Cây mẫu:" << endl;
    cout << "        1" << endl;
    cout << "       / \\" << endl;
    cout << "      2   3" << endl;
    cout << "     / \\   \\" << endl;
    cout << "    4   5   6" << endl;
    cout << endl;
    
    // Test preorder
    vector<int> preResult;
    traverser.preorderRecursive(root, preResult);
    traverser.printVector(preResult, "Preorder (Đệ quy)");
    
    vector<int> preIter = traverser.preorderIterative(root);
    traverser.printVector(preIter, "Preorder (Không đệ quy)");
    
    // Test postorder
    vector<int> postResult;
    traverser.postorderRecursive(root, postResult);
    traverser.printVector(postResult, "Postorder (Đệ quy)");
    
    vector<int> postIter = traverser.postorderIterative(root);
    traverser.printVector(postIter, "Postorder (2 stack)");
    
    vector<int> postSingle = traverser.postorderIterativeSingleStack(root);
    traverser.printVector(postSingle, "Postorder (1 stack)");
    
    // Test level order
    vector<vector<int>> topDown = traverser.topDownTraversal(root);
    traverser.printLevels(topDown, "Top-down traversal");
    
    vector<vector<int>> bottomUp = traverser.bottomUpTraversal(root);
    traverser.printLevels(bottomUp, "Bottom-up traversal");
    
    cout << endl;
    
    // Thông tin cây
    cout << "=== THÔNG TIN CÂY ===" << endl;
    cout << "Chiều cao: " << traverser.getHeight(root) << endl;
    cout << "Số node: " << traverser.countNodes(root) << endl;
    cout << "Cân bằng: " << (traverser.isBalanced(root) ? "Có" : "Không") << endl;
    
    cout << endl;
    
    // Test cây tổng quát
    cout << "=== DEMO DUYỆT CÂY TỔNG QUÁT ===" << endl;
    
    GeneralTreeNode* genRoot = traverser.createSampleGeneralTree();
    
    cout << "Cây tổng quát mẫu:" << endl;
    cout << "        1" << endl;
    cout << "      / | \\" << endl;
    cout << "     2  3  4" << endl;
    cout << "    /|    |\\" << endl;
    cout << "   5 6    7 8" << endl;
    cout << endl;
    
    vector<int> genPre, genPost;
    traverser.preorderGeneral(genRoot, genPre);
    traverser.postorderGeneral(genRoot, genPost);
    
    traverser.printVector(genPre, "Preorder cây tổng quát");
    traverser.printVector(genPost, "Postorder cây tổng quát");
    
    vector<vector<int>> genLevels = traverser.levelOrderGeneral(genRoot);
    traverser.printLevels(genLevels, "Level order cây tổng quát");
    
    return 0;
}
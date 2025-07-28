#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <memory>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Cấu trúc TreeNode
struct TreeNode {
    string data;
    vector<shared_ptr<TreeNode>> children;
    shared_ptr<TreeNode> parent;
    
    TreeNode(const string& value) : data(value), parent(nullptr) {}
    
    void addChild(shared_ptr<TreeNode> child) {
        children.push_back(child);
        child->parent = shared_from_base();
    }
    
    shared_ptr<TreeNode> shared_from_base() {
        return shared_ptr<TreeNode>(this, [](TreeNode*) {});
    }
};

// Cấu trúc TreeNode cho binary tree (để demo rõ hơn)
struct BinaryTreeNode {
    string data;
    shared_ptr<BinaryTreeNode> left;
    shared_ptr<BinaryTreeNode> right;
    shared_ptr<BinaryTreeNode> parent;
    
    BinaryTreeNode(const string& value) 
        : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
    
    void setLeft(shared_ptr<BinaryTreeNode> child) {
        left = child;
        if (child) child->parent = shared_from_this();
    }
    
    void setRight(shared_ptr<BinaryTreeNode> child) {
        right = child;
        if (child) child->parent = shared_from_this();
    }
};

class TreeTraversal {
private:
    vector<string> traversalResult;
    
public:
    // Phương pháp 1: Preorder Traversal
    vector<string> preorderTraversal(shared_ptr<BinaryTreeNode> root) {
        cout << "=== Preorder Traversal ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        preorderHelper(root);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Thứ tự: Root -> Left -> Right" << endl;
        
        return traversalResult;
    }
    
    // Phương pháp 2: Postorder Traversal  
    vector<string> postorderTraversal(shared_ptr<BinaryTreeNode> root) {
        cout << "\n=== Postorder Traversal ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        postorderHelper(root);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Thứ tự: Left -> Right -> Root" << endl;
        
        return traversalResult;
    }
    
    // Phương pháp 3: Top-down Traversal (Level Order)
    vector<string> topDownTraversal(shared_ptr<BinaryTreeNode> root) {
        cout << "\n=== Top-down Traversal (Level Order) ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        
        if (!root) {
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            cout << "Cây rỗng" << endl;
            cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
            return traversalResult;
        }
        
        queue<shared_ptr<BinaryTreeNode>> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            shared_ptr<BinaryTreeNode> current = nodeQueue.front();
            nodeQueue.pop();
            
            traversalResult.push_back(current->data);
            
            if (current->left) {
                nodeQueue.push(current->left);
            }
            if (current->right) {
                nodeQueue.push(current->right);
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Thứ tự: Từ trên xuống dưới, từ trái sang phải theo level" << endl;
        
        return traversalResult;
    }
    
    // Phương pháp 4: Bottom-up Traversal
    vector<string> bottomUpTraversal(shared_ptr<BinaryTreeNode> root) {
        cout << "\n=== Bottom-up Traversal ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        
        if (!root) {
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            cout << "Cây rỗng" << endl;
            cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
            return traversalResult;
        }
        
        // Sử dụng stack để lưu các level
        vector<vector<string>> levels;
        queue<shared_ptr<BinaryTreeNode>> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            vector<string> currentLevel;
            
            for (int i = 0; i < levelSize; i++) {
                shared_ptr<BinaryTreeNode> current = nodeQueue.front();
                nodeQueue.pop();
                
                currentLevel.push_back(current->data);
                
                if (current->left) {
                    nodeQueue.push(current->left);
                }
                if (current->right) {
                    nodeQueue.push(current->right);
                }
            }
            
            levels.push_back(currentLevel);
        }
        
        // Đảo ngược thứ tự levels (bottom-up)
        for (int i = levels.size() - 1; i >= 0; i--) {
            for (const string& node : levels[i]) {
                traversalResult.push_back(node);
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Thứ tự: Từ dưới lên trên, từ trái sang phải theo level" << endl;
        
        return traversalResult;
    }
    
    // Phương pháp Preorder cho general tree (n-ary tree)
    vector<string> preorderGeneralTree(shared_ptr<TreeNode> root) {
        cout << "\n=== Preorder Traversal - General Tree ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        preorderGeneralHelper(root);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Thứ tự: Root -> Children (left to right)" << endl;
        
        return traversalResult;
    }
    
    // Phương pháp Postorder cho general tree
    vector<string> postorderGeneralTree(shared_ptr<TreeNode> root) {
        cout << "\n=== Postorder Traversal - General Tree ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        postorderGeneralHelper(root);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Thứ tự: Children (left to right) -> Root" << endl;
        
        return traversalResult;
    }

private:
    // Helper functions
    void preorderHelper(shared_ptr<BinaryTreeNode> node) {
        if (!node) return;
        
        // Process current node (Root)
        traversalResult.push_back(node->data);
        
        // Traverse left subtree
        preorderHelper(node->left);
        
        // Traverse right subtree
        preorderHelper(node->right);
    }
    
    void postorderHelper(shared_ptr<BinaryTreeNode> node) {
        if (!node) return;
        
        // Traverse left subtree
        postorderHelper(node->left);
        
        // Traverse right subtree
        postorderHelper(node->right);
        
        // Process current node (Root)
        traversalResult.push_back(node->data);
    }
    
    void preorderGeneralHelper(shared_ptr<TreeNode> node) {
        if (!node) return;
        
        // Process current node (Root)
        traversalResult.push_back(node->data);
        
        // Traverse all children
        for (auto child : node->children) {
            preorderGeneralHelper(child);
        }
    }
    
    void postorderGeneralHelper(shared_ptr<TreeNode> node) {
        if (!node) return;
        
        // Traverse all children first
        for (auto child : node->children) {
            postorderGeneralHelper(child);
        }
        
        // Process current node (Root)
        traversalResult.push_back(node->data);
    }
    
public:
    // Iterative versions (non-recursive)
    vector<string> preorderIterative(shared_ptr<BinaryTreeNode> root) {
        cout << "\n=== Preorder Traversal (Iterative) ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        
        if (!root) {
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            cout << "Cây rỗng" << endl;
            cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
            return traversalResult;
        }
        
        stack<shared_ptr<BinaryTreeNode>> nodeStack;
        nodeStack.push(root);
        
        while (!nodeStack.empty()) {
            shared_ptr<BinaryTreeNode> current = nodeStack.top();
            nodeStack.pop();
            
            traversalResult.push_back(current->data);
            
            // Push right first, then left (vì stack là LIFO)
            if (current->right) {
                nodeStack.push(current->right);
            }
            if (current->left) {
                nodeStack.push(current->left);
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Phương pháp: Iterative sử dụng Stack" << endl;
        
        return traversalResult;
    }
    
    vector<string> postorderIterative(shared_ptr<BinaryTreeNode> root) {
        cout << "\n=== Postorder Traversal (Iterative) ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        traversalResult.clear();
        
        if (!root) {
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(end - start);
            cout << "Cây rỗng" << endl;
            cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
            return traversalResult;
        }
        
        stack<shared_ptr<BinaryTreeNode>> nodeStack;
        shared_ptr<BinaryTreeNode> current = root;
        shared_ptr<BinaryTreeNode> lastVisited = nullptr;
        
        while (current || !nodeStack.empty()) {
            if (current) {
                nodeStack.push(current);
                current = current->left;
            } else {
                shared_ptr<BinaryTreeNode> peekNode = nodeStack.top();
                
                if (peekNode->right && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    traversalResult.push_back(peekNode->data);
                    lastVisited = nodeStack.top();
                    nodeStack.pop();
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Kết quả: ";
        for (const string& node : traversalResult) {
            cout << node << " ";
        }
        cout << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Phương pháp: Iterative sử dụng Stack với lastVisited" << endl;
        
        return traversalResult;
    }
};

// Utility functions
shared_ptr<BinaryTreeNode> createSampleBinaryTree() {
    auto root = make_shared<BinaryTreeNode>("A");
    auto b = make_shared<BinaryTreeNode>("B");
    auto c = make_shared<BinaryTreeNode>("C");
    auto d = make_shared<BinaryTreeNode>("D");
    auto e = make_shared<BinaryTreeNode>("E");
    auto f = make_shared<BinaryTreeNode>("F");
    auto g = make_shared<BinaryTreeNode>("G");
    
    root->setLeft(b);
    root->setRight(c);
    b->setLeft(d);
    b->setRight(e);
    c->setLeft(f);
    c->setRight(g);
    
    return root;
}

shared_ptr<TreeNode> createSampleGeneralTree() {
    auto root = make_shared<TreeNode>("A");
    auto b = make_shared<TreeNode>("B");
    auto c = make_shared<TreeNode>("C");
    auto d = make_shared<TreeNode>("D");
    auto e = make_shared<TreeNode>("E");
    auto f = make_shared<TreeNode>("F");
    auto g = make_shared<TreeNode>("G");
    
    root->addChild(b);
    root->addChild(c);
    root->addChild(d);
    b->addChild(e);
    b->addChild(f);
    c->addChild(g);
    
    return root;
}

void printBinaryTree(shared_ptr<BinaryTreeNode> root, int space = 0) {
    const int COUNT = 4;
    if (!root) return;
    
    space += COUNT;
    
    printBinaryTree(root->right, space);
    
    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->data << endl;
    
    printBinaryTree(root->left, space);
}

void printGeneralTree(shared_ptr<TreeNode> root, int level = 0) {
    if (!root) return;
    
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << root->data << endl;
    
    for (auto child : root->children) {
        printGeneralTree(child, level + 1);
    }
}

int main() {
    cout << "=== TREE TRAVERSAL ALGORITHMS ===" << endl;
    cout << "Triển khai 4 phương pháp duyệt cây: Preorder, Postorder, Top-down, Bottom-up\n" << endl;
    
    // Tạo cây mẫu
    auto binaryTree = createSampleBinaryTree();
    auto generalTree = createSampleGeneralTree();
    
    cout << "Binary Tree Structure:" << endl;
    printBinaryTree(binaryTree);
    cout << endl;
    
    cout << "General Tree Structure:" << endl;
    printGeneralTree(generalTree);
    cout << endl;
    
    TreeTraversal traverser;
    
    // Test các phương pháp duyệt cho binary tree
    traverser.preorderTraversal(binaryTree);
    traverser.postorderTraversal(binaryTree);
    traverser.topDownTraversal(binaryTree);
    traverser.bottomUpTraversal(binaryTree);
    
    // Test phiên bản iterative
    traverser.preorderIterative(binaryTree);
    traverser.postorderIterative(binaryTree);
    
    // Test cho general tree
    traverser.preorderGeneralTree(generalTree);
    traverser.postorderGeneralTree(generalTree);
    
    cout << "\n=== KẾT QUẢ TỔNG KẾT ===" << endl;
    cout << "Tất cả 4 phương pháp duyệt cây đã được triển khai thành công!" << endl;
    cout << "- Preorder: Root -> Left -> Right" << endl;
    cout << "- Postorder: Left -> Right -> Root" << endl;
    cout << "- Top-down: Level by level từ trên xuống" << endl;
    cout << "- Bottom-up: Level by level từ dưới lên" << endl;
    
    return 0;
}
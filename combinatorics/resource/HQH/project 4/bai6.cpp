#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    char data;
    vector<TreeNode*> children;
    
    TreeNode(char val) : data(val) {}
};

class Tree {
private:
    TreeNode* root;
    map<char, TreeNode*> nodes;
    
public:
    Tree() : root(nullptr) {}
    
    // Xây d?ng cây t? input
    void buildTree() {
        cout << "Nhap cay theo dinh dang: node so_con danh_sach_con" << endl;
        cout << "Vi du: a 2 b c" << endl;
        cout << "       b 0" << endl;
        cout << "       c 1 d" << endl;
        cout << "       d 0" << endl;
        cout << "Nhap 'end' de ket thuc nhap:" << endl;
        
        string line;
        bool isFirst = true;
        
        while (getline(cin, line) && line != "end") {
            if (line.empty()) continue;
            
            stringstream ss(line);
            char nodeName;
            int numChildren;
            
            ss >> nodeName >> numChildren;
            
            // T?o node n?u chua t?n t?i
            if (nodes.find(nodeName) == nodes.end()) {
                nodes[nodeName] = new TreeNode(nodeName);
            }
            
            // Ð?t root là node d?u tiên du?c nh?p
            if (isFirst) {
                root = nodes[nodeName];
                isFirst = false;
            }
            
            // Thêm các con
            for (int i = 0; i < numChildren; i++) {
                char childName;
                ss >> childName;
                
                if (nodes.find(childName) == nodes.end()) {
                    nodes[childName] = new TreeNode(childName);
                }
                
                nodes[nodeName]->children.push_back(nodes[childName]);
            }
        }
    }
    
    // S? d?ng sample tree
    void buildSampleTree() {
        // T?o sample tree:
        //       a
        //     /   \
        //    b     c
        //         / \
        //        d   e
        //           /
        //          f
        
        root = new TreeNode('a');
        TreeNode* b = new TreeNode('b');
        TreeNode* c = new TreeNode('c');
        TreeNode* d = new TreeNode('d');
        TreeNode* e = new TreeNode('e');
        TreeNode* f = new TreeNode('f');
        
        root->children.push_back(b);
        root->children.push_back(c);
        c->children.push_back(d);
        c->children.push_back(e);
        e->children.push_back(f);
        
        nodes['a'] = root;
        nodes['b'] = b;
        nodes['c'] = c;
        nodes['d'] = d;
        nodes['e'] = e;
        nodes['f'] = f;
        
        cout << "Sample tree created:" << endl;
        cout << "       a" << endl;
        cout << "     /   \\" << endl;
        cout << "    b     c" << endl;
        cout << "         / \\" << endl;
        cout << "        d   e" << endl;
        cout << "           /" << endl;
        cout << "          f" << endl << endl;
    }
    
    // (a) Preorder Traversal: Root -> Left -> Right
    void preorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        
        cout << node->data << " ";
        
        for (TreeNode* child : node->children) {
            preorderTraversal(child);
        }
    }
    
    // (b) Postorder Traversal: Left -> Right -> Root
    void postorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        
        for (TreeNode* child : node->children) {
            postorderTraversal(child);
        }
        
        cout << node->data << " ";
    }
    
    // (c) Top-down Traversal (Level-order/BFS)
    void topDownTraversal() {
        if (root == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            for (TreeNode* child : current->children) {
                q.push(child);
            }
        }
    }
    
    // (d) Bottom-up Traversal (Reverse level-order)
    void bottomUpTraversal() {
        if (root == nullptr) return;
        
        vector<char> result;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            result.push_back(current->data);
            
            for (TreeNode* child : current->children) {
                q.push(child);
            }
        }
        
        // In ngu?c l?i
        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }
    
    void runAllTraversals() {
        if (root == nullptr) {
            cout << "Cay rong!" << endl;
            return;
        }
        
        cout << "=== CAC PHUONG THUC DUYET CAY ===" << endl;
        
        cout << "a) Preorder Traversal (Root-Left-Right): ";
        preorderTraversal(root);
        cout << endl;
        
        cout << "b) Postorder Traversal (Left-Right-Root): ";
        postorderTraversal(root);
        cout << endl;
        
        cout << "c) Top-down Traversal (Level-order): ";
        topDownTraversal();
        cout << endl;
        
        cout << "d) Bottom-up Traversal (Reverse level-order): ";
        bottomUpTraversal();
        cout << endl;
    }
    
    // Hi?n th? c?u trúc cây
    void displayTree(TreeNode* node, string prefix = "", bool isLast = true) {
        if (node == nullptr) return;
        
        cout << prefix;
        cout << (isLast ? "+-- " : "+-- ");
        cout << node->data << endl;
        
        for (size_t i = 0; i < node->children.size(); i++) {
            bool isLastChild = (i == node->children.size() - 1);
            displayTree(node->children[i], 
                       prefix + (isLast ? "    " : "¦   "), 
                       isLastChild);
        }
    }
    
    void printTreeStructure() {
        cout << "\n=== CAU TRUC CAY ===" << endl;
        displayTree(root);
        cout << endl;
    }
    
    // Destructor d? gi?i phóng b? nh?
    void destroyTree(TreeNode* node) {
        if (node == nullptr) return;
        for (TreeNode* child : node->children) {
            destroyTree(child);
        }
        delete node;
    }
    
    ~Tree() {
        destroyTree(root);
    }
};

int main() {
    Tree tree;
    int choice;
    
    cout << "=== CHUONG TRINH DUYET CAY ===" << endl;
    cout << "1. Su dung sample tree co san" << endl;
    cout << "2. Nhap tree tu ban phim" << endl;
    cout << "Chon lua chon (1/2): ";
    cin >> choice;
    cin.ignore(); // Xóa newline sau khi nhap so
    
    if (choice == 1) {
        tree.buildSampleTree();
    } else {
        tree.buildTree();
    }
    
    tree.printTreeStructure();
    tree.runAllTraversals();
    
    return 0;
}

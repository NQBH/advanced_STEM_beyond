#include <iostream>
#include <queue>

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

class CompleteBinaryTree {
private:
    Node* root;

public:
    CompleteBinaryTree() : root(nullptr) {}

    void buildTree(int n) {
        if (n == 0) return;
        root = new Node(1);
        std::queue<Node*> q;
        q.push(root);
        int count = 1;

        while (count < n) {
            Node* current = q.front();
            q.pop();

            if (count < n) {
                current->left = new Node(++count);
                q.push(current->left);
            }
            if (count < n) {
                current->right = new Node(++count);
                q.push(current->right);
            }
        }
    }

    void printLevelOrder() {
        if (!root) return;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->val << " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        std::cout << "\n";
    }
};

int main() {
    int n;
    std::cout << "Nhập số nút n: ";
    std::cin >> n;

    CompleteBinaryTree tree;
    tree.buildTree(n);

    std::cout << "Cây nhị phân đầy đủ (duyệt theo tầng):\n";
    tree.printLevelOrder();

    return 0;
}
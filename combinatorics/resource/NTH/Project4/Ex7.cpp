#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Cấu trúc của một nút trong cây
struct Node {
    char data;
    vector<Node*> children;
};

// Hàm tạo nút mới để code gọn hơn
Node* newNode(char data) {
    Node* node = new Node();
    node->data = data;
    return node;
}

// (a) Duyệt Tiền thứ tự (Preorder Traversal)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " "; // 1. Thăm gốc
    for (Node* child : root->children) {
        preorder(child); // 2. Duyệt các con
    }
}

// (b) Duyệt Hậu thứ tự (Postorder Traversal)
void postorder(Node* root) {
    if (root == nullptr) return;
    for (Node* child : root->children) {
        postorder(child); // 1. Duyệt các con
    }
    cout << root->data << " "; // 2. Thăm gốc
}

// (c) Duyệt từ trên xuống (Top-down / Level-order)
void top_down(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        for (Node* child : current->children) {
            q.push(child);
        }
    }
}

// (d) Duyệt từ dưới lên (Bottom-up)
void bottom_up(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);

    // Bước 1: Duyệt BFS và đẩy các nút vào stack
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        s.push(current);

        // Chú ý: duyệt con từ phải sang trái để khi lấy ra từ stack sẽ đúng thứ tự
        for (auto it = current->children.rbegin(); it != current->children.rend(); ++it) {
             q.push(*it);
        }
    }

    // Bước 2: Lấy các nút ra khỏi stack và in
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}


int main() {
    // Xây dựng cây ví dụ
    Node* root = newNode('F');
    root->children.push_back(newNode('B'));
    root->children.push_back(newNode('G'));
    root->children.push_back(newNode('I'));
    
    root->children[0]->children.push_back(newNode('A'));
    root->children[0]->children.push_back(newNode('D'));
    
    root->children[0]->children[1]->children.push_back(newNode('C'));
    root->children[0]->children[1]->children.push_back(newNode('E'));

    root->children[2]->children.push_back(newNode('H'));

    cout << "Duyet Tien thu tu (Preorder):  ";
    preorder(root);
    cout << endl;

    cout << "Duyet Hau thu tu (Postorder):  ";
    postorder(root);
    cout << endl;

    cout << "Duyet Tu tren xuong (Top-down): ";
    top_down(root);
    cout << endl;

    cout << "Duyet Tu duoi len (Bottom-up): ";
    bottom_up(root);
    cout << endl;
    
    // Lưu ý: Cần có hàm giải phóng bộ nhớ cho cây trong ứng dụng thực tế
    return 0;
}
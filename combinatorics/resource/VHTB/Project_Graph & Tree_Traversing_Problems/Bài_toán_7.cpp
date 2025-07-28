#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    string label;
    vector<Node*> children;
    Node(string l) : label(l) {}
};

void preorder(Node* node, vector<string>& result) {
    if (!node) return;
    result.push_back(node->label);
    for (Node* c : node->children)
        preorder(c, result);
}

void postorder(Node* node, vector<string>& result) {
    if (!node) return;
    for (Node* c : node->children)
        postorder(c, result);
    result.push_back(node->label);
}

vector<string> top_down(Node* root) {
    vector<string> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        res.push_back(cur->label);
        for (Node* c : cur->children)
            q.push(c);
    }
    return res;
}

vector<string> bottom_up(Node* root) {
    vector<vector<string>> levels;
    if (!root) return {};
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<string> level;
        while (sz--) {
            Node* cur = q.front(); q.pop();
            level.push_back(cur->label);
            for (Node* c : cur->children)
                q.push(c);
        }
        levels.push_back(level);
    }
    reverse(levels.begin(), levels.end());
    vector<string> res;
    for (auto& lvl : levels)
        for (auto& label : lvl)
            res.push_back(label);
    return res;
}

int main() {
    Node* T = new Node("A");
    T->children.push_back(new Node("B"));
    T->children.push_back(new Node("C"));
    T->children[0]->children.push_back(new Node("D"));
    T->children[0]->children.push_back(new Node("E"));
    T->children[1]->children.push_back(new Node("F"));

    vector<string> pre, post;
    preorder(T, pre);
    postorder(T, post);
    auto top = top_down(T);
    auto bottom = bottom_up(T);

    cout << "Preorder: ";
    for (auto& s : pre) cout << s << " "; cout << "\n";

    cout << "Postorder: ";
    for (auto& s : post) cout << s << " "; cout << "\n";

    cout << "Top-down: ";
    for (auto& s : top) cout << s << " "; cout << "\n";

    cout << "Bottom-up: ";
    for (auto& s : bottom) cout << s << " "; cout << "\n";

    return 0;
}

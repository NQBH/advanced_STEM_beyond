#include <bits/stdc++.h>
using namespace std;

struct Node {
    string val;
    vector<Node*> children;
    Node(string v) : val(v) {}
};

unordered_map<string, Node*> nodes;

//(a) Preorder: Node -> Children
void preorder(Node* root) {
    if (!root) return;
    cout<<root->val<<" ";
    for (auto child : root->children) preorder(child);
}

//(b) Postorder: Children -> Node
void postorder(Node* root) {
    if (!root) return;
    for (auto child : root->children) postorder(child);
    cout<<root->val<<" ";
}

//(c) Top-down traversal (level order)
void topDown(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* cur=q.front(); q.pop();
        cout<<cur->val<< " ";
        for (auto child : cur->children) q.push(child);
    }
}

//(d) Bottom-up traversal (reverse level order)
void bottomUp(Node* root) {
    if (!root) return;
    queue<Node*> q;
    vector<vector<string>> levels;
    q.push(root);
    while (!q.empty()) {
        int sz=q.size();
        vector<string> level;
        for (int i=0; i<sz; ++i) {
            Node* cur=q.front(); q.pop();
            level.push_back(cur->val);
            for (auto child : cur->children) q.push(child);
        }
        levels.push_back(level);
    }
    reverse(levels.begin(), levels.end());
    for (auto& level : levels)
        for (string& val : level) cout<<val<<" ";
}

int main() {
    int m;
    cin>>m;

    vector<pair<string, string>> edges;
    unordered_set<string> children_set;

    //nhập cạnh cha->con
    for (int i=0; i<m; ++i) {
        string u, v;
        cin>>u>>v;
        edges.emplace_back(u, v);
        children_set.insert(v);

        if (!nodes[u]) nodes[u]=new Node(u);
        if (!nodes[v]) nodes[v]=new Node(v);
        nodes[u]->children.push_back(nodes[v]);
    }

    //tìm root
    Node* root=nullptr;
    for (auto&[label, node] : nodes) {
        if (!children_set.count(label)) {
            root=node;
            break;
        }
    }

    if (!root) {
        cout<<"Khong tim thay root.";
        return 1;
    }

    cout<<"\n(a) Preorder  : ";
    preorder(root); cout<<"\n";

    cout<<"(b) Postorder : ";
    postorder(root); cout<<"\n";

    cout<<"(c) Top-down  : ";
    topDown(root); cout<<"\n";

    cout<<"(d) Bottom-up : ";
    bottomUp(root); cout<<"\n";

    return 0;
}
/*
5
A B
A C
A D
C E
C F

   A
 / | \
B  C  D
  / \
 E   F
*/

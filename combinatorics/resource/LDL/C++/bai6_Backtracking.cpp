#include <bits/stdc++.h>
using namespace std;

// Cau truc nut cay
struct TreeNode {
    int id;
    vector<TreeNode*> children;
    TreeNode(int _id) : id(_id) {}
};

// Xay dung cay tu mang cha
TreeNode* build_tree(const vector<int>& parents) {
    int n = parents.size();
    vector<TreeNode*> nodes(n, nullptr);
    TreeNode* root = nullptr;

    for (int i = 0; i < n; i++) {
        if (!nodes[i]) nodes[i] = new TreeNode(i);
        int p = parents[i];
        if (p == -1) {
            root = nodes[i];
        } else {
            if (!nodes[p]) nodes[p] = new TreeNode(p);
            nodes[p]->children.push_back(nodes[i]);
        }
    }
    return root;
}

// Ham tinh substitution cost
int substitution_cost(TreeNode* a, TreeNode* b) {
    if (a == nullptr && b == nullptr) return 0;
    if (a == nullptr || b == nullptr) return 1;
    return 0; // khong tinh doi ten nut
}

// De quy tinh tree edit distance
int compute(TreeNode* node1, TreeNode* node2) {
    if (!node1 && !node2) return 0;
    if (!node1) {
        // Them nut moi cho toan bo cay node2
        int sum = 1;
        for (auto child : node2->children)
            sum += compute(nullptr, child);
        return sum;
    }
    if (!node2) {
        // Xoa nut va tat ca con
        int sum = 1;
        for (auto child : node1->children)
            sum += compute(child, nullptr);
        return sum;
    }

    int cost = substitution_cost(node1, node2);
    auto& c1 = node1->children;
    auto& c2 = node2->children;
    int n = (int)c1.size();
    int m = (int)c2.size();

    int min_cost = INT_MAX;

    // Dung ham de quy long nhau giong Python align
    function<void(int,int,int)> align = [&](int i, int j, int acc) {
        if (i == n && j == m) {
            min_cost = min(min_cost, acc);
            return;
        }
        if (i == n) {
            int extra = 0;
            for (int k = j; k < m; k++) extra += compute(nullptr, c2[k]);
            min_cost = min(min_cost, acc + extra);
            return;
        }
        if (j == m) {
            int extra = 0;
            for (int k = i; k < n; k++) extra += compute(c1[k], nullptr);
            min_cost = min(min_cost, acc + extra);
            return;
        }

        // 1. Ghép cap (match)
        align(i + 1, j + 1, acc + compute(c1[i], c2[j]));
        // 2. Xoa c1[i]
        align(i + 1, j, acc + compute(c1[i], nullptr));
        // 3. Chen c2[j]
        align(i, j + 1, acc + compute(nullptr, c2[j]));
    };

    align(0, 0, 0);
    return cost + min_cost;
}

int tree_edit_distance(TreeNode* t1, TreeNode* t2) {
    return compute(t1, t2);
}

// Doc mang cha tu input
vector<int> read_parents(const string& prompt) {
    cout << prompt << "\n";
    cout << "Nhap mang cha (root = -1): ";
    string line;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // xoa bo dem
    getline(cin, line);
    stringstream ss(line);
    vector<int> parents;
    int x;
    while (ss >> x) parents.push_back(x);
    return parents;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Doc mang cha cua cay 1
    cout << "Cay thu nhat:\n";
    string line1;
    getline(cin, line1);
    stringstream ss1(line1);
    vector<int> parents1;
    int tmp;
    while (ss1 >> tmp) parents1.push_back(tmp);

    // Doc mang cha cua cay 2
    cout << "Cay thu hai:\n";
    string line2;
    getline(cin, line2);
    stringstream ss2(line2);
    vector<int> parents2;
    while (ss2 >> tmp) parents2.push_back(tmp);

    TreeNode* root1 = build_tree(parents1);
    TreeNode* root2 = build_tree(parents2);

    int dist = tree_edit_distance(root1, root2);
    cout << "\nTree edit distance: " << dist << "\n";
    return 0;
}
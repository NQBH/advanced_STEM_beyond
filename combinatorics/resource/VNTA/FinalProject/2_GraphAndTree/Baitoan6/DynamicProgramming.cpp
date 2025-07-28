#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;
    Node(int id) : id(id) {}
};

using Tree = unordered_map<int, Node*>;
using GammaFunc = function<int(Node*, Node*)>;

Tree buildTree(const vector<pair<int, int>>& edges, int& root) {
    Tree nodes;
    unordered_set<int> children;
    for (auto [u, v] : edges) {
        if (!nodes[u]) nodes[u] = new Node(u);
        if (!nodes[v]) nodes[v] = new Node(v);
        nodes[u]->children.push_back(nodes[v]);
        children.insert(v);
    }
    for (auto& [id, node] : nodes) {
        if (children.find(id) == children.end()) {
            root = id;
            break;
        }
    }
    return nodes;
}

// Substitution cost = 1
int gamma_sub1(Node* a, Node* b) {
    if (!a && !b) return 0;
    if (!a || !b) return 1;
    return a->id == b->id ? 0 : 1;
}

// Substitution cost = 0
int gamma_sub0(Node* a, Node* b) {
    if (!a && !b) return 0;
    if (!a || !b) return 1;
    return 0;
}

// DP
unordered_map<Node*, unordered_map<Node*, int>> memo;

int dp(Node* t1, Node* t2, GammaFunc gamma) {
    if (memo.count(t1) && memo[t1].count(t2)) return memo[t1][t2];
    if (!t1 && !t2) return 0;
    if (!t1) {
        int cost = 1;
        for (auto c : t2->children)
            cost += dp(nullptr, c, gamma);
        return memo[t1][t2] = cost;
    }
    if (!t2) {
        int cost = 1;
        for (auto c : t1->children)
            cost += dp(c, nullptr, gamma);
        return memo[t1][t2] = cost;
    }

    int cost = gamma(t1, t2);
    int n = t1->children.size(), m = t2->children.size();
    vector<vector<int>> subdp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j) {
            if (i == 0 && j == 0) subdp[i][j] = 0;
            else if (i == 0) subdp[i][j] = subdp[i][j - 1] + dp(nullptr, t2->children[j - 1], gamma);
            else if (j == 0) subdp[i][j] = subdp[i - 1][j] + dp(t1->children[i - 1], nullptr, gamma);
            else {
                int subCost = dp(t1->children[i - 1], t2->children[j - 1], gamma);
                int delCost = dp(t1->children[i - 1], nullptr, gamma);
                int insCost = dp(nullptr, t2->children[j - 1], gamma);
                subdp[i][j] = min({subdp[i - 1][j - 1] + subCost,
                                   subdp[i - 1][j] + delCost,
                                   subdp[i][j - 1] + insCost});
            }
        }

    return memo[t1][t2] = cost + subdp[n][m];
}

int main() {
    int n1, n2; // Số cạnh t1, t2
    vector<pair<int, int>> edges1, edges2;

    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        int u, v; cin >> u >> v;
        edges1.emplace_back(u, v);
    }

    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        int u, v; cin >> u >> v;
        edges2.emplace_back(u, v);
    }

    int root1, root2;
    Tree T1 = buildTree(edges1, root1);
    Tree T2 = buildTree(edges2, root2);

    int dp_1 = dp(T1[root1], T2[root2], gamma_sub1);
    memo.clear();
    int dp_0 = dp(T1[root1], T2[root2], gamma_sub0);
    cout << "\n===Dynamic Programing===";
    cout << "\nSubstitution cost = 1: " << dp_1;
    cout << "\nSubstitution cost = 0: " << dp_0;

    for (auto& [id, node] : T1) delete node;
    for (auto& [id, node] : T2) delete node;
    return 0;
}


/*
8
1 2
1 3
1 4
2 5
2 6
4 7
5 8
6 9
8
10 20
10 30
10 40
10 50
20 60
30 70
30 80
80 90
*/

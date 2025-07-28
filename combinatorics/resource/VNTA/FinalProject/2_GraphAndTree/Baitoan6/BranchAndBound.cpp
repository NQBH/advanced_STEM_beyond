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

int countNodes(Node* node) {
    if (!node) return 0;
    int count = 1;
    for (auto child : node->children) {
        count += countNodes(child);
    }
    return count;
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

// lb: min cost còn lại nếu chọn nhánh hiện tại
// Nếu chi phí hiện tại + lb >= minCost => prune
int computeLowerBound(const vector<Node*>& c1, const vector<Node*>& c2,
                      int i, int j, GammaFunc gamma) {
    int n1 = c1.size() - i; // số con còn lại của t1 cần xử lý
    int n2 = c2.size() - j; // số con còn lại của t2 cần xử lý

    if (n1 == 0 && n2 == 0) return 0;
    if (n1 == 0) {
        int cost = 0;
        for (int k = j; k < c2.size(); k++) {
            cost += 1 + countNodes(c2[k]) - 1;
        }
        return cost;
    }
    if (n2 == 0) {
        int cost = 0;
        for (int k = i; k < c1.size(); k++) {
            cost += 1 + countNodes(c1[k]) - 1;
        }
        return cost;
    }

    return abs(n1 - n2);
}

int branchAndBoundPure(Node* t1, Node* t2, GammaFunc gamma) {
    if (!t1 && !t2) return 0;
    if (!t1) {
        int cost = 1;
        for (auto c : t2->children)
            cost += branchAndBoundPure(nullptr, c, gamma);
        return cost;
    }
    if (!t2) {
        int cost = 1;
        for (auto c : t1->children)
            cost += branchAndBoundPure(c, nullptr, gamma);
        return cost;
    }

    int cost = gamma(t1, t2);
    auto& c1 = t1->children;
    auto& c2 = t2->children;
    int n = c1.size(), m = c2.size();

    if (n == 0 && m == 0) return cost;

    int minCost = INT_MAX;

    function<void(int, int, int)> tryAlign = [&](int i, int j, int currentCost) {
        int lowerBound = currentCost + computeLowerBound(c1, c2, i, j, gamma);
        if (lowerBound >= minCost) return; // prune

        if (i == n && j == m) {
            minCost = min(minCost, currentCost);
            return;
        }

        if (i == n) {
            int insertCost = currentCost;
            for (int k = j; k < m; k++)
                insertCost += branchAndBoundPure(nullptr, c2[k], gamma);
            minCost = min(minCost, insertCost);
            return;
        }

        if (j == m) {
            int deleteCost = currentCost;
            for (int k = i; k < n; k++)
                deleteCost += branchAndBoundPure(c1[k], nullptr, gamma);
            minCost = min(minCost, deleteCost);
            return;
        }

        // 1. Substitute
        tryAlign(i + 1, j + 1, currentCost + branchAndBoundPure(c1[i], c2[j], gamma));
        // 2. Delete
        tryAlign(i + 1, j, currentCost + branchAndBoundPure(c1[i], nullptr, gamma));
        // 3. Insert
        tryAlign(i, j + 1, currentCost + branchAndBoundPure(nullptr, c2[j], gamma));
    };

    tryAlign(0, 0, 0);
    return cost + minCost;
}

int main() {
    int n1, n2;
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

    int root1 = -1, root2 = -1;
    Tree T1 = buildTree(edges1, root1);
    Tree T2 = buildTree(edges2, root2);
    int bnb1 = branchAndBoundPure(T1[root1], T2[root2], gamma_sub1);
    int bnb0 = branchAndBoundPure(T1[root1], T2[root2], gamma_sub0);

    cout << "\n===Branch and Bound===";
    cout << "\nSubstitution cost = 1: " << bnb1;
    cout << "\nSubstitution cost = 0: " << bnb0;

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

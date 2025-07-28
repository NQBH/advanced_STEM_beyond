#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    char label;
    vector<int> children;
};

// (a) Backtracking
class BacktrackingTED {
    vector<TreeNode> T1, T2;
    int n1, n2;

public:
    BacktrackingTED(const vector<TreeNode>& t1, const vector<TreeNode>& t2)
        : T1(t1), T2(t2), n1(t1.size()), n2(t2.size()) {}

    int ted(int i, int j) {
        if (i == -1 && j == -1) return 0;
        if (i == -1) return j + 1; // Insert all remaining nodes of T2
        if (j == -1) return i + 1; // Delete all remaining nodes of T1

        int relabel_cost = (T1[i].label == T2[j].label) ? 0 : 1;
        int min_cost = INT_MAX;

        // Relabel
        for (size_t k = 0; k < T1[i].children.size(); ++k) {
            for (size_t l = 0; l < T2[j].children.size(); ++l) {
                min_cost = min(min_cost, ted(T1[i].children[k], T2[j].children[l]) +
                    ted(k < T1[i].children.size() - 1 ? T1[i].children[k+1] : -1,
                        l < T2[j].children.size() - 1 ? T2[j].children[l+1] : -1) + relabel_cost);
            }
        }
        // Delete i
        min_cost = min(min_cost, ted(i == 0 ? -1 : T1[i].children[0], j) + 1);
        // Insert j
        min_cost = min(min_cost, ted(i, j == 0 ? -1 : T2[j].children[0]) + 1);

        return min_cost;
    }
};

// (b) Branch-and-Bound
class BranchAndBoundTED {
    vector<TreeNode> T1, T2;
    int n1, n2, best_cost;

public:
    BranchAndBoundTED(const vector<TreeNode>& t1, const vector<TreeNode>& t2)
        : T1(t1), T2(t2), n1(t1.size()), n2(t2.size()), best_cost(INT_MAX) {}

    int ted(int i, int j, int cost) {
        if (cost >= best_cost) return INT_MAX;
        if (i == -1 && j == -1) {
            best_cost = min(best_cost, cost);
            return cost;
        }
        if (i == -1) return cost + j + 1;
        if (j == -1) return cost + i + 1;

        int relabel_cost = (T1[i].label == T2[j].label) ? 0 : 1;
        int min_cost = INT_MAX;

        // Relabel
        for (size_t k = 0; k < T1[i].children.size(); ++k) {
            for (size_t l = 0; l < T2[j].children.size(); ++l) {
                min_cost = min(min_cost, ted(T1[i].children[k], T2[j].children[l], cost + relabel_cost));
            }
        }
        // Delete i
        min_cost = min(min_cost, ted(i == 0 ? -1 : T1[i].children[0], j, cost + 1));
        // Insert j
        min_cost = min(min_cost, ted(i, j == 0 ? -1 : T2[j].children[0], cost + 1));

        return min_cost;
    }
};

// (c) Divide-and-Conquer (Simplified with DP)
class DivideAndConquerTED {
    vector<TreeNode> T1, T2;
    vector<vector<int>> D;
    int n1, n2;

public:
    DivideAndConquerTED(const vector<TreeNode>& t1, const vector<TreeNode>& t2)
        : T1(t1), T2(t2), n1(t1.size()), n2(t2.size()) {
        D.assign(n1 + 1, vector<int>(n2 + 1, INT_MAX));
    }

    int ted(int i, int j) {
        if (D[i + 1][j + 1] != INT_MAX) return D[i + 1][j + 1];
        if (i == -1 && j == -1) return 0;
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;

        int relabel_cost = (T1[i].label == T2[j].label) ? 0 : 1;
        int min_cost = INT_MAX;

        // Divide into subtrees
        for (size_t k = 0; k < T1[i].children.size(); ++k) {
            for (size_t l = 0; l < T2[j].children.size(); ++l) {
                min_cost = min(min_cost, ted(T1[i].children[k], T2[j].children[l]) + relabel_cost);
            }
        }
        min_cost = min(min_cost, ted(i == 0 ? -1 : T1[i].children[0], j) + 1);
        min_cost = min(min_cost, ted(i, j == 0 ? -1 : T2[j].children[0]) + 1);

        D[i + 1][j + 1] = min_cost;
        return min_cost;
    }
};

// (d) Dynamic Programming
class DynamicProgrammingTED {
    vector<TreeNode> T1, T2;
    vector<vector<int>> F, D;
    int n1, n2;

public:
    DynamicProgrammingTED(const vector<TreeNode>& t1, const vector<TreeNode>& t2)
        : T1(t1), T2(t2), n1(t1.size()), n2(t2.size()) {
        F.assign(n1 + 1, vector<int>(n2 + 1, INT_MAX));
        D.assign(n1 + 1, vector<int>(n2 + 1, INT_MAX));
    }

    int ted(int i, int j) {
        if (D[i + 1][j + 1] != INT_MAX) return D[i + 1][j + 1];
        if (i == -1 && j == -1) return 0;
        if (i == -1) return j + 1;
        if (j == -1) return i + 1;

        F[0][0] = 0;
        for (int i1 = 1; i1 <= i + 1; ++i1) F[i1][0] = F[i1-1][0] + 1;
        for (int j1 = 1; j1 <= j + 1; ++j1) F[0][j1] = F[0][j1-1] + 1;

        for (int i1 = 1; i1 <= i + 1; ++i1) {
            for (int j1 = 1; j1 <= j + 1; ++j1) {
                int relabel_cost = (T1[i1-1].label == T2[j1-1].label) ? 0 : 1;
                F[i1][j1] = min({
                    F[i1-1][j1] + 1, // Delete
                    F[i1][j1-1] + 1, // Insert
                    F[i1-1][j1-1] + relabel_cost // Relabel
                });
            }
        }
        D[i + 1][j + 1] = F[i + 1][j + 1];
        return D[i + 1][j + 1];
    }
};

int main() {
    vector<TreeNode> T1(3), T2(3);
    T1[0].label = 'a'; T1[0].children = {1, 2};
    T1[1].label = 'b'; T1[2].label = 'c';
    T2[0].label = 'a'; T2[0].children = {1, 2};
    T2[1].label = 'b'; T2[2].label = 'd';

    BacktrackingTED bt(T1, T2);
    cout << "Backtracking TED: " << bt.ted(0, 0) << endl;

    BranchAndBoundTED bnb(T1, T2);
    cout << "Branch-and-Bound TED: " << bnb.ted(0, 0, 0) << endl;

    DivideAndConquerTED dc(T1, T2);
    cout << "Divide-and-Conquer TED: " << dc.ted(0, 0) << endl;

    DynamicProgrammingTED dp(T1, T2);
    cout << "Dynamic Programming TED: " << dp.ted(2, 2) << endl;
    return 0;
}
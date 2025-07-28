#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Node {
    string label;
    vector<Node*> children;
    Node(string l) : label(l) {}
};

void post_order(Node* node, vector<Node*>& result) {
    if (node) {
        for (Node* c : node->children)
            post_order(c, result);
        result.push_back(node);
    }
}

int ted(Node* t1, Node* t2) {
    vector<Node*> A, B;
    post_order(t1, A);
    post_order(t2, B);
    int m = A.size(), n = B.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (A[i-1]->label == B[j-1]->label) ? 0 : 1;
            dp[i][j] = min({
                dp[i-1][j] + 1,
                dp[i][j-1] + 1,
                dp[i-1][j-1] + cost
            });
        }
    }
    return dp[m][n];
}

int main() {
    Node* T1 = new Node("a");
    T1->children.push_back(new Node("b"));
    T1->children.push_back(new Node("c"));

    Node* T2 = new Node("a");
    T2->children.push_back(new Node("b"));
    T2->children.push_back(new Node("d"));

    cout << "Tree Edit Distance: " << ted(T1, T2) << "\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Nut cay
struct TreeNode {
    string label;
    vector<TreeNode*> children;
    TreeNode(string l) : label(l) {}
};

// Duyet hau tu
void postOrder(TreeNode* node, vector<TreeNode*>& nodes) {
    for (auto c : node->children)
        postOrder(c, nodes);
    nodes.push_back(node);
}

// Tinh edit distance bang DP
int treeEditDistanceDP(TreeNode* t1, TreeNode* t2) {
    vector<TreeNode*> t1_nodes, t2_nodes;
    postOrder(t1, t1_nodes);
    postOrder(t2, t2_nodes);
    int m = t1_nodes.size(), n = t2_nodes.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1; i <= m; ++i)
        dp[i][0] = dp[i-1][0] + 1; // xoa
    for (int j = 1; j <= n; ++j)
        dp[0][j] = dp[0][j-1] + 1; // chen

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (t1_nodes[i-1]->label == t2_nodes[j-1]->label) ? 0 : 1;
            dp[i][j] = min({
                dp[i-1][j] + 1,       // xoa
                dp[i][j-1] + 1,       // chen
                dp[i-1][j-1] + cost   // doi
            });
        }
    }

    return dp[m][n];
}

// Ham nhap cay tu ban phim
TreeNode* inputTree() {
    string label;
    cout << "Nhap nhan goc: ";
    cin >> label;
    TreeNode* node = new TreeNode(label);
    int n;
    cout << "So con cua " << label << ": ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "-- Con thu " << i+1 << " cua " << label << ":\n";
        node->children.push_back(inputTree());
    }
    return node;
}

int main() {
    cout << "Nhap cay 1:\n";
    TreeNode* t1 = inputTree();
    cout << "Nhap cay 2:\n";
    TreeNode* t2 = inputTree();
    cout << "Edit distance (DP): " << treeEditDistanceDP(t1, t2) << endl;
    return 0;
}
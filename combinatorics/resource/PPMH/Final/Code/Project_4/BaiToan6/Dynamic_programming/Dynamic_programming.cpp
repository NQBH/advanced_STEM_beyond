#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    string label;
    vector<TreeNode*> children;
    TreeNode(string lbl) : label(lbl) {}
};

void postorder(TreeNode* node, vector<TreeNode*>& list,
               unordered_map<TreeNode*, TreeNode*>& lld,
               unordered_map<TreeNode*, string>& labels,
               unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!node) return;
    for (auto child : node->children) {
        parent[child] = node;
        postorder(child, list, lld, labels, parent);
    }
    lld[node] = (node->children.empty() ? node : lld[node->children[0]]);
    list.push_back(node);
    labels[node] = node->label;
}

int tree_edit_distance(TreeNode* t1, TreeNode* t2) {
    vector<TreeNode*> A, B;
    unordered_map<TreeNode*, TreeNode*> lld1, lld2, parent1, parent2;
    unordered_map<TreeNode*, string> labels1, labels2;

    postorder(t1, A, lld1, labels1, parent1);
    postorder(t2, B, lld2, labels2, parent2);

    unordered_map<TreeNode*, int> id1, id2;
    for (int i = 0; i < A.size(); ++i) id1[A[i]] = i;
    for (int i = 0; i < B.size(); ++i) id2[B[i]] = i;

    int n = A.size(), m = B.size();
    vector<vector<int>> TED(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; ++i) TED[i][0] = i;
    for (int j = 0; j <= m; ++j) TED[0][j] = j;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            TreeNode* node1 = A[i - 1];
            TreeNode* node2 = B[j - 1];
            int cost = (labels1[node1] == labels2[node2]) ? 0 : 1;

            TED[i][j] = min({
                TED[i - 1][j] + 1,     
                TED[i][j - 1] + 1,    
                TED[i - 1][j - 1] + cost  
            });
        }
    }

    return TED[n][m];
}

int main() {
    TreeNode* t1 = new TreeNode("A");
    t1->children = {new TreeNode("B"), new TreeNode("C")};

    TreeNode* t2 = new TreeNode("A");
    t2->children = {new TreeNode("B"), new TreeNode("D")};

    cout << "Tree Edit Distance = " << tree_edit_distance(t1, t2) << endl;  

    return 0;
}

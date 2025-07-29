#include <bits/stdc++.h>
using namespace std;

// Cau truc nut cua cay
struct TreeNode {
    int id;
    vector<TreeNode*> children;
    TreeNode(int _id) : id(_id) {}
};

// Xay dung cay tu mang cha
TreeNode* build_tree_from_parents(const vector<int>& parents) {
    int n = parents.size();
    vector<TreeNode*> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = new TreeNode(i);
    }
    TreeNode* root = nullptr;
    for (int i = 0; i < n; i++) {
        int p = parents[i];
        if (p == -1) {
            root = nodes[i];
        } else {
            nodes[p]->children.push_back(nodes[i]);
        }
    }
    return root;
}

// Ham de quy tinh tree edit distance
int compute(TreeNode* n1, TreeNode* n2) {
    // TH ca hai nut rong
    if (n1 == nullptr && n2 == nullptr) return 0;
    // TH nut n1 rong
    if (n1 == nullptr) {
        int sum = 1;
        for (auto c : n2->children)
            sum += compute(nullptr, c);
        return sum;
    }
    // TH nut n2 rong
    if (n2 == nullptr) {
        int sum = 1;
        for (auto c : n1->children)
            sum += compute(c, nullptr);
        return sum;
    }

    // Lay danh sach con cua 2 nut
    auto &c1 = n1->children;
    auto &c2 = n2->children;
    int m = (int)c1.size();
    int n = (int)c2.size();

    // Tao bang dp (m+1)x(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else if (i == 0) {
                // Khi danh sach con cua n1 rong -> phai them tat ca con cua n2
                dp[i][j] = dp[i][j - 1] + compute(nullptr, c2[j - 1]);
            } else if (j == 0) {
                // Khi danh sach con cua n2 rong -> phai xoa tat ca con cua n1
                dp[i][j] = dp[i - 1][j] + compute(c1[i - 1], nullptr);
            } else {
                // Ba truong hop:
                // 1. Khop con c1[i-1] voi c2[j-1]
                int cost_sub = compute(c1[i - 1], c2[j - 1]);
                // 2. Xoa con c1[i-1]
                int cost_del = compute(c1[i - 1], nullptr);
                // 3. Chen con c2[j-1]
                int cost_ins = compute(nullptr, c2[j - 1]);

                dp[i][j] = min({
                    dp[i - 1][j - 1] + cost_sub,
                    dp[i - 1][j] + cost_del,
                    dp[i][j - 1] + cost_ins
                });
            }
        }
    }

    // Chi phi substitute o goc la 0 vi khong quan tam nhan nut
    return dp[m][n];
}

// Ham tinh tree edit distance
int tree_edit_distance(TreeNode* t1, TreeNode* t2) {
    return compute(t1, t2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Doc du lieu dau vao
    cout << "Cay thu nhat (nhap mang cha, root = -1):\n";
    vector<int> parents1;
    string line;
    getline(cin, line);
    {
        stringstream ss(line);
        int x;
        while (ss >> x) parents1.push_back(x);
    }

    cout << "Cay thu hai (nhap mang cha, root = -1):\n";
    vector<int> parents2;
    getline(cin, line);
    {
        stringstream ss(line);
        int x;
        while (ss >> x) parents2.push_back(x);
    }

    // Xay dung cay
    TreeNode* root1 = build_tree_from_parents(parents1);
    TreeNode* root2 = build_tree_from_parents(parents2);

    // Tinh khoang cach TED
    int dist = tree_edit_distance(root1, root2);

    cout << "\nTree Edit Distance: " << dist << "\n";
    return 0;
}
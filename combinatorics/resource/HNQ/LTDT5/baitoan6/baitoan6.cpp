#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <memory>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Cấu trúc TreeNode cho cây
struct TreeNode {
    string label;
    vector<shared_ptr<TreeNode>> children;
    
    TreeNode(const string& lbl) : label(lbl) {}
    
    void addChild(shared_ptr<TreeNode> child) {
        children.push_back(child);
    }
};

// Enum cho các thao tác edit
enum EditOperation {
    INSERT,
    DELETE,
    REPLACE,
    MATCH
};

// Cấu trúc lưu trữ thông tin thao tác
struct Operation {
    EditOperation op;
    string from;
    string to;
    int cost;
    
    Operation(EditOperation operation, const string& f = "", const string& t = "", int c = 1)
        : op(operation), from(f), to(t), cost(c) {}
};

class TreeEditDistance {
private:
    // Chi phí cho các thao tác
    int insertCost = 1;
    int deleteCost = 1;
    int replaceCost = 1;
    
    // Biến toàn cục cho các thuật toán
    int minCost;
    vector<Operation> bestSolution;
    
public:
    // Constructor
    TreeEditDistance(int ins = 1, int del = 1, int rep = 1) 
        : insertCost(ins), deleteCost(del), replaceCost(rep) {}
    
    // Phương pháp 1: Backtracking
    int solveBacktracking(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2) {
        cout << "=== Phương pháp Backtracking ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        minCost = INT_MAX;
        bestSolution.clear();
        vector<Operation> currentSolution;
        
        backtrackHelper(tree1, tree2, 0, currentSolution);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Chi phí tối thiểu: " << minCost << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Chuỗi thao tác tối ưu:" << endl;
        printOperations(bestSolution);
        
        return minCost;
    }
    
    // Phương pháp 2: Branch-and-Bound
    int solveBranchAndBound(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2) {
        cout << "\n=== Phương pháp Branch-and-Bound ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        minCost = INT_MAX;
        bestSolution.clear();
        vector<Operation> currentSolution;
        
        // Tính upper bound ban đầu bằng cách xóa tất cả nút của tree1 và chèn tất cả nút của tree2
        int upperBound = getTreeSize(tree1) * deleteCost + getTreeSize(tree2) * insertCost;
        
        branchAndBoundHelper(tree1, tree2, 0, currentSolution, upperBound);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Chi phí tối thiểu: " << minCost << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        cout << "Chuỗi thao tác tối ưu:" << endl;
        printOperations(bestSolution);
        
        return minCost;
    }
    
    // Phương pháp 3: Divide-and-Conquer
    int solveDivideAndConquer(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2) {
        cout << "\n=== Phương pháp Divide-and-Conquer ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        int result = divideAndConquerHelper(tree1, tree2);
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Chi phí tối thiểu: " << result << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        
        return result;
    }
    
    // Phương pháp 4: Dynamic Programming
    int solveDynamicProgramming(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2) {
        cout << "\n=== Phương pháp Dynamic Programming ===" << endl;
        
        auto start = high_resolution_clock::now();
        
        // Chuyển đổi cây thành postorder traversal
        vector<shared_ptr<TreeNode>> postorder1, postorder2;
        vector<int> leftmost1, leftmost2;
        
        getPostorderAndLeftmost(tree1, postorder1, leftmost1);
        getPostorderAndLeftmost(tree2, postorder2, leftmost2);
        
        int m = postorder1.size();
        int n = postorder2.size();
        
        // Ma trận DP
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // Khởi tạo base cases
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i * deleteCost;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j * insertCost;
        }
        
        // Điền ma trận DP
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Kiểm tra xem có thể mapping được không
                if (leftmost1[i-1] == 0 && leftmost2[j-1] == 0) {
                    // Cả hai đều là lá
                    int matchCost = (postorder1[i-1]->label == postorder2[j-1]->label) ? 0 : replaceCost;
                    dp[i][j] = min({
                        dp[i-1][j] + deleteCost,           // Delete
                        dp[i][j-1] + insertCost,           // Insert
                        dp[i-1][j-1] + matchCost           // Match/Replace
                    });
                } else {
                    // Xử lý subtree
                    dp[i][j] = min(
                        dp[i-1][j] + deleteCost,           // Delete
                        dp[i][j-1] + insertCost            // Insert
                    );
                }
            }
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << "Chi phí tối thiểu: " << dp[m][n] << endl;
        cout << "Thời gian thực thi: " << duration.count() << " microseconds" << endl;
        
        return dp[m][n];
    }

private:
    // Helper functions
    void backtrackHelper(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2, 
                        int currentCost, vector<Operation>& currentSolution) {
        // Pruning: nếu chi phí hiện tại đã lớn hơn min thì dừng
        if (currentCost >= minCost) return;
        
        // Base cases
        if (!tree1 && !tree2) {
            if (currentCost < minCost) {
                minCost = currentCost;
                bestSolution = currentSolution;
            }
            return;
        }
        
        if (!tree1) {
            // Chỉ còn tree2, insert tất cả
            int insertAllCost = getTreeSize(tree2) * insertCost;
            if (currentCost + insertAllCost < minCost) {
                minCost = currentCost + insertAllCost;
                bestSolution = currentSolution;
                // Thêm các thao tác insert
                addInsertOperations(tree2, bestSolution);
            }
            return;
        }
        
        if (!tree2) {
            // Chỉ còn tree1, delete tất cả
            int deleteAllCost = getTreeSize(tree1) * deleteCost;
            if (currentCost + deleteAllCost < minCost) {
                minCost = currentCost + deleteAllCost;
                bestSolution = currentSolution;
                // Thêm các thao tác delete
                addDeleteOperations(tree1, bestSolution);
            }
            return;
        }
        
        // Thử các thao tác
        // 1. Match/Replace
        if (tree1->label == tree2->label) {
            currentSolution.push_back(Operation(MATCH, tree1->label, tree2->label, 0));
            processChildren(tree1, tree2, currentCost, currentSolution);
            currentSolution.pop_back();
        } else {
            currentSolution.push_back(Operation(REPLACE, tree1->label, tree2->label, replaceCost));
            processChildren(tree1, tree2, currentCost + replaceCost, currentSolution);
            currentSolution.pop_back();
        }
        
        // 2. Delete từ tree1
        currentSolution.push_back(Operation(DELETE, tree1->label, "", deleteCost));
        backtrackHelper(nullptr, tree2, currentCost + deleteCost, currentSolution);
        currentSolution.pop_back();
        
        // 3. Insert từ tree2
        currentSolution.push_back(Operation(INSERT, "", tree2->label, insertCost));
        backtrackHelper(tree1, nullptr, currentCost + insertCost, currentSolution);
        currentSolution.pop_back();
    }
    
    void branchAndBoundHelper(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2,
                             int currentCost, vector<Operation>& currentSolution, int bound) {
        // Pruning với bound
        if (currentCost >= minCost || currentCost >= bound) return;
        
        // Tính lower bound
        int lowerBound = currentCost + calculateLowerBound(tree1, tree2);
        if (lowerBound >= minCost) return;
        
        // Base cases (tương tự backtracking)
        if (!tree1 && !tree2) {
            if (currentCost < minCost) {
                minCost = currentCost;
                bestSolution = currentSolution;
            }
            return;
        }
        
        if (!tree1) {
            int insertAllCost = getTreeSize(tree2) * insertCost;
            if (currentCost + insertAllCost < minCost) {
                minCost = currentCost + insertAllCost;
                bestSolution = currentSolution;
                addInsertOperations(tree2, bestSolution);
            }
            return;
        }
        
        if (!tree2) {
            int deleteAllCost = getTreeSize(tree1) * deleteCost;
            if (currentCost + deleteAllCost < minCost) {
                minCost = currentCost + deleteAllCost;
                bestSolution = currentSolution;
                addDeleteOperations(tree1, bestSolution);
            }
            return;
        }
        
        // Thử các thao tác với bound checking
        if (tree1->label == tree2->label) {
            currentSolution.push_back(Operation(MATCH, tree1->label, tree2->label, 0));
            processChildren(tree1, tree2, currentCost, currentSolution);
            currentSolution.pop_back();
        } else {
            if (currentCost + replaceCost < bound) {
                currentSolution.push_back(Operation(REPLACE, tree1->label, tree2->label, replaceCost));
                processChildren(tree1, tree2, currentCost + replaceCost, currentSolution);
                currentSolution.pop_back();
            }
        }
        
        if (currentCost + deleteCost < bound) {
            currentSolution.push_back(Operation(DELETE, tree1->label, "", deleteCost));
            branchAndBoundHelper(nullptr, tree2, currentCost + deleteCost, currentSolution, bound);
            currentSolution.pop_back();
        }
        
        if (currentCost + insertCost < bound) {
            currentSolution.push_back(Operation(INSERT, "", tree2->label, insertCost));
            branchAndBoundHelper(tree1, nullptr, currentCost + insertCost, currentSolution, bound);
            currentSolution.pop_back();
        }
    }
    
    int divideAndConquerHelper(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2) {
        // Base cases
        if (!tree1 && !tree2) return 0;
        if (!tree1) return getTreeSize(tree2) * insertCost;
        if (!tree2) return getTreeSize(tree1) * deleteCost;
        
        // Nếu cây chỉ có một nút
        if (tree1->children.empty() && tree2->children.empty()) {
            return (tree1->label == tree2->label) ? 0 : replaceCost;
        }
        
        // Chia nhỏ bài toán
        int minCost = INT_MAX;
        
        // Thử match/replace root
        int rootCost = (tree1->label == tree2->label) ? 0 : replaceCost;
        int childrenCost = compareChildrenLists(tree1->children, tree2->children);
        minCost = min(minCost, rootCost + childrenCost);
        
        // Thử delete root của tree1
        minCost = min(minCost, deleteCost + divideAndConquerHelper(nullptr, tree2));
        
        // Thử insert root của tree2
        minCost = min(minCost, insertCost + divideAndConquerHelper(tree1, nullptr));
        
        return minCost;
    }
    
    int compareChildrenLists(const vector<shared_ptr<TreeNode>>& children1, 
                            const vector<shared_ptr<TreeNode>>& children2) {
        int m = children1.size();
        int n = children2.size();
        
        // DP cho so sánh danh sách con
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i * deleteCost;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j * insertCost;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min({
                    dp[i-1][j] + deleteCost,
                    dp[i][j-1] + insertCost,
                    dp[i-1][j-1] + divideAndConquerHelper(children1[i-1], children2[j-1])
                });
            }
        }
        
        return dp[m][n];
    }
    
    void processChildren(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2,
                        int currentCost, vector<Operation>& currentSolution) {
        // Xử lý danh sách con bằng DP đơn giản
        int childCost = compareChildrenLists(tree1->children, tree2->children);
        
        if (currentCost + childCost < minCost) {
            minCost = currentCost + childCost;
            bestSolution = currentSolution;
        }
    }
    
    int getTreeSize(shared_ptr<TreeNode> tree) {
        if (!tree) return 0;
        int size = 1;
        for (auto child : tree->children) {
            size += getTreeSize(child);
        }
        return size;
    }
    
    int calculateLowerBound(shared_ptr<TreeNode> tree1, shared_ptr<TreeNode> tree2) {
        if (!tree1 && !tree2) return 0;
        if (!tree1) return getTreeSize(tree2) * insertCost;
        if (!tree2) return getTreeSize(tree1) * deleteCost;
        
        // Lower bound đơn giản: chênh lệch kích thước
        int size1 = getTreeSize(tree1);
        int size2 = getTreeSize(tree2);
        return abs(size1 - size2);
    }
    
    void addInsertOperations(shared_ptr<TreeNode> tree, vector<Operation>& operations) {
        if (!tree) return;
        operations.push_back(Operation(INSERT, "", tree->label, insertCost));
        for (auto child : tree->children) {
            addInsertOperations(child, operations);
        }
    }
    
    void addDeleteOperations(shared_ptr<TreeNode> tree, vector<Operation>& operations) {
        if (!tree) return;
        operations.push_back(Operation(DELETE, tree->label, "", deleteCost));
        for (auto child : tree->children) {
            addDeleteOperations(child, operations);
        }
    }
    
    void getPostorderAndLeftmost(shared_ptr<TreeNode> tree, vector<shared_ptr<TreeNode>>& postorder, 
                                vector<int>& leftmost) {
        if (!tree) return;
        
        for (auto child : tree->children) {
            getPostorderAndLeftmost(child, postorder, leftmost);
        }
        
        postorder.push_back(tree);
        leftmost.push_back(tree->children.empty() ? 0 : 1);
    }
    
    void printOperations(const vector<Operation>& operations) {
        for (const auto& op : operations) {
            switch (op.op) {
                case INSERT:
                    cout << "INSERT '" << op.to << "' (cost: " << op.cost << ")" << endl;
                    break;
                case DELETE:
                    cout << "DELETE '" << op.from << "' (cost: " << op.cost << ")" << endl;
                    break;
                case REPLACE:
                    cout << "REPLACE '" << op.from << "' -> '" << op.to << "' (cost: " << op.cost << ")" << endl;
                    break;
                case MATCH:
                    cout << "MATCH '" << op.from << "' = '" << op.to << "' (cost: " << op.cost << ")" << endl;
                    break;
            }
        }
    }
};

// Hàm tiện ích để tạo cây
shared_ptr<TreeNode> createSampleTree1() {
    auto root = make_shared<TreeNode>("A");
    auto b = make_shared<TreeNode>("B");
    auto c = make_shared<TreeNode>("C");
    auto d = make_shared<TreeNode>("D");
    auto e = make_shared<TreeNode>("E");
    
    root->addChild(b);
    root->addChild(c);
    b->addChild(d);
    c->addChild(e);
    
    return root;
}

shared_ptr<TreeNode> createSampleTree2() {
    auto root = make_shared<TreeNode>("A");
    auto b = make_shared<TreeNode>("B");
    auto f = make_shared<TreeNode>("F");
    auto d = make_shared<TreeNode>("D");
    
    root->addChild(b);
    root->addChild(f);
    b->addChild(d);
    
    return root;
}

void printTree(shared_ptr<TreeNode> tree, int level = 0) {
    if (!tree) return;
    
    for (int i = 0; i < level; i++) cout << "  ";
    cout << tree->label << endl;
    
    for (auto child : tree->children) {
        printTree(child, level + 1);
    }
}

int main() {
    cout << "=== TREE EDIT DISTANCE PROBLEM ===" << endl;
    cout << "Giải bài toán Tree Edit Distance bằng 4 phương pháp khác nhau\n" << endl;
    
    // Tạo hai cây mẫu
    auto tree1 = createSampleTree1();
    auto tree2 = createSampleTree2();
    
    cout << "Cây 1:" << endl;
    printTree(tree1);
    cout << "\nCây 2:" << endl;
    printTree(tree2);
    cout << endl;
    
    TreeEditDistance solver(1, 1, 1); // insert_cost, delete_cost, replace_cost
    
    // Giải bằng 4 phương pháp
    int result1 = solver.solveBacktracking(tree1, tree2);
    int result2 = solver.solveBranchAndBound(tree1, tree2);
    int result3 = solver.solveDivideAndConquer(tree1, tree2);
    int result4 = solver.solveDynamicProgramming(tree1, tree2);
    
    cout << "\n=== KẾT QUẢ TỔNG KẾT ===" << endl;
    cout << "Backtracking: " << result1 << endl;
    cout << "Branch-and-Bound: " << result2 << endl;
    cout << "Divide-and-Conquer: " << result3 << endl;
    cout << "Dynamic Programming: " << result4 << endl;
    
    return 0;
}
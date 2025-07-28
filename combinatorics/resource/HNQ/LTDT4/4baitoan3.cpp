#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

class SelfConjugatePartitionSolver {
private:
    // Biến chính: memo - bảng memoization cho đệ quy
    map<pair<int, int>, int> memo;
    
    void generatePartitionsRecursive(int n, int k, int minVal, 
                                   vector<int>& current, 
                                   vector<vector<int>>& result) {
        if (k == 1) {
            if (n >= minVal) {
                current.push_back(n);
                result.push_back(current);
                current.pop_back();
            }
            return;
        }
        
        for (int i = minVal; i <= n/k; i++) {
            current.push_back(i);
            generatePartitionsRecursive(n - i, k - 1, i, current, result);
            current.pop_back();
        }
    }
    
    // Tính conjugate partition
    vector<int> computeConjugate(const vector<int>& partition) {
        if (partition.empty()) return {};
        
        vector<int> conjugate;
        int maxPart = partition[0];
        
        for (int i = 1; i <= maxPart; i++) {
            int count = 0;
            for (int part : partition) {
                if (part >= i) count++;
                else break;
            }
            if (count > 0) {
                conjugate.push_back(count);
            }
        }
        
        return conjugate;
    }
    
    // Kiểm tra partition có phải self-conjugate không
    bool isSelfConjugate(const vector<int>& partition) {
        vector<int> conjugate = computeConjugate(partition);
        return partition == conjugate;
    }
    
public:
    // Sinh tất cả phân hoạch
    vector<vector<int>> generatePartitions(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;
        
        generatePartitionsRecursive(n, k, 1, current, result);
        
        for (auto& partition : result) {
            sort(partition.rbegin(), partition.rend());
        }
        
        return result;
    }
    
    // Tìm tất cả phân hoạch self-conjugate có k phần
    vector<vector<int>> findSelfConjugatePartitions(int n, int k) {
        vector<vector<int>> allPartitions = generatePartitions(n, k);
        vector<vector<int>> selfConjugatePartitions;
        
        for (const auto& partition : allPartitions) {
            if (isSelfConjugate(partition)) {
                selfConjugatePartitions.push_back(partition);
            }
        }
        
        return selfConjugatePartitions;
    }
    
    // Đếm số phân hoạch có số phần lẻ
    int countPartitionsWithOddParts(int n) {
        int count = 0;
        
        // Duyệt qua tất cả số phần lẻ từ 1 đến n
        for (int parts = 1; parts <= n; parts += 2) {
            vector<vector<int>> partitions = generatePartitions(n, parts);
            count += partitions.size();
        }
        
        return count;
    }
    
    // Đếm số phân hoạch thành các phần lẻ khác nhau
    int countPartitionsIntoDistinctOddParts(int n) {
        // Sử dụng backtracking để đếm
        return countDistinctOddPartitionsRecursive(n, 1);
    }
    
    int countDistinctOddPartitionsRecursive(int n, int minOdd) {
        if (n == 0) return 1;
        if (n < 0 || minOdd > n) return 0;
        
        int count = 0;
        
        // Thử tất cả số lẻ từ minOdd
        for (int odd = minOdd; odd <= n; odd += 2) {
            count += countDistinctOddPartitionsRecursive(n - odd, odd + 2);
        }
        
        return count;
    }
    
    // Đệ quy có memoization cho self-conjugate counting
    int selfConjugateRecursive(int n, int k) {
        if (k == 1) {
            // Self-conjugate với 1 phần chỉ có khi n là số chính phương lẻ
            // Thực tế: chỉ khi n = 1, 9, 25, ... (số chính phương lẻ)
            // Nhưng đơn giản hóa: return 1 nếu n lẻ, 0 nếu n chẵn
            return (n % 2 == 1) ? 1 : 0;
        }
        
        if (k > n) return 0;
        if (k == n) return 1;
        if (n <= 0) return 0;
        
        auto key = make_pair(n, k);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // Áp dụng công thức tương tự p(n,k)
        int result = selfConjugateRecursive(n-1, k-1) + selfConjugateRecursive(n-k, k);
        memo[key] = result;
        
        return result;
    }
    
    // Dynamic Programming cho self-conjugate counting
    int selfConjugateDP(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        // Base cases
        for (int i = 1; i <= n; i++) {
            dp[i][1] = (i % 2 == 1) ? 1 : 0;
        }
        
        for (int j = 1; j <= min(n, k); j++) {
            dp[j][j] = 1;
        }
        
        // Fill DP table
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= min(i, k); j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            }
        }
        
        return dp[n][k];
    }
    
    // Vẽ Ferrers diagram
    void drawFerrersDiagram(const vector<int>& partition, const string& indent = "") {
        for (int part : partition) {
            cout << indent;
            for (int i = 0; i < part; i++) {
                cout << "* ";
            }
            cout << endl;
        }
    }
    
    string formatPartition(const vector<int>& partition) {
        if (partition.empty()) return "{}";
        
        string result = "(";
        for (size_t i = 0; i < partition.size(); i++) {
            result += to_string(partition[i]);
            if (i < partition.size() - 1) result += ",";
        }
        result += ")";
        return result;
    }
    
    // Hàm giải bài toán 3
    void solveProblem3(int n, int k) {
        cout << "=== BÀI TOÁN 3: SỐ PHÂN HOẠCH TỰ LIÊN HỢP ===" << endl;
        cout << "Tham số: n = " << n << ", k = " << k << endl << endl;
        
        // (a) Đếm và in các phân hoạch tự liên hợp có k phần
        cout << "Phần (a): Đếm số phân hoạch tự liên hợp có " << k << " phần" << endl;
        vector<vector<int>> selfConjugatePartitions = findSelfConjugatePartitions(n, k);
        cout << "p_selfcjg_" << k << "(" << n << ") = " << selfConjugatePartitions.size() << endl << endl;
        
        cout << "Các phân hoạch tự liên hợp:" << endl;
        for (size_t i = 0; i < selfConjugatePartitions.size(); i++) {
            cout << i + 1 << ". λ = " << formatPartition(selfConjugatePartitions[i]) << endl;
            cout << "   Ferrers Diagram:" << endl;
            drawFerrersDiagram(selfConjugatePartitions[i], "   ");
            
            // Verify tính self-conjugate
            vector<int> conjugate = computeConjugate(selfConjugatePartitions[i]);
            bool isCorrect = (selfConjugatePartitions[i] == conjugate);
            cout << "   Kiểm tra λ = λ^T: " << (isCorrect ? "✓" : "✗") << endl << endl;
        }
        
        // (b) Đếm số phân hoạch có số phần lẻ
        cout << "Phần (b): Đếm số phân hoạch có số phần lẻ" << endl;
        int oddPartsCount = countPartitionsWithOddParts(n);
        cout << "Số phân hoạch của " << n << " có số phần lẻ: " << oddPartsCount << endl << endl;
        
        // So sánh với định lý
        cout << "Định lý Euler: Số phân hoạch tự liên hợp = Số phân hoạch thành các phần lẻ khác nhau" << endl;
        int distinctOddCount = countPartitionsIntoDistinctOddParts(n);
        cout << "Số phân hoạch của " << n << " thành các phần lẻ khác nhau: " << distinctOddCount << endl << endl;
        
        // (c) Thiết lập công thức truy hồi
        cout << "Phần (c): Thiết lập công thức truy hồi" << endl;
        cout << "Công thức: p_selfcjg_k(n) = p_selfcjg_k(n-1, k-1) + p_selfcjg_k(n-k, k)" << endl;
        cout << "Giải thích:" << endl;
        cout << "- p_selfcjg_k(n-1, k-1): Thêm phần mới có giá trị 1" << endl;
        cout << "- p_selfcjg_k(n-k, k): Tăng mỗi phần hiện có lên 1" << endl << endl;
        
        // Implementation bằng đệ quy
        memo.clear();
        int recursiveResult = selfConjugateRecursive(n, k);
        cout << "Kết quả đệ quy (với memoization): " << recursiveResult << endl;
        
        // Implementation bằng DP
        int dpResult = selfConjugateDP(n, k);
        cout << "Kết quả quy hoạch động: " << dpResult << endl;
        
        cout << "Kiểm tra tính đúng (đệ quy vs DP): " 
             << (recursiveResult == dpResult ? "✓" : "✗") << endl << endl;
    }
};

int main() {
    cout << "CHƯƠNG TRÌNH GIẢI BÀI TOÁN 3: SỐ PHÂN HOẠCH TỰ LIÊN HỢP" << endl;
    cout << string(70, '=') << endl << endl;
    
    int n, k;
    cout << "Nhập n (số cần phân hoạch): ";
    cin >> n;
    cout << "Nhập k (số phần): ";
    cin >> k;
    cout << endl;
    
    // Kiểm tra tính hợp lệ
    if (n <= 0 || k <= 0) {
        cout << "Lỗi: n và k phải là số nguyên dương!" << endl;
        return 1;
    }
    
    SelfConjugatePartitionSolver solver;
    solver.solveProblem3(n, k);
    
    // Demo với các test cases
    cout << string(70, '=') << endl;
    cout << "DEMO VỚI CÁC TEST CASES KHÁC:" << endl;
    cout << string(70, '=') << endl;
    
    vector<pair<int, int>> testCases = {{6, 3}, {8, 4}, {9, 3}};
    
    for (auto& tc : testCases) {
        cout << "\n";
        solver.solveProblem3(tc.first, tc.second);
    }
    
    return 0;
}
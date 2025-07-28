#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class PartitionCountingSolver {
private:
    // Biến chính: dp[i][j] - số phân hoạch của i thành đúng j phần
    vector<vector<int>> dp;
    
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
    
public:
    // Hàm tính p(n,k) bằng Dynamic Programming
    int computePartitionCountDP(int n, int k) {
        // Khởi tạo bảng DP
        dp.assign(n + 1, vector<int>(k + 1, 0));
        
        // Base cases
        // p(i,1) = 1: chỉ có 1 cách phân hoạch i thành 1 phần (chính là i)
        for (int i = 1; i <= n; i++) {
            dp[i][1] = 1;
        }
        
        // p(j,j) = 1: chỉ có 1 cách phân hoạch j thành j phần (1+1+...+1)
        for (int j = 1; j <= min(n, k); j++) {
            dp[j][j] = 1;
        }
        
        // Fill bảng DP theo công thức: p(i,j) = p(i-1,j-1) + p(i-j,j)
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= min(i, k); j++) {
                // p(i-1,j-1): thêm phần mới có giá trị 1
                // p(i-j,j): tăng mỗi phần hiện có lên 1
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            }
        }
        
        return dp[n][k];
    }
    
    // Hàm tính p_max(n,k) - số phân hoạch có phần tử lớn nhất là k
    int computePartitionWithMax(int n, int maxVal) {
        if (maxVal > n) return 0;
        if (maxVal == n) return 1;
        
        // Sinh tất cả phân hoạch và đếm những phân hoạch có max = maxVal
        vector<vector<int>> allPartitions;
        
        // Sinh phân hoạch với tất cả số phần có thể
        for (int parts = 1; parts <= n; parts++) {
            vector<int> current;
            vector<vector<int>> partitionsWithParts;
            generatePartitionsRecursive(n, parts, 1, current, partitionsWithParts);
            
            // Sắp xếp và thêm vào danh sách tổng
            for (auto& partition : partitionsWithParts) {
                sort(partition.rbegin(), partition.rend());
                allPartitions.push_back(partition);
            }
        }
        
        // Đếm số phân hoạch có max = maxVal
        int count = 0;
        for (const auto& partition : allPartitions) {
            if (!partition.empty() && partition[0] == maxVal) {
                count++;
            }
        }
        
        return count;
    }
    
    // In bảng Dynamic Programming
    void printDPTable(int n, int k) {
        cout << "Bảng Dynamic Programming p(i,j):" << endl;
        
        // Header
        cout << setw(4) << "i\\j";
        for (int j = 1; j <= k; j++) {
            cout << setw(4) << j;
        }
        cout << endl;
        
        // Nội dung bảng
        for (int i = 1; i <= n; i++) {
            cout << setw(4) << i;
            for (int j = 1; j <= k; j++) {
                cout << setw(4) << dp[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    // Hàm giải bài toán 2
    void solveProblem2(int n, int k) {
        cout << "=== BÀI TOÁN 2: ĐẾM SỐ PHÂN HOẠCH ===" << endl;
        cout << "Tham số: n = " << n << ", k = " << k << endl << endl;
        
        // Tính p_k(n) bằng Dynamic Programming
        int pk_n = computePartitionCountDP(n, k);
        cout << "p_" << k << "(" << n << ") = " << pk_n << endl;
        cout << "Giải thích: Số cách phân hoạch " << n << " thành đúng " << k << " phần" << endl << endl;
        
        // Tính p_max(n,k)
        int pmax_n_k = computePartitionWithMax(n, k);
        cout << "p_max(" << n << "," << k << ") = " << pmax_n_k << endl;
        cout << "Giải thích: Số cách phân hoạch " << n << " có phần tử lớn nhất là " << k << endl << endl;
        
        // So sánh kết quả
        cout << "So sánh kết quả:" << endl;
        cout << "p_" << k << "(" << n << ") ";
        if (pk_n == pmax_n_k) {
            cout << "= ";
        } else if (pk_n > pmax_n_k) {
            cout << "> ";
        } else {
            cout << "< ";
        }
        cout << "p_max(" << n << "," << k << ")" << endl << endl;
        
        // In bảng DP
        printDPTable(n, k);
        
        // Giải thích công thức đệ quy
        cout << "Công thức đệ quy: p(n,k) = p(n-1,k-1) + p(n-k,k)" << endl;
        cout << "- p(n-1,k-1): Số cách khi phần nhỏ nhất = 1" << endl;
        cout << "- p(n-k,k): Số cách khi tất cả các phần ≥ 2" << endl << endl;
        
        // Verification bằng enumeration cho n,k nhỏ
        if (n <= 10 && k <= 6) {
            cout << "Verification bằng enumeration:" << endl;
            vector<int> current;
            vector<vector<int>> partitions;
            generatePartitionsRecursive(n, k, 1, current, partitions);
            
            cout << "Tất cả các phân hoạch:" << endl;
            for (size_t i = 0; i < partitions.size(); i++) {
                sort(partitions[i].rbegin(), partitions[i].rend());
                cout << i + 1 << ". (";
                for (size_t j = 0; j < partitions[i].size(); j++) {
                    cout << partitions[i][j];
                    if (j < partitions[i].size() - 1) cout << ",";
                }
                cout << ")" << endl;
            }
            cout << "Tổng cộng: " << partitions.size() << " phân hoạch ✓" << endl << endl;
        }
    }
};

int main() {
    cout << "CHƯƠNG TRÌNH GIẢI BÀI TOÁN 2: ĐẾM SỐ PHÂN HOẠCH" << endl;
    cout << string(60, '=') << endl << endl;
    
    int n, k;
    cout << "Nhập n (số cần phân hoạch): ";
    cin >> n;
    cout << "Nhập k (số phần hoặc giá trị max): ";
    cin >> k;
    cout << endl;
    
    // Kiểm tra tính hợp lệ
    if (n <= 0 || k <= 0) {
        cout << "Lỗi: n và k phải là số nguyên dương!" << endl;
        return 1;
    }
    
    PartitionCountingSolver solver;
    solver.solveProblem2(n, k);
    
    // Demo với các test cases
    cout << string(60, '=') << endl;
    cout << "DEMO VỚI CÁC TEST CASES KHÁC:" << endl;
    cout << string(60, '=') << endl;
    
    vector<pair<int, int>> testCases = {{6, 3}, {7, 4}, {8, 4}};
    
    for (auto& tc : testCases) {
        cout << "\n";
        solver.solveProblem2(tc.first, tc.second);
    }
    
    return 0;
}
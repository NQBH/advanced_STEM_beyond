#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Memoization cho tính toán nhanh
map<pair<int, int>, long long> memo;

// Hàm tính số phân hoạch của n với các phần không vượt quá max_part
long long partitionsWithMaxPart(int n, int max_part) {
    if (n == 0) return 1;
    if (n < 0 || max_part <= 0) return 0;
    
    pair<int, int> key = {n, max_part};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    long long result = partitionsWithMaxPart(n, max_part - 1);  // Không dùng max_part
    if (n >= max_part) {
        result += partitionsWithMaxPart(n - max_part, max_part);  // Dùng ít nhất 1 lần max_part
    }
    
    memo[key] = result;
    return result;
}

// Hàm tính số phân hoạch của n với phần tử lớn nhất CHÍNH XÁC là k
long long partitionsWithExactMax(int n, int k) {
    if (k > n) return 0;
    if (k == n) return 1;  // Chỉ có phân hoạch (n)
    
    // Số phân hoạch có max <= k trừ số phân hoạch có max <= k-1
    return partitionsWithMaxPart(n, k) - partitionsWithMaxPart(n, k - 1);
}

// Hàm tính p_k(n) - số phân hoạch của n với ĐÚNG k phần
long long partitionsWithExactParts(int n, int k) {
    if (k == 0) return (n == 0) ? 1 : 0;
    if (k > n) return 0;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            for (int part = 1; part <= i; part++) {
                if (i - part >= 0 && j - 1 >= 0) {
                    dp[i][j] += dp[i - part][j - 1];
                }
            }
        }
    }
    
    return dp[n][k];
}

// Phương pháp sinh và đếm trực tiếp để kiểm tra
void generateAndCount(int n, int target_max, int current_sum, int current_max, 
                     vector<int>& current_partition, long long& count) {
    if (current_sum == n) {
        if (current_max == target_max) {
            count++;
            // In ra phân hoạch (tùy chọn)
            cout << "(";
            for (int i = 0; i < current_partition.size(); i++) {
                cout << current_partition[i];
                if (i < current_partition.size() - 1) cout << ", ";
            }
            cout << ") ";
        }
        return;
    }
    
    if (current_sum > n) return;
    
    int start = current_partition.empty() ? target_max : 
                min(target_max, current_partition.back());
    
    for (int i = start; i >= 1; i--) {
        if (current_sum + i <= n) {
            current_partition.push_back(i);
            generateAndCount(n, target_max, current_sum + i, 
                           max(current_max, i), current_partition, count);
            current_partition.pop_back();
        }
    }
}

int main() {
    int n, k;
    cout << "Nhập n và k: ";
    cin >> n >> k;
    
    if (n <= 0 || k <= 0) {
        cout << "n và k phải là số nguyên dương!\n";
        return 0;
    }
    
    cout << "Phân tích cho n = " << n << ", k = " << k << ":\n";
    cout << "==========================================\n";
    
    // Tính p_max(n, k) - số phân hoạch có phần tử lớn nhất là k
    long long p_max = partitionsWithExactMax(n, k);
    cout << "p_max(" << n << ", " << k << ") = " << p_max << "\n";
    
    // Tính p_k(n) - số phân hoạch có đúng k phần  
    long long p_k = partitionsWithExactParts(n, k);
    cout << "p_" << k << "(" << n << ") = " << p_k << "\n";
    
    cout << "\nSo sánh:\n";
    if (p_max > p_k) {
        cout << "p_max(" << n << ", " << k << ") > p_" << k << "(" << n << ")\n";
    } else if (p_max < p_k) {
        cout << "p_max(" << n << ", " << k << ") < p_" << k << "(" << n << ")\n";  
    } else {
        cout << "p_max(" << n << ", " << k << ") = p_" << k << "(" << n << ")\n";
    }
    
    // Liệt kê các phân hoạch có max = k (nếu số lượng không quá lớn)
    if (p_max <= 20) {
        cout << "\nCác phân hoạch có phần tử lớn nhất là " << k << ":\n";
        vector<int> partition;
        long long count = 0;
        generateAndCount(n, k, 0, 0, partition, count);
        cout << "\nTổng: " << count << " phân hoạch\n";
    }
    
    // Tính một số giá trị khác để so sánh
    cout << "\nBảng so sánh p_max và p_k cho các giá trị khác:\n";
    cout << "k\tp_max(n,k)\tp_k(n)\n";
    cout << "------------------------\n";
    
    for (int i = 1; i <= min(n, 10); i++) {
        long long pm = partitionsWithExactMax(n, i);
        long long pk = partitionsWithExactParts(n, i);
        cout << i << "\t" << pm << "\t\t" << pk << "\n";
    }
    
    return 0;
}
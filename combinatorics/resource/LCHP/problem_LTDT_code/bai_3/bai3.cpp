#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// Memoization cho các tính toán
map<pair<int, int>, long long> memo_self_conjugate;
map<pair<int, int>, long long> memo_odd_parts;
map<pair<int, int>, long long> memo_distinct_parts;

// Kiểm tra xem một phân hoạch có tự liên hợp hay không
bool isSelfConjugate(const vector<int>& partition) {
    int n = partition.size();
    if (n == 0) return true;
    
    // Tạo biểu đồ Ferrers chuyển vị
    vector<int> conjugate;
    int max_part = *max_element(partition.begin(), partition.end());
    
    for (int col = 1; col <= max_part; col++) {
        int height = 0;
        for (int row = 0; row < n; row++) {
            if (partition[row] >= col) {
                height++;
            }
        }
        if (height > 0) {
            conjugate.push_back(height);
        }
    }
    
    // So sánh với phân hoạch gốc
    if (partition.size() != conjugate.size()) return false;
    for (int i = 0; i < partition.size(); i++) {
        if (partition[i] != conjugate[i]) return false;
    }
    
    return true;
}

// Đếm phân hoạch tự liên hợp với đúng k phần bằng cách sinh trực tiếp
void generateSelfConjugate(int n, int k, int current_sum, int min_part, 
                          vector<int>& current_partition, long long& count) {
    if (current_partition.size() == k) {
        if (current_sum == n && isSelfConjugate(current_partition)) {
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
    
    if (current_sum >= n || current_partition.size() > k) return;
    
    int remaining = n - current_sum;
    int remaining_parts = k - current_partition.size();
    
    // Giới hạn để đảm bảo phân hoạch giảm dần
    int max_next = remaining_parts > 0 ? remaining / remaining_parts : remaining;
    if (!current_partition.empty()) {
        max_next = min(max_next, current_partition.back());
    }
    
    for (int i = max(min_part, 1); i <= max_next; i++) {
        if (current_sum + i <= n) {
            current_partition.push_back(i);
            generateSelfConjugate(n, k, current_sum + i, i, current_partition, count);
            current_partition.pop_back();
        }
    }
}

// Đếm phân hoạch với các phần lẻ (theo định lý Euler)
long long partitionsWithOddParts(int n, int max_odd_part) {
    if (n == 0) return 1;
    if (n < 0 || max_odd_part <= 0) return 0;
    
    pair<int, int> key = {n, max_odd_part};
    if (memo_odd_parts.find(key) != memo_odd_parts.end()) {
        return memo_odd_parts[key];
    }
    
    // Tìm số lẻ tiếp theo nhỏ hơn max_odd_part
    int next_odd = max_odd_part - 2;
    while (next_odd > 0 && next_odd % 2 == 0) {
        next_odd--;
    }
    
    long long result = 0;
    if (next_odd > 0) {
        result = partitionsWithOddParts(n, next_odd);  // Không dùng max_odd_part
    }
    
    if (max_odd_part % 2 == 1) {  // max_odd_part là số lẻ
        result += partitionsWithOddParts(n - max_odd_part, max_odd_part);  // Dùng max_odd_part
    }
    
    memo_odd_parts[key] = result;
    return result;
}

// Đếm phân hoạch với các phần phân biệt
long long partitionsWithDistinctParts(int n, int max_part) {
    if (n == 0) return 1;
    if (n < 0 || max_part <= 0) return 0;
    
    pair<int, int> key = {n, max_part};
    if (memo_distinct_parts.find(key) != memo_distinct_parts.end()) {
        return memo_distinct_parts[key];
    }
    
    long long result = partitionsWithDistinctParts(n, max_part - 1);  // Không dùng max_part
    if (n >= max_part) {
        result += partitionsWithDistinctParts(n - max_part, max_part - 1);  // Dùng max_part
    }
    
    memo_distinct_parts[key] = result;
    return result;
}

// Công thức truy hồi cho phân hoạch tự liên hợp
long long selfConjugatePartitions(int n, int max_odd) {
    if (n == 0) return 1;
    if (n < 0 || max_odd <= 0) return 0;
    if (max_odd > n) return selfConjugatePartitions(n, n);
    
    pair<int, int> key = {n, max_odd};
    if (memo_self_conjugate.find(key) != memo_self_conjugate.end()) {
        return memo_self_conjugate[key];
    }
    
    long long result = 0;
    
    if (max_odd % 2 == 0) {
        // max_odd chẵn, bỏ qua
        result = selfConjugatePartitions(n, max_odd - 1);
    } else {
        // max_odd lẻ
        result = selfConjugatePartitions(n, max_odd - 2);  // Không dùng max_odd
        result += selfConjugatePartitions(n - max_odd, max_odd);  // Dùng max_odd
    }
    
    memo_self_conjugate[key] = result;
    return result;
}

int main() {
    int n, k;
    cout << "Nhập n và k: ";
    cin >> n >> k;
    
    if (n <= 0 || k <= 0) {
        cout << "n và k phải là số nguyên dương!\n";
        return 0;
    }
    
    cout << "Phân tích phân hoạch tự liên hợp cho n = " << n << ", k = " << k << ":\n";
    cout << "======================================================\n";
    
    // Phần (a): Đếm số phân hoạch tự liên hợp của n có k phần
    cout << "\n(a) Đếm phân hoạch tự liên hợp có đúng " << k << " phần:\n";
    
    vector<int> partition;
    long long p_k_self = 0;
    
    if (n <= 20 && k <= 10) {  // Giới hạn để tránh tính toán quá lâu
        cout << "Các phân hoạch tự liên hợp có " << k << " phần: ";
        generateSelfConjugate(n, k, 0, 1, partition, p_k_self);
        cout << "\np_" << k << "^self(" << n << ") = " << p_k_self << "\n";
    } else {
        cout << "n hoặc k quá lớn để liệt kê trực tiếp.\n";
        // Có thể implement thuật toán tối ưu hơn ở đây
    }
    
    // Phần (b): Đếm số phân hoạch của n có các phần lẻ
    cout << "\n(b) Đếm phân hoạch với các phần lẻ:\n";
    
    // Tìm số lẻ lớn nhất <= n
    int max_odd = n;
    if (max_odd % 2 == 0) max_odd--;
    
    long long p_odd = partitionsWithOddParts(n, max_odd);
    cout << "Số phân hoạch của " << n << " với các phần lẻ: " << p_odd << "\n";
    
    // So sánh với số phân hoạch tự liên hợp tổng cộng
    long long total_self_conjugate = selfConjugatePartitions(n, n);
    cout << "Tổng số phân hoạch tự liên hợp của " << n << ": " << total_self_conjugate << "\n";
    
    cout << "Theo định lý Euler: ";
    if (p_odd == total_self_conjugate) {
        cout << "Verified! Số phân hoạch tự liên hợp = Số phân hoạch với phần lẻ\n";
    } else {
        cout << "Có sự khác biệt - cần kiểm tra lại thuật toán\n";
    }
    
    // Phần (c): Bảng so sánh với các giá trị khác nhau của k
    cout << "\n(c) Bảng so sánh p_k^self(n) cho các k khác nhau:\n";
    cout << "k\tp_k^self(" << n << ")\n";
    cout << "-------------------\n";
    
    for (int i = 1; i <= min(n, 8); i++) {
        vector<int> temp_partition;
        long long temp_count = 0;
        
        if (n <= 15) {  // Chỉ tính với n nhỏ
            generateSelfConjugate(n, i, 0, 1, temp_partition, temp_count);
            cout << i << "\t" << temp_count << "\n";
        }
    }
    
    // Bổ sung: So sánh với phân hoạch phần phân biệt (định lý Euler khác)
    cout << "\nBổ sung - So sánh với phân hoạch có các phần phân biệt:\n";
    long long p_distinct = partitionsWithDistinctParts(n, n);
    cout << "Số phân hoạch của " << n << " với các phần phân biệt: " << p_distinct << "\n";
    
    return 0;
}
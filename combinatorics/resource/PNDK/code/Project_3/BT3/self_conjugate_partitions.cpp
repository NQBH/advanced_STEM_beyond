#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sinh tất cả phân hoạch của n thành đúng k phần
vector<vector<int>> generate_partitions(int n, int k, int max_val = -1) {
    vector<vector<int>> result;
    
    if (max_val == -1) {
        max_val = n;
    }
    
    if (k == 1) {
        if (n >= 1 && n <= max_val) {
            result.push_back({n});
        }
        return result;
    }
    
    if (k > n || n <= 0) {
        return result;
    }
    
    int min_first = max(1, (n + k - 1) / k);
    int max_first = min(n - k + 1, max_val);
    
    for (int first = min_first; first <= max_first; first++) {
        vector<vector<int>> sub_partitions = generate_partitions(n - first, k - 1, first);
        for (auto& partition : sub_partitions) {
            vector<int> new_partition = {first};
            new_partition.insert(new_partition.end(), partition.begin(), partition.end());
            result.push_back(new_partition);
        }
    }
    
    return result;
}

bool is_self_conjugate(const vector<int>& partition) {
    // Tạo Ferrers transpose
    int max_width = partition.empty() ? 0 : partition[0];
    vector<int> conjugate;
    for (int col = 0; col < max_width; col++) {
        int count = 0;
        for (int row = 0; row < (int)partition.size(); row++) {
            if (col < partition[row]) {
                count++;
            } else {
                break;
            }
        }
        if (count > 0) {
            conjugate.push_back(count);
        } else {
            break;
        }
    }
    return partition == conjugate;
}

pair<int, vector<vector<int>>> count_self_conjugate_partitions(int n, int k) {
    vector<vector<int>> partitions = generate_partitions(n, k);
    int self_conjugate_count = 0;
    vector<vector<int>> self_conjugate_partitions;
    
    for (const auto& partition : partitions) {
        if (is_self_conjugate(partition)) {
            self_conjugate_count++;
            self_conjugate_partitions.push_back(partition);
        }
    }
    
    return {self_conjugate_count, self_conjugate_partitions};
}

int count_partitions_k_parts(int n, int k) {
    if (k == 1) {
        return (1 <= n && n <= k) ? 1 : 0;
    }
    if (k > n || n <= 0) {
        return 0;
    }
    int total = 0;
    for (int m = 1; m <= min(k, n); m++) {
        total += count_partitions_k_parts(n - m, k - 1, m);
    }
    return total;
}

int main() {
    int n, k;
    
    cout << "Nhập n: ";
    cin >> n;
    cout << "Nhập k: ";
    cin >> k;
    
    if (n <= 0 || k <= 0) {
        cout << "n và k phải là số nguyên dương!\n";
        return 1;
    }
    
    // Tính p_selfconj(n, k)
    auto [self_conjugate_count, self_conjugate_partitions] = count_self_conjugate_partitions(n, k);
    cout << "\nSố phân hoạch tự liên hợp của " << n << " thành " << k << " phần: " << self_conjugate_count << endl;
    cout << "Các phân hoạch tự liên hợp:\n";
    for (const auto& partition : self_conjugate_partitions) {
        for (int part : partition) {
            cout << part << " ";
        }
        cout << endl;
    }
    
    // Tính p_k(n)
    int p_k = count_partitions_k_parts(n, k);
    cout << "\nSố phân hoạch của " << n << " thành " << k << " phần: " << p_k << endl;
    
    // So sánh
    cout << "\nSo sánh:\n";
    if (self_conjugate_count > p_k) {
        cout << "p_selfconj(" << n << ", " << k << ") > p_" << k << "(" << n << ")\n";
    } else if (self_conjugate_count < p_k) {
        cout << "p_selfconj(" << n << ", " << k << ") < p_" << k << "(" << n << ")\n";
    } else {
        cout << "p_selfconj(" << n << ", " << k << ") = p_" << k << "(" << n << ")\n";
    }
    
    return 0;
}
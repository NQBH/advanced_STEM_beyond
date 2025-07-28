#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sinh tất cả phân hoạch của n
vector<vector<int>> generate_all_partitions(int n, int max_val = -1) {
    vector<vector<int>> result;
    
    if (max_val == -1) {
        max_val = n;
    }
    
    if (n == 0) {
        result.push_back({});
        return result;
    }
    
    for (int first = min(n, max_val); first >= 1; first--) {
        vector<vector<int>> sub_partitions = generate_all_partitions(n - first, first);
        for (auto& partition : sub_partitions) {
            vector<int> new_partition = {first};
            new_partition.insert(new_partition.end(), partition.begin(), partition.end());
            result.push_back(new_partition);
        }
    }
    
    return result;
}

// Đếm số phân hoạch có phần tử lớn nhất là k
int count_partitions_with_max(int n, int k) {
    if (k > n || k <= 0) {
        return 0;
    }
    
    vector<vector<int>> partitions = generate_all_partitions(n);
    int count = 0;
    
    for (const auto& partition : partitions) {
        if (!partition.empty() && partition[0] == k) {
            count++;
        }
    }
    
    return count;
}

// Sinh phân hoạch thành k phần
vector<vector<int>> generate_partitions_k_parts(int n, int k, int max_val = -1) {
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
        vector<vector<int>> sub_partitions = generate_partitions_k_parts(n - first, k - 1, first);
        for (auto& partition : sub_partitions) {
            vector<int> new_partition = {first};
            new_partition.insert(new_partition.end(), partition.begin(), partition.end());
            result.push_back(new_partition);
        }
    }
    
    return result;
}

// Đếm số phân hoạch thành k phần
int count_partitions_k_parts(int n, int k) {
    vector<vector<int>> partitions = generate_partitions_k_parts(n, k);
    return partitions.size();
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
    
    // Tính p_max(n, k)
    int p_max = count_partitions_with_max(n, k);
    
    // Tính p_k(n)
    int p_k = count_partitions_k_parts(n, k);
    
    cout << "\nKết quả:\n";
    cout << "p_max(" << n << ", " << k << ") = " << p_max << "\n";
    cout << "p_" << k << "(" << n << ") = " << p_k << "\n";
    
    cout << "\nSo sánh:\n";
    if (p_max > p_k) {
        cout << "p_max(" << n << ", " << k << ") > p_" << k << "(" << n << ")\n";
    } else if (p_max < p_k) {
        cout << "p_max(" << n << ", " << k << ") < p_" << k << "(" << n << ")\n";
    } else {
        cout << "p_max(" << n << ", " << k << ") = p_" << k << "(" << n << ")\n";
    }
    
    return 0;
}
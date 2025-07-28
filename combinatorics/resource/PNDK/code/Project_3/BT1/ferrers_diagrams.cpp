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
    
    // Tính giới hạn cho phần tử đầu tiên
    int min_first = max(1, (n + k - 1) / k);  // ceil(n/k)
    int max_first = min(n - k + 1, max_val);
    
    for (int first = min_first; first <= max_first; first++) {
        // Sinh phân hoạch cho phần còn lại
        vector<vector<int>> sub_partitions = generate_partitions(n - first, k - 1, first);
        
        for (auto& partition : sub_partitions) {
            vector<int> new_partition = {first};
            new_partition.insert(new_partition.end(), partition.begin(), partition.end());
            result.push_back(new_partition);
        }
    }
    
    return result;
}

// In biểu đồ Ferrers
void print_ferrers_diagram(const vector<int>& partition, const string& title) {
    cout << title << ":\n";
    for (int part : partition) {
        for (int i = 0; i < part; i++) {
            cout << "*";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Tìm phân hoạch liên hợp (chuyển vị)
vector<int> get_conjugate_partition(const vector<int>& partition) {
    if (partition.empty()) {
        return {};
    }
    
    vector<int> conjugate;
    int max_width = partition[0];
    
    // Đếm số dấu * ở mỗi cột
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
    
    return conjugate;
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
    
    cout << "\n=== TẤT CẢ PHÂN HOẠCH pk(" << n << ") VỚI k=" << k << " ===\n\n";
    
    vector<vector<int>> partitions = generate_partitions(n, k);
    
    if (partitions.empty()) {
        cout << "Không tồn tại phân hoạch của " << n << " thành đúng " << k << " phần!\n";
        return 0;
    }
    
    cout << "Tổng số phân hoạch: " << partitions.size() << "\n\n";
    
    for (int i = 0; i < (int)partitions.size(); i++) {
        cout << "--- Phân hoạch " << (i + 1) << ": (";
        for (int j = 0; j < (int)partitions[i].size(); j++) {
            cout << partitions[i][j];
            if (j < (int)partitions[i].size() - 1) cout << ", ";
        }
        cout << ") ---\n";
        
        // In biểu đồ Ferrers gốc
        print_ferrers_diagram(partitions[i], "Biểu đồ Ferrers F");
        
        // Tìm và in biểu đồ Ferrers chuyển vị
        vector<int> conjugate = get_conjugate_partition(partitions[i]);
        print_ferrers_diagram(conjugate, "Biểu đồ Ferrers chuyển vị F^T");
    }
    
    return 0;
}
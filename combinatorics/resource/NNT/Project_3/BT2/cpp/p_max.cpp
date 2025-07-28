#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sinh phân hoạch n thành k phần (không tăng)
void generate_partitions(int n, int k, int max_val, vector<int>& current, vector<vector<int>>& result) {
    if (k == 0) {
        if (n == 0) result.push_back(current);
        return;
    }
    for (int i = min(n, max_val); i >= 1; --i) {
        current.push_back(i);
        generate_partitions(n - i, k - 1, i, current, result);
        current.pop_back();
    }
}

// Sinh phân hoạch n mà phần tử lớn nhất là k (không tăng)
void generate_pmax(int n, int k, vector<int>& current, vector<vector<int>>& result) {
    if (n == 0 && !current.empty()) {
        // Kiểm tra xem k có xuất hiện trong phân hoạch không
        bool has_k = false;
        for (int x : current) {
            if (x == k) {
                has_k = true;
                break;
            }
        }
        if (has_k) {
            result.push_back(current);
        }
        return;
    }
    
    if (n <= 0) return;
    
    // Đảm bảo thứ tự không tăng: phần tử tiếp theo không lớn hơn phần trước
    int max_val = current.empty() ? k : min(current.back(), k);
    for (int i = max_val; i >= 1; --i) {
        current.push_back(i);
        generate_pmax(n - i, k, current, result);
        current.pop_back();
    }
}

void print_partition(const vector<int>& part) {
    for (int x : part) cout << x << ' ';
    cout << '\n';
}

int main() {
    int n, k;
    cout << "Nhap n, k: ";
    cin >> n >> k;
    
    vector<vector<int>> pk_partitions, pmax_partitions;
    vector<int> current;
    
    // p_k(n): phân hoạch n thành k phần
    generate_partitions(n, k, n, current, pk_partitions);
    
    // p_max(n, k): phân hoạch n mà phần tử lớn nhất là k
    generate_pmax(n, k, current, pmax_partitions);
    
    cout << "\nSo phan hoach n thanh k phan (p_k(n)): " << pk_partitions.size() << endl;
    cout << "Cac phan hoach p_k(n):" << endl;
    for (auto& part : pk_partitions) print_partition(part);
    
    cout << "\nSo phan hoach n co phan tu lon nhat la k (p_max(n, k)): " << pmax_partitions.size() << endl;
    cout << "Cac phan hoach p_max(n, k):" << endl;
    for (auto& part : pmax_partitions) print_partition(part);
    
    cout << "\nSo sanh: p_k(n) = " << pk_partitions.size() << ", p_max(n, k) = " << pmax_partitions.size() << endl;
    
    return 0;
}
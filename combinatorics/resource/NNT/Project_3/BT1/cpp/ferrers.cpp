#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm sinh tất cả các phân hoạch của n thành k phần, thứ tự không tăng
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

// In biểu đồ Ferrers
void print_ferrers(const vector<int>& partition) {
    for (int x : partition) {
        for (int i = 0; i < x; ++i) cout << "* ";
        cout << '\n';
    }
}

// In biểu đồ Ferrers chuyển vị
void print_ferrers_transpose(const vector<int>& partition) {
    int max_row = *max_element(partition.begin(), partition.end());
    for (int i = 0; i < max_row; ++i) {
        for (int j = 0; j < partition.size(); ++j) {
            if (partition[j] > i) cout << "* ";
            else cout << "  ";
        }
        cout << '\n';
    }
}

int main() {
    int n, k;
    cout << "Nhap n, k: ";
    cin >> n >> k;
    vector<vector<int>> partitions;
    vector<int> current;
    generate_partitions(n, k, n, current, partitions);
    cout << "So phan hoach: " << partitions.size() << endl;
    for (int idx = 0; idx < partitions.size(); ++idx) {
        cout << "Phan hoach " << idx + 1 << ": ";
        for (int x : partitions[idx]) cout << x << ' ';
        cout << "\nFerrers diagram:\n";
        print_ferrers(partitions[idx]);
        cout << "Ferrers transpose diagram:\n";
        print_ferrers_transpose(partitions[idx]);
        cout << "--------------------------\n";
    }
    return 0;
}

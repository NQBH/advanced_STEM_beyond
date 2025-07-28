#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate_partitions(int n, int k, int max_val, vector<int>& current, vector<vector<int>>& partitions) {
    if (k == 0) {
        if (n == 0) partitions.push_back(current);
        return;
    }
    if (n < k) return;
    for (int i = 1; i <= min(n - k + 1, max_val); i++) {
        current.push_back(i);
        generate_partitions(n - i, k - 1, i, current, partitions);
        current.pop_back();
    }
}

void print_ferrers(const vector<int>& partition) {
    cout << "Ferrers diagram:" << endl;
    for (int val : partition) {
        for (int j = 0; j < val; j++) cout << "*";
        cout << endl;
    }
}

void print_ferrers_transpose(const vector<int>& partition) {
    cout << "Ferrers transpose diagram:" << endl;
    int max_val = *max_element(partition.begin(), partition.end());
    vector<int> transpose;
    for (int i = 1; i <= max_val; i++) {
        int count = 0;
        for (int val : partition) if (val >= i) count++;
        transpose.push_back(count);
    }
    for (int val : transpose) {
        for (int j = 0; j < val; j++) cout << "*";
        cout << endl;
    }
}

int main() {
    int n, k;
    cout << "Nhap n: "; cin >> n;
    cout << "Nhap k: "; cin >> k;
    vector<int> current;
    vector<vector<int>> partitions;
    generate_partitions(n, k, n, current, partitions);
    for (size_t i = 0; i < partitions.size(); i++) {
        cout << "\nPartition " << i + 1 << ": ";
        for (int val : partitions[i]) cout << val << " ";
        cout << endl;
        print_ferrers(partitions[i]);
        print_ferrers_transpose(partitions[i]);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Ham sinh phan hoach n thanh k phan
void generate_partitions(int n, int k, vector<int> prefix, vector<vector<int>>& result) {
    if (k == 0) {
        if (n == 0)
            result.push_back(prefix);
        return;
    }

    // Gia tri bat dau: n neu prefix rong, nguoc lai la min(prefix.back(), n)
    int start = prefix.empty() ? n : min(prefix.back(), n);

    // Duyet cac gia tri hop le
    for (int i = start; i >= 1; --i) {
        vector<int> new_prefix = prefix;
        new_prefix.push_back(i);
        generate_partitions(n - i, k - 1, new_prefix, result);
    }
}

// In bieu do Ferrers F
void print_ferrers(const vector<int>& partition) {
    for (int val : partition) {
        for (int i = 0; i < val; ++i)
            cout << '*';
        cout << '\n';
    }
}

// In bieu do Ferrers chuyen vi F^T
void print_transpose(const vector<int>& partition) {
    int max_len = *max_element(partition.begin(), partition.end());
    for (int i = 0; i < max_len; ++i) {
        for (int val : partition) {
            cout << (val > i ? '*' : ' ');
        }
        cout << '\n';
    }
}

int main() {
    int n, k;
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap k: ";
    cin >> k;

    cout << "Tat ca cac phan hoach cua " << n << " thanh " << k << " phan:\n\n";

    vector<vector<int>> partitions;
    vector<int> prefix;
    generate_partitions(n, k, prefix, partitions);

    int count = 0;
    for (size_t idx = 0; idx < partitions.size(); ++idx) {
        const auto& part = partitions[idx];
        cout << "Phan hoach " << (idx + 1) << ": [";
        for (size_t i = 0; i < part.size(); ++i) {
            cout << part[i];
            if (i + 1 < part.size()) cout << ", ";
        }
        cout << "]\n";

        cout << "Bieu do Ferrers F:\n";
        print_ferrers(part);

        cout << "Bieu do Ferrers chuyen vi F^T:\n";
        print_transpose(part);

        cout << string(30, '-') << "\n";
        ++count;
    }

    cout << "Tong so phan hoach p_" << k << "(" << n << ") = " << count << "\n";

    return 0;
}
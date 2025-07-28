#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// --- Phần 1: Liệt kê và in các phân hoạch ---

// Hàm tính phân hoạch chuyển vị (liên hợp)
vector<int> getTranspose(const vector<int>& partition) {
    if (partition.empty()) return {};
    vector<int> transpose(partition[0], 0);
    for (int part : partition) {
        for (int i = 0; i < part; ++i) {
            transpose[i]++;
        }
    }
    return transpose;
}

// Hàm kiểm tra một phân hoạch có tự liên hợp không
bool isSelfConjugate(const vector<int>& partition) {
    return partition == getTranspose(partition);
}

// Hàm in một phân hoạch
void printPartition(const vector<int>& partition) {
    cout << "(";
    for (size_t i = 0; i < partition.size(); ++i) {
        cout << partition[i] << (i == partition.size() - 1 ? "" : ", ");
    }
    cout << ")" << endl;
}

// Hàm đệ quy để tìm và in các phân hoạch tự liên hợp
void generateAndPrint(int n, int k, vector<int>& current_partition, int max_val) {
    if (k == 0) {
        if (n == 0) {
            if (isSelfConjugate(current_partition)) {
                printPartition(current_partition);
            }
        }
        return;
    }

    for (int i = min(n, max_val); i >= 1; --i) {
        if (n - i >= k - 1) {
            current_partition.push_back(i);
            generateAndPrint(n - i, k - 1, current_partition, i);
            current_partition.pop_back(); // Quay lui
        }
    }
}


// --- Phần 2: Đếm bằng Quy hoạch động ---

int countSelfConjugate(int n_max, int k_max) {
    // dp[i][j] là số phân hoạch tự liên hợp của i có j phần
    vector<vector<int>> dp(n_max + 1, vector<int>(k_max + 1, 0));
    dp[0][0] = 1; // Phân hoạch rỗng

    for (int k = 1; k <= k_max; ++k) {
        for (int i = 1; i <= n_max; ++i) {
            int prev_n = i - (2 * k - 1);
            if (prev_n >= 0) {
                int sum = 0;
                for (int j = 0; j < k; ++j) {
                    sum += dp[prev_n][j];
                }
                dp[i][k] = sum;
            }
        }
    }
    return dp[n_max][k_max];
}


int main() {
    int n, k;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    cout << "Nhap so phan tu k: ";
    cin >> k;
    
    cout << "\n--- Cau (a): Cac phan hoach tu lien hop cua " << n << " co " << k << " phan ---" << endl;
    vector<int> current_partition;
    if (n < k || k <= 0) {
        cout << "Khong co phan hoach nao." << endl;
    } else {
        generateAndPrint(n, k, current_partition, n - k + 1);
    }
    
    cout << "\n--- Cau (c): Dem so phan hoach bang Quy hoach dong ---" << endl;
    cout << "So luong: " << countSelfConjugate(n, k) << endl;

    return 0;
}
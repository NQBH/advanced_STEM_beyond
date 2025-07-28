#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> partitions;

void printFerrers(const vector<int>& partition) {
    cout << "Phân hoạch: ";
    for (int i = 0; i < partition.size(); i++) {
        cout << partition[i];
        if (i < partition.size() - 1) cout << " + ";
    }
    cout << "\n";
    
    // In biểu đồ Ferrers gốc
    cout << "Biểu đồ Ferrers:\n";
    for (int part : partition) {
        for (int j = 0; j < part; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    
    // In biểu đồ Ferrers chuyển vị
    cout << "Biểu đồ Ferrers chuyển vị:\n";
    if (!partition.empty()) {
        int maxCol = partition[0];  // Phần tử đầu tiên (lớn nhất)
        for (int col = 0; col < maxCol; col++) {
            for (int row = 0; row < partition.size(); row++) {
                if (col < partition[row]) {
                    cout << "*";
                }
            }
            cout << "\n";
        }
    }
    cout << "------------------------\n";
}

void generatePartitions(int n, int k, int currentSum, int lastValue, vector<int>& currentPartition) {
    // Nếu đã có đủ k phần
    if (currentPartition.size() == k) {
        if (currentSum == n) {
            partitions.push_back(currentPartition);
            printFerrers(currentPartition);
        }
        return;
    }
    
    // Nếu còn thiếu phần nhưng tổng đã bằng n
    if (currentSum == n) return;
    
    // Thử các giá trị từ 1 đến min(lastValue, n - currentSum)
    int remaining = n - currentSum;
    int remainingParts = k - currentPartition.size();
    
    // Đảm bảo có thể phân chia được
    for (int i = 1; i <= min(lastValue, remaining - remainingParts + 1); i++) {
        currentPartition.push_back(i);
        generatePartitions(n, k, currentSum + i, i, currentPartition);
        currentPartition.pop_back();
    }
}

int main() {
    int n, k;
    cout << "Nhập n và k: ";
    cin >> n >> k;
    
    // Kiểm tra điều kiện hợp lệ
    if (k > n || k <= 0 || n <= 0) {
        cout << "Không có phân hoạch nào thỏa mãn!\n";
        return 0;
    }
    
    vector<int> currentPartition;
    cout << "Các phân hoạch của " << n << " với đúng " << k << " phần:\n";
    cout << "========================\n";
    
    generatePartitions(n, k, 0, n, currentPartition);
    
    cout << "Tổng cộng có " << partitions.size() << " phân hoạch.\n";
    
    return 0;
}
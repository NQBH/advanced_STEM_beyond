#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Hàm in biểu đồ Ferrers từ một phân hoạch
void printDiagram(const vector<int>& partition) {
    for (int part : partition) {
        for (int i = 0; i < part; ++i) {
            cout << "* ";
        }
        cout << endl;
    }
}

// Hàm tính phân hoạch chuyển vị (liên hợp)
vector<int> getTranspose(const vector<int>& partition) {
    if (partition.empty()) {
        return {};
    }
    // Số phần tử của phân hoạch chuyển vị bằng giá trị phần tử lớn nhất
    vector<int> transpose(partition[0], 0);
    for (int part : partition) {
        for (int i = 0; i < part; ++i) {
            transpose[i]++;
        }
    }
    return transpose;
}

// Hàm đệ quy quay lui để tìm các phân hoạch
void findPartitions(int n, int k, vector<int>& current_partition, int max_val) {
    // Trường hợp cơ sở: đã đủ k phần tử
    if (k == 0) {
        // Nếu tổng đúng bằng n thì đây là một phân hoạch hợp lệ
        if (n == 0) {
            cout << "Phan hoach: ";
            for (int p : current_partition) cout << p << " ";
            cout << endl;

            cout << "Bieu do Ferrers:" << endl;
            printDiagram(current_partition);

            vector<int> transpose = getTranspose(current_partition);
            cout << "\nBieu do chuyen vi (Phan hoach lien hop: ";
            for (int p : transpose) cout << p << " ";
            cout << "):" << endl;
            printDiagram(transpose);
            cout << string(25, '-') << endl;
        }
        return;
    }

    // Thử các giá trị cho phần tử tiếp theo
    // Giá trị phải nhỏ hơn hoặc bằng max_val để đảm bảo thứ tự không tăng
    for (int i = min(n, max_val); i >= 1; --i) {
        // Điều kiện để đảm bảo các phần tử còn lại có thể tạo thành tổng
        if (n - i >= k - 1) { 
            current_partition.push_back(i);
            findPartitions(n - i, k - 1, current_partition, i);
            current_partition.pop_back(); // Quay lui
        }
    }
}

int main() {
    int n, k;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    cout << "Nhap so phan tu k: ";
    cin >> k;
    
    if (n < k || k <= 0) {
        cout << "Khong co phan hoach nao." << endl;
        return 0;
    }

    vector<int> current_partition;
    findPartitions(n, k, current_partition, n - k + 1);

    return 0;
}
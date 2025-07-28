#include <iostream>     // Thu vien nhap xuat
#include <vector>       // Su dung vector de luu cac phan hoach
using namespace std;

// Ham in bieu do Ferrers: moi phan tu la mot hang gom * 
void printFerrers(const vector<int>& part) {
    for (int row : part) {
        for (int i = 0; i < row; ++i)
            cout << "*";
        cout << "\n";
    }
}

// Ham in bieu do chuyen vi Ferrers
void printTranspose(const vector<int>& part) {
    int maxLen = part[0];  // Lay chieu cao lon nhat cua cot (phan tu lon nhat)
    for (int i = 0; i < maxLen; ++i) {  // Quet tung hang doc
        for (int val : part) {
            if (val > i)
                cout << "*";   // Cot van con phan tu => in *
            else
                cout << " ";   // Cot da het => in khoang trang
        }
        cout << "\n";
    }
}

// Ham sinh tat ca cac phan hoach cua n thanh k so, thu tu giam dan
void generatePartitions(int n, int k, vector<int> current = {}, int maxVal = -1) {
    if (maxVal == -1) maxVal = n;  // Neu chua co maxVal, set = n

    if (k == 0) {  // Khi da lay du k phan tu
        if (n == 0) {  // Va tong la dung n thi in ra
            cout << "Phan hoach: ";
            for (int x : current) cout << x << " ";
            cout << "\nFerrers:\n";
            printFerrers(current);
            cout << "Transpose:\n";
            printTranspose(current);
            cout << "----------\n";
        }
        return;
    }

    // Thu tung gia tri i tu min(n, maxVal) ve 1
    for (int i = min(n, maxVal); i >= 1; --i) {
        vector<int> next = current;
        next.push_back(i);  // Them i vao danh sach hien tai
        generatePartitions(n - i, k - 1, next, i);  // Goi de quy voi n-i va k-1
    }
}

// Chuong trinh chinh
int main() {
    int n, k;
    cout << "Nhap n: ";
    cin >> n;  // Tong so can phan hoach
    cout << "Nhap k: ";
    cin >> k;  // So thanh phan cua phan hoach
    generatePartitions(n, k);  // Goi ham sinh phan hoach va in ket qua
    return 0;
}
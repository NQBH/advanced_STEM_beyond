#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, c;
    cout << "Nhap so hang va so cot cua ma tran A (cach nhau bang dau cach): ";
    cin >> h >> c;
    vector<vector<int>> A(h, vector<int>(c));
    cout << "Nhap cac hang cua ma tran A (cach nhau bang dau cach):\n";
    for (int i = 0; i < h; ++i) {
        cout << "Hang " << i + 1 << ": ";
        for (int j = 0; j < c; ++j) {
            cin >> A[i][j];
        }
    }
    int size_b;
    cout << "Nhap kich thuoc cua ma tran B (so dong): ";
    cin >> size_b;
    vector<int> b(size_b);
    cout << "Nhap vector B (cac phan tu cach nhau bang dau cach): ";
    for (int i = 0; i < size_b; ++i) {
        cin >> b[i];
    }
    if (size_b != h) {
        cout << "Impossible\n";
    } else {
        cout << "Ma tran bo sung [A|B]:\n";
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < c; ++j) {
                cout << A[i][j] << " ";
            }
            cout << "| " << b[i] << "\n";
        }
    }
    return 0;
}


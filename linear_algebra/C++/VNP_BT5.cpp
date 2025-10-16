#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cout << "Nhap so hang cua ma tran A: ";
    cin >> a;
    cout << "Nhap so cot cua ma tran A: ";
    cin >> b;

    vector<vector<int>> A(a, vector<int>(b));
    vector<vector<int>> AT(b, vector<int>(a));

    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            AT[j][i] = A[i][j];
        }
    }

    cout << "\nMa tran A:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Ma tran chuyen vi A^T:";
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            cout << AT[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

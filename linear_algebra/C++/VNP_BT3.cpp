#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cout << "nhap so hang: ";
    cin >> a;
    cout << "nhap so cot: ";
    cin >> b;

    vector<vector<double>> A(a, vector<double>(b));
    cout << "nhap cac phan tu cua ma tran A" << endl;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> A[i][j];
        }
    }

    double c;
    cout << "nhap so thuc c ";
    cin >> c;

    vector<vector<double>> C(a, vector<double>(b));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            C[i][j] = A[i][j] * c;
        }
    }

    cout << "ma tran A khi nhan voi c la ";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << C[i][j] << " ";
        }
    }
    cout << endl;
    return 0;
}
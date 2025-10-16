#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    cout << "nhap so hang: ";
    cin >> a;
    cout << "nhap so cot: ";
    cin >> b;

    vector<vector<double>> A(b, vector<double>(a));
    cout << "nhap cac phan tu cua ma tran A" << endl;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "ma tran vua nhap:" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

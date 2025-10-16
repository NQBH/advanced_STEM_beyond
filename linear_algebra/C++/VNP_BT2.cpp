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
    vector<vector<double>> B(a, vector<double>(b));

    cout << "nhap cac phan tu cua ma tran A ";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "A[ " << i + 1 << " ]" << "[ " << j + 1 << " ]";
            cin >> A[i][j];
        }
    }
    cout << "nhap cac phan tu cua ma tran B ";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "B[ " << i + 1 << " ]" << "[ " << j + 1 << " ]";
            cin >> B[i][j];
        }
    }
    vector<vector<double>> C(a, vector<double>(b));
    vector<vector<double>> D(a, vector<double>(b));

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            C[i][j] = A[i][j] + B[i][j];
            D[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "ma tran A + B la ";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << C[i][j] << " ";
        }
    }
    cout << "\nMa tran A - B:\n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
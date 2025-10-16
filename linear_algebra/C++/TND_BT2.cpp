#include <iostream>
using namespace std;

int main() {
    int colums, rows;
    cout << "Nhap so hang va so cot: ";
    cin >> colums >> rows;

    double A[100][100], B[100][100], C[100][100] = {0};

    cout << "Nhap ma tran A:\n";
    for (int i = 0; i < colums; i++)
        for (int j = 0; j < rows; j++) cin >> A[i][j];

    cout << "Nhap ma tran B:\n";
    for (int i = 0; i < colums; i++)
        for (int j = 0; j < rows; j++) cin >> B[i][j];

    cout << "A + B:\n";
    for (int i = 0; i < colums; i++) {
        for (int j = 0; j < rows; j++) cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    cout << "A - B:\n";
    for (int i = 0; i < colums; i++) {
        for (int j = 0; j < rows; j++) cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

    cout << "A * B:\n";
    for (int i = 0; i < colums; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < rows; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

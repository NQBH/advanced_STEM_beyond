#include <iostream>
using namespace std;

int main()
{
    int row, colum;
    int A[10][10], B[10][10], C[10][10];

    cout << "Nhap so hang: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> colum;

    cout << "Nhap ma tran ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "Nhap ma tran ";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }

    cout << "A*B" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int row, colum;
    int A[10][10], C[10][10];

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

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            C[j][i] = A[i][j];
        }
    }

    cout << "Ma tran sau khi chuyen vi la" << endl;
    for (int i = 0; i < colum; i++) {
        for (int j = 0; j < row; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int row, colum;
    cout << "Nhap so hang: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> colum;
    int matrix[100][100];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << "matrix[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    cout << "Ma tran vua nhap:" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
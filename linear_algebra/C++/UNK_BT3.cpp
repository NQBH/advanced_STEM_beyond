#include <iostream>
using namespace std;

int main()
{
    int row, colum;
    int A[10][10], B[10][10], c;

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

    cout << "Nhap so thuc c" << endl;
    cin >> c;

    cout << "Ma tran sau khi nhan la" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < colum; j++) {
            cout << A[i][j] * c << " ";
        }
        cout << endl;
    }


    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int colums, rows, c;
    cout << "Nhap so hang va so cot: ";
    cin >> colums >> rows;
    cout << "Nhap so thuc c: ";
    cin >> c;

    int matrix[100][100];

    cout << "\nNhap gia tri cho ma tran " << rows << "x" << colums << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nMa tran sau khi nhan voi c la:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            cout << matrix[i][j] * c << " ";
        }
        cout << endl;
    }
    return 0;
}
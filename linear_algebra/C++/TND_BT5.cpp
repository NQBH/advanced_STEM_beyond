#include <iostream>
using namespace std;

int main() 
{
    int colums, rows;
    cout << "Nhap so hang va so cot: ";
    cin >> colums >> rows;

    int matrix[100][100];

    cout << "\nNhap gia tri cho ma tran " << rows << "x" << colums << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colums; j++) {
            cout << "Nhap phan tu [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << "\nMa tran sau khi dao nguoc:\n";
    for (int i = 0; i < colums; i++) {
        for (int j = 0; j < rows; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
    
}
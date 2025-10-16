#include <iostream>
using namespace std;

int main() 
{
    int rows, cols;
    cout << "Nhap so hang va so cot cua ma tran A: ";
    cin >> rows >> cols;

    int A[100][100];
    cout << "\nNhap gia tri cho ma tran A (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    int SizeB;
    cout << "\nNhap so phan tu cua vector b: ";
    cin >> SizeB;

    int b[100];
    if (SizeB != rows) {
        cout << "Impossible";
        return 0;
    }

    cout << "Nhap vector b:\n";
    for (int i = 0; i < SizeB; i++) {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }

    cout << "\nMa tran bo sung [A|b]:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << "| " << b[i] << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

int main(){
    int a = 2, b = 2;
    cout << "Ma tran co so hang: " << a << " va so cot: " << b << endl;
    int A[a][b];

    cout << "\nNhap cac phan tu cua ma tran: " << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMa tran vua nhap la: " << endl;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < b; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    cout << "\nDinh thuc cua ma tran la: " << det << endl;
}
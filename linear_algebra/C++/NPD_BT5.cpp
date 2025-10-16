/*
Bai toan 5. Viet chương trình tìm ma tran chuyển vị AT E Rnxm của 1 ma trận A E Rmxn cho trước.
*/

#include <iostream>

using namespace std;

int main(){
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    int A[m][n];
    int ketqua[n][m];

    cout << "\nNhap cac phan tu cua ma tran: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    //doi vi tri hang cot
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ketqua[j][i] = A[i][j];
        }
    }

    cout << "\nMa tran truoc khi chuyen vi: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMa tran chuyen vi la: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ketqua[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
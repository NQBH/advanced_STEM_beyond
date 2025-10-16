/*
Bài toán 3 (Phép nhân vô hướng của ma trận với 1 hằng số). Viết chương trình Python, C++ để thực hiện phép nhân vô hướng
ma trận, A thuộc R mxn với 1 số thực c thuộc R
*/

#include <iostream>

using namespace std;

int main(){
    int m, n;
    float c;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    int A[m][n];
    float ketqua[m][n];

    cout << "\nNhap cac phan tu cua ma tran: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nNhap so thuc c: ";
    cin >> c;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            ketqua[i][j] = A[i][j] * c;
        }
    }
    
    cout << "\nMa tran sau khi nhan voi so thuc c la: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << ketqua[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
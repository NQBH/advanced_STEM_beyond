/*
Matrix - Ma trận
Bài toán 1 (Nhập xuất ma trận). Viết chương trình Python, C++ để nhập vào số hàng, số cột, & các phần tử của 1 ma trận
A thuộc Rm×n, sau đó xuất ra màn hình
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
    cout << "\nNhap cac phan tu cua ma tran: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMa tran vua nhap la: " << endl;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
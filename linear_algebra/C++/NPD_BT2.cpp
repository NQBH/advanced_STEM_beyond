/*
Bài toán 2 (Cộng, trừ ma trận). Viết chương trình Python, C++ để cộng, trừ 2 ma trận A,B thuộc R m x n
*/

#include <iostream>

using namespace std;

int main(){
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;
    int A[m][n], B[m][n];
    int Cong[m][n], Tru[m][n];

    cout << "\nNhap cac phan tu cua ma tran A: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nNhap cac phan tu cua ma tran B: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    // cong tru 2 ma tran A va B
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            Cong[i][j] = A[i][j] + B[i][j];
            Tru[i][j] = A[i][j] - B[i][j];
        }
    }

    cout << "\nMa tran A + B la: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << Cong[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nMa tran A - B la: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << Tru[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "so hang va cot: \n";
    cin >> n;

    int A[100][100];
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> A[i][j];
        }    
    }
    
    bool dgcheo = true;
    for (int i = 0; i < n && dgcheo; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && A[i][j] != 0) {
             dgcheo = false;
                break;
            }
        }
    }
    if (dgcheo)
        cout << "la matr dg cheo.\n";
    else
        cout << " kh phai la matr dg cheo.\n";
        
    bool tamgiactren = true;
    for (int i = 0; i < n && tamgiactren; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > j && A[i][j] != 0) {
             tamgiactren = false;
                break;
            }
        }
    }
    if (tamgiactren)
        cout << "la matr tam giac tren.\n";
    else
        cout << " kh phai la matr tam giac tren.\n";    

    bool tamgiacduoi = true;
        for (int i = 0; i < n && tamgiacduoi; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && A[i][j] != 0) {
                tamgiacduoi = false;
                    break;
                }
            }
        }
        if (tamgiacduoi)
            cout << "la matr tam giac duoi.\n";
        else
            cout << " kh phai la matr tam giac duoi.\n";    

    bool matrdoixung = true;
        for (int i = 0; i < n && matrdoixung; ++i) {
            for (int j = 0; j < n; ++j) {
                if (A[i][j] != A[j][i]) {
                matrdoixung = false;
                break;
            }
        }
    }
    if (matrdoixung)
        cout << "La matr doi xung.\n";
    else
        cout << "Khong phai la matr doi xung.\n";

    return 0;
}

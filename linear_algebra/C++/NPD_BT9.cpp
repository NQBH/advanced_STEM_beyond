#include <iostream>

using namespace std;

int main() {
    int a, b;
    cout << "Nhap so hang: ";
    cin >> a;
    cout << "nhap so cot: ";
    cin >> b;

    int A[a][b];
    cout << "\nNhap cac phan tu cua ma tran: " << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMa tran vua nhap la: " << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    bool maTranDuongCheo = true;
    bool maTranTamGiacTren = true;
    bool maTranTamGiacDuoi = true;
    bool maTranDoiXung = true;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            //  ma tran dg cheo, A[i][j] = 0, voi moi i != j
            if (i != j && A[i][j] != 0) {
                maTranDuongCheo = false;
            }
            // ma tran tam giac tren, A[i][j] = 0, voi moi i > j
            if (i > j && A[i][j] != 0) {
                maTranTamGiacTren = false;
            }
            // ma tran tam giac duoi, A[i][j] = 0, voi moi i < j
            if (i < j && A[i][j] != 0) {
                maTranTamGiacDuoi = false;
            }
            // ma tran doi xung, A[i][j] = A[j][i], A = A^T
            if (i > j && A[i][j] != A[j][i]) {
                maTranDoiXung = false;
            }
        }
    }

    cout << "\nKet qua kiem tra: " << endl;
    if (maTranDuongCheo) {
        cout << "Ma tran la ma tran duong cheo." << endl;
    } else if (maTranTamGiacTren) {
        cout << "Ma tran la ma tran tam giac tren." << endl;
    } else if (maTranTamGiacDuoi) {
        cout << "Ma tran la ma tran tam giac duoi." << endl;
    } else if (maTranDoiXung) {
        cout << "Ma tran la ma tran doi xung." << endl;
    } else {
        cout << "Ma tran khong phai la ma tran duong cheo, tam giac tren, tam giac duoi hay doi xung." << endl;
    }
}
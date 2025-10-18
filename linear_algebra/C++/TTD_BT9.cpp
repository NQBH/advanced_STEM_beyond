#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "==============================" << endl;
    cout << "CHUONG TRINH KIEM TRA CAC LOAI MA TRAN" << endl;
    cout << "==============================" << endl;

    vector<vector<vector<int>>> mau = {
        { {3, 0, 0}, {0, 5, 0}, {0, 0, 8} }, // Duong cheo
        { {2, 4, 5}, {0, 3, 7}, {0, 0, 6} }, // Tam giac tren
        { {3, 0, 0}, {4, 5, 0}, {6, 7, 8} }, // Tam giac duoi
        { {1, 2, 3}, {2, 4, 5}, {3, 5, 6} }  // Doi xung
    };
    string ten[] = {"Duong cheo", "Tam giac tren", "Tam giac duoi", "Doi xung"};

    for (int k = 0; k < 4; k++) {
        cout << "\nMa tran " << ten[k] << " la:" << endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << mau[k][i][j] << " ";
            cout << endl;
        }
    }

    while (true) {
        cout << "\n==============================" << endl;
        int a, b;
        cout << "Nhap so hang (0 de thoat): ";
        cin >> a;
        if (a == 0) {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        }
        cout << "Nhap so cot: ";
        cin >> b;

        int A[a][b];
        cout << "\nNhap cac phan tu cua ma tran:" << endl;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                cout << "A[" << i << "][" << j << "] = ";
                cin >> A[i][j];
            }
        }

        cout << "\nMa tran vua nhap la:" << endl;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }

        bool maTranDuongCheo = true;
        bool maTranTamGiacTren = true;
        bool maTranTamGiacDuoi = true;
        bool maTranDoiXung = (a == b); // chi vuong moi doi xung

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (i != j && A[i][j] != 0)
                    maTranDuongCheo = false;    //   A(i, j) = 0, voi moi i khac j
                if (i > j && A[i][j] != 0)
                    maTranTamGiacTren = false;  //  A(i,j)= 0, voi moi i > j
                if (i < j && A[i][j] != 0)
                    maTranTamGiacDuoi = false;  //  A(i,j)= 0, voi moi i < j
                if (maTranDoiXung && A[i][j] != A[j][i])
                    maTranDoiXung = false;      //  A(i,j) = A (j,i) , A = A^T
            }
        }

        cout << "\nKet qua kiem tra:" << endl;
        if (maTranDuongCheo) {
            cout << "Ma tran la ma tran duong cheo." << endl;
        } else if (maTranTamGiacTren) {
            cout << "Ma tran la ma tran tam giac tren." << endl;
        } else if (maTranTamGiacDuoi) {
            cout << "Ma tran la ma tran tam giac duoi." << endl;
        } else if (maTranDoiXung) {
            cout << "Ma tran la ma tran doi xung." << endl;
        } else {
            cout << "Ma tran khong phai la duong cheo, tam giac tren, tam giac duoi hay doi xung." << endl;
        }

        char tiep;
        cout << "\nBan co muon nhap ma tran khac khong? (y/n): ";
        cin >> tiep;
        if (tiep == 'n' || tiep == 'N') {
            cout << "Ket thuc chuong trinh." << endl;
            break;
        }
    }

    return 0;
}

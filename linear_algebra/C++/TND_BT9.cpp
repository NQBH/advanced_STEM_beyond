#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    if (n <= 0){
        cout << "Vui long n hap so nguyen duong > 0.";
        return 0;
    }

    double A[100][100];
    if (n > 100) {
        cout << "Vui long n khong vuot qua 100.\n";
        return 0;
    }
    cout << "\nNhap gia tri cho ma tran A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    cout << "\nMa tran A:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    bool duongCheo = true;
    bool tamGiacTren = true;
    bool tamGiacDuoi = true;
    bool doiXung = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && A[i][j] != 0)
                duongCheo = false;
            if (i < j && A[i][j] != 0)
                tamGiacTren = false;
            if (i > j && A[i][j] != 0)
                tamGiacDuoi = false;
            if (A[i][j] != A[j][i])
                doiXung = false;
        }
    }

    cout << "\nKet qua kiem tra:\n";
    cout << "- Ma tran duong cheo: " << (duongCheo ? "Co" : "Khong") << endl;
    cout << "- Ma tran tam giac tren: " << (tamGiacTren ? "Co" : "Khong") << endl;
    cout << "- Ma tran tam giac duoi: " << (tamGiacDuoi ? "Co" : "Khong") << endl;
    cout << "- Ma tran doi xung: " << (doiXung ? "Co" : "Khong") << endl;

    return 0;
}

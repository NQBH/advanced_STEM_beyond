#include <iostream>
using namespace std;

int main()
{
    int n;
    int A[100][100];
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n <= 0) {
        cout << "n phai la so nguyen duong";
        return 0;
    }
    cout << "Nhap ma tran A:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
        cout << endl;
    }
    cout << "Ma tran" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    bool duongcheo = true;
    bool tamGiacTren = true;
    bool tamGiacDuoi = true;
    bool doixung = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0 && i != j) {
                duongcheo = false;
            }
            if (A[i][j] != 0 && i < j) {
                tamGiacDuoi = false;
            }
            if (A[i][j] != 0 && i > j) {
                tamGiacTren = false;
            }
            if (A[i][j] != A[j][i]) {
                doixung = false;
            }
        }
    }
    cout << "Ma tran duong cheo: " << (duongcheo ? "true" : "false") << endl;
    cout << "Ma tran tam giac tren: " << (tamGiacTren ? "true" : "false") << endl;
    cout << "Ma tran tam giac duoi: " << (tamGiacDuoi ? "true" : "false") << endl;
    cout << "Ma tran doi xung: " << (doixung ? "true" : "false") << endl;

    return 0;


}
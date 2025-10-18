#include <iostream>
using namespace std;

int main() {
    int n;
    int A[100][100];

    cout << "Nhap kich thuoc ma tran vuong n x n: ";
    cin >> n;
    cout << "Nhap ma tran:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    bool duongCheo = true, tamGiacTren = true, tamGiacDuoi = true, doiXung = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && A[i][j] != 0)
                duongCheo = false;

            if (i > j && A[i][j] != 0)
                tamGiacTren = false;

            if (i < j && A[i][j] != 0)
                tamGiacDuoi = false;

            if (A[i][j] != A[j][i])
                doiXung = false;
        }
    }
    if (duongCheo)
        cout << "Day la ma tran duong cheo.\n";
    else if (tamGiacTren)
        cout << "Day la ma tran tam giac tren.\n";
    else if (tamGiacDuoi)
        cout << "Day la ma tran tam giac duoi.\n";
    else
        cout << "Day khong phai ma tran duong cheo hay tam giac.\n";

    if (doiXung)
        cout << "Day la ma tran doi xung (A = A^T).\n";
    else
        cout << "Day khong phai ma tran doi xung.\n";

    return 0;
}

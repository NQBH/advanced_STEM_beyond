#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Nhap kich thuoc ma tran n: ";
    cin >> n;
    int a[100][100];
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    bool duongCheo = true;
    bool tamGiacTren = true;
    bool tamGiacDuoi = true;
    bool doiXung = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && a[i][j] != 0)
                duongCheo = false;
            if (i > j && a[i][j] != 0)
                tamGiacTren = false;
            if (i < j && a[i][j] != 0)
                tamGiacDuoi = false;
            if (a[i][j] != a[j][i])
                doiXung = false;
        }
    }
    cout << "\nKet qua kiem tra:\n";
    cout << (duongCheo ? "- La ma tran duong cheo\n" : "- Khong phai ma tran duong cheo\n");
    cout << (tamGiacTren ? "- La ma tran tam giac tren\n" : "- Khong phai ma tran tam giac tren\n");
    cout << (tamGiacDuoi ? "- La ma tran tam giac duoi\n" : "- Khong phai ma tran tam giac duoi\n");
    cout << (doiXung ? "- La ma tran doi xung\n" : "- Khong phai ma tran doi xung\n");

    return 0;
}
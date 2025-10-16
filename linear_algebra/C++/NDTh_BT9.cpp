#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int a[100][100];

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    bool duong_cheo = true, tam_giac_tren = true, tam_giac_duoi = true, doi_xung = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && a[i][j] != 0) duong_cheo = false;
            if (i > j && a[i][j] != 0) tam_giac_tren = false;
            if (i < j && a[i][j] != 0) tam_giac_duoi = false;
            if (a[i][j] != a[j][i]) doi_xung = false;
        }
    }

    cout << "Duong cheo: " << (duong_cheo ? "Co" : "Khong") << endl;
    cout << "Tam giac tren: " << (tam_giac_tren ? "Co" : "Khong") << endl;
    cout << "Tam giac duoi: " << (tam_giac_duoi ? "Co" : "Khong") << endl;
    cout << "Doi xung: " << (doi_xung ? "Co" : "Khong") << endl;

    return 0;
}


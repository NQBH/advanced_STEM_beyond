#include <bits/stdc++.h>
using namespace std;

// In ma tran 0
void mt0(int n) {
    vector<vector<int> > a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "\t" << a[i][j];
        }
        cout << endl;
    }
}

// In ma tran don vi
void mtdv(int n) {
    vector<vector<int> > a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) a[i][j] = 1;
            cout << "\t" << a[i][j];
        }
        cout << endl;
    }
}

// Kiem tra ma tran duong cheo
bool checkcheo(vector<vector<int> >& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && a[i][j] != 0)
                return false;
    return true;
}

// Tam giac tren
bool check_giac_tren(vector<vector<int> >& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i][j] != 0)
                return false;
    return true;
}

// Tam giac duoi
bool check_giac_duoi(vector<vector<int> >& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i][j] != 0)
                return false;
    return true;
}

// Doi xung
bool check_dx(vector<vector<int> >& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[j][i])
                return false;
    return true;
}

// Nhap va xuat ma tran
void nhapmt(vector<vector<int> >& a, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cout << "Nhap [" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
}

void xuatmt(const vector<vector<int> >& a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << "\t" << a[i][j];
        cout << "\n";
    }
}

// Dinh thuc ma tran 2x2
void det(vector<vector<int> >& a) {
    if (a.size() != 2 || a[0].size() != 2) {
        cout << "Chi tinh duoc cho ma tran 2x2!\n";
        return;
    }
    int ans = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    cout << "Dinh thuc la: " << ans << endl;
}

int main() {
    int n = 0;
    vector<vector<int> > a;
    int choice;

    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Nhap & xuat ma tran\n";
        cout << "2. In ma tran 0\n";
        cout << "3. In ma tran don vi\n";
        cout << "4. Kiem tra ma tran duong cheo\n";
        cout << "5. Kiem tra ma tran tam giac tren\n";
        cout << "6. Kiem tra ma tran tam giac duoi\n";
        cout << "7. Kiem tra ma tran doi xung\n";
        cout << "8. Tinh dinh thuc ma tran 2x2\n";
        cout << "0. Thoat\n";
        cout << "=========================\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap cap ma tran n = ";
            cin >> n;
            a.assign(n, vector<int>(n));
            nhapmt(a, n);
            cout << "\nMa tran vua nhap:\n";
            xuatmt(a, n);
            break;
        case 2:
            cout << "Nhap cap ma tran n = ";
            cin >> n;
            mt0(n);
            break;
        case 3:
            cout << "Nhap cap ma tran n = ";
            cin >> n;
            mtdv(n);
            break;
        case 4:
            cout << (checkcheo(a) ? "? La ma tran duong cheo\n" : "? Khong phai ma tran duong cheo\n");
            break;
        case 5:
            cout << (check_giac_tren(a) ? "? La ma tran tam giac tren\n" : "? Khong phai ma tran tam giac tren\n");
            break;
        case 6:
            cout << (check_giac_duoi(a) ? "? La ma tran tam giac duoi\n" : "? Khong phai ma tran tam giac duoi\n");
            break;
        case 7:
            cout << (check_dx(a) ? "? La ma tran doi xung\n" : "? Khong phai ma tran doi xung\n");
            break;
        case 8:
            det(a);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    return 0;
}
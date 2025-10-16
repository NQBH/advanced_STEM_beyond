#include <iostream>
#include <vector>
using namespace std;
void nhapMTvuong(vector<vector<float> >& a, int& n) {
    cout << "Nhap cap ma tran vuong n x n: ";
    cin >> n;
    a.resize(n, vector<float>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
}

void xuatMT(const vector<vector<float> >& a) {
    int n = a.size();
    cout << "Ma tran vua nhap la:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

void ktramatrancheo(const vector<vector<float> >& a) {
    int n = a.size();
    bool cheo = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && a[i][j] != 0) {
                cheo = false;
                break;
            }
    if (cheo)
        cout << "Ma tran la ma tran duong cheo.\n";
    else
        cout << "Ma tran ko phai la ma tran duong cheo.\n";
}

void ktramatrantamgiactren(const vector<vector<float> >& a) {
    int n = a.size();
    bool tamgiac = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j && a[i][j] != 0) {
                tamgiac = false;
                break;
            }
    if (tamgiac)
        cout << "Ma tran la ma tran tam giac tren.\n";
    else
        cout << "Ma tran ko phai la ma tran tam giac tren.\n";
}

void ktramatrantamgiacduoi(const vector<vector<float> >& a) {
    int n = a.size();
    bool tamgiac = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < j && a[i][j] != 0) {
                tamgiac = false;
                break;
            }
    if (tamgiac)
        cout << "Ma tran la ma tran tam giac duoi.\n";
    else
        cout << "Ma tran ko phai la ma tran tam giac duoi.\n";
}

void ktramatrandoixung(const vector<vector<float> >& a) {
    int n = a.size();
    bool doixung = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != a[j][i]) {
                doixung = false;
                break;
            }
    if (doixung)
        cout << "Ma tran la ma tran doi xung.\n";
    else
        cout << "Ma tran ko phai la ma tran doi xung.\n";
}

int main() {
    vector<vector<float> > a;
    int n;
    nhapMTvuong(a, n);
    xuatMT(a);
    ktramatrancheo(a);
    ktramatrantamgiactren(a);
    ktramatrantamgiacduoi(a);
    ktramatrandoixung(a);
    return 0;
}


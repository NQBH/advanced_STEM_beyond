#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

matrix Nhap(ll m, ll n)
{
    matrix a(m, vector<ll>(n));
    for (vector<ll> &i : a)
        for (ll &j : i)
            cin >> j;
    return a;
}
matrix Nhan(matrix A, matrix B, ll m, ll n, ll p)
{
    matrix c(m, vector<ll>(p));

    for (ll i = 0; i < m; ++i) {
        for (ll j = 0; j < p; ++j) {
            for (ll k = 0; k < n; ++k) {
                c[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return c;
}
void xuat_ma_tran(matrix A)
{
    for (auto &i : A) {
        cout << "\n";
        for (auto &j : i)
            cout << j << " ";
    }
    cout << "\n";
}
void Cong_va_tru(matrix A, matrix B, ll m , ll n)
{
    cout << "Ma tran sau khi Cong:";
    for (ll i = 0; i < m; ++i) {
        cout << "\n";
        for (ll j = 0; j < n; ++j) {
            cout << A[i][j] + B[i][j] << " ";
        }
    }
    cout << "\n";
    cout << "Ma tran sau khi Tru:";
    for (ll i = 0; i < m; ++i) {
        cout << "\n";
        for (ll j = 0; j < n; ++j) {
            cout << A[i][j] - B[i][j] << " ";
        }
    }
    cout << "\n";
}


int main()
{
    ll m, n, n1, p;
    char lc;
    cout << "Nhap m,n cua ma tran A: " << "\n";
    cin >> m >> n;
    matrix A = Nhap(m, n);
    cout << "Nhap m,n cua ma tran B: " << "\n";
    cin >> n1 >> p;
    matrix B = Nhap(m, n);
    cout << "Ma tran A: ";
    xuat_ma_tran(A);
    cout << "Ma tran B: ";
    xuat_ma_tran(B);
    cout << "Ban co muon thuc hien Cong, Tru 2 ma tran khong? Y/N: " << "\n";
    cin >> lc;
    if (lc == 'y') {
        if (m == n1 && n == p) Cong_va_tru(A, B, m, n);
    }
    cout << "Ban co muon thuc hien nhan ma tran khong? Y/N: " << "\n";
    cin >> lc;
    if (lc == 'Y') {
        if (n == n1) {
            cout << "Ket qua nhan ma tran : ";
            matrix C;
            C = Nhan(A, B, m, n, p);
            xuat_ma_tran(C);
        }
        else cout << "Loi, ko thoa dieu kien nhan ma tran";
    }
    cout << "Ban co muon nhan ma tran A voi 1 so a khong? Y/N: \n";
    cin >> lc;
    if (lc == 'Y') {
        cout << "Hay nhap so thuc a:\n";
        ll a; cin >> a;
        cout << "Ma tran A sau khi nhan voi " << a << " la :";
        for (auto &i : A) {
            cout << "\n";
            for (auto &j : i)
                cout << j*a << " ";
        }
        cout << "\n";
    }
    cout << "Ban co muon tim ma tran chuyen vi cua A khong? Y/N: \n";
    cin >> lc;
    if (lc == 'Y') {
        cout << "Ma tran chuyen vi cua A:";
        for (ll i = 0; i < m; ++i) {
            cout << "\n";
            for (ll j = 0; j < n; ++j)
                cout << A[j][i] << " ";
        }
        cout << "\n";
    }
    cout << "Ban co muon kiem tra xem lieu ma tran A voi b co tao dc ma tran bo sung hay ko? Y/n: \n";
    cin >> lc;
    if (lc == 'Y') {
        cout << "Nhap do dai cua b: \n";
        ll p1; cin >> p1;
        vector<ll> b(p1);
        if (n == p1) {
            cout << "Nhap vector b:";
            for (ll &i : b) cin >> i;
            cout << "Ma tran bo sung A|b: ";
            ll ptb = 0;
            for (auto &i : A) {
                cout << "\n";
                for (auto &j : i) {
                    cout << j << " ";
                }
                cout << b[ptb++];
            }
            cout << "\n";
        }
        else cout << "Impossible" << "\n";
    }
    cout << "Ban co muon thuc hien 3 phep bien doi dong tren ma tran A khong? Y/n: \n";
    cin >> lc;
    if (lc == 'Y') {
        cout << "1. Doi Cho Hai Dong Bat Ky Cho Nhau.\n";
        cout << "Nhap 2 dong ma ban muon doi cho: \n";
        ll d1, d2; cin >> d1 >> d2;
        d1 -= 1; d2 -= 1;
        A[d1].swap(A[d2]);
        cout << "DA DOI CHO 2 DONG CHO NHAU: ";
        for (auto &i : A) {
            cout << "\n";
            for (auto &j : i)
                cout << j << " ";
        }
        cout << "\n";
        cout << "2. Nhan 1 Dong Voi 1 So Bat Ky Khac 0.\n";
        cout << "Nhap so dong va so a muon nhan:\n";
        ll d3, d4; cin >> d3 >> d4;
        d3 -= 1;
        for (ll &i : A[d3]) i *= d4;
        cout << "DA NHAN:";
        for (auto &i : A) {
            cout << "\n";
            for (ll &j : i)
                cout << j << " ";
        }
        cout << "\n";
        cout << "3. Nhan 1 Dong Voi 1 He So K (+ hoac -) * 1 Dong Khac: \n";
        cout << "Nhap dong muon thay doi, he so K va dong con lai: \n";
        ll d5, d6, d7; cin >> d5 >> d6 >> d7;
        d5 -= 1; d7 -= 1;
        cout << "DA XONG: ";
        for (ll i = 0; i < n; ++i) A[d5][i] += d6 * A[d7][i];
        for (auto &i : A) {
            cout << "\n";
            for (auto &j : i)
                cout << j << " ";
        }
        cout << "\n";
    }
}

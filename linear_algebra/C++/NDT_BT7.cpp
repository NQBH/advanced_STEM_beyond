#include <iostream>
#include <vector>
using namespace std;

void nhapMT(vector<vector<float>> &A, int &n, int &m) {
    cout << "Nhap so hang cua ma tran A ";
    cin >> n;
    cout << "Nhap so cot cua ma tran A ";
    cin >> m;
    A.resize(n, vector<float>(m));
    cout << "Nhap cac phan tu cua ma tran A\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "," << j << "] = ";
            cin >> A[i][j];
        }
    }
}
void xemMT(const vector<vector<float>> &A) {
    cout << "Ma tran hien tai\n";
    for (const auto &hang : A) {
        for (float x : hang)
            cout << x << "\t";
        cout << endl;
    }
}
int main() {
    vector<vector<float>> A;
    int n, m;
    nhapMT(A, n, m);
    xemMT(A);
    cout << "Chon thao tac\n";
    cout << "1 Doi cho 2 hang\n";
    cout << "2 Cong boi cua dong nay sang dong khac\n";
    cout << "3 Nhan 1 dong voi he so k\n";
    cout << "Nhap lua chon tu 1 den 3 ";
    int chon;
    cin >> chon;
    if (chon == 1) {
        cout << "Ban chon doi cho 2 hang\n";
        int i, j;
        cout << "Nhap 2 dong muon doi cho (tu 0 den " << n - 1 << ") ";
        cin >> i >> j;
        if (i >= 0 && i < n && j >= 0 && j < n) {
            swap(A[i], A[j]);
            xemMT(A);
        } else {
            cout << "Chi so dong khong hop le\n";
        }
    }
    else if (chon == 2) {
        cout << "Ban chon cong boi cua dong nay sang dong khac\n";
        cout << "Cong thuc R[i]=R[i]+k*R[j]\n";
        int i, j;
        float k;
        cout << "Nhap 2 dong i j (tu 0 den " << n - 1 << ") ";
        cin >> i >> j;
        cout << "Nhap he so k ";
        cin >> k;
        if (i >= 0 && i < n && j >= 0 && j < n) {
            for (int col = 0; col < m; col++) {
                A[i][col] += k * A[j][col];
            }
            cout << "Da thuc hien R[" << i << "] = R[" << i << "] + " << k << " * R[" << j << "]\n";
            xemMT(A);
        } else {
            cout << "Chi so dong khong hop le\n";
        }
    }
    else if (chon == 3) {
        cout << "Ban chon nhan mot dong voi he so k\n";
        int i;
        float k;
        cout << "Nhap dong i muon nhan (tu 0 den " << n - 1 << ") ";
        cin >> i;
        cout << "Nhap he so k ";
        cin >> k;
        if (i >= 0 && i < n) {
            for (int col = 0; col < m; col++) {
                A[i][col] *= k;
            }
            xemMT(A);
        } else {
            cout << "Chi so dong khong hop le\n";
        }
    }
    else {
        cout << "Lua chon khong hop le\n";
    }
    return 0;
}


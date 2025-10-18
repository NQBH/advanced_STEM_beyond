#include <iostream>
#include <vector>
using namespace std;

bool laMaTranDuongCheo(const vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && A[i][j] != 0)
                return false;
    return true;
}

bool laMaTranTamGiacTren(const vector<vector<int>>& A, int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (A[i][j] != 0)
                return false;
    return true;
}

bool laMaTranTamGiacDuoi(const vector<vector<int>>& A, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i][j] != 0)
                return false;
    return true;
}

bool laMaTranDoiXung(const vector<vector<int>>& A, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] != A[j][i])
                return false;
    return true;
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran vuong n: ";
    cin >> n;

    if (n <= 0) {
        cout << "n phai la so nguyen duong" << endl;
        return 0;
    }

    vector<vector<int>> A(n, vector<int>(n));
    cout << "Nhap cac phan tu cua ma tran A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "\nMa tran vua nhap:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    cout << "\n=== KET QUA KIEM TRA ===\n";
    cout << "- Ma tran duong cheo: " << (laMaTranDuongCheo(A, n) ? "CO" : "KHONG") << endl;
    cout << "- Ma tran tam giac tren: " << (laMaTranTamGiacTren(A, n) ? "CO" : "KHONG") << endl;
    cout << "- Ma tran tam giac duoi: " << (laMaTranTamGiacDuoi(A, n) ? "CO" : "KHONG") << endl;
    cout << "- Ma tran doi xung (A = A^T): " << (laMaTranDoiXung(A, n) ? "CO" : "KHONG") << endl;

    return 0;
}




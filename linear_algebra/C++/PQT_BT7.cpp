#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va cot cua ma tran A: ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "\nChon phep bien doi:\n";
    cout << "1. Hoan doi 2 dong\n";
    cout << "2. Nhan 1 dong voi hang so k\n";
    cout << "3. Cong 1 dong voi boi cua dong khac\n";
    int chon;
    cin >> chon;

    if (chon == 1) {
        int i, j;
        cout << "Nhap hai dong i va j can hoan doi (bat dau tu 0): ";
        cin >> i >> j;
        if (i >= 0 && i < m && j >= 0 && j < m)
            swap(A[i], A[j]);
        else {
            cout << "Chi so dong khong hop le!\n";
            return 0;
        }
    }
    else if (chon == 2) {
        int i; double k;
        cout << "Nhap dong i va he so k: ";
        cin >> i >> k;
        if (i >= 0 && i < m && k != 0)
            for (int c = 0; c < n; ++c)
                A[i][c] *= k;
        else {
            cout << "Du lieu khong hop le!\n";
            return 0;
        }
    }
    else if (chon == 3) {
        int i, j; double k;
        cout << "Nhap dong i, dong j va he so k (Ri = Ri + k*Rj): ";
        cin >> i >> j >> k;
        if (i >= 0 && i < m && j >= 0 && j < m)
            for (int c = 0; c < n; ++c)
                A[i][c] += k * A[j][c];
        else {
            cout << "Chi so dong khong hop le!\n";
            return 0;
        }
    }
    else {
        cout << "Lua chon khong hop le!\n";
        return 0;
    }

    cout << "\nMa tran sau khi bien doi:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << A[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
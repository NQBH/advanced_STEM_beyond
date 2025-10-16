#include <iostream>
#include <vector>
using namespace std;

void printMatrix(const vector<vector<double>>& A) {
    for (const auto& row : A) {
        for (double val : row) cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int m, n;
    cout << "Nhap m(dong) va n(cot): ";
    cin >> m >> n;

    if (m <= 0 || n <= 0) {
        cout << "Kich thuoc sai\n";
        return 0;
    }

    vector<vector<double>> A(m, vector<double>(n));

    cout << "Nhap ma tran:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    while (true) {
        cout << "\nMa tran:\n";
        printMatrix(A);

        cout << "\nChon:\n"
             << "1 - Hoan vi 2 dong\n"
             << "2 - Nhan dong voi he so\n"
             << "3 - Cong dong i voi k lan dong j\n"
             << "0 - Thoat\n"
             << "Chon: ";

        int chon;
        cin >> chon;

        if (chon == 0) break;

        int r1, r2;
        double k;

        if (chon == 1) {
            cout << "Nhap 2 dong: ";
            cin >> r1 >> r2;
            if (r1 < 1 || r1 > m || r2 < 1 || r2 > m) {
                cout << "Sai dong\n";
                continue;
            }
            swap(A[r1 - 1], A[r2 - 1]);
        } else if (chon == 2) {
            cout << "Nhap dong va he so k: ";
            cin >> r1 >> k;
            if (r1 < 1 || r1 > m) {
                cout << "Sai dong\n";
                continue;
            }
            for (double& val : A[r1 - 1]) val *= k;
        } else if (chon == 3) {
            cout << "Nhap dong i, he so k, dong j: ";
            cin >> r1 >> k >> r2;
            if (r1 < 1 || r1 > m || r2 < 1 || r2 > m) {
                cout << "Sai dong\n";
                continue;
            }
            for (int j = 0; j < n; j++)
                A[r1 - 1][j] += k * A[r2 - 1][j];
        } else {
            cout << "Lua chon sai\n";
        }
    }

    cout << "Ket thuc\n";
    return 0;
}
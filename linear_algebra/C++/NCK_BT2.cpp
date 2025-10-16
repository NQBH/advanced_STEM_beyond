#include <iostream>
#include <vector>
using namespace std;
int main() {
    int m, n;
    cout << "Nhap so hang va cot cua ma tran: ";
    cin >> m >> n;
    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu ma tran A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    cout << "Chon phep bien doi:\n";
    cout << "1. Hoan doi 2 dong\n";
    cout << "2. Nhan 1 dong voi 1 so khac 0\n";
    cout << "3. Cong boi cua dong nay vao dong khac\n";
    int chon; cin >> chon;
    if (chon == 1) {
        int r1, r2;
        cout << "Nhap 2 dong can hoan doi: ";
        cin >> r1 >> r2;
        swap(A[r1 - 1], A[r2 - 1]);
    }
    else if (chon == 2) {
        int r; double k;
        cout << "Nhap dong va he so nhan: ";
        cin >> r >> k;
        for (int j = 0; j < n; j++) {
            A[r - 1][j] *= k;
        }
    }
    else if (chon == 3) {
        int r1, r2; double k;
        cout << "Nhap dong bi cong, dong cong vao, va he so k: ";
        cin >> r1 >> r2 >> k;
        for (int j = 0; j < n; j++) {
            A[r1 - 1][j] += k * A[r2 - 1][j];
        }
    }
    else {
        cout << "Lua chon khong hop le!\n";
    }

    cout << "Ma tran sau bien doi:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
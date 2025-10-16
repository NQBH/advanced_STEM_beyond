#include <vector>
#include <iomanip>
using namespace std;

void printMatrix(const vector<vector<double>>& matrix) {
    if (matrix.empty()) return;
    cout << "\n----- Ma Tran Hien Tai -----\n";
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << setw(8) << val << " ";
        }
        cout << endl;
    }
    cout << "---------------------------\n";
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    for (int i = 0; i < m; ++i) {
        cout << i + 1;
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    int choice;
    do {
        printMatrix(A);
        cout << "1. Hoan vi hai dong " << endl;
        cout << "2. Nhan mot dong voi mot so k " << endl;
        cout << "3. Cong vao dong i mot boi cua dong j " << endl;
        cout << "0. Thoat" << endl;
        cin >> choice;

        int r1, r2;
        double k;


        switch (choice) {
        case 1:
            cout << "Nhap hai dong can hoan vi  ";
            cin >> r1 >> r2;
            if (r1 > 0 && r1 <= m && r2 > 0 && r2 <= m) {
                swap(A[r1 - 1], A[r2 - 1]);
            } else {
                cout << "sai so !" << endl;
            }
            break;
        case 2:
            cout << "Nhap dong can nhan va he so k ";
            cin >> r1 >> k;
            if (k == 0) {
                cout << "so phai != 0" << endl;
            } else if (r1 > 0 && r1 <= m) {
                for (int j = 0; j < n; ++j) {
                    A[r1 - 1][j] *= k;
                }
            } else {
                cout << "sai so !" << endl;
            }
            break;
        case 3:
            cout << "Nhap dong i, dong j va he so k  ";
            cin >> r1 >> r2 >> k;
            if (r1 > 0 && r1 <= m && r2 > 0 && r2 <= m) {
                for (int j = 0; j < n; ++j) {
                    A[r1 - 1][j] += k * A[r2 - 1][j];
                }
            } else {
                cout << "sai so !" << endl;
            }
            break;
        case 0:
            cout << "Thoat" << endl;
            break;
        default:
            cout << "Sai so! chon lai." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
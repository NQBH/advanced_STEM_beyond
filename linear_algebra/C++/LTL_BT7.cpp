#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
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
    cout << "Nhap so dong (m) va so cot (n): ";
    cin >> m >> n;

    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:\n";
    for (int i = 0; i < m; ++i) {
        cout << "Dong " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    int choice;
    do {
        printMatrix(A);
        cout << "\nChon phep bien doi so cap:" << endl;
        cout << "1. Hoan vi hai dong (R_i <-> R_j)" << endl;
        cout << "2. Nhan mot dong voi mot so k (R_i -> k * R_i)" << endl;
        cout << "3. Cong vao dong i mot boi cua dong j (R_i -> R_i + k * R_j)" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon cua ban: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int r1, r2;
        double k;

        switch (choice) {
        case 1:
            cout << "Nhap hai dong can hoan vi (vi du: 1 2): ";
            cin >> r1 >> r2;
            if (cin.fail() || r1 <= 0 || r1 > m || r2 <= 0 || r2 > m) {
                cout << "So dong khong hop le. Vui long thu lai." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                for (int j = 0; j < n; ++j) {
                    double temp = A[r1 - 1][j];
                    A[r1 - 1][j] = A[r2 - 1][j];
                    A[r2 - 1][j] = temp;
                }
                cout << "Da hoan vi dong " << r1 << " va dong " << r2 << "." << endl;
            }
            break;

        case 2:
            cout << "Nhap dong can nhan va he so k (vi du: 1 5.5): ";
            cin >> r1 >> k;
            if (cin.fail() || r1 <= 0 || r1 > m) {
                cout << "Nhap sai dong hoac he so. Vui long thu lai." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (k == 0) {
                cout << "He so k phai khac 0!" << endl;
            } else {
                for (int j = 0; j < n; ++j) {
                    A[r1 - 1][j] *= k;
                }
                cout << "Da nhan dong " << r1 << " voi he so " << k << "." << endl;
            }
            break;

        case 3:
            cout << "Thuc hien R_i -> R_i + k * R_j." << endl;
            cout << "Nhap dong i, dong j va he so k (vi du: 1 2 3): ";
            cin >> r1 >> r2 >> k;
            if (cin.fail() || r1 <= 0 || r1 > m || r2 <= 0 || r2 > m) {
                cout << "Nhap sai dong hoac he so. Vui long thu lai." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                for (int j = 0; j < n; ++j) {
                    A[r1 - 1][j] += k * A[r2 - 1][j];
                }
                cout << "Da thuc hien phep bien doi R" << r1 << " = R" << r1 << " + " << k << "*R" << r2 << "." << endl;
            }
            break;

        case 0:
            cout << "Da thoat chuong trinh." << endl;
            break;

        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

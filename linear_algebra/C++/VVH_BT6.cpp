#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang va so cot: ";
    cin >> m >> n;
// them vector ma tran A
    vector<vector<double>> A(m, vector<double>(n));
    cout << "Nhap cac phan tu cua ma tran A:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
	// thêm kich thuoc vector b
    int side_b;
    cout << "Nhap kich thuoc vector b: ";
    cin >> side_b;
	// them vector b
    vector<double> b(side_b);
    cout << "Nhap cac phan tu cua vector b:" << endl;
    for (int i = 0; i < side_b; ++i) {
        cin >> b[i];
    }
    // xem co loi ko 
    if (side_b != m) {
        cout << "Khong ton tai ma tran bo sung vi kich thuoc khong phu hop." << endl;
        return 0;
    }

    // In ma tran bo sung [A | b]
    cout << "Ma tran bo sung [A | b] la:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << "| " << b[i] << endl;
    }

    return 0;
}

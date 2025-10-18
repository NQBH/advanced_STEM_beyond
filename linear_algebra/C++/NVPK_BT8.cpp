#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void xuatMaTran(const vector<vector<int>>& maTran, const string& tenMaTran) {
    cout << "\n--- Ma tran " << tenMaTran << " kich thuoc " << maTran.size() << "x" << maTran.size() << " ---" << endl;
    for (const auto& hang : maTran) {
        for (int phanTu : hang) {
            cout << setw(3) << phanTu;
        }
        cout << endl;
    }
}
int main() {
    int n;
    cout << "nhap kich thuoc n(so nguyen duong): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Error: khong hop le, vui long nhap lai!" << endl;
        return 1; 
    }
    vector<vector<int>> maTranKhong(n, vector<int>(n, 0));

    vector<vector<int>> maTranDonVi(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        maTranDonVi[i][i] = 1;
    }
    xuatMaTran(maTranKhong, "Khong");
    xuatMaTran(maTranDonVi, "Don vi");

    return 0;
}
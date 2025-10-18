#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<vector<int>> A(2, vector<int>(2));

    cout << "nhập ma trận 2x2 dạng (a b; c d) cách nhau = khoảng trắng:\n";
    cin >> A[0][0] >> A[0][1] >> A[1][0] >> A[1][1];
    
    cout << "\nma trận đã nhập:" << endl;
    cout << A[0][0] << "\t" << A[0][1] << endl;
    cout << A[1][0] << "\t" << A[1][1] << endl;

    int det = A[0][0] * A[1][1] - A[0][1] * A[1][0];

    cout << "\nDinh thuc cua ma tran la: " << det << endl;

    return 0;
}

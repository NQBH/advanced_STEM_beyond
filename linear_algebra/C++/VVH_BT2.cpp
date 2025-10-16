#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Nhap so hang: ";
    cin >> m;
    cout << "Nhap so cot: ";
    cin >> n;

    vector<vector<int>> A(m, vector<int>(n)), B(m, vector<int>(n));

    cout << "Nhap ma tran A:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Nhap ma tran B:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    cout << "Tong 2 ma tran A va B la:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] + B[i][j] << " ";
        cout << endl;
    }

    cout << "Hieu 2 ma tran A va B la:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] - B[i][j] << " ";
        cout << endl;
    }

    return 0;
}
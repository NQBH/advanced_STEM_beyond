#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    vector<vector<int>> zeroMatrix(n, vector<int>(n, 0));

    vector<vector<int>> identityMatrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            identityMatrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    cout << "\n Ma tran 0 \n";
    for (const auto& row : zeroMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\n Ma tran Don vi\n";
    for (const auto& row : identityMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
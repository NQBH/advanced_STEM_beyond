#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "So nguyen duong n: ";
    cin >> n;

    vector<vector<int>> zero(n, vector<int>(n, 0));
    cout << "\nMa tran 0 (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) // neu n = 2; A(0,0);(0,1);(1,0);(1,1)
            cout << zero[i][j] << " ";
        cout << endl;
    }
    vector<vector<int>> identity(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        identity[i][i] = 1;

    cout << "\nMa tran don vi (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << identity[i][j] << " ";
        cout << endl;
    }

    return 0;
}

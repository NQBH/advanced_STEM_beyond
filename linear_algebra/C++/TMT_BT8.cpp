#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> zero(n, vector<int>(n, 0));
    vector<vector<int>> identity(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) identity[i][i] = 1;

    cout << "Ma tran 0:\n";
    for (auto &row : zero) { for (int x : row) cout << x << ' '; cout << '\n'; }

    cout << "\nMa tran don vi:\n";
    for (auto &row : identity) { for (int x : row) cout << x << ' '; cout << '\n'; }
}

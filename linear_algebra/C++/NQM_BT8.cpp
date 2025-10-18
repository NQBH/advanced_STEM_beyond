#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    vector<vector<int>> mt_0(n, vector<int>(n, 0));
    vector<vector<int>> mt_donvi(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        mt_donvi[i][i] = 1;
    }

    for (const auto& row : mt_0) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << endl;
    }

    cout << endl;

    for (const auto& row : mt_donvi) {
        for (int value : row) {
            cout << value << ' ';
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "nhap vao so nguyen duong n: ";
    cin >> n;
    if (n <= 0) {
        cout << "n phai la so nguyen duong" << endl;
        return 0;
    }
    vector<vector<int>> zeromatrix(n, vector<int>(n, 0));
    vector<vector<int>> identitymatrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        identitymatrix[i][i] = 1;
    }
    cout << "\nma tran 0 (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << zeromatrix[i][j] << " ";
        cout << endl;
    }
    cout << "\nMa tran don vi (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << identitymatrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}

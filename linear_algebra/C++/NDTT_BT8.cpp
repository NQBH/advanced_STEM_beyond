#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "so hang va cot: ";
    cin >> n;

    double a[100][100], b[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
            if (i == j) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = 0;
            }
        }
    }
    cout << "ma tran 0\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "ma tran don vi\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

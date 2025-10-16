#include <iostream>
using namespace std;

int main() {
    int m, n;
    double A[100][100], c;

    cout << " hang, so cot: ";
    cin >> m >> n;
    cout << "so c: ";
    cin >> c;

    cout << "ma tran A:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "c * A \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] * c << " ";
        cout << endl;
    }

    return 0;
}

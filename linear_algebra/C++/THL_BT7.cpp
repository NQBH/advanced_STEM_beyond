#include <iostream>
#include <vector>
using namespace std;

int main() {
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int> > A(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
        int r1, r2;
        cin >> r1 >> r2;
        if (r1 < 0 || r1 >= m || r2 < 0 || r2 >= m) {
            cout << "Impossible\n";
        } else {
            swap(A[r1], A[r2]);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j)
                    cout << A[i][j] << " ";
                cout << "\n";
            }
        }
    }
    {
        int m, n;
        cin >> m >> n;
        vector<vector<double> > A(m, vector<double>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
        int r;
        double alpha;
        cin >> r >> alpha;
        if (r < 0 || r >= m) {
            cout << "Impossible\n";
        } else {
            for (int j = 0; j < n; ++j)
                A[r][j] *= alpha;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j)
                    cout << A[i][j] << " ";
                cout << "\n";
            }
        }
    }
    {
        int m, n;
        cin >> m >> n;
        vector<vector<double> > A(m, vector<double>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
        int r1, r2;
        double k;
        cin >> r1 >> r2 >> k;
        if (r1 < 0 || r1 >= m || r2 < 0 || r2 >= m) {
            cout << "Impossible\n";
        } else {
            for (int j = 0; j < n; ++j)
                A[r1][j] += k * A[r2][j];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j)
                    cout << A[i][j] << " ";
                cout << "\n";
            }
        }
    }
    return 0;
}

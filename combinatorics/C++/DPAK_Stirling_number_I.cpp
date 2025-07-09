#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Stirling_number_I;

int main() {
    int N; cin >> N;
    Stirling_number_I.resize(N + 1, vector<int>(N + 1, 0));

    Stirling_number_I[0][0] = 1;

    for (int n = 1; n <= N; ++n)
        for (int k = 0; k <= n; ++k)
            if (k >= 1)
                Stirling_number_I[n][k] = (n - 1) * Stirling_number_I[n - 1][k] + Stirling_number_I[n - 1][k - 1];

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j)
            cout << Stirling_number_I[i][j] << "\t";
        cout << '\n';
    }
}
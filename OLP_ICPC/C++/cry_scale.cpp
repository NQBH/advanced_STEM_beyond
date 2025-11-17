#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
    	int n, k;
    	cin >> n >> k;
    	char A[n][n];
    	for (auto &row : A)
    		for (char &c: row) cin >> c;
    	for (int i = 0; i < n; i += k) {
    		for (int j = 0; j < n; j += k) cout << A[i][j];
    		cout << '\n';
    	}
    }
}
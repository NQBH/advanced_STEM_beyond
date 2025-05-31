#include <bits/stdc++.h>

using namespace std;
int N = 1e6;
vector<int> divisor(N + 5, 1);

void bruce_sieve() {
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j+=i) {
            divisor[j]++;
        }
    }
}

int main(){
    bruce_sieve();
    int n; cin >> n;
    while(n--) {
        int x; cin >> x;
        cout << divisor[x] << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            freq[x]++;
        }
        int score = 0;
        while (true) {
            int cnt = 0;
            while (freq[score] > 0) {
                freq[score]--;
                score++;
                cnt++;
            }
            if (cnt == 0) break;
        }
        cout << score << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    char current = s[0];
    int count = 1, answer = 1;
    cin >> s;
    for (int i = 0; i < static_cast<int>(s.size()); i++) {
        if (s[i] == current) {
            current = s[i];
            count ++;
        }
        else {
            current = s[i];
            count = 1;
        }
        answer = max(answer, count);
    }
    cout << answer << endl;
}
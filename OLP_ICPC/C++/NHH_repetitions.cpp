#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // int n; cin >> n;
    string s; cin >> s;

    int count = 1, max = 0;
    /*
    cout << s.size() << "\n";
    cout << s[s.size() - 1] << "\n";
    cout << s[s.size()] << "\n";
    */
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == s[i + 1]) {
            count++;
        } else {
            if (max < count) {
                max = count;
            };
            count = 1;
        }
    }
    cout << max << "\n";

    return 0;
}
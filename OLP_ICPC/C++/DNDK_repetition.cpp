#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int max_count = 1;
    int count = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else {
            count = 1;
        }
        if (count > max_count) {
            max_count = count;
        }
    }
    cout << max_count << endl;
    return 0;
}
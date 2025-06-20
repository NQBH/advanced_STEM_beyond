#include <bits/stdc++.h>
using namespace std;

int n3(int a) {
    int count = 0;
    while (a != 1) {
        if (a % 2 == 0) a /= 2;
        else a = a * 3 + 1;
        ++count;
    }
    return count;
}
int main() {
    int start, end, Max = 0;
    while (cin >> start >> end) {
        for (int i = start; i <= end; ++i) Max = max(Max, n3(i));
        cout << start << " " << end << " " << ++Max << '\n';
    }
}
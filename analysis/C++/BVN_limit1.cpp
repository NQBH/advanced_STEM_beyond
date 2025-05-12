//Cau b
#include <bits/stdc++.h>
using namespace std;

int main() {
    double epsilon;
    cin >> epsilon;
    int n = 2;
    double d = 1.0 / (n + 1);
    while (d >= epsilon) {
        n++;
        d = 1.0 / (n + 1);
    }
    cout << n;
    return 0;
}
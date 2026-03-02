#include <iostream>
using namespace std;
int main() {
    int n, a, chan, le;
    cout << "n = ";
    cin >> n;
    chan = le = 0;
    for (int i = 1 ; i <= n; ++i) {
        cin >> a;
        if (!(a % 2)) chan++;
        else le++;
    }
    cout << "so cac so chan la " << chan << endl;
    cout << "so cac so le la " << le << endl;
}
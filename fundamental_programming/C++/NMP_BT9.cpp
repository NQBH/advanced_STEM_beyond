#include <iostream>
using namespace std;

int main() {
    int n, a, chan = 0, le = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a % 2 == 0) chan++;
        else le++;
    }

    cout << "chan: " << chan << endl;
    cout << "le: " << le << endl;
    return 0;
}
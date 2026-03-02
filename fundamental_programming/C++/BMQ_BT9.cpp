#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;

    int chan = 0, le = 0;

    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x % 2 == 0) chan++;
        else le++;
    }

    cout << "So chan: " << chan << endl;
    cout << "So le: " << le << endl;
    return 0;
}

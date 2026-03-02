#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "n: ";
    cin >> n;

    int a;
    int demChan = 0, demLe = 0;

    for (int i = 1; i <= n; i++) {
        cout << "so thuC " << i << ": ";
        cin >> a;
        if (a % 2 == 0)
            demChan++;
        else
            demLe++;
    }

    cout << "chan: " << demChan << endl;
    cout << "le: " << demLe << endl;
    return 0;
}

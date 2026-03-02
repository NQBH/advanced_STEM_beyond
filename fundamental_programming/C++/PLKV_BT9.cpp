#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int demChan = 0, demLe = 0;
    int a;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a % 2 == 0)
            demChan++;
        else
            demLe++;
    }

    cout << demChan << endl;
    cout << demLe << endl;

    return 0;
}

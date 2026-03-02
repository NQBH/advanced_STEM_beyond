#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "n bang = ";
    cin >> n;
    int x;
    int demChan = 0, demLe = 0;

    for (int i = 1; i <= n; i++){
        cin >> x;
        if (x % 2 == 0) demChan++;
        else demLe++;
    }

    cout << "La so chan: " << demChan << endl;
    cout << "La so le: " << demLe << endl;

    return 0;
}
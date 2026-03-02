#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    int sc = 0, sl = 0;
    long long v;

    cout << "Nhap n: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cout << "Nhap so thu " << i << ": ";
        cin >> v;

        if (v % 2 == 0)
            sc++;
        else
            sl++;
    }

    cout << "Dem so chan: " << sc << endl;
    cout << "Dem so le: " << sl << endl;

    return 0;
}


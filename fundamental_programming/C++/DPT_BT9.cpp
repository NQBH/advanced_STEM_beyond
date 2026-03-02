#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int a = 0; //a la so chan
    int b = 0; //b la so le
    for (int i = 0; i < n; ++i) {
        int x;
        cout << "x = ";
        cin >> x;
        if (x % 2 == 0)
            a++;
        else
            b++;
    }
    cout << "so chan = " << a << '\n';
    cout << "so le = " << b << '\n';
}

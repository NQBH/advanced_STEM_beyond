#include <iostream>
using namespace std;
int main()
{
    float a, b, c, max, min;
    cin >> a >> b >> c;

    if (a >= b && a >= c)
        max = a;
    else if (b >= a && b >= c)
        max = b;
    else
        max = c;
    if (a <= b && a <= c)
        min = a;
    else if (b <= a && b <= c)
        min = b;
    else
        min = c;

    cout << "So lon nhat = " << max << endl;
    cout << "so nho nhat = " << min;
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
#define pi 3.1415
int main()
{
    float x, y, kq;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        kq = (x*x + y*y) * pi/100;
        cout << "Property " << i + 1 << ": This property will begin eroding in year " << ceil(kq) << endl;
    }
    cout << "END OF OUTPUT";
    return 0;
}
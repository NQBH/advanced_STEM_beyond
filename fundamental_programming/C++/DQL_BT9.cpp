#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    int demSoChan = 0, demSoLe = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x % 2 == 0)
            demSoChan++;
        else
            demSoLe++;
    }

    cout << "So chan: " << demSoChan << endl;
    cout << "So le: " << demSoLe;

    return 0;
}
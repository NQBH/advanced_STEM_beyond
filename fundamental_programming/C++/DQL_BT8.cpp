#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int demSoAm = 0, demSoDuong = 0, demSoKhong = 0;
    float x;

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x > 0)
            demSoDuong++;
        else if (x < 0)
            demSoAm++;
        else
            demSoKhong++;
    }

    cout << "So duong: " << demSoDuong << endl;
    cout << "So am: " << demSoAm << endl;
    cout << "So khong: " << demSoKhong;

    return 0;
}
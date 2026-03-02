#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n=";
    cin >> n;
    int duong = 0, am = 0;
    double x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0)
            duong = duong + 1;
        if (x < 0)
            am = am + 1;
    }
    cout << "so so duong la: " << duong << endl;
    cout << "so so am la: " << am << endl;
}
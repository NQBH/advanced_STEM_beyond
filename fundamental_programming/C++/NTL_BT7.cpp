#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    double sln = a;
    if (b > sln) {
        sln = b;
    }
    if (c > sln) {
        sln = c;
    }
    double snn = a;
    if (b < snn) {
        snn = b;
    }
    if (c < snn) {
        snn = c;
    }
    cout << "So nho nhat la: " << snn << "\n";
    cout << "So lon nhat la: " << sln << "\n";

    int n;
    cout << "n=";
    cin >> n;
    double x;
    cin >> x;
    double sln1 = x;
    double snn1 = x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x > sln1)
            sln1 = x;
        if (x < snn1)
            snn1 = x;
    }
    cout << "So nho nhat la: " << snn1 << endl;
    cout << "So lon nhat la: " << sln1 << endl;
}
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n=";
    cin >> n;
    int chan = 0, le = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % 2 == 0)
            chan = chan + 1;
        if (x % 2 != 0)
            le = le + 1;
    }
    cout << "so so chan la: " << chan << endl;
    cout << "so so le la: " << le << endl;
}
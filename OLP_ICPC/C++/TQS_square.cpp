#include <iostream>
using namespace std;
int main()
{
    long long n; cin >> n;
    while (n--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == b and a == c and a == d) {
            cout << "YES" << "\n";
            continue;
        }
        cout << "NO" << "\n";
    }
}

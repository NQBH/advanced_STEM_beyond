#include <iostream>
using namespace std;
#define ll long long

int main() {
    double c;
    while (cin >> c and c != 0) {
        int cnt = 0;
        double a = 2;
        double hang = 0;
        while (hang <= c) {
            hang += 1 / a;
            ++a;
            ++cnt;
        }
        cout << cnt << " cards" << " \n";
    }
}
/*
Source: ACM Rocky Mountain 2004.
IDs for online judges: POJ 2000, ZOJ 2345, UVA 3045.
Status: Accepted
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        int d = n;
        int day = 1;
        int coin = 0;
        while (n - day >= 0) {
            n -= day;
            coin += day * day;
            ++day;
        }
        if (n > 0) {
            coin += (n * day);
        }
        cout << d << " " << coin << '\n';
    }
}
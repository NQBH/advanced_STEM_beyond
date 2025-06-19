/*
Source:
IDs for online judges:  UVA 11000.
Status: Accepted
*/

#include <iostream>
#define int long long
using namespace std;

const int magicBee = 1;

signed main() {
    int year;
    while (cin >> year && year != -1) {
        int femaleBee = 0;
        int maleBee = 0;
        for (int y = 1; y <= year; ++y) {
            int newFemaleBee = maleBee;
            int newMaleBee = maleBee + femaleBee + magicBee;
            maleBee = newMaleBee;
            femaleBee = newFemaleBee;
        }
        cout << maleBee << " " << maleBee + femaleBee + magicBee << endl;
    }
}
/*
Source: Duke Internet Programming Contest 1990.
IDs for online judges: POJ 1207, UVA 100.
Status: Accepted
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int l, r;
    while (cin >> l >> r) {
        int maxCycle = -1;
        for (int i = min(l,r) ; i <= max(l,r) ; ++i) {
            int num = i;
            int currentCycle = 0;
            while(num != 1) {
                if (num % 2 == 1)
                    num = num * 3 + 1;
                else
                    num = num /2;
                ++currentCycle;
            }
            maxCycle = max(maxCycle, currentCycle + 1);
        }
        cout << l << " " << r << " " << maxCycle << endl;
    }
}
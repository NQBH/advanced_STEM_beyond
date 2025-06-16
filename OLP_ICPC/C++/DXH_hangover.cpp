#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        double c;
        cin >> c; // Nhap gia tri c de ktra
        if (c == 0.00) break;

        double sum = 0.0;
        int card = 0;
        while (sum < c) {
            ++card;
            sum += 1.0 / (card + 1);
        }
        cout << card << " card(s)" << endl;
    }
    return 0;
}
#include <iostream>
#define ll long long
using namespace std;

ll spiral(ll row, ll col) {
    if (row == col) {
        return row * row - (row - 1);
    } else {
        ll val = max(row, col);
        val = val * val - (val - 1);
        if (row > col) {
            if (row % 2 == 0)
                val += (row - col);
            else
                val -= (row - col);
        }
        if (row < col) {
            if (col % 2 == 0)
                val -= (col - row);
            else
                val += (col - row);
        }
        return val;
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        ll row, col;
        cin >> row >> col;
        cout << spiral(row, col) << "\n";
    }
}
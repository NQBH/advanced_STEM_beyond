#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int sum = 0;
    if (n > 0) sum = (n * (n + 1)) / 2; // sum of 1st n natural numbers
    else if (n < 0)
        for (int i = 1; i >= n; --i)
            sum += i;
    cout << sum;
}
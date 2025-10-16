#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "input n: ";
    cin >> n;
    if (pow(2, n) >= 100)
        cout << "a true" << endl;
    else
        cout << "a false" << endl;
    return 0;
}

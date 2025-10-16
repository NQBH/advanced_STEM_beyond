#include <iostream>
#include <cmath> // bro made me find this damn thing hours
using namespace std;

int main() {
    double n;
    cout << "input n: ";
    cin >> n;
    if (pow(2, n) >= 100)
        cout << "a true" << endl;
    else
        cout << "a false" << endl;
    return 0;
}
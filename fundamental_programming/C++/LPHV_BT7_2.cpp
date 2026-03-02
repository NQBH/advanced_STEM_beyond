#include<iostream>
using namespace std;
int main () {
    int n;
    cin >> n;
    double x;
    cin >> x;
    double maxNumber = x;
    double minNumber = x;
    int i = 2;
    while (i <= n) {
        cin >> x;
        if (x > maxNumber)  maxNumber = x;
        if (x < minNumber)  minNumber = x;
        i++;
    }
    cout << maxNumber << " " << minNumber;
}
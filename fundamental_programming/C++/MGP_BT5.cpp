#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double a, b;
    cin >> a >> b;
    float x=-b/a;
    if (a==0 && b==0) {
        cout << "Vo so nghiem" << endl;
    }
    else if (b!=0) {
        cout << "Vo nghiem" << endl;
    }
    if (a!=0) {
        cout << x << endl;
    }
    return 0;
}

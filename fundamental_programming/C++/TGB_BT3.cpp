#include <cmath>
#include <iostream>
using namespace std;
int main() {
    float a;
    cout << " so nguen a:";
    cin >> a;
    float b;
    cout << " so nguyen b:";
    cin >> b;
    float c;
    cout << " so nguyen c:";
    cin >> c;
    if (a == b && b == c) {
        cout << "HLP" << '\n';
    } else {
        cout << "HHCN" << '\n';
    }
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << -1;
    }
}

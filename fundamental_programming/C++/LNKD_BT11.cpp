#include <iostream>
using namespace std;

int main() {
    double a, b, c, A, B, C;

    cout << "a, b, c: ";
    cin >> a >> b >> c;
    cout << "A, B, C: ";
    cin >> A >> B >> C;

    double D  = a*B - b*A;
    double Dx = c*B - b*C;
    double Dy = a*C - c*A;

    if (D == 0) {
        if (Dx == 0 && Dy == 0)
            cout << "pt co vo so nghiem.";
        else
            cout << "pt vo nghiem.";
    } else {
        double x = Dx / D;
        double y = Dy / D;
        cout << "Nghiem cua he pt:\n";
        cout << "x = "<<x<<endl;
        cout << "y = "<<y<<endl; }
    
    return 0;
}

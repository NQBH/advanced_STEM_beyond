#include <iostream>
using namespace std;

int main() {
    double a, b, c, d, e, f;

    cout << "a, b, c: ";
    cin >> a >> b >> c;
    cout << "d, e, f: ";
    cin >> d >> e >> f;

    double D  = a*e - b*d;
    double Dx = c*e - b*f;
    double Dy = a*f - c*d;

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
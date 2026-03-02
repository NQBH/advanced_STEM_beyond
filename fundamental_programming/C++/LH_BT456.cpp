
#include <cmath> // Thư viện cho hàm sqrt và pow
#include <iostream>
using namespace std;
int main()
{
    // Bài tập 4
    cout << "Bài tập 4: \n";
    double x;
    cin >> x;
    if (x < 0) cout << "x must be nonnegative";
    else cout << sqrt(x) << '\n';
    double z, t;
    cin >> z >> t;
    if (z < 0 || t < 0 ) cout << "x must be nonnegative";
    else cout << pow(z, t) << '\n';
    double h;
    cin >> h;
    cout << exp(h) << '\n';
    double a;
    cin >> a;
    cout << log(a) << '\n';
    double b;
    cin >> b;
    cout << log10(b) << '\n';
    int c;
    long r;
    double j;
    cin >> c;
    cout << abs(c) << labs(r) << fabs(j) << '\n';
    double d;
    cin >> d;
    cout << cos(d) << sin(d) << tan(d) << '\n';
    double e;
    cin >> e;
    cout << acos(e) << asin(e) << atan(e) << '\n';
    double f;
    cin >> f;
    cout << floor(f) << ceil(f) << '\n';
    // Bài tập 5
    cout << "Bài tập 5: \n";
    double v, k;
    cin >> v >> k;
    if (v == 0) {
        if (k == 0) {
            cout << "Vô số nghiệm";
        } else {
            cout << "Vô nghiệm";
        }
    } else {
        cout << double(-k / v);
    }
    // Bài tập 6
    cout << "Bài tập 6: \n";
    double n, m, l;
    cin >> n >> m >> l;
    if (n == 0) {
        if (m == 0) {
            if (l == 0) {
                cout << "Vo so nghiem." << endl;
            } else {
                cout << "Vo nghiem." << endl;
            }
        } else {
            cout << "x = " << -l / m << endl;
        }
    }
    else {
        double delta = m * m - 4 * n * l;
        if (delta > 0 ) {
            cout << "Hai nghiem phan biet: \n";
            cout << "x= " << (-m + sqrt(delta)) / (2 * n) << endl;
            cout << "x= " << (-m - sqrt(delta)) / (2 * n) << endl;
        }
        else if (delta == 0) {
            cout << "Phuong trinh co nghiem kep: " << endl;
            cout << "x= " << -m / (2 * n) << endl;
        }
        else if (delta < 0) {
            cout << "Phuong trinh co 2 nghiem phuc: " << endl;
            cout << "x= " << -m / (2 * n) << " + " << sqrt(abs(delta)) / (2 * n) << "i" << endl;
            cout << "x= " << -m / (2 * n) << " - " << sqrt(abs(delta)) / (2 * n) << "i" << endl;
        }
    }
    return 0;
}
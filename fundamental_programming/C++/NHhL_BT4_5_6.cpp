#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
    cout << "problem 4"<<'\n';

    cout <<"1. double sqrt(double x)";
    double x_sqrt;
    cin >> x_sqrt;
    if (x_sqrt < 0) cout << "sqrt: x must be nonnegative";
    else cout << sqrt(x_sqrt) << '\n';

    cout <<"2. double pow(double x, double y)";
    double x_pow, y_pow;
    cin >> x_pow >> y_pow;
    cout << pow(x_pow, y_pow) << '\n';

    cout <<"3. double exp(double x)";
    double x_exp;
    cin >> x_exp;
    cout << exp(x_exp) << '\n';

    cout <<"4. double log(double x)";
    double x_log;
    cin >> x_log;
    if (x_log <= 0) cout << "log: x must be positive";
    else cout << log(x_log) << '\n';

    cout <<"5. double log10(double x)";
    double x_log10;
    cin >> x_log10;
    if (x_log10 <= 0) cout << "log10: x must be positive";
    else cout << log10(x_log10) << '\n';

    cout <<"6. int abs(int x)";
    int x_abs;
    cin >> x_abs;
    cout << abs(x_abs) << '\n';

    cout <<"7. long labs(long x)";
    long x_labs;
    cin >> x_labs;
    cout << labs(x_labs) << '\n';

    cout <<"8. double fabs(double x)";
    double x_fabs;
    cin >> x_fabs;
    cout << fabs(x_fabs) << '\n';

    cout <<"9. double cos(double x)";
    double x_cos;
    cin >> x_cos;
    cout << cos(x_cos) << '\n';

    cout <<"10. double sin(double x)";
    double x_sin;
    cin >> x_sin;
    cout << sin(x_sin) << '\n';

    cout <<"11. double tan(double x)";
    double x_tan;
    cin >> x_tan;
    cout << tan(x_tan) << '\n';

    cout <<"12. double acos(double x)";
    double x_acos;
    cin >> x_acos;
    if (x_acos < -1 || x_acos > 1) cout << "acos: x must be in [-1, 1]";
    else cout << acos(x_acos) << '\n';

    cout <<"13. double asin(double x)";
    double x_asin;
    cin >> x_asin;
    if (x_asin < -1 || x_asin > 1) cout << "asin: x must be in [-1, 1]";
    else cout << asin(x_asin) << '\n';

    cout <<"14. double atan(double x)";
    double x_atan;
    cin >> x_atan;
    cout << atan(x_atan) << '\n';

    cout <<"15. double floor(double x)";
    double x_floor;
    cin >> x_floor;
    cout << floor(x_floor) << '\n';

    cout <<"16. double ceil(double x)";
    double x_ceil;
    cin >> x_ceil;
    cout << ceil(x_ceil) << '\n';

    cout <<" problem 5"<<'\n';

    double a, b;
    cout << " a và b: ";
    cin >> a >> b;

    if (a == 0) {
        if (b == 0) cout << "Vô số nghiệm";
        else cout << "vô nghiệm";    
    } 
    else {
        cout << "x = " << -b / a << '\n';
    }
    */
    cout <<" problem 6" << '\n';

    cout<<" ax^2 + bx + c = 0 "<<'\n';
    double a, b, c;
    cout << " a, b, c: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout<<" bx + c = 0 "<<'\n';
        if (b == 0) {
            if (c == 0) cout << "giải pháp Vô Hạn";
            else cout << "không giải pháp";
        } else {
            cout << "Phương trình (a=0): x = " << -c / b << '\n';
        }
    } 
    else {
        double delta = b*b - 4*a*c;
        
        if (delta > 0) {
            double x1 = (-b + sqrt(delta)) / (2*a);
            double x2 = (-b - sqrt(delta)) / (2*a);
            cout << "2 nghiệm phân biệt khác nhau:" << '\n';
            cout << "x1 = " << x1 << '\n';
            cout << "x2 = " << x2 << '\n';
        } 
        else if (delta == 0) {
            cout << "căn bậc 2: x = " << -b / (2*a) << '\n';
        } 
        else { 
            double phanthuc = -b / (2*a);
            double phanao = sqrt(abs(delta)) / (2*a);
            
            cout << "phức tạm (delta < 0):" << '\n';
            cout << "x1 = " << phanthuc << " + " << phanao << "i" << '\n';
            cout << "x2 = " << phanthuc << " - " << phanao << "i" << '\n';
        }
    }

    return 0;
}
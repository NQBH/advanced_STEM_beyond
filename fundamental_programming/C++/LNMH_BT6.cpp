#include<bits/stdc++.h>
using namespace std ;
int main () {
    float a , b , c ;
    cin >> a >> b >> c ;
    float delta = b * b - 4 * a * c ;
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                cout << "pt vo so nghiem << endl" ;
            }
            else {
                cout << "pt vo nghiem" ;
            }
        }
    }
    if ( delta < 0 ) {
        cout << "PT vo nghiem " << endl ;
    }
    else if ( delta == 0 ) {
        float x = -b / (2 * a) ;
        cout << "PT co nghiem kep x = " << x ;
    }

    else if ( delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a) ;
        double x2 = (-b - sqrt(delta)) / (2 * a) ;
        cout << fixed << setprecision(2) << "PT co 2 nghiem x1 = " << x1 << " " << ", x2 = " << x2 ;
    }
    else {
        double S = sqrt(abs(delta)) / (2 * a);
        cout << "so nghiem thuc = " << S ;
    }

    return 0;

}

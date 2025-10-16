#include <iostream>
using namespace std; 
int main() { 
bool p, q; 
    if  (1 + 1 == 2 ) p = true;
    else p = false;
    if ( 2 + 2 == 3) q = true;
    else q = false;
    cout << " Proposition 1 is "<< p << '\n';
    cout << " Proposition 2 is "<< q << '\n';
     //Input valune of x , decide if x + 1 = 2 is true or not
    // Input value of x, y, z decide if x + y = z is true or not
    int x;// integer: so nguyen
    cin >> x;
    if (2+2==4) ++x; 
    cout << x; 
}

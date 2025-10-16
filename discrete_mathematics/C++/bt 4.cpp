#include <iostream>
using namespace std;
int main() {
    bool p, q;

    if (1 + 1 == 2 ) p = true;
    
    if (2 + 2 == 3) q = true;
    else q = false;
    cout << "Proposition 3 is " << p << '\n';
    cout << "Proposition 4 is " << q << '\n';
    // Input value of x, decide if x + 1 = 2 is true or not 
    // Input values of x, y, z, decide if x + y = z is true or not
    int x = 10; // integer: so nguyen  
    if (2 + 2 == 4) ++x; 
    cout << x;
}

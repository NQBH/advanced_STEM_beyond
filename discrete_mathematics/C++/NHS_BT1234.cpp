#include <cmath>
#include <iostream>
using namespace std;

int main() {
    //Problem 1

    if (x + 1 == 2)
        cout << "(a) true" << endl;
    else
        cout << "(a) false" << endl;
    if (x + y == z)
        cout << "(b) true" << endl;
    else
        cout << "(b) false" << endl;
    return 0;
}
//Problem 2

bool p = (x + 1 == 2);
bool q = (x + y == z);
cout << "a" << (p ? "true" : "false") << endl;
cout << "b" << ((p^q) ? "true" : "false") << endl;
if (p && q)
    cout << "p and q are both true" << endl;
else
    cout << "p and q are not both true" << endl;
if (p || q)
    cout << "p or q is true" << endl;
else
    cout << "p or q is not true" << endl;
if (!p && !q)
    cout << "p and q are both true and return false" << endl;
else
    cout << "p and q are not both true and return true" << endl;
return 0;
}
//Problem 3

if (x + 1 == 2) // normal one
    cout << "p true" << endl;
else
    cout << "p false" << endl;
if ((x + 1 == 2) == true) // reverse one
    cout << "p true" << endl;
else
    cout << "p false" << endl;
if (x + 1 != 2) // inverse one
    cout << "p true" << endl;
else
    cout << "p false" << endl;
if ((x + 1 == 2) == false) // opposite one
    cout << "p true" << endl;
else
    cout << "p false" << endl;
if (x + y == z) // normal one
    cout << "q true" << endl;
else
    cout << "q false" << endl;
if ((x + y == z) == true) // reverse one
    cout << "q true" << endl;
else
    cout << "q false" << endl;
if (x + y != z) // inverse one
    cout << "q true" << endl;
else
    cout << "q false" << endl;
if ((x + y == z) == false) // opposite one
    cout << "q true" << endl;
else
    cout << "q false" << endl;
return 0;
}
//Problem 4
int n = 9;
if (pow(2, n) >= 100)
    cout << "a true" << endl;
else
    cout << "a false" << endl;
return 0;
}
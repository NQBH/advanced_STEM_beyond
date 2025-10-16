/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i <= 1; i++)
        for (int r = 0; r <= 1; r++) {
            {
                bool p = i;
                bool q = false;
                cout << "p = " << p << endl;
//Identity
                cout << "(p && true) == p: " << ((p && true) == p) << endl;
                cout << "(p || false) == p: " << ((p || false) == p) << endl;
//Negation
                cout << "(p || !p) == true: " << ((p || !p) == true) << endl;
                cout << "(p && !p) == false: " << ((p && !p) == false) << endl;
//Domination
                cout << "(p || true) == true: " << ((p || true) == true) << endl;
                cout << "(p && false) == false: " << ((p && false) == false) << endl;
//Idempotent
                cout << "(p || p) == p: " << ((p || p) == p) << endl;
                cout << "(p && p) == p: " << ((p && p) == p) << endl;
//Commutative
                cout << "(p || q) == (q || p): " << ((p || q) == (q || p)) << endl;
                cout << "(p && q) == (q && p): " << ((p && q) == (q && p)) << endl;
//Associative
                cout << "((p || q) || r) == (p || (q || r)): " << (((p || q) || r) == (p || (q || r))) << endl;
                cout << "((p && q) && r) == (p && (q && r)): " << (((p && q) && r) == (p && (q && r))) << endl;
//Distributive
                cout << "p || (q && r) == (p || q) && (p || r): " << ((p || (q && r)) == ((p || q) && (p || r))) << endl;
                cout << "p && (q || r) == (p && q) || (p && r): " << ((p && (q || r)) == ((p && q) || (p && r))) << endl;
//Absorption
                cout << "(p || (p && q)) == p: " << ((p || (p && q)) == p) << endl;
                cout << "(p && (p || q)) == p: " << ((p && (p || q)) == p) << endl;
//De Morgan
                cout << "!(p || q) == (!p && !q): " << (!(p || q) == (!p && !q)) << endl;
                cout << "!(p && q) == (!p || !q): " << (!(p && q) == (!p || !q)) << endl;
//Double Negation
                cout << "!!p == p: " << ((!!p) == p) << endl;
            }
        }
}
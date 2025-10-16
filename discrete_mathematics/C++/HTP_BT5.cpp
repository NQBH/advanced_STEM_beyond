/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int p, q, r;
    cout << "=== KIEM TRA CAC QUY TAC LOGIC (TABLE 6) ===\n\n";

    // Duyet tat ca truong hop p, q, r = 0 hoac 1
    for (p = 0; p <= 1; p++)
        for (q = 0; q <= 1; q++)
            for (r = 0; r <= 1; r++) {

                cout << "p=" << p << " q=" << q << " r=" << r << "\n";

                // 1. Identity laws
                cout << ((p && true) == p && (p || false) == p) << " Identity\n";

                // 2. Domination laws
                cout << ((p || true) == true && (p && false) == false) << " Domination\n";

                // 3. Idempotent laws
                cout << ((p || p) == p && (p && p) == p) << " Idempotent\n";

                // 4. Double negation
                cout << ((!(!p)) == p) << " Double negation\n";

                // 5. Commutative laws
                cout << ((p || q) == (q || p) && (p && q) == (q && p)) << " Commutative\n";

                // 6. Associative laws
                cout << (((p || q) || r) == (p || (q || r)) && ((p && q) && r) == (p && (q && r))) << " Associative\n";

                // 7. Distributive laws
                cout << ((p || (q && r)) == ((p || q) && (p || r)) && (p && (q || r)) == ((p && q) || (p && r))) << " Distributive\n";

                // 8. De Morgan’s laws
                cout << ((!(p && q)) == (!p || !q) && (!(p || q)) == (!p && !q)) << " De Morgan\n";

                // 9. Absorption laws
                cout << ((p || (p && q)) == p && (p && (p || q)) == p) << " Absorption\n";

                // 10. Negation laws
                cout << ((p || !p) == true && (p && !p) == false) << " Negation\n\n";
            }

    cout << "=> Tat ca cac quy tac trong Table 6 deu dung \n";
    return 0;
}
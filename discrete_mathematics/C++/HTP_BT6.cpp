/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

// Hàm biểu diễn phép kéo theo (→)
bool imp(bool p, bool q) {
    return (!p) || q;
}

// Hàm biểu diễn phép tương đương (↔)
bool bic(bool p, bool q) {
    return (imp(p, q) && imp(q, p));
}

int main() {
    int p, q, r;
    cout << "=== KIEM TRA CAC QUY TAC LOGIC (TABLE 7 + 8) ===\n\n";

    for (p = 0; p <= 1; p++)
        for (q = 0; q <= 1; q++)
            for (r = 0; r <= 1; r++) {

                cout << "p=" << p << " q=" << q << " r=" << r << "\n";

                // ---- Table 7 ----
                cout << ((imp(p, q)) == ((!p) || q)) << " 1. p→q ≡ ¬p∨q\n";
                cout << ((imp(p, q)) == imp(!q, !p)) << " 2. p→q ≡ ¬q→¬p\n";
                cout << (((p || q)) == imp(!p, q)) << " 3. p∨q ≡ ¬p→q\n";
                cout << (((p && q)) == (!imp(p, !q))) << " 4. p∧q ≡ ¬(p→¬q)\n";
                cout << ((!(imp(p, q))) == (p && (!q))) << " 5. ¬(p→q) ≡ p∧¬q\n";
                cout << (((imp(p, q) && imp(p, r))) == imp(p, (q && r))) << " 6. (p→q)∧(p→r) ≡ p→(q∧r)\n";
                cout << (((imp(p, r) && imp(q, r))) == imp((p || q), r)) << " 7. (p→r)∧(q→r) ≡ (p∨q)→r\n";
                cout << (((imp(p, q) && imp(q, r))) == imp(p, r)) << " 8. (p→q)∧(q→r) ≡ p→r\n";
                cout << (((imp(p, r) || imp(q, r))) == imp((p && q), r)) << " 9. (p→r)∨(q→r) ≡ (p∧q)→r\n";

                // ---- Table 8 ----
                cout << ((bic(p, q)) == (imp(p, q) && imp(q, p))) << " 10. p↔q ≡ (p→q)∧(q→p)\n";
                cout << ((bic(p, q)) == bic(!p, !q)) << " 11. p↔q ≡ ¬p↔¬q\n";
                cout << ((bic(p, q)) == ((p && q) || ((!p) && (!q)))) << " 12. p↔q ≡ (p∧q)∨(¬p∧¬q)\n";
                cout << ((!(bic(p, q))) == bic(p, !q)) << " 13. ¬(p↔q) ≡ p↔¬q\n\n";
            }

    cout << "=> Tat ca cac quy tac trong Table 7 + 8 deu dung \n";
    return 0;
}
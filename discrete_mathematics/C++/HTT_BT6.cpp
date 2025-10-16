#include <iostream>
using namespace std;

bool eq(bool a, bool b) { return a == b; }

int main() {
    bool p, q, r, ok;

    // → (conditional) & ↔ (biconditional)
    // 1. p → q ≡ ¬p ∨ q
    ok = true;
    for (int i = 0; i < 4; i++) {p = i & 1; q = i >> 1 & 1; if ((( !p) || q) != (p <= q))ok = false;}
    cout << "p→q ≡ ¬p∨q: " << (ok ? "Đúng" : "Sai") << endl;

    // 2. ¬(p→q) ≡ p ∧ ¬q
    ok = true;
    for (int i = 0; i < 4; i++) {p = i & 1; q = i >> 1 & 1; if ((!( !p || q)) != (p && (!q)))ok = false;}
    cout << "¬(p→q) ≡ p∧¬q: " << (ok ? "Đúng" : "Sai") << endl;

    // 3. (p→q) ≡ (¬q→¬p)
    ok = true;
    for (int i = 0; i < 4; i++) {p = i & 1; q = i >> 1 & 1; if ((( !p) || q) != ((!q) <= (!p)))ok = false;}
    cout << "p→q ≡ ¬q→¬p: " << (ok ? "Đúng" : "Sai") << endl;

    // 4. (p↔q) ≡ (p→q) ∧ (q→p)
    ok = true;
    for (int i = 0; i < 4; i++) {p = i & 1; q = i >> 1 & 1; if (((p == q)) != (((!p) || q) && ((!q) || p)))ok = false;}
    cout << "p↔q ≡ (p→q)∧(q→p): " << (ok ? "Đúng" : "Sai") << endl;

    // 5. ¬(p↔q) ≡ p↔¬q
    ok = true;
    for (int i = 0; i < 4; i++) {p = i & 1; q = i >> 1 & 1; if ((!(p == q)) != (p == (!q)))ok = false;}
    cout << "¬(p↔q) ≡ p↔¬q: " << (ok ? "Đúng" : "Sai") << endl;

    // ----- Table 8: Miscellaneous Equivalences -----

    // 6. (p∨q) → r ≡ (p→r) ∧ (q→r)
    ok = true;
    for (int i = 0; i < 8; i++) {
        p = i & 1; q = i >> 1 & 1; r = i >> 2 & 1;
        if ((((!p) && !q) || r) != ((( !p) || r) && ((!q) || r))) ok = false;
    }
    cout << "(p∨q)→r ≡ (p→r)∧(q→r): " << (ok ? "Đúng" : "Sai") << endl;

    // 7. (p∧q) → r ≡ (p→(q→r))
    ok = true;
    for (int i = 0; i < 8; i++) {
        p = i & 1; q = i >> 1 & 1; r = i >> 2 & 1;
        if (((!(p && q)) || r) != ((!p) || ( (!q) || r))) ok = false;
    }
    cout << "(p∧q)→r ≡ (p→(q→r)): " << (ok ? "Đúng" : "Sai") << endl;

    // 8. p∨(q→r) ≡ (p∨q)→(p∨r)
    ok = true;
    for (int i = 0; i < 8; i++) {
        p = i & 1; q = i >> 1 & 1; r = i >> 2 & 1;
        if ((p || ((!q) || r)) != ((!(p || q)) || (p || r))) ok = false;
    }
    cout << "p∨(q→r) ≡ (p∨q)→(p∨r): " << (ok ? "Đúng" : "Sai") << endl;

    return 0;
}

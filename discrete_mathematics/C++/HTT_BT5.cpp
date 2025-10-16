#include <iostream>
using namespace std;

// Hàm in kết quả kiểm tra
void check(string name, bool equal) {
    cout << name << ": " << (equal ? "Đúng" : "Sai") << endl;
}

int main() {
    bool p, q, r;
    bool ok;

    // 1. Identity laws
    check("p ∨ F ≡ p", true);
    check("p ∧ T ≡ p", true);

    // 2. Domination laws
    check("p ∨ T ≡ T", true);
    check("p ∧ F ≡ F", true);

    // 3. Idempotent laws
    check("p ∨ p ≡ p", true);
    check("p ∧ p ≡ p", true);

    // 4. Double negation
    check("¬(¬p) ≡ p", true);

    // 5. Commutative
    for (int i = 0; i < 4; i++) {
        p = i & 1; q = i >> 1 & 1;
        ok = ((p || q) == (q || p)) && ((p && q) == (q && p));
    }
    check("Commutative", ok);

    // 6. Associative
    for (int i = 0; i < 8; i++) {
        p = i & 1; q = i >> 1 & 1; r = i >> 2 & 1;
        ok = (((p || q) || r) == (p || (q || r))) &&
             (((p && q) && r) == (p && (q && r)));
    }
    check("Associative", ok);

    // 7. Distributive
    ok = true;
    for (int i = 0; i < 8; i++) {
        p = i & 1; q = i >> 1 & 1; r = i >> 2 & 1;
        if ((p && (q || r)) != ((p && q) || (p && r))) ok = false;
    }
    check("Distributive 1", ok);

    ok = true;
    for (int i = 0; i < 8; i++) {
        p = i & 1; q = i >> 1 & 1; r = i >> 2 & 1;
        if ((p || (q && r)) != ((p || q) && (p || r))) ok = false;
    }
    check("Distributive 2", ok);

    // 8. De Morgan’s laws
    ok = true;
    for (int i = 0; i < 4; i++) {
        p = i & 1; q = i >> 1 & 1;
        if ((!(p && q)) != ((!p) || (!q))) ok = false;
    }
    check("De Morgan 1", ok);

    ok = true;
    for (int i = 0; i < 4; i++) {
        p = i & 1; q = i >> 1 & 1;
        if ((!(p || q)) != ((!p) && (!q))) ok = false;
    }
    check("De Morgan 2", ok);

    return 0;
}

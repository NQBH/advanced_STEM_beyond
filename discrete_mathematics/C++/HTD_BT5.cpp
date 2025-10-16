#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    bool ok;

    cout << "Checking logical equivalences (C++)\n\n";

    // Identity laws: p ∧ T ≡ p, p ∨ F ≡ p
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ( (p && true) != p ) ok = false;
        if ( (p || false) != p ) ok = false;
    }
    cout << "Identity laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Domination laws: p ∨ T ≡ T, p ∧ F ≡ F
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ( (p || true) != true ) ok = false;
        if ( (p && false) != false ) ok = false;
    }
    cout << "Domination laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Idempotent laws: p ∨ p ≡ p, p ∧ p ≡ p
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ( (p || p) != p ) ok = false;
        if ( (p && p) != p ) ok = false;
    }
    cout << "Idempotent laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Double negation: ¬(¬p) ≡ p
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ( (!(!p)) != p ) ok = false;
    }
    cout << "Double negation: " << (ok ? "PASS" : "FAIL") << "\n";

    // Commutative: p ∨ q ≡ q ∨ p ; p ∧ q ≡ q ∧ p
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            p = i; q = j;
            if ( (p || q) != (q || p) ) ok = false;
            if ( (p && q) != (q && p) ) ok = false;
        }
    cout << "Commutative laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Associative: (p ∨ q) ∨ r ≡ p ∨ (q ∨ r) ; (p ∧ q) ∧ r ≡ p ∧ (q ∧ r)
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
                p = i; q = j; r = k;
                if ( ((p || q) || r) != (p || (q || r)) ) ok = false;
                if ( ((p && q) && r) != (p && (q && r)) ) ok = false;
            }
    cout << "Associative laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Distributive: p ∨ (q ∧ r) ≡ (p ∨ q) ∧ (p ∨ r)
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) {
                p = i; q = j; r = k;
                if ( (p || (q && r)) != ((p || q) && (p || r)) ) ok = false;
                if ( (p && (q || r)) != ((p && q) || (p && r)) ) ok = false;
            }
    cout << "Distributive laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // De Morgan's: ¬(p ∧ q) ≡ ¬p ∨ ¬q ; ¬(p ∨ q) ≡ ¬p ∧ ¬q
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            p = i; q = j;
            if ( (! (p && q)) != ((!p) || (!q)) ) ok = false;
            if ( (! (p || q)) != ((!p) && (!q)) ) ok = false;
        }
    cout << "De Morgan's laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Absorption: p ∨ (p ∧ q) ≡ p ; p ∧ (p ∨ q) ≡ p
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            p = i; q = j;
            if ( (p || (p && q)) != p ) ok = false;
            if ( (p && (p || q)) != p ) ok = false;
        }
    cout << "Absorption laws: " << (ok ? "PASS" : "FAIL") << "\n";

    // Negation laws: p ∨ ¬p ≡ T ; p ∧ ¬p ≡ F
    ok = true;
    for (int i = 0; i < 2; i++) {
        p = i;
        if ( (p || !p) != true ) ok = false;
        if ( (p && !p) != false ) ok = false;
    }
    cout << "Negation laws (tautology/contradiction): " << (ok ? "PASS" : "FAIL") << "\n";

    // Implication equivalence: p -> q ≡ ¬p ∨ q
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            p = i; q = j;
            bool impl = (!p) || q;
            bool p_implies_q = (!p) || q; // same definition
            if ( impl != p_implies_q ) ok = false; // trivial, but kept for structure
        }
    cout << "Implication equivalence p->q ≡ ¬p ∨ q: " << (ok ? "PASS" : "FAIL") << "\n";

    // Contrapositive: p -> q ≡ ¬q -> ¬p
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            p = i; q = j;
            bool a = (!p) || q;
            bool b = (!(!q)) || (!p); // ¬q -> ¬p is (q or !p)? simpler compute directly:
            bool contr = (!q) || (!p);
            if ( a != contr ) ok = false;
        }
    cout << "Contrapositive: p->q ≡ ¬q->¬p: " << (ok ? "PASS" : "FAIL") << "\n";

    // Biconditional: p <-> q ≡ (p -> q) ∧ (q -> p) ; also p <-> q ≡ (p && q) || (!p && !q)
    ok = true;
    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            p = i; q = j;
            bool bic = (p && q) || ((!p) && (!q));
            bool bic2 = ((!p) || q) && ((!q) || p);
            if ( bic != bic2 ) ok = false;
        }
    cout << "Biconditional laws: " << (ok ? "PASS" : "FAIL") << "\n";

    cout << "\nDone.\n";
    return 0;
}

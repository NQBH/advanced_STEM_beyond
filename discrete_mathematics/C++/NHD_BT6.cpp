#include <iostream>
using namespace std;

// Hàm p → q
bool implies(bool p, bool q) {
    return (!p) || q;
}

// Hàm p ↔ q
bool iff(bool p, bool q) {
    return (p && q) || (!p && !q);
}

int main() {
    bool p, q, r;
    bool all_passed = true;

    cout << boolalpha;

    for (int ip = 0; ip <= 1; ++ip) {
        for (int iq = 0; iq <= 1; ++iq) {
            for (int ir = 0; ir <= 1; ++ir) {
                p = ip;
                q = iq;
                r = ir;

                // === Table 7: Logical equivalences involving conditionals ===
                if (implies(p, q) != ((!p) || q)) {
                    cout << "Fail: p → q ≡ ¬p ∨ q\n";
                    all_passed = false;
                }
                if (implies(p, q) != implies(!q, !p)) {
                    cout << "Fail: p → q ≡ ¬q → ¬p\n";
                    all_passed = false;
                }
                if ((p || q) != implies(!p, q)) {
                    cout << "Fail: p ∨ q ≡ ¬p → q\n";
                    all_passed = false;
                }
                if ((p && q) != (!implies(p, !q))) {
                    cout << "Fail: p ∧ q ≡ ¬(p → ¬q)\n";
                    all_passed = false;
                }
                if ((!implies(p, q)) != (p && !q)) {
                    cout << "Fail: ¬(p → q) ≡ p ∧ ¬q\n";
                    all_passed = false;
                }
                if ((implies(p, q) && implies(p, r)) != implies(p, q && r)) {
                    cout << "Fail: (p → q) ∧ (p → r) ≡ p → (q ∧ r)\n";
                    all_passed = false;
                }
                if ((implies(p, r) && implies(q, r)) != implies(p || q, r)) {
                    cout << "Fail: (p → r) ∧ (q → r) ≡ (p ∨ q) → r\n";
                    all_passed = false;
                }
                if ((implies(p, q) || implies(p, r)) != implies(p, q || r)) {
                    cout << "Fail: (p → q) ∨ (p → r) ≡ p → (q ∨ r)\n";
                    all_passed = false;
                }
                if ((implies(p, r) || implies(q, r)) != implies(p && q, r)) {
                    cout << "Fail: (p → r) ∨ (q → r) ≡ (p ∧ q) → r\n";
                    all_passed = false;
                }

                // === Table 8: Logical equivalences involving biconditionals ===
                if (iff(p, q) != (implies(p, q) && implies(q, p))) {
                    cout << "Fail: p ↔ q ≡ (p → q) ∧ (q → p)\n";
                    all_passed = false;
                }
                if (iff(p, q) != iff(!p, !q)) {
                    cout << "Fail: p ↔ q ≡ ¬p ↔ ¬q\n";
                    all_passed = false;
                }
                if (iff(p, q) != ((p && q) || (!p && !q))) {
                    cout << "Fail: p ↔ q ≡ (p ∧ q) ∨ (¬p ∧ ¬q)\n";
                    all_passed = false;
                }
                if ((!iff(p, q)) != iff(p, !q)) {
                    cout << "Fail: ¬(p ↔ q) ≡ p ↔ ¬q\n";
                    all_passed = false;
                }
            }
        }
    }

    if (all_passed) {
        cout << " All logical equivalences in Table 7 & 8 are verified.\n";
    } else {
        cout << " Some equivalences failed. See above.\n";
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef function<bool(vector<bool>)> Expr;

bool implies(bool p, bool q) { return !p || q; }
bool bicond(bool p, bool q) { return p == q; }

void test(string name, int nVars, Expr e1, Expr e2) {
    bool ok = true;
    for (int i = 0; i < (1 << nVars); ++i) {
        vector<bool> v(nVars);
        for (int j = 0; j < nVars; ++j)
            v[j] = (i >> j) & 1;
        if (e1(v) != e2(v)) {
            cout << "[FALSE] " << name << " sai với input: ";
            for (bool b : v) cout << b << " ";
            cout << endl;
            ok = false;
        }
    }
    if (ok)
        cout << "[TRUE] " << name << " đúng\n";
}

int main() {
    cout << " Table 7 – Logical Equivalences (C++)\n\n";

    // TABLE 7
    test("p → q ≡ ¬p ∨ q", 2,
         [](auto v){ return implies(v[0], v[1]); },
         [](auto v){ return !v[0] || v[1]; });

    test("p → q ≡ ¬q → ¬p", 2,
         [](auto v){ return implies(v[0], v[1]); },
         [](auto v){ return implies(!v[1], !v[0]); });

    test("¬p → (p → q) ≡ p ∨ q", 2,
         [](auto v){ return implies(!v[0], implies(v[0], v[1])); },
         [](auto v){ return v[0] || v[1]; });

    test("p ∧ q ≡ p → ¬(q → F)", 2,
         [](auto v){ return v[0] && v[1]; },
         [](auto v){ return implies(v[0], !implies(v[1], false)); });

    test("¬(p → q) ≡ p ∧ ¬q", 2,
         [](auto v){ return !implies(v[0], v[1]); },
         [](auto v){ return v[0] && !v[1]; });

    test("(p → r) ∧ (q → r) ≡ (p ∨ q) → r", 3,
         [](auto v){ return implies(v[0], v[2]) && implies(v[1], v[2]); },
         [](auto v){ return implies(v[0] || v[1], v[2]); });

    test("(p → q) ∧ (p → r) ≡ p → (q ∧ r)", 3,
         [](auto v){ return implies(v[0], v[1]) && implies(v[0], v[2]); },
         [](auto v){ return implies(v[0], v[1] && v[2]); });

    test("p → (q ∧ r) ≡ (p → q) ∧ (p → r)", 3,
         [](auto v){ return implies(v[0], v[1] && v[2]); },
         [](auto v){ return implies(v[0], v[1]) && implies(v[0], v[2]); });

    test("(p → r) ∧ (q → r) ≡ (p ∨ q) → r", 3,
         [](auto v){ return implies(v[0], v[2]) && implies(v[1], v[2]); },
         [](auto v){ return implies(v[0] || v[1], v[2]); });
    // TABLE 8    
    cout << " Table 8 – Logical Equivalences (C++)\n\n";
    test("p ↔ q ≡ (p → q) ∧ (q → p)", 2,
         [](auto v){ return bicond(v[0], v[1]); },
         [](auto v){ return implies(v[0], v[1]) && implies(v[1], v[0]); });

    test("p ↔ q ≡ ¬p ↔ ¬q", 2,
         [](auto v){ return bicond(v[0], v[1]); },
         [](auto v){ return bicond(!v[0], !v[1]); });

    test("p ↔ q ≡ (p ∧ q) ∨ (¬p ∧ ¬q)", 2,
         [](auto v){ return bicond(v[0], v[1]); },
         [](auto v){ return (v[0] && v[1]) || (!v[0] && !v[1]); });

    test("¬(p ↔ q) ≡ p ↔ ¬q", 2,
         [](auto v){ return !bicond(v[0], v[1]); },
         [](auto v){ return bicond(v[0], !v[1]); });

    return 0;
}

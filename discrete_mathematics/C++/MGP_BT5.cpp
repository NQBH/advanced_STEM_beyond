#include <iostream>
#include <vector>
#include <functional>
using namespace std;

typedef function<bool(vector<bool>)> Expr;

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
    cout << " Kiểm tra Table 6 – Logical Equivalences (C++):\n\n";

    // Identity laws
    test("p ∧ T ≡ p", 1, [](auto v){ return v[0] && true; }, [](auto v){ return v[0]; });
    test("p ∨ F ≡ p", 1, [](auto v){ return v[0] || false; }, [](auto v){ return v[0]; });

    // Domination laws
    test("p ∨ T ≡ T", 1, [](auto v){ return v[0] || true; }, [](auto v){ return true; });
    test("p ∧ F ≡ F", 1, [](auto v){ return v[0] && false; }, [](auto v){ return false; });

    // Idempotent laws
    test("p ∨ p ≡ p", 1, [](auto v){ return v[0] || v[0]; }, [](auto v){ return v[0]; });
    test("p ∧ p ≡ p", 1, [](auto v){ return v[0] && v[0]; }, [](auto v){ return v[0]; });

    // Double negation
    test("¬(¬p) ≡ p", 1, [](auto v){ return !(!v[0]); }, [](auto v){ return v[0]; });

    // Commutative laws
    test("p ∨ q ≡ q ∨ p", 2, [](auto v){ return v[0] || v[1]; }, [](auto v){ return v[1] || v[0]; });
    test("p ∧ q ≡ q ∧ p", 2, [](auto v){ return v[0] && v[1]; }, [](auto v){ return v[1] && v[0]; });

    // Associative laws
    test("(p ∨ q) ∨ r ≡ p ∨ (q ∨ r)", 3,
         [](auto v){ return (v[0] || v[1]) || v[2]; },
         [](auto v){ return v[0] || (v[1] || v[2]); });

    test("(p ∧ q) ∧ r ≡ p ∧ (q ∧ r)", 3,
         [](auto v){ return (v[0] && v[1]) && v[2]; },
         [](auto v){ return v[0] && (v[1] && v[2]); });

    // Distributive laws
    test("p ∨ (q ∧ r) ≡ (p ∨ q) ∧ (p ∨ r)", 3,
         [](auto v){ return v[0] || (v[1] && v[2]); },
         [](auto v){ return (v[0] || v[1]) && (v[0] || v[2]); });

    test("p ∧ (q ∨ r) ≡ (p ∧ q) ∨ (p ∧ r)", 3,
         [](auto v){ return v[0] && (v[1] || v[2]); },
         [](auto v){ return (v[0] && v[1]) || (v[0] && v[2]); });

    // De Morgan’s laws
    test("¬(p ∧ q) ≡ ¬p ∨ ¬q", 2,
         [](auto v){ return !(v[0] && v[1]); },
         [](auto v){ return !v[0] || !v[1]; });

    test("¬(p ∨ q) ≡ ¬p ∧ ¬q", 2,
         [](auto v){ return !(v[0] || v[1]); },
         [](auto v){ return !v[0] && !v[1]; });

    // Absorption laws
    test("p ∨ (p ∧ q) ≡ p", 2,
         [](auto v){ return v[0] || (v[0] && v[1]); },
         [](auto v){ return v[0]; });

    test("p ∧ (p ∨ q) ≡ p", 2,
         [](auto v){ return v[0] && (v[0] || v[1]); },
         [](auto v){ return v[0]; });

    // Negation laws
    test("p ∨ ¬p ≡ T", 1,
         [](auto v){ return v[0] || !v[0]; },
         [](auto v){ return true; });

    test("p ∧ ¬p ≡ F", 1,
         [](auto v){ return v[0] && !v[0]; },
         [](auto v){ return false; });

    return 0;
    
}

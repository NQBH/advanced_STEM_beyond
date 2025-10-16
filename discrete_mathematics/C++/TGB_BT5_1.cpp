/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <functional>
#include <vector>
using namespace std;

void check_equivalence(const string& name, int num_vars,
    function<bool(bool, bool, bool)> lhs,
    function<bool(bool, bool, bool)> rhs) {
    
    bool equivalent = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= (num_vars >= 2 ? 1 : 0); ++q)
            for (int r = 0; r <= (num_vars >= 3 ? 1 : 0); ++r) {
                bool left = lhs(p, q, r);
                bool right = rhs(p, q, r);
                if (left != right) {
                    equivalent = false;
                    cout << "false" << name << " failed for: p=" << p << ", q=" << q << ", r=" << r << endl;
                }
            }
    if (equivalent)
        cout << "true" << name << " holds for all values.\n";
}

int main() {
    struct Law {
        string name;
        int num_vars;
        function<bool(bool, bool, bool)> lhs;
        function<bool(bool, bool, bool)> rhs;
    };

    vector<Law> laws = {
        // Identity
        {"Identity Law 1: p ∧ T ≡ p", 1, [](bool p, bool, bool){ return p && true; }, [](bool p, bool, bool){ return p; }},
        {"Identity Law 2: p ∨ F ≡ p", 1, [](bool p, bool, bool){ return p || false; }, [](bool p, bool, bool){ return p; }},

        // Domination
        {"Domination Law 1: p ∨ T ≡ T", 1, [](bool p, bool, bool){ return p || true; }, [](bool, bool, bool){ return true; }},
        {"Domination Law 2: p ∧ F ≡ F", 1, [](bool p, bool, bool){ return p && false; }, [](bool, bool, bool){ return false; }},

        // Idempotent
        {"Idempotent Law 1: p ∨ p ≡ p", 1, [](bool p, bool, bool){ return p || p; }, [](bool p, bool, bool){ return p; }},
        {"Idempotent Law 2: p ∧ p ≡ p", 1, [](bool p, bool, bool){ return p && p; }, [](bool p, bool, bool){ return p; }},

        // Double negation
        {"Double Negation: ¬(¬p) ≡ p", 1, [](bool p, bool, bool){ return !(!p); }, [](bool p, bool, bool){ return p; }},

        // Commutative
        {"Commutative OR: p ∨ q ≡ q ∨ p", 2, [](bool p, bool q, bool){ return p || q; }, [](bool p, bool q, bool){ return q || p; }},
        {"Commutative AND: p ∧ q ≡ q ∧ p", 2, [](bool p, bool q, bool){ return p && q; }, [](bool p, bool q, bool){ return q && p; }},

        // Associative
        {"Associative OR", 3, [](bool p, bool q, bool r){ return (p || q) || r; }, [](bool p, bool q, bool r){ return p || (q || r); }},
        {"Associative AND", 3, [](bool p, bool q, bool r){ return (p && q) && r; }, [](bool p, bool q, bool r){ return p && (q && r); }},

        // Distributive
        {"Distributive OR over AND", 3, [](bool p, bool q, bool r){ return p || (q && r); }, [](bool p, bool q, bool r){ return (p || q) && (p || r); }},
        {"Distributive AND over OR", 3, [](bool p, bool q, bool r){ return p && (q || r); }, [](bool p, bool q, bool r){ return (p && q) || (p && r); }},

        // De Morgan
        {"De Morgan OR: ¬(p ∨ q) ≡ ¬p ∧ ¬q", 2, [](bool p, bool q, bool){ return !(p || q); }, [](bool p, bool q, bool){ return !p && !q; }},
        {"De Morgan AND: ¬(p ∧ q) ≡ ¬p ∨ ¬q", 2, [](bool p, bool q, bool){ return !(p && q); }, [](bool p, bool q, bool){ return !p || !q; }},

        // Absorption
        {"Absorption OR: p ∨ (p ∧ q) ≡ p", 2, [](bool p, bool q, bool){ return p || (p && q); }, [](bool p, bool q, bool){ return p; }},
        {"Absorption AND: p ∧ (p ∨ q) ≡ p", 2, [](bool p, bool q, bool){ return p && (p || q); }, [](bool p, bool q, bool){ return p; }},

        // Negation
        {"Negation OR: p ∨ ¬p ≡ T", 1, [](bool p, bool, bool){ return p || !p; }, [](bool, bool, bool){ return true; }},
        {"Negation AND: p ∧ ¬p ≡ F", 1, [](bool p, bool, bool){ return p && !p; }, [](bool, bool, bool){ return false; }},
    };
    for (const auto& law : laws) {
        check_equivalence(law.name, law.num_vars, law.lhs, law.rhs);
    }

    return 0;
}

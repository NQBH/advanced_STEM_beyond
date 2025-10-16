#include <iostream>
#include <string>
using namespace std;

using Fn = bool(*)(bool,bool,bool);

bool equiv(Fn f, Fn g) {
    for (int i = 0; i < 8; ++i) {
        bool p = (i & 1) != 0;
        bool q = (i & 2) != 0;
        bool r = (i & 4) != 0;
        if (f(p,q,r) != g(p,q,r)) return false;
    }
    return true;
}

/* --- Table 7 functions --- */
/* implication p->q is (!p) || q */
bool impl(bool p,bool q,bool r){ return (!p) || q; }

bool not_impl(bool p,bool q,bool r){ return !( (!p) || q ); } // ¬(p->q)
bool p_or_q(bool p,bool q,bool r){ return p || q; }
bool p_and_q(bool p,bool q,bool r){ return p && q; }

/* Table8 use p==q for biconditional */
bool bic(bool p,bool q,bool r){ return p == q; }

/* Now define RHS/LHS pairs as functions inline using lambdas via wrappers are not allowed easily,
   so we implement direct check calls in main using expressions. */

int main(){
    cout << "=== Table 7 & 8 checks ===\n";

    // Table7
    cout << "p -> q ≡ ¬p ∨ q : " 
         << (equiv([](bool p,bool q,bool r){ return (!p)||q; },
                  [](bool p,bool q,bool r){ return (!p)||q; }) ? "True":"False") << "\n";

    cout << "p -> q ≡ ¬q -> ¬p (contrapositive) : "
         << (equiv([](bool p,bool q,bool r){ return (!p)||q; },
                  [](bool p,bool q,bool r){ return (!(!q))||(!p); }) ? "True":"False") << "\n";

    cout << "p ∨ q ≡ ¬p -> q : "
         << (equiv([](bool p,bool q,bool r){ return p||q; },
                  [](bool p,bool q,bool r){ return ((!(!p))||q); }) ? "True":"False") << "\n";

    cout << "p ∧ q ≡ ¬(p -> ¬q) : "
         << (equiv([](bool p,bool q,bool r){ return p&&q; },
                  [](bool p,bool q,bool r){ return !((!p) || (!q)); }) ? "True":"False") << "\n";

    cout << "¬(p -> q) ≡ p ∧ ¬q : "
         << (equiv([](bool p,bool q,bool r){ return !((!p)||q); },
                  [](bool p,bool q,bool r){ return p && (!q); }) ? "True":"False") << "\n";

    cout << "(p->q) ∧ (p->r) ≡ p -> (q ∧ r) : "
         << (equiv([](bool p,bool q,bool r){ return (((!p)||q) && ((!p)||r)); },
                  [](bool p,bool q,bool r){ return ((!p) || (q && r)); }) ? "True":"False") << "\n";

    cout << "(p->r) ∧ (q->r) ≡ (p ∨ q) -> r : "
         << (equiv([](bool p,bool q,bool r){ return (((!p)||r) && ((!q)||r)); },
                  [](bool p,bool q,bool r){ return ((! (p||q)) || r); }) ? "True":"False") << "\n";

    cout << "(p->q) ∨ (p->r) ≡ p -> (q ∨ r) : "
         << (equiv([](bool p,bool q,bool r){ return (((!p)||q) || ((!p)||r)); },
                  [](bool p,bool q,bool r){ return ((!p) || (q || r)); }) ? "True":"False") << "\n";

    cout << "(p->r) ∨ (q->r) ≡ (p ∧ q) -> r : "
         << (equiv([](bool p,bool q,bool r){ return (((!p)||r) || ((!q)||r)); },
                  [](bool p,bool q,bool r){ return ((! (p&&q)) || r); }) ? "True":"False") << "\n";

    // Table8 (biconditional)
    cout << "p <-> q ≡ (p->q) ∧ (q->p) : "
         << (equiv([](bool p,bool q,bool r){ return p==q; },
                  [](bool p,bool q,bool r){ return (((!p)||q) && ((!q)||p)); }) ? "True":"False") << "\n";

    cout << "p <-> q ≡ ¬p <-> ¬q : "
         << (equiv([](bool p,bool q,bool r){ return p==q; },
                  [](bool p,bool q,bool r){ return ((!p) == (!q)); }) ? "True":"False") << "\n";

    cout << "p <-> q ≡ (p∧q) ∨ (¬p ∧ ¬q) : "
         << (equiv([](bool p,bool q,bool r){ return p==q; },
                  [](bool p,bool q,bool r){ return (p&&q) || ((!p) && (!q)); }) ? "True":"False") << "\n";

    cout << "¬(p <-> q) ≡ p <-> ¬q : "
         << (equiv([](bool p,bool q,bool r){ return !(p==q); },
                  [](bool p,bool q,bool r){ return p == (!q); }) ? "True":"False") << "\n"; }

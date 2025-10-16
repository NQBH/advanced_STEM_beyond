/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

 #include <iostream>
#include <vector>
using namespace std;

bool impl(bool a, bool b) {
    return (!a) || b;
}
bool biimpl(bool a, bool b) {
    return a == b;
}

int main() {
    // kiểm tra Table 7:
    cout << "=== Table 7 equivalences ===\n";
    for (int pi = 0; pi < 2; pi++) {
        for (int qi = 0; qi < 2; qi++) {
            bool p = pi, q = qi;
            // đẳng thức 1: p -> q ≡ ¬p ∨ q
            bool left1 = impl(p, q);
            bool right1 = (!p) || q;
            if (left1 != right1) {
                cout << "Fail eq1 at p="<<p<<" q="<<q<<"\n";
            }
            // đẳng thức 2: p -> q ≡ ¬q -> ¬p
            bool left2 = impl(p, q);
            bool right2 = impl(!q, !p);
            if (left2 != right2) {
                cout << "Fail eq2 at p="<<p<<" q="<<q<<"\n";
            }
            // đẳng thức 3: p ∨ q ≡ ¬p → q
            bool left3 = p || q;
            bool right3 = impl(!p, q);
            if (left3 != right3) {
                cout << "Fail eq3 at p="<<p<<" q="<<q<<"\n";
            }
            // đẳng thức 4: p ∧ q ≡ ¬(p → ¬q)
            bool left4 = p && q;
            bool right4 = !(impl(p, !q));
            if (left4 != right4) {
                cout << "Fail eq4 at p="<<p<<" q="<<q<<"\n";
            }
            // đẳng thức 5: ¬(p → q) ≡ p ∧ ¬q
            bool left5 = !(impl(p, q));
            bool right5 = p && (!q);
            if (left5 != right5) {
                cout << "Fail eq5 at p="<<p<<" q="<<q<<"\n";
            }
        }
    }
    cout << "Table 7 check done.\n";

    // kiểm tra Table 8:
    cout << "=== Table 8 equivalences ===\n";
    for (int pi = 0; pi < 2; pi++) {
        for (int qi = 0; qi < 2; qi++) {
            bool p = pi, q = qi;
            // eq A: p ↔ q ≡ (p → q) ∧ (q → p)
            bool leftA = biimpl(p, q);
            bool rightA = impl(p, q) && impl(q, p);
            if (leftA != rightA) {
                cout << "Fail eqA at p="<<p<<" q="<<q<<"\n";
            }
            // eq B: p ↔ q ≡ ¬p ↔ ¬q
            bool rightB = biimpl(!p, !q);
            if (leftA != rightB) {
                cout << "Fail eqB at p="<<p<<" q="<<q<<"\n";
            }
            // eq C: p ↔ q ≡ (p ∧ q) ∨ (¬p ∧ ¬q)
            bool rightC = (p && q) || ((!p) && (!q));
            if (leftA != rightC) {
                cout << "Fail eqC at p="<<p<<" q="<<q<<"\n";
            }
            // eq D: ¬(p ↔ q) ≡ p ↔ ¬q
            bool leftD = !biimpl(p, q);
            bool rightD = biimpl(p, !q);
            if (leftD != rightD) {
                cout << "Fail eqD at p="<<p<<" q="<<q<<"\n";
            }
        }
    }
    // Với các dạng có 3 biến (p, q, r) cho các đẳng thức liên quan →, ∧, ∨ trong Table 8:
    for (int pi = 0; pi < 2; pi++) {
        for (int qi = 0; qi < 2; qi++) {
            for (int ri = 0; ri < 2; ri++) { 
                bool p = pi, q = qi, r = ri;
                // eq E: (p → q) ∧ (p → r) ≡ p → (q ∧ r)
                bool leftE = impl(p, q) && impl(p, r);
                bool rightE = impl(p, (q && r));
                if (leftE != rightE) {
                    cout << "Fail eqE at p="<<p<<" q="<<q<<" r="<<r<<"\n";
                }
                // eq F: (p → r) ∧ (q → r) ≡ (p ∨ q) → r
                bool leftF = impl(p, r) && impl(q, r);
                bool rightF = impl(p || q, r);
                if (leftF != rightF) {
                    cout << "Fail eqF at p="<<p<<" q="<<q<<" r="<<r<<"\n";
                }
                // eq G: (p → q) ∨ (p → r) ≡ p → (q ∨ r)
                bool leftG = impl(p, q) || impl(p, r);
                bool rightG = impl(p, (q || r));
                if (leftG != rightG) {
                    cout << "Fail eqG at p="<<p<<" q="<<q<<" r="<<r<<"\n";
                }
                // eq H: (p → r) ∨ (q → r) ≡ (p ∧ q) → r
                bool leftH = impl(p, r) || impl(q, r);
                bool rightH = impl(p && q, r);
                if (leftH != rightH) {
                    cout << "Fail eqH at p="<<p<<" q="<<q<<" r="<<r<<"\n";
                }
            }
        }
    }
    cout << "Table 8 check done.\n";

    return 0;
}
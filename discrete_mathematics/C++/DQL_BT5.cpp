#include <iostream>
using namespace std;
void check_equivalence(string name, bool expr1, bool expr2) {
    if (expr1 != expr2)
        cout << " sai quy tắc: " << name << endl;
}

int main() {
    bool p, q, r;
    for (int i = 0; i < 8; ++i) {
        p = i & 1;
        q = (i >> 1) & 1;
        r = (i >> 2) & 1;

        cout << "thử nghiệm " << i + 1 << ": p=" << p << " q=" << q << " r=" << r << endl;
        ("Identity AND", p && true, p);
        ("Identity OR", p || false, p);
        ("Domination OR", p || true, true);
        ("Idempotent OR", p || p, p);
        ("Idempotent AND", p && p, p);
        ("Double Negation", !!p, p);
        ("Commutative OR", p || q, q || p);
        ("Commutative AND", p && q, q && p);
        ("Associative OR", (p || q) || r, p || (q || r));
        ("Associative AND", (p && q) && r, p && (q && r));
        ("Distributive OR over AND", p || (q && r), (p || q) && (p || r));
        ("Distributive AND over OR", p && (q || r), (p && q) || (p && r));
        ("De Morgan AND", !(p && q), !p || !q);
        ("De Morgan OR", !(p || q), !p && !q);
        ("Absorption OR", p || (p && q), p);
        ("Absorption AND", p && (p || q), p);
        ("Negation OR", p || !p, true);
        ("Negation AND", p && !p, false);

    }

    return 0;
}

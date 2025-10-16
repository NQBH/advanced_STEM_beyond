#include <iostream>
using namespace std;
void check_equivalence(string name, bool expr1, bool expr2) {
    if (expr1 != expr2)
        cout << " Vi phạm quy tắc: " << name << endl;
}

int main() {
    bool p, q, r;
    for (int i = 0; i < 8; ++i) {
        p = i & 1;
        q = (i >> 1) & 1;
        r = (i >> 2) & 1;

        cout << "Test case " << i + 1 << ": p=" << p << " q=" << q << " r=" << r << endl;

        // Identity laws
        check_equivalence("Identity AND", p && true, p);
        check_equivalence("Identity OR", p || false, p);

        // Domination laws
        check_equivalence("Domination OR", p || true, true);
        check_equivalence("Domination AND", p && false, false);

        // Idempotent laws
        check_equivalence("Idempotent OR", p || p, p);
        check_equivalence("Idempotent AND", p && p, p);

        // Double negation law
        check_equivalence("Double Negation", !!p, p);

        // Commutative laws
        check_equivalence("Commutative OR", p || q, q || p);
        check_equivalence("Commutative AND", p && q, q && p);

        // Associative laws
        check_equivalence("Associative OR", (p || q) || r, p || (q || r));
        check_equivalence("Associative AND", (p && q) && r, p && (q && r));

        // Distributive laws
        check_equivalence("Distributive OR over AND", p || (q && r), (p || q) && (p || r));
        check_equivalence("Distributive AND over OR", p && (q || r), (p && q) || (p && r));

        // De Morgan's laws
        check_equivalence("De Morgan AND", !(p && q), !p || !q);
        check_equivalence("De Morgan OR", !(p || q), !p && !q);

        // Absorption laws
        check_equivalence("Absorption OR", p || (p && q), p);
        check_equivalence("Absorption AND", p && (p || q), p);

        // Negation laws
        check_equivalence("Negation OR", p || !p, true);
        check_equivalence("Negation AND", p && !p, false);

        cout << "-----------------------------\n";
    }

    cout << "Kiểm tra hoàn tất.\n";
    return 0;
}
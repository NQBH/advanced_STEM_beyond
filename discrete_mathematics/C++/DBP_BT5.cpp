#include <iostream>
using namespace std;

int main() {
    bool p, q, r;
    cout << "Kiem tra cac quy dinh logic\n\n";
    // 1.Identity laws
    cout << "1.Identity laws\n";
    cout << "p and True  <=>  p\n";
    cout << "p or False  <=>  p\n\n";

    for (int P = 0; P <= 1; P++) {
        p = P;
        cout << "   Khi p = " << p << ":\n";
        cout << " p && True  = " << (p and true) << endl;
        cout << " p || False  = " << (p or false) << endl;
    }
    // 2.Domination laws
    cout << "2.Domination laws\n";
    cout << "p || True  <=>  True\n";
    cout << "p && False  <=>  False\n\n";

    for (int P = 0; P <= 1; P++) {
        p = P;
        cout << "   Khi p = " << p << ":\n";
        cout << " p || True   = " << (p or true) << endl;
        cout << " p && False = " << (p and false) << endl;
    }
    // 3.Idemtotent laws
    cout << "3.Idemtotent laws\n";
    cout << "p || p  <=>  p\n";
    cout << " p && p <=>  p\n\n";

    for (int P = 0; P <= 1; P++) {
        p = P;
        cout << " Khi p = " << p << ":\n";
        cout << " p || p  = " << (p or p) << endl;
        cout << " p && p = " << (p and p) << endl;
    }
    // 4.Double negation
    cout << "4. Double negation\n";
    cout << "!(!(p))  <=>  p\n\n";

    for (int P = 0; P <= 1; P++) {
        p = P;
        cout << "Khi p = " << p << ":\n";
        cout << "!(!(p)) = " << (not(not(p))) << endl;
    }
    // 5.Communtative laws
    cout << "5.Communtative laws\n";
    cout << " p || q  <=>  q or p\n";
    cout << " p && q <=>  q and p\n\n";

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {
            p = P; q = Q;
            cout << "Khi p=" << p << ", q=" << q << ":\n";
            cout << "p || q = " << (p or q) << ", q || p = " << (q or p) << endl;
            cout << "p && q = " << (p and q) << ", q && p = " << (q and p) << endl;
        }
    }
    // 6.Associative laws
    cout << "6. Associative laws\n";
    cout << " (p || q) or r  <=>  p || (q || r)\n";
    cout << " (p && q) and r  <=>  p && (q && r)\n\n";

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {
            for (int R = 0; R <= 1; R++) {
                p = P; q = Q; r = R;
                cout << " p=" << p << ", q=" << q << ", r=" << r << ":\n";
                cout << " (p || q) || r = " << ((p or q) or r);
                cout << ", p or (q && r) = " << (p or (q or r)) << endl;
                cout << "(p && q) && r = " << ((p and q) and r);
                cout << ",p && (q && r) = " << (p and (q and r)) << endl;
            }
        }
    }
    // 7.De morgan's laws
    cout << "7.De morgan's laws\n";
    cout << "!(p && q)  <=>  !(p) || !(q)\n";
    cout << "!(p || q)   <=>  !(p) && !(q)\n\n";

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {
            p = P; q = Q;
            cout << "   Khi p=" << p << ", q=" << q << ":\n";
            cout << "!(p && q) = " << (not(p and q));
            cout << ",!(p) || !(q) = " << (not(p) or not(q)) << endl;
            cout << "!(p || q) = " << (not(p or q));
            cout << ",!(p) && !(q) = " << (not(p) and not(q)) << endl;
        }
    }
    // 8. Absorption laws
    cout << "8.Absorption laws\n";
    cout << " p || (p && q)  <=>  p\n";
    cout << " p && (p || q)  <=>  p\n\n";

    for (int P = 0; P <= 1; P++) {
        for (int Q = 0; Q <= 1; Q++) {
            p = P; q = Q;
            cout << "Khi p=" << p << ", q=" << q << ":\n";
            cout << "p || (p a&& q) = " << (p or (p and q));
            cout << ",p && (p || q) = " << (p and (p or q)) << endl;
        }
    }
    // 9.Negation laws
    cout << "9.Negation laws\n";
    cout << "p || !(p)  <=>  True\n";
    cout << "p && !(p) <=>  False\n\n";

    for (int P = 0; P <= 1; P++) {
        p = P;
        cout << "Khi p = " << p << ":\n";
        cout << "p || !(p) = " << (p or not(p)) << endl;
        cout << "p && !(p) = " << (p and not(p)) << endl;
    }
    return 0;
}

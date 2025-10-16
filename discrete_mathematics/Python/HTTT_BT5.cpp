#include <iostream>
using namespace std;

bool eq(bool a[], bool (*f1)(bool,bool,bool), bool (*f2)(bool,bool,bool)) {
    for (int i = 0; i < 8; i++) {
        bool p = a[i] & 1, q = (a[i]>>1)&1, r = (a[i]>>2)&1;
        if (f1(p,q,r) != f2(p,q,r)) return false;
    }
    return true;
}

bool identity1(bool p,bool q,bool r){ return p && true; }
bool identity1c(bool p,bool q,bool r){ return p; }
bool identity2(bool p,bool q,bool r){ return p || false; }
bool identity2c(bool p,bool q,bool r){ return p; }

bool domination1(bool p,bool q,bool r){ return p || true; }
bool domination1c(bool p,bool q,bool r){ return true; }

bool domination2(bool p,bool q,bool r){ return p && false; }
bool domination2c(bool p,bool q,bool r){ return false; }

bool idemp1(bool p,bool q,bool r){ return p || p; }
bool idemp1c(bool p,bool q,bool r){ return p; }

bool idemp2(bool p,bool q,bool r){ return p && p; }
bool idemp2c(bool p,bool q,bool r){ return p; }

bool doubleneg(bool p,bool q,bool r){ return !!p; }
bool doublenegc(bool p,bool q,bool r){ return p; }

bool comm1(bool p,bool q,bool r){ return p || q; }
bool comm1c(bool p,bool q,bool r){ return q || p; }

bool comm2(bool p,bool q,bool r){ return p && q; }
bool comm2c(bool p,bool q,bool r){ return q && p; }

bool assoc1(bool p,bool q,bool r){ return (p||q)||r; }
bool assoc1c(bool p,bool q,bool r){ return p||(q||r); }

bool assoc2(bool p,bool q,bool r){ return (p&&q)&&r; }
bool assoc2c(bool p,bool q,bool r){ return p&&(q&&r); }

bool distr1(bool p,bool q,bool r){ return p||(q&&r); }
bool distr1c(bool p,bool q,bool r){ return (p||q)&&(p||r); }

bool distr2(bool p,bool q,bool r){ return p&&(q||r); }
bool distr2c(bool p,bool q,bool r){ return (p&&q)||(p&&r); }

bool dem1(bool p,bool q,bool r){ return !(p&&q); }
bool dem1c(bool p,bool q,bool r){ return !p || !q; }

bool dem2(bool p,bool q,bool r){ return !(p||q); }
bool dem2c(bool p,bool q,bool r){ return !p && !q; }

bool abs1(bool p,bool q,bool r){ return p || (p&&q); }
bool abs1c(bool p,bool q,bool r){ return p; }

bool abs2(bool p,bool q,bool r){ return p && (p||q); }
bool abs2c(bool p,bool q,bool r){ return p; }

bool neg1(bool p,bool q,bool r){ return p || !p; }
bool neg1c(bool p,bool q,bool r){ return true; }

bool neg2(bool p,bool q,bool r){ return p && !p; }
bool neg2c(bool p,bool q,bool r){ return false; }

int main() {
    cout << "=== Logical Equivalence Check ===\n";
    cout << "Identity 1: " << eq(nullptr,identity1,identity1c) << endl;
    cout << "Identity 2: " << eq(nullptr,identity2,identity2c) << endl;
    cout << "Domination 1: " << eq(nullptr,domination1,domination1c) << endl;
    cout << "Domination 2: " << eq(nullptr,domination2,domination2c) << endl;
    cout << "Idempotent 1: " << eq(nullptr,idemp1,idemp1c) << endl;
    cout << "Idempotent 2: " << eq(nullptr,idemp2,idemp2c) << endl;
    cout << "Double Negation: " << eq(nullptr,doubleneg,doublenegc) << endl;
cout << "Commutative 1: " << eq(nullptr,comm1,comm1c) << endl;
cout << "Commutative 2: " << eq(nullptr,comm2,comm2c) << endl;
    cout << "Associative 1: " << eq(nullptr,assoc1,assoc1c) << endl;
    cout << "Associative 2: " << eq(nullptr,assoc2,assoc2c) << endl;
    cout << "Distributive 1: " << eq(nullptr,distr1,distr1c) << endl;
    cout << "Distributive 2: " << eq(nullptr,distr2,distr2c) << endl;
    cout << "De Morgan 1: " << eq(nullptr,dem1,dem1c) << endl;
    cout << "De Morgan 2: " << eq(nullptr,dem2,dem2c) << endl;
    cout << "Absorption 1: " << eq(nullptr,abs1,abs1c) << endl;
    cout << "Absorption 2: " << eq(nullptr,abs2,abs2c) << endl;
    cout << "Negation 1: " << eq(nullptr,neg1,neg1c) << endl;
    cout << "Negation 2: " << eq(nullptr,neg2,neg2c) << endl; }
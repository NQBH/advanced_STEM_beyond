#include <iostream>
using namespace std;

bool implies(bool a, bool b){
    return !a || b; // a => b
}
bool equiv(bool a, bool b){
    return a == b; // a = b
}

int main(){
    bool p, q, r;
    bool ok;

    // Quy tac 1
    ok = true;
    for (int i=0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = implies(p, q);
        bool right = (!p) || q;
        if (!equiv(left, right)) ok = false;
    }
    cout << "p => q equiv !p V q: " << (ok ? "True" : "False") << endl;

    // Quy tac 2
    ok = true;
    for (int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = implies(p, q);
        bool right = implies(!q, !p);
        if (!equiv(left, right)) ok = false;
    }
    cout << "p => q equiv (!q => !p): " << (ok ? "True" : "False") << endl;

    // Quy tac 3
    ok = true;
    for (int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = p || q;
        bool right = implies(!p, q);
        if (!equiv(left, right)) ok = false;
    }
    cout << "p V q equiv (!p => q): " << (ok ? "True" : "False") << endl;

    // Quy tac 4
    ok = true;
    for (int i = 0; i < 4; i++){
        p = i / 2;
        q = i%2;
        bool left = p && !q;
        bool right = !implies(p, q);
        if (!equiv(left, right)) ok = false;
    }
    cout << "p ^ q equiv !(p => !q): " << (ok ? "True" : "False") << endl;

    // Quy tac 5
    ok = true;
    for (int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = !implies(p, q);
        bool right = p && !q;
        if (!equiv(left, right)) ok = false;
    }
    cout << "! (p => q) equiv (p ^ !q): " << (ok ? "True" : "False") << endl;

    // Quy tac 6
    ok = true;
    for (int i =0; i < 8; i++){
        p = (i >> 2) & 1;
        q = (i >> 1) & 1;
        r = i & 1;
        bool left = implies(p, q) && implies(q,r);
        bool right = implies(p, q && r);
        if (!equiv(left, right)) ok = false;
    }
    cout << "(p => q) ^ (q => r) equiv (p => (q ^ r)): " << (ok ? "True" : "False") << endl;

    // Quy tac 7
    ok = true;
    for (int i =0; i < 8; i++){
        p = (i >> 2) & 1;
        q = (i >> 1) & 1;
        r = i & 1;
        bool left = implies(p,r) && implies(q,r);
        bool right = implies(p || q, r);
        if (!equiv(left, right)) ok = false;
    }
    cout << "(p => r) ^ (q => r) equiv ((p V q) => r): " << (ok ? "True" : "False") << endl;

    // Quy tac 8
    ok = true;
    for (int i = 0; i < 8; i++){
        p = (i >> 2) && 1;
        q = (i >> 1) && 1;
        r = i && 1;
        bool left = implies(p, q) || implies(p, r);
        bool right = implies(p, q || r);
        if (!equiv(left, right)) ok = false;
    }
    cout << "(p => q) V (p => r) equiv (p => (q V r)): " << (ok ? "True" : "False") << endl;

    // Quy tac 9
    ok = true;
    for (int i = 0; i < 8; i++){
        p = (i >> 2) && 1;
        q = (i >> 1) && 1;
        r = i && 1;
        bool left = implies(p && q, r);
        bool right = implies(p, implies(q, r));
        if (!equiv(left, right)) ok = false;
    }
    cout << "(p ^ q => r) equiv (p => (q => r)): " << (ok ? "True" : "False") << endl;

    return 0;
}
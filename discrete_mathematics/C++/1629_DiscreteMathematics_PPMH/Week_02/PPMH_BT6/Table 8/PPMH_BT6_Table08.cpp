#include <iostream>
using namespace std;

bool implies(bool a, bool b){
    return (!a) || b; 
}

bool equiv(bool a, bool b){
    return a == b; 
}

bool biconditional(bool a, bool b){
    return a == b; 
}

int main() {
    bool p, q;
    bool ok;

    // p biconditional q equiv (p => q) ^ (q => p)
    ok = true;
    for(int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = biconditional(p, q);
        bool right = implies(p, q) && implies(q, p);
        if (!equiv(left, right)) ok = false;
    }
    cout << "p <=> q equiv (p => q) ^ (q => p): " << (ok ? "True" : "False") << endl;

    // p <=> q equiv !p <=> !q
    ok = true;
    for(int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = biconditional(p, q);
        bool right = biconditional(!p, !q);
        if (!equiv(left, right)) ok = false;
    }
    cout << "p <=> q equiv !p <=> !q: " << (ok ? "True" : "False") << endl;

    // p <=> q equiv (p 6 q) V (!p ^ !q)
    ok = true;
    for(int i = 0; i<4; i++){
        p = i / 2;
        q = i % 2;
        bool left = biconditional(p, q);
        bool right = (p && q) || (!p && !q);
        if (!equiv(left, right)) ok = false;
    }
    cout << "p <=> q equiv (p ^ q) V (!p ^ !q): " << (ok ? "True" : "False") << endl;

    // !(p <=> q) equiv p <=> !q
    ok = true;
    for(int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        bool left = !biconditional(p, q);
        bool right = biconditional(p, !q);
        if (!equiv(left, right)) ok = false;
    }
    cout << "!(p <=> q) equiv p <=> !q: " << (ok ? "True" : "False") << endl;

    return 0;
}
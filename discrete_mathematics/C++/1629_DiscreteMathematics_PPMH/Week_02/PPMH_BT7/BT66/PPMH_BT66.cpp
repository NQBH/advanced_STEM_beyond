// a) (p V q V !r) ^ (p V !q V !s) ^ (p V !r V !s) ^ (!p V !q V !s) ^ (p V q V !s)
// b) (!p V !q V r) ^ (!p V q V !s) ^ (p V !q V !s) ^ (!p V !r V !s) ^ (p V q V !s) ^ (q V !r V !s)
// c) (p V q V r) ^ (p V !q V !s) ^ (q V !r V s) ^ (!p V !q V s) ^ (!p V !r V !s)

#include <iostream>
using namespace std;

bool implies(bool a, bool b) {
    return (!a) || b;
}

bool biconditional(bool a, bool b) {
    return a == b;
}

int main() {
    bool p, q, r, s;
    bool value;
    bool sat;

    // a
    cout << "a)" << endl;
    sat = false;
    for(int i = 0; i<16; i++){
        p = (i / 8) % 2;
        q = (i / 4) % 2;
        r = (i / 2) % 2;
        s = i % 2;

        value = ( (p || q || !r)
                && (p || !q || !s)
                && (p || !r || !s)
                && (!p || !q || s)
                && (p || q || !s) );
        if(value){
            cout << "\nSatisfiable for p=" << p << ", q=" << q << ", r=" << r << ", s=" << s;
            sat = true;
            break;
        }
    }
    if(!sat) cout << "\nNot satisfiable";

    // b
    cout << "\n\nb)" << endl;
    sat = false;
    for(int i = 0; i<16; i++){
        p = (i / 8) % 2;
        q = (i / 4) % 2;
        r = (i / 2) % 2;
        s = i % 2;

        value = ( (!p || !q || r)
               && (!p || q || !s)
               && (p || !q || !s)
               && (!p || !r || !s)
               && (p || q || !r)
               && (p || !r || !s) );
        if(value){
            cout << "\nSatisfiable for p=" << p << ", q=" << q << ", r=" << r << ", s=" << s;
            sat = true;
            break;
        }
    }
    if(!sat) cout << "\nNot satisfiable";

    // c
    cout << "\n\nc)" << endl;
    sat = false;
    for(int i = 0; i<16; i++){
        p = (i / 8) % 2;
        q = (i / 4) % 2;
        r = (i / 2) % 2;
        s = i % 2;

        value = ( (p || q || r)
               && (p || !q || !s)
               && (q || !r || s)
               && (!p || r || s)
               && (!p || q || !s)
               && (p || !q || !r)
               && (!p || !q || s)
               && (!p || !r || !s) );

        if(value){
            cout << "\nSatisfiable for p=" << p << ", q=" << q << ", r=" << r << ", s=" << s;
            sat = true;
            break;
        }
    }
    if(!sat) cout << "\nNot satisfiable";
    cout << endl;
    return 0;
}
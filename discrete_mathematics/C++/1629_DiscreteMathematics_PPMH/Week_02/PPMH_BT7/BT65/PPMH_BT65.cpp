#include <iostream>
using namespace std;

bool implies(bool a, bool b) {
    return (!a) || b;
}

bool biconditional(bool a, bool b) {
    return a == b;
}

int main(){
    bool p, q;
    bool value;
    bool sat;
    // a
    sat = false;
    cout << "(p V !q) ^ (!p V q) ^ (!p V !q)" ;
    for(int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        value = ((p || !q) && (!p || q) && (!p || !q));
        if(value){
            cout << "\nSatisfiable for p = " << p << ", q = " << q;
            sat = true;
            break;
        }
    }
    if(!sat) cout << "\nNot satisfiable";

    // b
    sat = false;
    cout << "\n\n(p => q) ^ (p => !q) ^ (!p => q) ^ (!p => !q)" ;
    for(int i = 0; i < 4; i++){
        p = i / 2;
        q = i % 2;
        value = (implies(p,q) && implies(p, !q) && implies(!p,q) && implies(!p,!q));
        if(value){
            cout << "\nSatisfiable for p = " << p << ", q = " << q;
            sat = true;
            break;
        }
    }
    if(!sat) cout << "\nNot satisfiable";

    // c
    sat = false;
    cout << "\n\n(p <=> q) ^ (!p <=> q)";
    for(int i=0; i < 4; i++){
        p = i /2;
        q = i % 2;
        value = (biconditional(p,q) && biconditional(!p,q));
        if(value){
            cout << "\nSatisfiable for p = " << p << ", q = " << q;
            sat = true;
            break;
        }
    }
    if(!sat) cout << "\nNot satisfiable";
    return 0;
}
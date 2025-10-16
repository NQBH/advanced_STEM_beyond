/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

bool implies(bool a, bool b) { return (!a) || b; }
bool equiv(bool a, bool b) { return a == b; }

struct Val { bool p,q,r,s; };

// ===== Bài 65 =====
bool BT65a(Val v) {
    return (v.p || !v.q) && (!v.p || v.q) && (!v.p || !v.q);
}
bool BT65b(Val v) {
    return implies(v.p, v.q) && implies(v.p, !v.q)
        && implies(!v.p, v.q) && implies(!v.p, !v.q);
}
bool BT65c(Val v) {
    return equiv(v.p, v.q) && equiv(!v.p, v.q);
}

// ===== Bài 66 =====
bool BT66a(Val v){
    return (v.p||v.q||!v.r)&&(v.p||!v.q||!v.s)&&(v.p||!v.r||!v.s)
        &&(!v.p||!v.q||!v.s)&&(!v.p||v.q||v.s);
}
bool BT66b(Val v){
    return (!v.p||!v.q||v.r)&&(!v.p||v.q||!v.s)&&(v.p||!v.q||!v.s)&&(v.p||v.q||!v.r);
}
bool BT66c(Val v){
    return (v.p||v.q||v.r)&&(v.p||!v.q||!v.s)&&(v.p||!v.r||v.s)
        &&(!v.p||v.r||v.s)&&(!v.p||v.q||!v.s)&&(v.p||!v.r||!v.s);
}

// ===== Hàm kiểm tra =====
void check(function<bool(Val)> f, int nvars){
    for(int mask = 0; mask < (1 << nvars); ++mask){
        Val v{};
        v.p = mask & (1 << 0);
        v.q = nvars > 1 ? mask & (1 << 1) : false;
        v.r = nvars > 2 ? mask & (1 << 2) : false;
        v.s = nvars > 3 ? mask & (1 << 3) : false;
        if(f(v)){
            cout << "satisfiable, ví dụ: {";
            cout << "p=" << v.p << ", q=" << v.q
                 << ", r=" << v.r << ", s=" << v.s << "}\n";
            return;
        }
    }
    cout << "unsatisfiable\n";
}

// ===== MAIN =====
int main(){
    cout << "Bài 65:\n";
    check(BT65a, 2);
    check(BT65b, 2);
    check(BT65c, 2);

    cout << "\nBài 66:\n";
    check(BT66a, 4);
    check(BT66b, 4);
    check(BT66c, 4);
}
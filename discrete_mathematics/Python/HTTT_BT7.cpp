#include <bits/stdc++.h>
using namespace std;

bool implies(bool a, bool b){ return (!a) || b; }
bool equiv(bool a, bool b){ return a == b; }

bool f65_a(bool p,bool q){
    return (p || !q) && (!p || q) && (!p || !q);
}
bool f65_b(bool p,bool q){
    return implies(p,q) && implies(p,!q) && implies(!p,q) && implies(!p,!q);
}
bool f65_c(bool p,bool q){
    return equiv(p,q) && equiv(!p,q);
}

bool f66_a(bool p,bool q,bool r,bool s){
    return (p||q||!r) && (p||!q||!s) && (p||!r||!s) && (!p||!q||!s) && (p||q||!s);
}
bool f66_b(bool p,bool q,bool r,bool s){
    return (!p||!q||r) && (!p||q||!s) && (p||!q||!s) && (!p||!r||!s) && (p||q||!r) && (p||!r||!s);
}
bool f66_c(bool p,bool q,bool r,bool s){
    return (p||q||r) && (p||!q||!s) && (q||!r||s) && (!p||r||s) && (!p||q||!s) && (p||!q||!r) && (!p||!q||s) && (!p||!r||!s);
}

int main(){
    // 65
    vector<pair<string,bool>> res;
    // 65a..c
    bool sat; 
    // 2-vars
    sat = false;
    for(int P=0; P<2 && !sat; ++P) for(int Q=0; Q<2 && !sat; ++Q)
        if(f65_a(P,Q)){ sat=true; cout<<"65a: satisfiable. Example: p="<<P<<" q="<<Q<<"\n"; }
    if(!sat) cout<<"65a: unsatisfiable.\n";

    sat = false;
    for(int P=0; P<2 && !sat; ++P) for(int Q=0; Q<2 && !sat; ++Q)
        if(f65_b(P,Q)){ sat=true; cout<<"65b: satisfiable. Example: p="<<P<<" q="<<Q<<"\n"; }
    if(!sat) cout<<"65b: unsatisfiable.\n";

    sat = false;
    for(int P=0; P<2 && !sat; ++P) for(int Q=0; Q<2 && !sat; ++Q)
        if(f65_c(P,Q)){ sat=true; cout<<"65c: satisfiable. Example: p="<<P<<" q="<<Q<<"\n"; }
    if(!sat) cout<<"65c: unsatisfiable.\n";

    // 66 (4-vars)
    sat = false;
    for(int P=0; P<2 && !sat; ++P) for(int Q=0; Q<2 && !sat; ++Q)
        for(int R=0; R<2 && !sat; ++R) for(int S=0; S<2 && !sat; ++S)
            if(f66_a(P,Q,R,S)){ sat=true; cout<<"66a: satisfiable. Example: p="<<P<<" q="<<Q<<" r="<<R<<" s="<<S<<"\n"; }
    if(!sat) cout<<"66a: unsatisfiable.\n";

    sat = false;
    for(int P=0; P<2 && !sat; ++P) for(int Q=0; Q<2 && !sat; ++Q)
        for(int R=0; R<2 && !sat; ++R) for(int S=0; S<2 && !sat; ++S)
            if(f66_b(P,Q,R,S)){ sat=true; cout<<"66b: satisfiable. Example: p="<<P<<" q="<<Q<<" r="<<R<<" s="<<S<<"\n"; }
    if(!sat) cout<<"66b: unsatisfiable.\n";

    sat = false;
    for(int P=0; P<2 && !sat; ++P) for(int Q=0; Q<2 && !sat; ++Q)
        for(int R=0; R<2 && !sat; ++R) for(int S=0; S<2 && !sat; ++S)
            if(f66_c(P,Q,R,S)){ sat=true; cout<<"66c: satisfiable. Example: p="<<P<<" q="<<Q<<" r="<<R<<" s="<<S<<"\n"; }
    if(!sat) cout<<"66c: unsatisfiable.\n";
    return 0;
}
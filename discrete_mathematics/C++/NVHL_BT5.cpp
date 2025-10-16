#include <bits/stdc++.h>
using namespace std;

int main(){
    bool v[] = {0 , 1};
    bool ok;

    auto T = [](bool b){ cout << (b ? "Dung\n" : "Sai\n");};

     // Indetity laws
    ok = true;
    for (bool p : v) if (!((p && true) ==  p && (p || false) == p)) ok = false;
        T(ok);
     // Domination laws
    ok = true;
    for (bool p : v) if (!((p || true) == true && (p && false) == false)) ok = false;
        T(ok);
     // Idempotent laws
    ok = true;
    for (bool p : v) if (!((p || p) == p && (p && p) == p)) ok = false;
     T(ok);
     // Double negation laws
     ok = true;
     for (bool p : v) if (!((!(!p)) == p)) ok = true;
     T(ok);
     // Commutative laws
     ok = true;
     for (bool p : v) for (bool q : v)
        if (!(((p || q) == (q || p)) && ((p && q) == (q && p)))) ok = false;
     T(ok);
     // Associative laws
     ok = true;
     for(bool p : v) for (bool q : v) for (bool r : v)
        if (!((((p || q) || r) == (p || (q || r))) && (((p && q) && r) == (p && (q && r))))) ok = true;
      T(ok);
     //Distributive laws
    ok = true;
    for(bool p : v) for(bool q : v) for (bool r : v)
        if(!(((p || (q && r)) == ((p || q) && (p || r))) && ((p && (q || r)) == ((p && q) || (p && r))))) ok = true;
    T(ok);

    // De morgan's laws
    ok = true;
    for(bool p : v) for (bool q : v)
        if (!((!(p && q) == ((!p) || (!q))) && (p || q)) == ((!p) && (!q))) ok = true;
    T(ok);

    // Absorption laws
    ok = true;
    for(bool p : v) for (bool q : v)
        if(!(((p || (p && q)) == p) && ((p && (p || q)) == p))) ok = false;
    T(ok);

    //Negation laws
    ok = true;
    for ( bool p : v)
        if (!((( p || !p) == true) && ((p && !p) == false))) ok = false;
    T(ok);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// ==================== COMMON UTILS ==================== //
bool imply(bool p, bool q){ return (!p) || q; }
bool iff(bool p, bool q){ return p == q; }

void test_equiv(const string& name,
                const vector<string>& vars,
                function<bool(map<string,bool>&)> f1,
                function<bool(map<string,bool>&)> f2)
{
    int n = vars.size();
    for(int mask=0; mask<(1<<n); ++mask){
        map<string,bool> env;
        for(int i=0;i<n;++i) env[vars[i]] = (mask>>i)&1;
        if(f1(env)!=f2(env)){
            cout<<"[FAIL] "<<name<<"  ";
            for(auto &v: vars) cout<<v<<"="<<(env[v]?"T ":"F ");
            cout<<"\n"; return;
        }
    }
    cout<<"[OK] "<<name<<"\n";
}

// ==================== BT5 – TABLE 6 ==================== //
void run_table6(){
    cout << "=== TABLE 6 ===\n";
    // Identity
    test_equiv("Identity ∧", {"p"},
        [](auto&e){return e["p"]&&true;},
        [](auto&e){return e["p"];});
    test_equiv("Identity ∨", {"p"},
        [](auto&e){return e["p"]||false;},
        [](auto&e){return e["p"];});

    // Domination
    test_equiv("Domination ∨", {"p"},
        [](auto&e){return e["p"]||true;},
        [](auto&e){return true;});
    test_equiv("Domination ∧", {"p"},
        [](auto&e){return e["p"]&&false;},
        [](auto&e){return false;});

    // Idempotent
    test_equiv("Idempotent ∨", {"p"},
        [](auto&e){return e["p"]||e["p"];},
        [](auto&e){return e["p"];});
    test_equiv("Idempotent ∧", {"p"},
        [](auto&e){return e["p"]&&e["p"];},
        [](auto&e){return e["p"];});

    // Double Negation
    test_equiv("Double Negation", {"p"},
        [](auto&e){return !(!e["p"]);},
        [](auto&e){return e["p"];});

    // Commutative
    test_equiv("Commutative ∨", {"p","q"},
        [](auto&e){return e["p"]||e["q"];},
        [](auto&e){return e["q"]||e["p"];});
    test_equiv("Commutative ∧", {"p","q"},
        [](auto&e){return e["p"]&&e["q"];},
        [](auto&e){return e["q"]&&e["p"];});

    // Associative
    test_equiv("Associative ∨", {"p","q","r"},
        [](auto&e){return (e["p"]||e["q"])||e["r"];},
        [](auto&e){return e["p"]||(e["q"]||e["r"]);});
    test_equiv("Associative ∧", {"p","q","r"},
        [](auto&e){return (e["p"]&&e["q"])&&e["r"];},
        [](auto&e){return e["p"]&&(e["q"]&&e["r"]);});

    // Distributive
    test_equiv("Distributive ∨ over ∧", {"p","q","r"},
        [](auto&e){return e["p"]||(e["q"]&&e["r"]);},
        [](auto&e){return (e["p"]||e["q"])&&(e["p"]||e["r"]);});
    test_equiv("Distributive ∧ over ∨", {"p","q","r"},
        [](auto&e){return e["p"]&&(e["q"]||e["r"]);},
        [](auto&e){return (e["p"]&&e["q"])||(e["p"]&&e["r"]);});

    // De Morgan
    test_equiv("De Morgan ¬(p∧q)", {"p","q"},
        [](auto&e){return !(e["p"]&&e["q"]);},
        [](auto&e){return (!e["p"])||(!e["q"]);});
    test_equiv("De Morgan ¬(p∨q)", {"p","q"},
        [](auto&e){return !(e["p"]||e["q"]);},
        [](auto&e){return (!e["p"])&&(!e["q"]);});

    // Absorption
    test_equiv("Absorption ∨", {"p","q"},
        [](auto&e){return e["p"]||(e["p"]&&e["q"]);},
        [](auto&e){return e["p"];});
    test_equiv("Absorption ∧", {"p","q"},
        [](auto&e){return e["p"]&&(e["p"]||e["q"]);},
        [](auto&e){return e["p"];});

    // Negation
    test_equiv("Negation ∨", {"p"},
        [](auto&e){return e["p"]||(!e["p"]);},
        [](auto&e){return true;});
    test_equiv("Negation ∧", {"p"},
        [](auto&e){return e["p"]&&(!e["p"]);},
        [](auto&e){return false;});

    cout<<"\nAll Table 6 equivalences verified.\n\n";
}

// ==================== BT6 – TABLE 7 + 8 ==================== //
void run_table78(){
    cout << "=== TABLE 7 & 8 ===\n";

    // Table 7
    test_equiv("1. p→q ≡ ¬p∨q", {"p","q"},
        [](auto&e){return imply(e["p"],e["q"]);},
        [](auto&e){return (!e["p"])||e["q"];});

    test_equiv("2. p→q ≡ ¬q→¬p", {"p","q"},
        [](auto&e){return imply(e["p"],e["q"]);},
        [](auto&e){return imply(!e["q"],!e["p"]);});

    test_equiv("3. p∨q ≡ ¬p→q", {"p","q"},
        [](auto&e){return e["p"]||e["q"];},
        [](auto&e){return imply(!e["p"],e["q"]);});

    test_equiv("4. p∧q ≡ ¬(p→¬q)", {"p","q"},
        [](auto&e){return e["p"]&&e["q"];},
        [](auto&e){return !(imply(e["p"],!e["q"]));});

    test_equiv("5. ¬(p→q) ≡ p∧¬q", {"p","q"},
        [](auto&e){return !(imply(e["p"],e["q"]));},
        [](auto&e){return e["p"] && (!e["q"]);});

    test_equiv("6. (p→q)∧(p→r) ≡ p→(q∧r)", {"p","q","r"},
        [](auto&e){return imply(e["p"],e["q"]) && imply(e["p"],e["r"]);},
        [](auto&e){return imply(e["p"], e["q"] && e["r"]);});

    test_equiv("7. (p→r)∧(q→r) ≡ (p∨q)→r", {"p","q","r"},
        [](auto&e){return imply(e["p"],e["r"]) && imply(e["q"],e["r"]);},
        [](auto&e){return imply(e["p"]||e["q"], e["r"]);});

    test_equiv("8. (p→q)∨(p→r) ≡ p→(q∨r)", {"p","q","r"},
        [](auto&e){return imply(e["p"],e["q"]) || imply(e["p"],e["r"]);},
        [](auto&e){return imply(e["p"], e["q"]||e["r"]);});

    // Table 8
    test_equiv("9. p↔q ≡ (p→q)∧(q→p)", {"p","q"},
        [](auto&e){return iff(e["p"],e["q"]);},
        [](auto&e){return imply(e["p"],e["q"]) && imply(e["q"],e["p"]);});

    test_equiv("10. p↔q ≡ ¬p↔¬q", {"p","q"},
        [](auto&e){return iff(e["p"],e["q"]);},
        [](auto&e){return iff(!e["p"],!e["q"]);});

    test_equiv("11. p↔q ≡ (p∧q)∨(¬p∧¬q)", {"p","q"},
        [](auto&e){return iff(e["p"],e["q"]);},
        [](auto&e){return (e["p"]&&e["q"]) || ((!e["p"])&&(!e["q"]));});

    test_equiv("12. ¬(p↔q) ≡ p↔¬q", {"p","q"},
        [](auto&e){return !(iff(e["p"],e["q"]));},
        [](auto&e){return iff(e["p"],!e["q"]);});

    cout<<"\nAll Table 7 & 8 equivalences verified.\n\n";
}

// ==================== BT7 – EX 65 + 66 ==================== //
bool check_satisfiable(const vector<char>& vars,
                       function<bool(const map<char,bool>&)> expr,
                       string label) {
    int n = vars.size();
    for (int mask=0; mask < (1<<n); ++mask) {
        map<char,bool> v;
        for (int i=0;i<n;i++) v[vars[i]] = (mask>>i)&1;
        if (expr(v)) {
            cout << label << " is satisfiable\n";
            cout << "Example assignment: ";
            for (char c:vars) cout << c << "=" << (v[c]?"T ":"F ");
            cout << "\n";
            return true;
        }
    }
    cout << label << " is unsatisfiable\n";
    return false;
}

void run_bt7(){
    cout << "=== EXERCISES 65–66 ===\n";

    // 65a
    auto expr65a = [](const map<char,bool>& v){
        bool p=v.at('p'), q=v.at('q');
        return (p || !q) && (!p || q) && (!p || !q);
    };
    // 65b
    auto expr65b = [](const map<char,bool>& v){
        bool p=v.at('p'), q=v.at('q');
        return ((!p||q) && (!p||!q) && (p||q) && (p||!q));
    };
    // 65c
    auto expr65c = [](const map<char,bool>& v){
        bool p=v.at('p'), q=v.at('q');
        return (p==q) && ((!p)==q);
    };

    check_satisfiable({'p','q'}, expr65a, "(65a)");
    check_satisfiable({'p','q'}, expr65b, "(65b)");
    check_satisfiable({'p','q'}, expr65c, "(65c)");

    // 66a
    auto expr66a = [](const map<char,bool>& v){
        bool p=v.at('p'), q=v.at('q'), r=v.at('r'), s=v.at('s');
        return (p||q||!r) && (p||!q||!s) && (p||!r||!s) &&
               (!p||!q||!s) && (p||q||!s);
    };
    // 66b
    auto expr66b = [](const map<char,bool>& v){
        bool p=v.at('p'), q=v.at('q'), r=v.at('r'), s=v.at('s');
        return (!p||!q||r) && (!p||q||!s) && (p||!q||!s) &&
               (!p||!r||!s) && (p||q||!r) && (p||!r||!s);
    };
    // 66c
    auto expr66c = [](const map<char,bool>& v){
        bool p=v.at('p'), q=v.at('q'), r=v.at('r'), s=v.at('s');
        return (p||q||r) && (p||!q||!s) && (q||!r||s) &&
               (!p||r||s) && (!p||q||!s) && (p||!q||!r) &&
               (!p||!q||s) && (!p||!r||!s);
    };

    check_satisfiable({'p','q','r','s'}, expr66a, "(66a)");
    check_satisfiable({'p','q','r','s'}, expr66b, "(66b)");
    check_satisfiable({'p','q','r','s'}, expr66c, "(66c)");

    cout << "\nAll Exercise 65–66 checked.\n";
}

// ==================== MAIN ==================== //
int main(){
    run_table6();
    run_table78();
    run_bt7();
    return 0;
}

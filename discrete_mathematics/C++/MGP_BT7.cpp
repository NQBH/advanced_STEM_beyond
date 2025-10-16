#include <bits/stdc++.h>
using namespace std;

bool val(char var, const map<char, bool>& values) {
    return values.at(var);
}

bool expr65a(const map<char,bool>& v) {
    bool p=v.at('p'), q=v.at('q');
    return (p || !q) && (!p || q) && (!p || !q);
}

bool expr65b(const map<char,bool>& v) {
    bool p=v.at('p'), q=v.at('q');
    return ((p<=q) && ((p<=!q)) && ((!p)<=q) && ((!p)<=!q)); 
}

bool expr65c(const map<char,bool>& v) {
    bool p=v.at('p'), q=v.at('q');
    return ((p==q) && ((!p)==q)); 
}

bool expr66a(const map<char,bool>& v) {
    bool p=v.at('p'), q=v.at('q'), r=v.at('r'), s=v.at('s');
    return (p||q||!r) && (p||!q||!s) && (p||!r||!s) && (!p||!q||!s) && (p||q||!s);
}

bool expr66b(const map<char,bool>& v) {
    bool p=v.at('p'), q=v.at('q'), r=v.at('r'), s=v.at('s');
    return (!p||!q||r) && (!p||q||!s) && (p||!q||!s) &&
           (!p||!r||!s) && (p||q||!r) && (p||!r||!s);
}

bool expr66c(const map<char,bool>& v) {
    bool p=v.at('p'), q=v.at('q'), r=v.at('r'), s=v.at('s');
    return (p||q||r) && (p||!q||!s) && (q||!r||s) &&
           (!p||r||s) && (!p||q||!s) && (p||!q||!r) &&
           (!p||!q||s) && (!p||!r||!s);
}

bool check_satisfiable(const vector<char>& vars,
                       function<bool(const map<char,bool>&)> expr,
                       string label) {
    int n = vars.size();
    for (int mask=0; mask < (1<<n); ++mask) {
        map<char,bool> v;
        for (int i=0;i<n;i++)
            v[vars[i]] = (mask>>i)&1;
        if (expr(v)) {
            cout << label << " is satisfiable\n";
            cout << "Example assignment: ";
            for (char c:vars)
                cout << c << "=" << (v[c] ? "T " : "F ");
            cout << "\n";
            return true;
        }
    }
    cout << label << " is unsatisfiable\n";
    return false;
}

int main() {
    cout << "=== Exercise 65 ===\n";
    check_satisfiable({'p','q'}, expr65a, "(65a)");
    check_satisfiable({'p','q'}, expr65b, "(65b)");
    check_satisfiable({'p','q'}, expr65c, "(65c)");

    cout << "\n=== Exercise 66 ===\n";
    check_satisfiable({'p','q','r','s'}, expr66a, "(66a)");
    check_satisfiable({'p','q','r','s'}, expr66b, "(66b)");
    check_satisfiable({'p','q','r','s'}, expr66c, "(66c)");

    return 0;
}

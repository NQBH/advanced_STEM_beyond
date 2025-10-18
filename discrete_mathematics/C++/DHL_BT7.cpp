#include <iostream>
#define IMPLIES
using namespace std;
void check_sat(const string& ten_bai, int num_vars) {
    bool is_sat = false;
    int num_cases = (1 << num_vars);
    for (int i = 0; i < num_cases; ++i) {
        bool p = (i & 1);
        bool q = (i & 2);
        bool r = (i & 4);  
        bool formula_value = false;
        if (ten_bai == "65a") {
            formula_value = p && !p; 
        } 
        else if (ten_bai == "66a") {
            formula_value = IMPLIES((p || q), (p && q));
        }

        if (formula_value) {
            cout << ten_bai << ": satisfiable" << endl;
            cout << "Bo gia tri thoa man:" << endl;
            cout << "  p: " << (p ? "True" : "False") << endl;
            if (num_vars >= 2) cout << "  q: " << (q ? "True" : "False") << endl;
            if (num_vars >= 3) cout << "  r: " << (r ? "True" : "False") << endl;
            is_sat = true;
            return; }
    }

    if (!is_sat) {
        cout << ten_bai << ": unsatisfiable" << endl;
    }
} 

int main() {
    check_sat("65a", 1); 
    check_sat("66a", 2); 
    return 0;
}
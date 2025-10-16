#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool bt5_1(vector<bool> v) {
    return v[0] && v[1];
}
bool bt5_1_check(vector<bool> v) {
    return v[1] && v[0];
}

bool bt5_2(vector<bool> v) {
    return (v[0] && v[1]) && v[2];
}
bool bt5_2_check(vector<bool> v) {
    return v[0] && (v[1] && v[2]);
}

bool bt5_3(vector<bool> v) {
    return v[0] && (v[1] || v[2]);
}
bool bt5_3_check(vector<bool> v) {
    return (v[0] && v[1]) || (v[0] && v[2]);
}

bool bt5_4(vector<bool> v) {
    return !(v[0] && v[1]);
}
bool bt5_4_check(vector<bool> v) {
    return !v[0] || !v[1];
}

bool bt5_5(vector<bool> v) {
    return !!v[0];
}
bool bt5_5_check(vector<bool> v) {
    return v[0];
}

bool bt5_6(vector<bool> v) {
    return v[0] || false;
}
bool bt5_6_check(vector<bool> v) {
    return v[0];
}

bool bt5_7(vector<bool> v) {
    return v[0] && false;
}
bool bt5_7_check(vector<bool> v) {
    return false;
}

void kiem_tra_bt5(bool (*a)(vector<bool>), bool (*b)(vector<bool>), vector<string> vars) {
    int n = vars.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<bool> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = (mask >> i) & 1;
        }
        if (a(v) != b(v)) {
            cout << "sai\n";
            return;
        }
    }
    cout << "dung\n";
}

void bt5() {
    kiem_tra_bt5(bt5_1, bt5_1_check, {"p","q"});
    kiem_tra_bt5(bt5_2, bt5_2_check, {"p","q","r"});
    kiem_tra_bt5(bt5_3, bt5_3_check, {"p","q","r"});
    kiem_tra_bt5(bt5_4, bt5_4_check, {"p","q"});
    kiem_tra_bt5(bt5_5, bt5_5_check, {"p"});
    kiem_tra_bt5(bt5_6, bt5_6_check, {"p"});
    kiem_tra_bt5(bt5_7, bt5_7_check, {"p"});
}

// BT6

bool bt6_1(vector<bool> v) {
    return v[0] || false;
}
bool bt6_1_check(vector<bool> v) {
    return v[0];
}

bool bt6_2(vector<bool> v) {
    return v[0] && true;
}
bool bt6_2_check(vector<bool> v) {
    return v[0];
}

bool bt6_3(vector<bool> v) {
    return v[0] || true;
}
bool bt6_3_check(vector<bool> v) {
    return true;
}

bool bt6_4(vector<bool> v) {
    return v[0] && false;
}
bool bt6_4_check(vector<bool> v) {
    return false;
}

bool bt6_5(vector<bool> v) {
    return v[0] || !v[0];
}
bool bt6_5_check(vector<bool> v) {
    return true;
}

bool bt6_6(vector<bool> v) {
    return v[0] && !v[0];
}
bool bt6_6_check(vector<bool> v) {
    return false;
}

bool bt6_7(vector<bool> v) {
    return !!v[0];
}
bool bt6_7_check(vector<bool> v) {
    return v[0];
}

bool bt6_8(vector<bool> v) {
    return v[0] || (v[0] && v[1]);
}
bool bt6_8_check(vector<bool> v) {
    return v[0];
}

bool bt6_9(vector<bool> v) {
    return v[0] && (v[0] || v[1]);
}
bool bt6_9_check(vector<bool> v) {
    return v[0];
}

bool bt6_10(vector<bool> v) {
    return (!v[0] || v[1]) && (!v[1] || v[0]);
}
bool bt6_10_check(vector<bool> v) {
    return v[0] == v[1];
}

void kiem_tra_bt6(bool (*a)(vector<bool>), bool (*b)(vector<bool>), vector<string> vars) {
    int n = vars.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<bool> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = (mask >> i) & 1;
        }
        if (a(v) != b(v)) {
            cout << "sai\n";
            return;
        }
    }
    cout << "dung\n";
}

void bt6() {
    kiem_tra_bt6(bt6_1, bt6_1_check, {"p"});
    kiem_tra_bt6(bt6_2, bt6_2_check, {"p"});
    kiem_tra_bt6(bt6_3, bt6_3_check, {"p"});
    kiem_tra_bt6(bt6_4, bt6_4_check, {"p"});
    kiem_tra_bt6(bt6_5, bt6_5_check, {"p"});
    kiem_tra_bt6(bt6_6, bt6_6_check, {"p"});
    kiem_tra_bt6(bt6_7, bt6_7_check, {"p"});
    kiem_tra_bt6(bt6_8, bt6_8_check, {"p","q"});
    kiem_tra_bt6(bt6_9, bt6_9_check, {"p","q"});
    kiem_tra_bt6(bt6_10, bt6_10_check, {"p","q"});
}

// BT7

bool bt65(vector<bool> v) {
    bool p = v[0], q = v[1];
    return (p && !p) || q;
}

bool bt66(vector<bool> v) {
    bool p = v[0], q = v[1], r = v[2];
    return (!p || q) && (!q || r) && (!r);
}

void kiem_tra_bt7(bool (*expr)(vector<bool>), vector<string> vars) {
    int n = vars.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<bool> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = (mask >> i) & 1;
        }
        if (expr(v)) {
            cout << "satisfiable\n";
            for (int i = 0; i < n; i++) {
                cout << vars[i] << " = " << (v[i] ? "True" : "False") << endl;
            }
            return;
        }
    }
    cout << "unsatisfiable\n";
}

void bt7() {
    kiem_tra_bt7(bt65, {"p","q"});
    kiem_tra_bt7(bt66, {"p","q","r"});
}

int main() {
    bt5();
    bt6();
    bt7();
    return 0;
}

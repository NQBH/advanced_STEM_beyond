#include <iostream>
using namespace std;

const bool T = true, F = false;

int main() {
    cout << "=== KIỂM TRA LUẬT TƯƠNG ĐƯƠNG LOGIC (Rosen, Table 6) ===\n";

    bool ok;

    // Phủ định kép: ¬(¬p) ↔ p
    ok = true;
    for (int p = 0; p <= 1; ++p)
        if (!((!(!p)) == p)) ok = false;
    cout << "✅ Phủ định kép: ¬(¬p) ↔ p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Giao hoán (OR)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if (!((p||q)==(q||p))) ok = false;
    cout << "✅ Giao hoán (OR): p∨q ↔ q∨p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Giao hoán (AND)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if (!((p&&q)==(q&&p))) ok = false;
    cout << "✅ Giao hoán (AND): p∧q ↔ q∧p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // De Morgan (AND)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if (!((!(p&&q))==(!p||!q))) ok = false;
    cout << "✅ De Morgan (AND): ¬(p∧q) ↔ ¬p∨¬q → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // De Morgan (OR)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if (!((!(p||q))==(!p&&!q))) ok = false;
    cout << "✅ De Morgan (OR): ¬(p∨q) ↔ ¬p∧¬q → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Hấp thụ (OR)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if (!(((p||(p&&q))==p))) ok = false;
    cout << "✅ Hấp thụ (OR): p∨(p∧q) ↔ p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Hấp thụ (AND)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            if (!(((p&&(p||q))==p))) ok = false;
    cout << "✅ Hấp thụ (AND): p∧(p∨q) ↔ p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Đồng nhất (AND)
    ok = ((T&&T)==T && (F&&T)==F);
    cout << "✅ Đồng nhất (AND): p∧T ↔ p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Đồng nhất (OR)
    ok = ((T||F)==T && (F||F)==F);
    cout << "✅ Đồng nhất (OR): p∨F ↔ p → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Thống trị (OR)
    ok = ((T||T)==T && (F||T)==T);
    cout << "✅ Thống trị (OR): p∨T ↔ T → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Thống trị (AND)
    ok = ((T&&F)==F && (F&&F)==F);
    cout << "✅ Thống trị (AND): p∧F ↔ F → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Phủ định (OR)
    ok = ((T||!T)&& (F||!F));
    cout << "✅ Phủ định (OR): p∨¬p ↔ T → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Phủ định (AND)
    ok = ((!(T&&(!T)))&&(!(F&&(!F))));
    cout << "✅ Phủ định (AND): p∧¬p ↔ F → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Kết hợp (OR)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                if (!(((p||q)||r)==(p||(q||r)))) ok = false;
    cout << "✅ Kết hợp (OR): (p∨q)∨r ↔ p∨(q∨r) → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Kết hợp (AND)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                if (!(((p&&q)&&r)==(p&&(q&&r)))) ok = false;
    cout << "✅ Kết hợp (AND): (p∧q)∧r ↔ p∧(q∧r) → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Phân phối (OR/AND)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                if (!(((p||(q&&r))==((p||q)&&(p||r))))) ok = false;
    cout << "✅ Phân phối (OR/AND): p∨(q∧r) ↔ (p∨q)∧(p∨r) → " << (ok ? "ĐÚNG" : "SAI") << endl;

    // Phân phối (AND/OR)
    ok = true;
    for (int p = 0; p <= 1; ++p)
        for (int q = 0; q <= 1; ++q)
            for (int r = 0; r <= 1; ++r)
                if (!(((p&&(q||r))==((p&&q)||(p&&r))))) ok = false;
    cout << "✅ Phân phối (AND/OR): p∧(q∨r) ↔ (p∧q)∨(p∧r) → " << (ok ? "ĐÚNG" : "SAI") << endl;

    cout << "\n=== Hoàn tất kiểm tra ===\n";
    return 0;
}

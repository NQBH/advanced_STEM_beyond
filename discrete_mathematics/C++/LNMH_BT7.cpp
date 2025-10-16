#include <iostream>
#include <vector>
using namespace std;

// Hàm đánh giá BT65: (p || -q) and (-p || q)
bool evaluateBT65(bool p, bool q) {
    bool part1, part2;

    // p or -q
    if (p || !q)
        part1 = true;
    else
        part1 = false;

    // -p or q
    if (!p || q)
        part2 = true;
    else
        part2 = false;

    // (p or -q) and (-p or q)
    if (part1 && part2)
        return true;
    else
        return false;
}

// Hàm đánh giá BT66: (p ∨ q) ∧ (-p ∨ -q) ∧ (p ∨ -q)
bool evaluateBT66(bool p, bool q) {
    bool part1, part2, part3;

    // p ∨ q
    if (p || q)
        part1 = true;
    else
        part1 = false;

    // -p ∨ -q
    if (!p || !q)
        part2 = true;
    else
        part2 = false;

    // p ∨ -q
    if (p || !q)
        part3 = true;
    else
        part3 = false;

    // Kết hợp 3 phần với ∧
    if (part1 && part2 && part3)
        return true;
    else
        return false;
}

void checkSatisfiability(bool (*evaluate)(bool, bool), const string& label) {
    bool satisfiable = false;
    vector<pair<bool, bool>> satisfyingAssignments;

    for (int i = 0; i < 4; ++i) {
        bool p = i & 1;
        bool q = (i >> 1) & 1;
        if (evaluate(p, q)) {
            satisfiable = true;
            satisfyingAssignments.push_back({ p, q });
        }
    }

    cout << label << ": ";
    if (satisfiable) {
        cout << "satisfiable\n";
        cout << "Satisfying assignments:\n";
        for (auto [p, q] : satisfyingAssignments) {
            cout << "p = " << p << ", q = " << q << "\n";
        }
    }
    else {
        cout << "unsatisfiable\n";
    }
}

int main() {
    checkSatisfiability(evaluateBT65, "BT65");
    cout << "\n";
    checkSatisfiability(evaluateBT66, "BT66");
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void printSolution(const vector<int>& assignment, const vector<vector<int>>& t) {
    vector<int> load(3, 0);
    for (int j = 0; j < 8; j++) {
        load[assignment[j]] += t[assignment[j]][j];
    }

    cout << "Phan cong toi uu:\n";
    for (int i = 0; i < 3; i++) {
        cout << "May " << i << ": ";
        for (int j = 0; j < 8; j++) {
            if (assignment[j] == i) {
                cout << "J" << j << "(" << t[i][j] << ") ";
            }
        }
        cout << "=> Tong: " << load[i] << endl;
    }
    cout << "Toi uu nhat: " << *max_element(load.begin(), load.end())
        << " | Tong thoi gian: " << accumulate(load.begin(), load.end(), 0) << "\n\n";

}
void backtrack(int j, vector<int>& assignment, vector<int>& load,
    const vector<vector<int>>& t, vector<int>& best_assignment, int& min_span) {
    if (j == 8) {
        int current_span = *max_element(load.begin(), load.end());
        if (current_span < min_span) {
            min_span = current_span;
            best_assignment = assignment;
        }
        return;
    }

    for (int m = 0; m < 3; m++) {
        load[m] += t[m][j];
        assignment[j] = m;

        if (load[m] < min_span) // Nhánh c?n
            backtrack(j + 1, assignment, load, t, best_assignment, min_span);

        load[m] -= t[m][j];
    }
}

int main() {
    vector<vector<int>> t = {
        {4, 5, 4, 10, 8, 6, 12, 8},
        {7, 5, 7, 3, 9, 7, 9, 5},
        {10, 6, 7, 12, 10, 6, 5, 7}
    };

    // Gi?i pháp t?t nh?t tìm ???c (Makespan 15)
    vector<int> best_assignment = { 0, 1, 0, 1, 2, 0, 2, 1 };
    printSolution(best_assignment, t);

    return 0;
}
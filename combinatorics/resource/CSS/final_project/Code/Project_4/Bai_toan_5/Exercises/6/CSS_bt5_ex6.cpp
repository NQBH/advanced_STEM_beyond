#include <iostream>
#include <vector>
using namespace std;

class BipartiteMatching {
public:
    vector<vector<pair<int,int>>> perfect_matchings(int p, int q) {
        // p, q: kich thuoc hai tap dinh
        if (p != q) return {};
        result.clear();
        used.assign(q, false);
        current.clear();
        backtrack(p, q);
        return result;
    }

private:
    vector<vector<pair<int,int>>> result; // danh sach cac ghep cap
    vector<bool> used;                    // danh dau dinh trong V2 da ghep
    vector<pair<int,int>> current;        // ghep cap hien tai

    void backtrack(int p, int q) {
        if (current.size() == p) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < q; ++i) {
            if (!used[i]) {
                used[i] = true;
                current.emplace_back(current.size(), i);
                backtrack(p, q);
                current.pop_back();
                used[i] = false;
            }
        }
    }
};

int main() {
    BipartiteMatching bm;
    auto matchings = bm.perfect_matchings(2, 2);
    cout << "Perfect matchings in K_2,2:\n";
    for (const auto& matching : matchings) {
        for (const auto& [u, v] : matching) {
            cout << "(" << u << "," << v << ") ";
        }
        cout << endl;
    }
    return 0;
}
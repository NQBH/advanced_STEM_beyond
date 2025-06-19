/*
Source: ACM Southeastern Europe 2002.
IDs for online judges: POJ 1281, UVA 2514.
Status: Accepted
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int maximum_cost;
    int n;
    while (cin >> maximum_cost >> n) {
        vector<int> costs(maximum_cost + 1, 0);
        vector<int> removal_list(n);
        for (int i = 0; i < n; ++i)
            cin >> removal_list[i];

        char c;
        int cnt = 0, policy = 1;
        while (cin >> c && c != 'e') {
            if (c == 'a') {
                int cost; cin >> cost;
                ++costs[cost];
            }
            else if (c == 'p') {
                int p; cin >> p;
                policy = p;
            }
            else if (c == 'r') {
                ++cnt;
                bool check = false;
                for (int j = 0; j < removal_list.size(); ++j)
                    if (removal_list[j] == cnt)
                        check = true;

                int val = -1;

                if (policy == 1) {
                    for (int j = 0; j <= maximum_cost; ++j) {
                        if (costs[j] == 0) continue;
                        --costs[j];
                        val = j;
                        break;
                    }
                }
                else {
                    for (int j = maximum_cost; j >= 0; --j) {
                        if (costs[j] == 0) continue;
                        --costs[j];
                        val = j;
                        break;
                    }
                }
                if (check)
                    cout << val << '\n';
            }
        }
    }
}
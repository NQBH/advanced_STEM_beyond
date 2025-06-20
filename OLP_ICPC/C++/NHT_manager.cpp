#include <bits/stdc++.h>
using namespace std;

int main() {
    int max_cost, removal_count;

    while (cin >> max_cost) {
        if (max_cost == 0) break;

        cin >> removal_count;

        set<int> removal_list;
        for (int i = 0; i < removal_count; ++i) {
            int r_id;
            cin >> r_id;
            removal_list.insert(r_id);
        }

        string line;
        vector<string> commands;
        cin.ignore(); // bỏ newline

        while (getline(cin, line)) {
            if (line.empty()) break;
            commands.push_back(line);
            if (line[0] == 'e') break;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        priority_queue<int> maxHeap;
        unordered_map<int, int> count;
        int policy = 1;
        int removal_id = 1;
        vector<int> output;

        for (const string& cmd : commands) {
            if (cmd[0] == 'a') {
                int x = stoi(cmd.substr(2));
                if (++count[x] == 1) {
                    minHeap.push(x);
                    maxHeap.push(x);
                }
            } else if (cmd[0] == 'p') {
                policy = cmd[2] - '0';
            } else if (cmd[0] == 'r') {
                int val = -1;

                if (policy == 1) {
                    // Remove min
                    while (!minHeap.empty()) {
                        int x = minHeap.top();
                        if (count[x] > 0) {
                            val = x;
                            break;
                        }
                        minHeap.pop();
                    }
                } else {
                    // Remove max
                    while (!maxHeap.empty()) {
                        int x = maxHeap.top();
                        if (count[x] > 0) {
                            val = x;
                            break;
                        }
                        maxHeap.pop();
                    }
                }

                if (val != -1) {
                    count[val]--;
                }

                if (removal_list.count(removal_id)) {
                    cout << val << '\n';
                }

                ++removal_id;
            } else if (cmd[0] == 'e') {
                break;
            }
        }

        cout << '\n'; // output separator between test cases
    }

    return 0;
}
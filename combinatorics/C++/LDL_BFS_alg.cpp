#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
    int n, Vs, Vt;
    cin >> n >> Vs >> Vt;
    cin.ignore();

    vector<vector<int>> graph(n + 1);

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor) {
            graph[i].push_back(neighbor);
        }
    }

    queue<vector<int>> q;
    vector<vector<int>> all_paths;

    q.push({Vs});

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();
        int last = path.back();

        if (last == Vt) {
            all_paths.push_back(path);
        } else {
            for (int neighbor : graph[last]) {
                if (find(path.begin(), path.end(), neighbor) == path.end()) {
                    vector<int> new_path = path;
                    new_path.push_back(neighbor);
                    q.push(new_path);
                }
            }
        }
    }

    if (!all_paths.empty()) {
        for (size_t i = 0; i < all_paths.size(); ++i) {
            cout << "Path " << i + 1 << ": ";
            for (size_t j = 0; j < all_paths[i].size(); ++j) {
                if (j > 0) cout << " -> ";
                cout << all_paths[i][j];
            }
            cout << endl;
        }
        cout << "\nTotal paths found: " << all_paths.size() << endl;
    } else {
        cout << "No path found from " << Vs << " to " << Vt << endl;
    }

    return 0;
}
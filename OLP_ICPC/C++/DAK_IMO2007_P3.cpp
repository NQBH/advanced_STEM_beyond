#include <bits/stdc++.h>
using namespace std;
const int N = 65;
int n;
bool adj[N][N];
vector<int> best_clique_so_far;

void find_max_clique_recursive(const vector<int>& potential_nodes, vector<int> current_clique) {
    if (current_clique.size() > best_clique_so_far.size())
        best_clique_so_far = current_clique;

    for (size_t i = 0; i < potential_nodes.size(); ++i) {
        int v = potential_nodes[i];
        if (current_clique.size() + (potential_nodes.size() - i) <= best_clique_so_far.size())
            return;

        vector<int> new_potential_nodes;
        for (size_t j = i + 1; j < potential_nodes.size(); ++j)
            if (adj[v][potential_nodes[j]])
                new_potential_nodes.push_back(potential_nodes[j]);

        vector<int> next_clique = current_clique;
        next_clique.push_back(v);
        find_max_clique_recursive(new_potential_nodes, next_clique);
    }
}

vector<int> get_max_clique(const vector<int>& nodes) {
    if (nodes.empty())
        return {};
    best_clique_so_far.clear();
    find_max_clique_recursive(nodes, {});
    return best_clique_so_far;
}

void print_vector(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << (i == vec.size() - 1 ? "" : " ");
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cin.ignore();

    for (int i = 1; i <= n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int neighbor;
        while (ss >> neighbor)
            adj[i][neighbor] = true;
    }

    vector<int> all_nodes(n);
    iota(all_nodes.begin(), all_nodes.end(), 1);

    vector<int> C = get_max_clique(all_nodes);
    cout << C.size() << '\n';

    vector<int> room1 = C;
    vector<int> room2;

    sort(C.begin(), C.end());
    sort(all_nodes.begin(), all_nodes.end());

    set_difference(all_nodes.begin(), all_nodes.end(),
                   C.begin(), C.end(),
                   back_inserter(room2));

    for (size_t i = 0; i <= C.size(); ++i) {
        sort(room1.begin(), room1.end());
        sort(room2.begin(), room2.end());

        int size1 = get_max_clique(room1).size();
        int size2 = get_max_clique(room2).size();

        if (size1 == size2) {
            print_vector(room1);
            print_vector(room2);
            cout << size1 << '\n';
            return 0;
        }

        if (i < C.size()) {
            int node_to_move = C[i];

            room1.erase(remove(room1.begin(), room1.end(), node_to_move), room1.end());
            room2.push_back(node_to_move);
        }
    }

    return 1;
}
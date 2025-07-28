#include <bits/stdc++.h>
#include "Graph_Tree.h"
using namespace std;

const double INF = numeric_limits<double>::infinity();

pair<map<Graph::Vertex*, double>, map<Graph::Vertex*, Graph::Edge*>> 
dijkstra(const Graph* graph, Graph::Vertex* start_node) {
    map<Graph::Vertex*, double> distances;
    map<Graph::Vertex*, Graph::Edge*> shortest_path_tree;
    for (Graph::Vertex* v : graph->vertices()) { distances[v] = INF; }
    distances[start_node] = 0;

    using P = pair<double, Graph::Vertex*>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0.0, start_node});

    while(!pq.empty()) {
        double d = pq.top().first; Graph::Vertex* u = pq.top().second; pq.pop();
        if (d > distances[u]) continue;
        for (auto const& [v, edges_to_v] : graph->get_outgoing_map(u)) {
            for (Graph::Edge* edge : edges_to_v) {
                if (distances[u] + edge->weight() < distances[v]) {
                    distances[v] = distances[u] + edge->weight();
                    shortest_path_tree[v] = edge;
                    pq.push({distances[v], v});
                }
            }
        }
    }
    return {distances, shortest_path_tree};
}

struct TestGraphInfo {
    string name;
    vector<vector<double>> matrix; 
    bool is_undirected;
};

void run_dijkstra_test(TestGraphInfo test) {
    if(test.is_undirected) {
        for(size_t i = 0; i < test.matrix.size(); ++i) {
            for(size_t j = i + 1; j < test.matrix.size(); ++j) {
                test.matrix[i][j] = test.matrix[j][i] = max(test.matrix[i][j], test.matrix[j][i]); // min
            }
        }
    }
    cout << "\nDijkstra on: " << test.name << "\n";
    Graph g(test.is_undirected);
    vector<Graph::Vertex*> vertices;
    for(size_t i = 0; i < test.matrix.size(); ++i) vertices.push_back(g.new_vertex(0));
    for(size_t i = 0; i < test.matrix.size(); ++i) {
        for(size_t j = 0; j < test.matrix.size(); ++j) {
            if (test.matrix[i][j] > 0 && test.matrix[i][j] != INF) {
                 if (!test.is_undirected || i <= j) {
                    g.new_edge(vertices[i], vertices[j], test.matrix[i][j]);
                 }
            }
        }
    }

    if (vertices.empty()) { cout << "Graph is empty.\n"; return; }

    Graph::Vertex* start_node = vertices[0];
    cout << "Running Dijkstra from source " << start_node->id() << ":" << endl;
    auto result = dijkstra(&g, start_node);
    auto distances = result.first;

    for (auto const& [vertex, dist] : distances) {
        cout << "  - Distance to vertex " << vertex->id() << ": " << (dist == INF ? "infinity" : to_string(dist)) << endl;
    }
    cout << "-------------------------------------------------\n";
}

void read_graphs_from_input(vector<TestGraphInfo>& test_cases);

int main() {
    // freopen("graph_input.txt", "r", stdin);
    // vector<TestGraphInfo> test_cases;
    // read_graphs_from_input(test_cases);

    vector<TestGraphInfo> test_cases = {
        {"Directed Simple Graph", {{0,10,5,0},{0,0,2,0},{0,0,0,1},{0,7,0,0}}, false},
        {"Undirected Simple Graph", {{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}}, true},
        {"Directed Multigraph", {{0,2,1,0},{0,0,3,0},{0,0,0,4},{0,5,0,0}}, false},
        {"Undirected Multigraph", {{0,2,1,0},{2,0,3,8},{1,3,0,0},{0,8,0,0}}, true},
        {"Directed Pseudograph", {{7,5,0,0},{0,0,1,0},{2,0,0,3},{0,4,0,9}}, false},
        {"Undirected Pseudograph", {{7,2,1,0},{2,0,3,8},{1,3,5,0},{0,8,0,9}}, true}
    };

    for (const auto& test : test_cases) {
        run_dijkstra_test(test);
    }

    return 0;
}

void read_graphs_from_input(vector<TestGraphInfo>& test_cases) {
    string line;
    int graph_count = 1;

    while (true) {
        if (!getline(cin, line) || line.empty()) {
            break; 
        }

        stringstream ss(line);
        int n, m;
        char type_char;
        if (!(ss >> n >> m >> type_char)) {
            cerr << "Invalid format.\n";
            continue;
        }

        bool is_undirected = (type_char == 'U' || type_char == 'u');
        vector<vector<double>> matrix(n, vector<double>(n, 0));
        bool input_error = false;

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            if (!(cin >> u >> v >> w)) {
                cerr << "Invalid edge format.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                input_error = true;
                break; 
            }
            if (u >= n || v >= n || u < 0 || v < 0) {
                 cerr << "Out of bound.\n";
                 continue;
            }
            matrix[u][v]++;
            if (is_undirected && u != v) {
                matrix[v][u]++;
            }
        }
        
        if (input_error) continue; 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        string name = "Graph #" + to_string(graph_count) + " (" + (is_undirected ? "Undirected" : "Directed") + ")";
        test_cases.push_back({name, matrix, is_undirected});
        graph_count++;
    }
}
#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int a, b, width;
    // see https://stackoverflow.com/a/11805395/12128483 for why we use const Edge&
    bool operator<(const Edge &y) { return width < y.width; }
};

struct Edge_only {
    int a, b, width;
};

struct Edge_sort_multiple_criteria {
    int a, b, width;
    bool operator<(const Edge_sort_multiple_criteria &y) {
        if (width != y.width) return width < y.width;
        return a < y.a;
    }
};

int main() {
    // use built-in data structure: pair
    constexpr int edge_num = 4;
    vector<pair<int, pair<int, int>>> edges(edge_num);
    for (auto &[width, edge] : edges) cin >> edge.first >> edge.second >> width;
    sort(edges.begin(), edges.end());
    for (const auto &[width, edge] : edges) printf("(%i, %i): %i\n", edge.first, edge.second, width);
    
    // use built-in data structure: array
    vector<array<int, 3>> edges_arr;
    // vector<vector<int>> edges; // also works, but is slower
    for (int e = 0; e < edge_num; ++e) {
        int a, b, width;
        cin >> a >> b >> width;
        edges_arr.push_back({width, a, b});
    }
    sort(edges_arr.begin(), edges_arr.end());
    for (const auto &e : edges_arr) { printf("(%i, %i): %i\n", e[1], e[2], e[0]); }

    // overloading operator<
    vector<Edge> edges_opr(edge_num);
    for (Edge &e : edges_opr) { cin >> e.a >> e.b >> e.width; }
    sort(edges_opr.begin(), edges_opr.end());
    for (const Edge &e : edges_opr) { printf("(%i, %i): %i\n", e.a, e.b, e.width); }

    // comparison function
    vector<Edge_only> edges_lambda(edge_num);
    for (Edge_only &e : edges_lambda) cin >> e.a >> e.b >> e.width;
    sort(edges_lambda.begin(), edges_lambda.end(), [](const Edge_only &x, const Edge_only &y) {return x.width < y.width; });
    for (const Edge_only &e : edges_lambda) printf("(%i, %i): %i\n", e.a, e.b, e.width);

    // sort by multiple criteria
    vector<Edge_sort_multiple_criteria> edges_multiple_criteria(edge_num);
    for (Edge_sort_multiple_criteria &e: edges_multiple_criteria) cin >> e.a >> e.b >> e.width;
    sort(edges_multiple_criteria.begin(), edges_multiple_criteria.end());
    for (const Edge_sort_multiple_criteria &e : edges_multiple_criteria)printf("(%i, %i): %i\n", e.a, e.b, e.width);
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Ham chuyen tu ma tran ke sang ban do ke (adjacency map)
map<int, map<int, int>> adjacencyMatrixToMap(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    map<int, map<int, int>> adjMap;  // Ban do ke

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight = matrix[i][j];
            if (weight != 0) {
                adjMap[i][j] = weight;  // Gan dinh j voi trong so vao map cua i
            }
        }
    }

    return adjMap;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Nhap ma tran ke:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    auto adjMap = adjacencyMatrixToMap(matrix);

    // In ket qua
    cout << "Adjacency Map:\n";
    for (const auto& [u, neighbors] : adjMap) {
        cout << u << ": ";
        for (const auto& [v, w] : neighbors) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << endl;
    }

    return 0;
}
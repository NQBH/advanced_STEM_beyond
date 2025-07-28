#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_to_list(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j])
                adjList[i].push_back(j);
    return adjList;
}

vector<vector<int>> list_to_matrix(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j : adjList[i])
            matrix[i][j] = 1;
    return matrix;
}

int main() {
    vector<vector<int>> matrix = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };

    auto adjList = matrix_to_list(matrix);
    cout << "Adjacency List:\n";
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << ": ";
        for (int j : adjList[i]) cout << j << " ";
        cout << "\n";
    }

    auto backMatrix = list_to_matrix(adjList);
    cout << "\nBack to Matrix:\n";
    for (auto& row : backMatrix) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

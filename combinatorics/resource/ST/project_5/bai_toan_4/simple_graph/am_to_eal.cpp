#include <iostream>
#include <vector>
#include <utility> // pair

using namespace std;

// Ham chuyen tu ma tran ke co trong so sang danh sach ke mo rong (EAL)
vector<vector<pair<int, int>>> adjacencyMatrixToExtendedList(const vector<vector<int>>& matrix) {
    int n = matrix.size(); // So dinh cua do thi
    vector<vector<pair<int, int>>> adjList(n); // Khoi tao danh sach ke mo rong

    for (int i = 0; i < n; ++i) { // Duyet tung dinh i
        for (int j = 0; j < n; ++j) { // Duyet tung dinh j
            int weight = matrix[i][j]; // Lay trong so canh tu i den j
            if (weight != 0) { // Neu co canh (trong so khac 0)
                adjList[i].emplace_back(j, weight); // Them (j, trong so) vao danh sach ke cua i
            }
        }
    }

    return adjList; // Tra ve danh sach ke mo rong
}

// Ham in danh sach ke mo rong
void printExtendedList(const vector<vector<pair<int, int>>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) {
        cout << i << ": ";
        for (const auto& [v, w] : adjList[i]) {
            cout << "(" << v << ", " << w << ") ";
        }
        cout << endl;
    }
}

int main() {
    // Ma tran ke co trong so
    vector<vector<int>> adjMatrix = {
        {0, 2, 0, 0},
        {2, 0, 3, 1},
        {0, 3, 0, 4},
        {0, 1, 4, 0}
    };

    // Chuyen doi va in ket qua
    auto adjList = adjacencyMatrixToExtendedList(adjMatrix);
    printExtendedList(adjList);
    return 0;
}
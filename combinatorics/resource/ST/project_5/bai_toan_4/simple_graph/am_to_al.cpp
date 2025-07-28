#include <iostream>
#include <vector>

using namespace std;

// Ham chuyen ma tran ke sang danh sach ke
vector<vector<int>> adjacencyMatrixToList(const vector<vector<int>>& matrix) {
    int n = matrix.size(); // So dinh cua do thi
    vector<vector<int>> adjList(n); // Khoi tao danh sach ke rong

    for (int i = 0; i < n; ++i) { // Duyet tung dinh i
        for (int j = 0; j < n; ++j) { // Duyet tung dinh j
            if (matrix[i][j] != 0) { // Neu co canh tu i den j
                adjList[i].push_back(j); // Them j vao danh sach ke cua i
            }
        }
    }

    return adjList; // Tra ve danh sach ke
}

// Ham in danh sach ke
void printAdjList(const vector<vector<int>>& adjList) {
    for (int i = 0; i < adjList.size(); ++i) { // Duyet tung dinh
        cout << i << ": ";
        for (int v : adjList[i]) { // Duyet cac dinh ke voi i
            cout << v << " "; // In dinh ke
        }
        cout << endl;
    }
}

int main() {
    // Ma tran ke cua do thi 4 dinh
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };

    // Goi ham chuyen doi va in ket qua
    vector<vector<int>> adjList = adjacencyMatrixToList(adjMatrix);
    printAdjList(adjList);
    return 0;
}
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int>> alToAm(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Khoi tao ma tran 0

    for (int i = 0; i < n; ++i) {
        for (int j : adjList[i]) {
            matrix[i][j]++; // Tang dem moi lan co canh
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    vector<vector<int>> adjList(n);
    cout << "Nhap danh sach ke (cac so cach nhau bang dau cach):\n";
    cin.ignore(); // Xoa bo nho dem

    for (int i = 0; i < n; ++i) {
        cout << "Ke cua dinh " << i << ": ";
        string line;
        getline(cin, line);
        istringstream iss(line);
        int x;
        while (iss >> x)
            adjList[i].push_back(x);
    }

    // Chuyen doi va in ket qua
    vector<vector<int>> matrix = alToAm(adjList);
    cout << "Ma tran ke:\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
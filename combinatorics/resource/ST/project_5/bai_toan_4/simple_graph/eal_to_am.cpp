#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Ham chuyen danh sach ke mo rong sang ma tran ke
vector<vector<int>> extendedListToMatrix(const vector<vector<pair<int, int>>>& eal, int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0)); // Khoi tao ma tran toan 0

    for (int i = 0; i < n; ++i) {
        for (const auto& [j, w] : eal[i]) {
            matrix[i][j] = w; // Ghi trong so vao ma tran
        }
    }

    return matrix;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;
    cin.ignore();

    vector<vector<pair<int, int>>> eal(n);
    cout << "Nhap danh sach ke mo rong:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Dinh " << i << " (dinh,trongso): ";
        string line;
        getline(cin, line);
        stringstream ss(line);
        string token;
        while (ss >> token) {
            int u, w;
            sscanf(token.c_str(), "(%d,%d)", &u, &w); // Tach (u,w)
            eal[i].emplace_back(u, w);
        }
    }

    // Chuyen doi va in ma tran
    auto matrix = extendedListToMatrix(eal, n);

    cout << "Ma tran ke:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
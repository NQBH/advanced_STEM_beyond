#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Ham chuyen tu danh sach ke mo rong ve danh sach ke
vector<vector<int>> ealToAl(const vector<vector<pair<int, int>>>& eal, int n) {
    vector<vector<int>> al(n);  // Khoi tao danh sach ke

    for (int i = 0; i < n; ++i) {
        for (const auto& [j, _] : eal[i]) {
            al[i].push_back(j);  // Chi lay dinh j, bo qua trong so
        }
    }

    return al;
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
            sscanf(token.c_str(), "(%d,%d)", &u, &w);
            eal[i].emplace_back(u, w);
        }
    }

    // Chuyen doi va in danh sach ke
    auto al = ealToAl(eal, n);

    cout << "Danh sach ke (AL):\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        for (int v : al[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
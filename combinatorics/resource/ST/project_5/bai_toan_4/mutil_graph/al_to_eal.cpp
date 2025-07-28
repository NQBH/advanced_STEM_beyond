#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<tuple<int, int, int>> alToEal(const vector<vector<int>>& adjList) {
    vector<tuple<int, int, int>> eal;
    for (int u = 0; u < adjList.size(); ++u) {
        map<int, int> freq;
        for (int v : adjList[u]) {
            freq[v]++;  // Dem so lan xuat hien cua v
        }
        for (const auto& [v, w] : freq) {
            eal.push_back({u, v, w});  // Tao bo (u,v,w)
        }
    }
    return eal;
}

int main() {
    int n;
    cout << "Nhap so dinh: ";
    cin >> n;

    vector<vector<int>> adjList(n);
    cin.ignore(); // Xoa bo dem

    cout << "Nhap danh sach ke:\n";
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
    auto eal = alToEal(adjList);
    cout << "Danh sach ke mo rong (EAL):\n";
    for (const auto& [u, v, w] : eal) {
        cout << "(" << u << ", " << v << ", " << w << ")\n";
    }

    return 0;
}
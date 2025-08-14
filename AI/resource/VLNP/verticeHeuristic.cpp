#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int num_vertex, num_edge;
vector<vector<int>> neighbor; // vertex j is in neighbor of vertex i: j\in N[i]
vector<int> color;

void readGraph() {
    cin >> num_vertex >> num_edge;
    neighbor.resize(num_vertex);  // C?p ph�t b? nh? cho c�c ??nh t? 0 ??n num_vertex - 1
    color.resize(num_vertex, -1); // Kh?i t?o m?ng m�u v?i -1 (ch?a t�)

    cin.ignore(); // B? qua k� t? newline sau khi ??c num_vertex v� num_edge

    for (int i = 0; i < num_vertex; ++i) { // ??c t? ??nh 0 ??n num_vertex - 1
        string line;
        getline(cin, line);
        stringstream ss(line);
        int adjacent;

        while (ss >> adjacent) {
            neighbor[i].push_back(adjacent); // Th�m ??nh k?
            neighbor[adjacent].push_back(i); // Th�m c?nh hai chi?u (?? th? v� h??ng)
        }
    }
}

void greedyColoring() {
    color[0] = 0; // B?t ??u t� m�u 0 cho ??nh 0
    for (int u = 1; u < num_vertex; ++u) {
        vector<bool> available(num_vertex, true); // M?ng ?�nh d?u m�u kh? d?ng

        // Ki?m tra m�u c?a c�c ??nh k?
        for (int v : neighbor[u]) {
            if (color[v] != -1) {
                available[color[v]] = false;
            }
        }

        // Ch?n m�u nh? nh?t kh? d?ng
        int cr;
        for (cr = 0; cr < num_vertex; ++cr) {
            if (available[cr]) break;
        }
        color[u] = cr;
    }
}

void printColoring() {
    cout << "Phan to mau do thi:\n";
    for (int u = 0; u < num_vertex; ++u) {
        cout << "Dinh " << u << ": Mau " << color[u] << "\n";
    }
    int num_colors = *max_element(color.begin(), color.end()) + 1;
    cout << "\nTong so mau su dung: " << num_colors << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("p2.txt", "r", stdin); // ??c d? li?u t? file p2.txt

    readGraph();
    greedyColoring();
    printColoring();

    return 0;
}
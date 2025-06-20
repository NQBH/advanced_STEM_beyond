/*
Source: ACM Japan 2004, Domestic.
IDs for online judges: POJ 1979.
Status: Accepted.
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define x first
#define y second
using namespace std;

vector<string> matrix;
vector<vector<bool>> visited;
int w, h;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void search(int x, int y) {
    if (x < 0 || x >= h || y < 0 || y >= w || matrix[x][y] == '#' || visited[x][y] == true) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        search(new_x, new_y);
    }
}
int main() {
    while (cin >> w >> h && w != 0 && h != 0) {
        matrix.clear();
        visited.clear();
        matrix.resize(h);
        visited.resize(h, vector<bool>(w, false));

        pair<int, int> man;

        for (int i = 0; i < h; ++i) {
            cin >> matrix[i];
            for (int j = 0; j < w; j++)
                if (matrix[i][j] == '@') {
                    man.x = i;
                    man.y = j;
                }
        }
        search(man.x, man.y);
        int count = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; j++)
                if (visited[i][j] == true) ++count;
        cout << count << '\n';
    }
}
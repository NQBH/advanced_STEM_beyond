// PPP_Counting_rooms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
constexpr auto MAX = 1e3;

int n, m;   // Height & width of the map
vector<string> grid;
vector<vector<bool>> visited;

void DFS(int x, int y) 
{
    if (x < 0 || y < 0 || x >= n || y >= m) return;
    if (grid[x][y] == '#' || visited[x][y]) return;

    visited[x][y] = true;

    DFS(x + 1, y);
    DFS(x - 1, y);
    DFS(x, y + 1);
    DFS(x, y - 1);
}

int main()
{
	cin >> n >> m;	// Input the height & width of the map
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) 
        cin >> grid[i];
    
    int room_counts = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (grid[i][j] == '.' && !visited[i][j]) 
            {
                DFS(i, j);
                room_counts++;
            }
        }
    }

    cout << room_counts << endl;
    return 0;
}
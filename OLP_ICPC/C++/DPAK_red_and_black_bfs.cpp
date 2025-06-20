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

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main(){
//    freopen("red_and_black_input.txt", "r", stdin);
//    freopen("red_and_black_out.txt", "w", stdout);
    // int i = 0;
    int w,h;
    while (cin >> w >> h && w != 0 && h != 0) {
    
        matrix.clear();
        visited.clear();
        matrix.resize(h);
        visited.resize(h, vector<bool>(w, false));

        pair<int,int> man;

        for (int i = 0; i < h; i++) {
            cin >> matrix[i];
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == '@') {
                    man.x = i;
                    man.y = j;
                }
            }
        }
        
        queue<pair<int,int>> q;        
        
        q.push({man.x, man.y});
        visited[man.x][man.y] = true;
        while(q.empty() == false) {
            pair<int,int> point = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = point.x + dx[i];
                int new_y = point.y + dy[i];

                if (new_x >= 0 && new_x <h && new_y >= 0 && new_y < w &&
                    visited[new_x][new_y] == false && matrix[new_x][new_y] != '#') {
                        visited[new_x][new_y] = true;
                        q.push({new_x, new_y});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (visited[i][j] == true) {
                //    cout << 1 << " ";
                    count++;
                }
                //else cout << 0 << " ";
            }
            //cout << endl;
        }
        cout << count << endl;
    }

}

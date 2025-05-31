#include <iostream> 
#include <queue>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
    int n, m; cin>>n>>m;
    vector<vector<int>> connection(n+1); 
    
    // Input zalo
    for (int i=1; i<=m; i++){
        int a, b; cin>>a>>b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }
    cout<<endl;

    // // Output 
    // for (int i=0; i<n; i++){
    //     for (int neighbor : connection[i]) { // Loop through all neighbors of node i
    //         cout << neighbor << " ";
    //     }   
    //     cout<<endl;
    // }

    queue<int> q;
    vector<bool> visited(n+1, false); //1-based index
    vector<int> distance(n+1, 0);
    vector<int> parent(n+1, -1);
    bool found = false; 

    q.push(1); // start BFS at node 1 {a, b}
    visited[1] = true; // mark the 1st node as visited 

    while (!q.empty()){
        int curr = q.front(); 
        q.pop(); // mandatory, to move to the next  

        for (int tmp : connection[curr]){
            if (!visited[tmp]){
                visited[tmp] = true; 
                distance[tmp] = distance[curr] + 1;
                parent[tmp] = curr;; 
                q.push(tmp);                

                if (tmp == n){
                    found = true; 
                    break;
                }
            }
        }
        if (found) break; 
    }

    if (visited[n]){
        cout<<distance[n] + 1<<endl;

        // Test case output 
        vector<int> path; 
        int curr = n; 
        while (curr != -1){
            path.push_back(curr); 
            curr = parent[curr]; // move to the parent (backwards)
        }
        reverse(path.begin(), path.end()); 

        for (int node : path){
            cout<<node<<" ";
        }
    } else {
        cout<<"IMPOSSIBLE";
    }

    return 0; 
}
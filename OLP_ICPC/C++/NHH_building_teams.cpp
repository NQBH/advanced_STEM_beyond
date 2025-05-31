#include <iostream> 
#include <vector> 
using namespace std;

// Global variable 
vector<int> team; // store which team a pupil is on 
vector<vector<int>> pairlist; // the original couple 

bool dfs(int pupil, int assign_team) {
    team[pupil] = assign_team;
    for (int friend_pupil : pairlist[pupil]) { 
        if (team[friend_pupil] == 0) {
            // Friend not assigned, assign to the opposite team and go deeper
            if (!dfs(friend_pupil, 3 - assign_team))
                return false; // If any assignment fails, stop
        } else if (team[friend_pupil] == assign_team) {
            // Conflict! Friend already assigned the same team
            return false;
        }
    }
    return true;
}

int main(){
    int n, m; cin>>n>>m; // n là số hs, m là số cặp 
    pairlist.assign(n+1, vector<int>()); // now we know n, can size global vector
    team.assign(n+1, 0);
    
    for (int i=0; i<m; i++){
        int a, b; cin>>a>>b; 
        pairlist[a].push_back(b);
        pairlist[b].push_back(a);
    }

    // for (int i=1; i<=n; i++){
    //     cout<<"Node "<<i<<": ";
    //     for (int tmp: pair[i]){
    //         cout<<tmp<<" ";
    //     }
    //     cout<<endl;
    // }

    for (int pupil = 1; pupil <=n; pupil++) {
        if (team[pupil] == 0) { // Not yet assigned, start DFS and assign to team 1
            if (!dfs(pupil, 1)) {
                cout << "IMPOSSIBLE";
                return 0;
            } 
        }
    }

    for (int i=1; i<=n; i++){
        cout<<team[i]<<" ";
    }
    cout<<endl;

    return 0; 
}
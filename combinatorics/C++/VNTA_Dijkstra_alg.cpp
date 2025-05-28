#include <bits/stdc++.h>
#define KhangGPT40_TramAnhGrok3 ios_base::sync_with_stdio(0)
#define INF 1e9
using namespace std;
typedef pair<int,int> p; // adjacent(u), weight of e[u,v]

void inp(vector<vector<p>>&graph, int&n, int&m) {
    cin>>n>>m; //n:so dinh, m:so canh
    graph.assign(n, vector<p>());
    for (int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }
}

vector<int> findPath(int target, const vector<int>&prev) {
    vector<int> path;
    for(int i=target; i!=-1; i=prev[i]) path.push_back(i);
    reverse(path.begin(), path.end());
    return path;
}

void dijkstra_trad(int source, const vector<vector<p>>&graph,
                   vector<int>&dist, vector<int>&prev){
    /*
    source: dinh bat dau
    dist[v]: khoang cach ngan nhat tu source den v
    prev[v]: dinh truoc v trong duong di ngan nhat
    */

    int n=graph.size();
    dist.assign(n, INF); //dist[v] := INFINITY
    prev.assign(n, -1); //prev[v] := UNDEFINED
    vector<bool> visited(n, false);
    vector<int> Q; //tap cac dinh chua xu ly
    for(int v=0; v<n; v++) Q.push_back(v); //add v to Q
    dist[source]=0;
    while(!Q.empty()) {
        int u=-1; //dist[u] nho nhat trong Q
        for(int v:Q) {
            if(!visited[v]&&(u==-1 || dist[v]<dist[u])) u=v;
        }
        if (u==-1) break;
        visited[u]=true;
        Q.erase(remove(Q.begin(), Q.end(), u), Q.end()); //Q.remove(u)
        for (const auto&e : graph[u]){
            int v=e.first; //v: dinh ke
            int w=e.second; //w: trong so (u,v)
            if(visited[v]) continue;
            int alt=dist[u]+w;
            if(alt<dist[v]) {
                dist[v]=alt;
                prev[v]=u;
            }
        }
    }
}

int main() {
    KhangGPT40_TramAnhGrok3;
    int n, m, source;
    vector<vector<p>> graph;
    inp(graph, n, m);
    cin>>source;
    vector<int> dist, prev;

    cout<<"=== Traditional Dijkstra ===\n";
    cout<<"Khoang cach ngan nhat tu dinh "<<source<<" den dinh :\n";
    dijkstra_trad(source, graph, dist, prev);
    for(int v=0; v<n; v++) {
        cout<<v<<": ";
        if(dist[v]==INF) cout<<"Khong co duong di\n";
        else {
            cout<<"Khoang cach = "<<dist[v]<<"; Duong di: ";
            vector<int>path = findPath(v, prev);
            for(int u : path) cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
/*
5 7
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 1
4 3 2
0
*/
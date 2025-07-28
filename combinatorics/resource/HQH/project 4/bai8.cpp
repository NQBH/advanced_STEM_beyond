# include <iostream>
# include <vector>
# include <queue>
# include <map>
using namespace std ;
class SimpleGraph {
private :
int numVertices ;
vector < vector < int > > adjList ;
public :
SimpleGraph ( int n ) : numVertices ( n ) {
adjList . resize ( n ) ;
}
// Add edge ( undirected )
void addEdge ( int u , int v ) {
if ( u != v ) { // No self - loops in simple graph
adjList [ u ]. push_back ( v ) ;
adjList [ v ]. push_back ( u ) ;
}
}
// BFS traversal
void BFS ( int startVertex ) {
vector < bool > visited ( numVertices , false ) ;
queue < int > q ;
cout << " BFS traversal starting from vertex " << startVertex <<
" : " ;
visited [ startVertex ] = true ;
q . push ( startVertex ) ;
while (! q . empty () ) {
int current = q . front () ;

q . pop () ;
cout << current << " " ;
// Visit all adjacent vertices
for ( int neighbor : adjList [ current ]) {
if (! visited [ neighbor ]) {
visited [ neighbor ] = true ;
q . push ( neighbor ) ;
}
}
}
cout << endl ;
}
// BFS to find shortest path
void BFSShortestPath(int start, int target) {
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);
    vector<int> distance(numVertices, -1);
    queue<int> q;
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        if (current == target) break;
        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }
    if (distance[target] == -1) {
        cout << "No path from " << start << " to " << target << endl;
    } else {
        cout << "Shortest distance from " << start << " to " << target << " is: " << distance[target] << endl;
        // Print path
        vector<int> path;
        int curr = target;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        cout << "Path: ";
        for (int i = path.size() - 1; i >= 0; i--) { // Fixed: i-- instead of i - -
            cout << path[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    }
}
void printGraph () {
cout << " Simple Graph adjacency list : " << endl ;
for ( int i = 0; i < numVertices ; i ++) {
cout << " Vertex " << i << " : " ;
for ( int neighbor : adjList [ i ]) {
cout << neighbor << " " ;
}
cout << endl ;
}
}
};
// Test function for Simple Graph BFS
void testSimpleGraphBFS () {
cout << " === SIMPLE GRAPH BFS TEST === " << endl ;
SimpleGraph g (6) ;
g . addEdge (0 , 1) ;
g . addEdge (0 , 2) ;
g . addEdge (1 , 3) ;
g . addEdge (2 , 4) ;
g . addEdge (3 , 4) ;
g . addEdge (3 , 5) ;
g . printGraph () ;
g . BFS (0) ;
g . BFSShortestPath (0 , 5) ;
cout << endl ;
}

int main() {
    testSimpleGraphBFS();
    return 0;
}

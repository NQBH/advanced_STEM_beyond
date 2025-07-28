# include <iostream>
# include <vector>
using namespace std ;
// Convert adjacency matrix to adjacency list
vector < vector < int > > matrixToList ( vector < vector < int > >& matrix ) {
int n = matrix . size () ;
vector < vector < int > > adjList ( n ) ;
for ( int i = 0; i < n ; i ++) {
for ( int j = 0; j < n ; j ++) {
if ( matrix [ i ][ j ] == 1) {
adjList [ i ]. push_back ( j ) ;
}
}
}
return adjList ;
}
void printAdjList ( const vector < vector < int > >& adjList ) {
cout << " Adjacency List : " << endl ;
for ( int i = 0; i < adjList . size () ; i ++) {
cout << i << " : " ;
for ( int v : adjList [ i ]) {
cout << v << " " ;
}
cout << endl ;
}
}

int main () {
// Example adjacency matrix
vector < vector < int > > matrix = {
{0 , 1 , 1 , 0} ,
{1 , 0 , 0 , 1} ,
{1 , 0 , 0 , 1} ,
{0 , 1 , 1 , 0}
};
cout << " Original Adjacency Matrix : " << endl ;
for ( auto & row : matrix ) {
for ( int val : row ) {
cout << val << " " ;
}
cout << endl ;
}
cout << endl ;
vector < vector < int > > adjList = matrixToList ( matrix ) ;
printAdjList ( adjList ) ;
return 0;
}

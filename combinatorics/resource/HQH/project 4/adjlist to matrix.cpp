# include <iostream>
# include <vector>
using namespace std ;
// Convert adjacency list to adjacency matrix
vector < vector < int > > listToMatrix ( const vector < vector < int > >& adjList )
{
int n = adjList . size () ;
vector < vector < int > > matrix (n , vector < int >( n , 0) ) ;
for ( int i = 0; i < n ; i ++) {
for ( int v : adjList [ i ]) {
matrix [ i ][ v ] = 1;
}
}
return matrix ;
}

void printMatrix ( const vector < vector < int > >& matrix ) {
cout << " Adjacency Matrix : " << endl ;
for ( const auto & row : matrix ) {
for ( int val : row ) {
cout << val << " " ;
}
cout << endl ;
}
}
int main () {
// Example adjacency list
vector < vector < int > > adjList = {
{1 , 2} , // vertex 0 connects to 1 , 2
{0 , 3} , // vertex 1 connects to 0 , 3
{0 , 3} , // vertex 2 connects to 0 , 3
{1 , 2} // vertex 3 connects to 1 , 2
};
cout << " Original Adjacency List : " << endl ;
for ( int i = 0; i < adjList . size () ; i ++) {
cout << i << " : " ;
for ( int v : adjList [ i ]) {
cout << v << " " ;
}
cout << endl ;
}
cout << endl ;
vector < vector < int > > matrix = listToMatrix ( adjList ) ;
printMatrix ( matrix ) ;
return 0;
}

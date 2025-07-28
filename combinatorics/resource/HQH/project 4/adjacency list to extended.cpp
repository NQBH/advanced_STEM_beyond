# include <iostream>
# include <vector>
# include <random>
using namespace std ;
struct Edge {
int vertex ;
int weight ;
};
// Convert adjacency list to extended adjacency list with weights
vector < vector < Edge > > listToExtendedList ( const vector < vector < int > >&
adjList ) {
vector < vector < Edge > > extendedList ( adjList . size () ) ;
random_device rd ;
mt19937 gen ( rd () ) ;
uniform_int_distribution < > dis (1 , 10) ;
for ( int i = 0; i < adjList . size () ; i ++) {
for ( int v : adjList [ i ]) {
Edge edge = {v , dis ( gen ) }; // random weight 1 -10
extendedList [ i ]. push_back ( edge ) ;
}
}
return extendedList ;
}
void printExtendedList ( const vector < vector < Edge > >& extList ) {
cout << " Extended Adjacency List ( with weights ) : " << endl ;
for ( int i = 0; i < extList . size () ; i ++) {
cout << i << " : " ;
for ( const Edge & e : extList [ i ]) {
cout << " ( " << e . vertex << " ," << e . weight << " ) " ;
}
cout << endl ;
}
}
int main () {
// Example adjacency list
vector < vector < int > > adjList = {
{1 , 2} ,
{0 , 3} ,
{0 , 3} ,
{1 , 2}
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
vector < vector < Edge > > extList = listToExtendedList ( adjList ) ;
printExtendedList ( extList ) ;
return 0;
}

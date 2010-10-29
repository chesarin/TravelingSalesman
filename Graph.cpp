/*Cesar Vargas
 *AI Fall 2010
 *Graph.cpp 
 */
#include "Graph.h"
Graph::Graph(){
  size=0;
}
void Graph::create(const vector<int>& in){
  size=in.size();
  for ( unsigned int i=0 ; i < size ; i+=3 ){
    matrix[in[i]][in[i+1]].set_cost(in[i+2]);
    matrix[in[i]][in[i+1]].set_presence();
  }
}
void Graph::print(){
  for ( int i=1 ; i < MAX ; i++ ){
    for ( int j=1 ; j < MAX ; j++ ){
      if  (matrix[i][j].is_present() ){
        cout << "from node " << i << " to node " << j << " cost " << matrix[i][j].cost << endl;
      }
    }
  }
}
void Graph::find_lowest(int node_num){
  Node lowest = matrix[node_num][1];
  int location=1;
  for ( int j=1 ; j < MAX ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      if ( lowest.cost == 0 ){
	lowest = matrix[node_num][j];
	location = j;
      }
      if ( matrix[node_num][j].cost < lowest.cost ){
	lowest = matrix[node_num][j];
	location = j;
      }
    }
  }
  cout << "The lowest cost from node " << node_num << " to node " << location << " is " << lowest.cost << endl;
}

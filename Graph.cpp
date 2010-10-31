/*Cesar Vargas
 *AI Fall 2010
 *Graph.cpp 
 */
#include "Graph.h"
Graph::Graph(){
  size=0; cities_visited = 0;
}
void Graph::create(const vector<int>& in){
  size=MAX-2;//size of graph
  for ( unsigned int i=0 ; i < in.size() ; i+=3 ){
    matrix[in[i]][in[i+1]].set_cost(in[i+2]);
    matrix[in[i]][in[i+1]].set_presence();
  }
}
void Graph::print(){
  cout << "Graph size is : " << size << endl;
  for ( int i=1 ; i < MAX ; i++ ){
    for ( int j=1 ; j < MAX ; j++ ){
      if  (matrix[i][j].is_present() ){
        cout << "from node " << i << " to node " << j << " cost " << matrix[i][j].cost << endl;
      }
    }
  }
}
/*
 *Find_lowest(int node_num)
 *find the child with lowest path cost on node node_num
 */
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
void Graph::update_children_h(int node_num){
  for ( int j=1 ; j < MAX ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      matrix[node_num][j].h = matrix[node_num][0].h;
    }
  }
}
void Graph::calculate_h(int node_num, int nodes_left){
  float total_cost=0,cost=0;
  int nodes=0;
  //let's find how many child nodes we have and calculate the h at this level
  for ( int j=1 ; j < MAX ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      total_cost += matrix[node_num][j].cost;
      nodes++;
    }
  }
  //we have the h, I'm calling it cost here it should be h at this level
  cost = (total_cost / nodes) * nodes_left;
  //let's store at matrix[node_num][0]
  matrix[node_num][0].h = cost;
  cout << "Total cost at node " << node_num << " is " << cost << endl;
}
void Graph::explore(int begin){
  int explored=0;
  while ( explored != size ){
    //calculate the h*, this will be the same for all child nodes
    //look at the README file
    //the g* is the actual path cost towards this node this will be different
    //for all of them
    //f* is the sum of the g* and h* functions
    //f* will be diferent for all children nodes
    //Expand the child node with the smallest f* function
    //Repeat this until we have visited all nodes
    //
  }
}
void Graph::calculate_children_f(int node_num){
  for ( int j = 1 ; j < MAX ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      matrix[node_num][j].calculate_f();
    }
  }
}
void Graph::expand(int node_num){
  
}

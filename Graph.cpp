/*Cesar Vargas
 *AI Fall 2010
 *Graph.cpp 
 */
#include "Graph.h"
Graph::Graph(){
  size=0; cities_visited = 0;
}
void Graph::create(const vector<int>& in){
  for ( unsigned int i=0 ; i < in.size() ; i+=3 ){
    matrix[in[i]][in[i+1]].set_cost(in[i+2]);
    matrix[in[i]][in[i+1]].set_presence();
    matrix[in[i]][0].incr_child();
  }
  calculate_size();
}
void Graph::calculate_size(){
  for ( int i=1 ; i < MAX ; i++ ){
    if ( matrix[i][0].children > 0 )
      size++;
  }
  size++; //add one extra instead of the actual size
}
void Graph::print(){
  cout << "Graph size is : " << size << endl;
  for ( int i=1 ; i < size ; i++ ){
    for ( int j=1 ; j < size ; j++ ){
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
int Graph::find_lowest(int node_num){
  Node lowest = matrix[node_num][1];
  int location=1;
  for ( int j=1 ; j < size ; j++ ){
    if ( matrix[node_num][j].is_present() && look_up(node_num)){
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
  //  cout << "The lowest cost from node " << node_num << " to node " << location << " is " << lowest.cost << endl;
  return location;
}
void Graph::update_children_h(int node_num){
  for ( int j=1 ; j < size ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      matrix[node_num][j].h = matrix[node_num][0].h;
    }
  }
}
void Graph::calculate_h(int node_num, int nodes_left){
  float total_cost=0,cost=0;
  int nodes=0;
  //let's find how many child nodes we have and calculate the h at this level
  for ( int j=1 ; j < size ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      total_cost += matrix[node_num][j].cost;
      nodes++;
    }
  }
  //we have the h, I'm calling it cost here it should be h at this level
  cost = (total_cost / nodes) * nodes_left;
  //let's store at matrix[node_num][0]
  matrix[node_num][0].h = cost;
  //let's place this node on the open list
  openlist.push_back(node_num);
  cout << "Total cost at node " << node_num << " is " << cost << endl;
  cout << "Print the contents of openlist " << endl;
  print_list();
}
void Graph::explore(int total_nodes,int start_node){
  int temp=0;
  if ( total_nodes == 0 ){
    cout << " we have reached the goal " << total_nodes << endl;
  } else {
    cout << " start_node " << start_node << " total nodes " << total_nodes << endl;
    calculate_h(start_node,total_nodes);
    calculate_children_f(start_node);
    temp = find_lowest(start_node);
    explore ( total_nodes-1,temp );
  }
  // int explored=0;
  // while ( explored != size ){
  //calculate the h*, this will be the same for all child nodes
  //look at the README file
  //the g* is the actual path cost towards this node this will be different
  //for all of them
  //f* is the sum of the g* and h* functions
  //f* will be diferent for all children nodes
  //Expand the child node with the smallest f* function
  //Repeat this until we have visited all nodes
  //
  // }
}
void Graph::calculate_children_f(int node_num){
  for ( int j = 1 ; j < size ; j++ ){
    if ( matrix[node_num][j].is_present() ){
      matrix[node_num][j].calculate_f();
    }
  }
}
void Graph::expand(int node_num){
  calculate_h(node_num,size);
  calculate_children_f(node_num);
  int low = find_lowest(node_num);
}
bool Graph::look_up(int node_num){
  bool is_there=false;
  list<int>::iterator i;
  cout << "in look_up function , node_num " << node_num << endl;
  for ( i=openlist.begin() ; i != openlist.end() ; ++i){
    if ( *i == node_num ){
      cout << "node_num " << node_num << " *i " << *i << endl;
      is_there=true;
      break;
    }
  }
  cout << "is_there " << is_there << endl;
  return is_there;
}
void Graph::print_list(){
  cout << "size of list " << openlist.size() << endl;
  list<int>::iterator i;
  cout << "Contents of open list " << endl;
  for (i=openlist.begin() ; i != openlist.end() ; ++i ){
    cout << *i << " ";
  }
  cout << endl;
}

/*A Cesar Vargas
 *AI Fall 2010
 *execute.cpp
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Node.h"
#include "Graph.h"
using namespace std;
void parse(string input);
void prompt();
void graph();
vector<int> nodes;
Graph test;
int main(){
  prompt();
  graph();
  return 0;
}
void parse(string input){
  int temp;
  for ( istringstream i(input) ; i >> temp ; ){
    nodes.push_back (temp);
  }
}
void prompt(){
  string line;
  ifstream ifs ("input.txt");
  cout << "Opening the file with input nodes" << endl;
  if (ifs.is_open()){
    while( getline(ifs,line) ){
      parse(line);
    }
    ifs.close();
  }
  else cout << "unable to find input file" << endl;
}
void graph(){
  cout << "in graph method" << endl;
  test.create(nodes);
  test.print();
  /*  int row = 6;
      int col = 6;
      Node matrix[row][col];
      for ( unsigned int i=0 ; i < nodes.size() ; i+=3 ){
      matrix[nodes[i]][nodes[i+1]].set_cost(nodes[i+2]);
      matrix[nodes[i]][nodes[i+1]].set_presence();
      }
      for ( int i=1 ; i < row ; i++ ){
      for ( int j=1 ; j < col ; j++ ){
      if  (matrix[i][j].is_present() ){
      cout << "from node " << i << " to node " << j << " cost " << matrix[i][j].cost << endl;
      }
      }
      }*/
}

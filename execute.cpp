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
  test.explore(6,1);
  // test.find_lowest(1);
  // test.find_lowest(2);
  // test.find_lowest(3);
  // test.find_lowest(4);
  // test.calculate_h(1,6);
}

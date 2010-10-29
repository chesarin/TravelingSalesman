/*Cesar Vargas
 * AI Fall 2010
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 6
#include "Node.h"
#include <vector>
#include <iostream>
using namespace std;
class Graph{
 private:
  int cities_visited;
  int size;
  Node matrix[MAX][MAX];
 public:
  Graph();
  void create(const vector <int>& in);
  void print();
  void find_lowest(int node_num);
  void update_h(int node_num, int nodes_left);
  void explore(int begin);
};
#endif

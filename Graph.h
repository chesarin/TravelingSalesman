/*Cesar Vargas
 * AI Fall 2010
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_
#define MAX 20
#include "Node.h"
#include <vector>
#include <iostream>
#include <list>
using namespace std;
class Graph{
 private:
  int cities_visited;
  int size;
  Node matrix[MAX][MAX];
  list<int> openlist;
  list<int> closedlist;
 public:
  Graph();
  void create(const vector <int>& in);
  void print();
  int find_lowest(int node_num);
  void update_children_h(int node_num);
  void calculate_h(int node_num, int nodes_left);
  void calculate_children_f(int node_num);
  void explore(int total_nodes, int start_node);
  void expand(int node_num);
  void calculate_size();
  bool look_up(int node_num);
};
#endif

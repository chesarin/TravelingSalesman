/*A Cesar Vargas
 *AI Fall 2010
 *Node.h
 */
#ifndef NODE_H_
#define NODE_H_
class Node{
 public:
  int id,num_level,g,cost,children;
  double f,h;
  bool present;
  Node* father;
 Node():present(false){ father=0; children=0;cost=0;};
 Node(int i, Node* f=0):id(i),father(f){children=0;cost=0;};
  void set_id(int i){id=i;};
  void set_cost(int i){cost=i;};
  void set_presence(){present=true;};
  void calculate_f(){ f = cost + h; };
  bool is_present(){ return present;};
  void set_father(Node* f){ father=f;};
  void incr_child(){ children+=1; };
};
#endif

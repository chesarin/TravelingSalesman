#ifndef NODE_H_
#define NODE_H_
class Node{
 public:
  int id,num_level,g;
  double f,h;
  Node* father;
  Node(){ father=NULL; };
 Node(int i, Node* f=0):id(i),father(f){};
 set_id(int i):id(i);
};
#endif

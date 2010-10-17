#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
void parse(string input);
vector<int> nodes;
int main(){
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
  return 0;
}
void parse(string input){
  int temp;
  for ( istringstream i(input) ; i >> temp ; ){
    nodes.push_back (temp);
  }
  for ( unsigned int i=0 ; i < nodes.size() ; i++ )
    cout << nodes[i] << "  ";

  cout << endl;
}

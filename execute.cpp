#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(){
  ifstream ifs ("input.txt");
  cout << "Opening the file with input nodes" << endl;
  while (ifs.good())
    cout << ifs.get() << endl;
  return 0;
}

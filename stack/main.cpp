#include <iostream>
#include "Stack.h"

using namespace std;

int main(){
  cout << "\n\n";
  cout << "Creating stack of integers..." << endl;
  Stack<int> x;
  x.push(1);
  x.push(2);
  x.push(3);

  cout << "Creating stack of characters..." << endl;
  Stack<char> c;
  c.push('C');
  c.push('B');
  c.push('A');

  cout << "Creating stack of strings..." << endl;
  Stack<string> s;
  s.push("Last");
  s.push("Middle");
  s.push("First");

  return 0;
}

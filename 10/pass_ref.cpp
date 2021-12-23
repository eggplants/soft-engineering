#include <iostream>

using namespace std;

void func(int &x) { x += 1; }

int main() {
  int a = 1;
  cout << "before: a=" << a << endl;  // "before: a=1"
  func(a);
  cout << "after:  a=" << a << endl;  // "after:  a=2"
}

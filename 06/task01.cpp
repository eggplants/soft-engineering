#include <iostream>
#include <string>

using namespace std;

int main() {
  int age;
  cout << "please input your age" << endl;
  cin >> age;

  float height;
  cout << "please input your height" << endl;
  cin >> height;

  string name;
  cout << "please input your name" << endl;
  cin >> name;

  cout << "your name is " << name << ", age is " << age << ", height is "
       << height << endl;
  return 0;
}

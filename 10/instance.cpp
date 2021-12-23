#include <iostream>

using namespace std;

class Person {
 public:
  string name;
  int age;
  void say() { cout << "I'm " << name << ", my age is " << age << endl; }
};

int main() {
  Person* p;
  p = new Person;
  p->name = "taro";
  p->age = 20;
  p->say();  // 「->」で直接メソッドやメンバにアクセスできる
  (*p).say();  // 「->」を省略しないで書くと、こう書くこともできる
}

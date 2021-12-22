#include <iostream>
using namespace std;

class Animal {
 protected:
  string name;

 public:
  Animal(){};
  void setName(string _name) { name = _name; }
  // virtualを持つ関数は純粋仮想関数で実装を持たない
  // 継承を強制できる
  virtual void make_sound() = 0;
};

class Dog : public Animal {
 public:
  void make_sound() {  // 必須実装
    cout << "Bow!! Bow!!" << endl;
  };
};

int main() {
  Dog pochi;
  pochi.make_sound();
}

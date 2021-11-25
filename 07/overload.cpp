#include <cmath>
#include <iostream>

using namespace std;

class Person {
 private:
  string name;
  float weight;
  int current_floor;

 public:
  Person(string n, float w, int f);
  string get_name();
  void set_name(string n);
  float get_weight();
  void set_weight(float w);
  int get_current_floor();
  void set_current_floor(int cf);
  void self_introduce();
};

Person::Person(string n, float w, int f) {
  name = n;
  weight = w;
  current_floor = f;
};
string Person::get_name() { return name; };
void Person::set_name(string n) { name = n; };
float Person::get_weight() { return weight; };
void Person::set_weight(float w) { weight = w; };
int Person::get_current_floor() { return Person::current_floor; };
void Person::set_current_floor(int cf) { current_floor = cf; };
void Person::self_introduce() {
  cout << "I'm " << name
       << ".\n"
          "Now I'm on floor "
       << current_floor << "!\n";
};

class Elevetor {
 private:
  string name;
  float max_weight;

 public:
  Elevetor(string n, float mw);
  void get_on(Person p1);
  void get_on(Person p1, Person p2);
};
;

Elevetor::Elevetor(string n, float mw) {
  name = n;
  max_weight = mw;
}
void Elevetor::get_on(Person p1) {
  if (p1.get_weight() > max_weight) {
    cout << "Over Capacity!";
  } else {
    int next_floor;
    next_floor = p1.get_current_floor() + 1;
    p1.set_current_floor(next_floor);
    cout << "Bring " << p1.get_name() << " to floor " << next_floor << endl;
  }
};

void Elevetor::get_on(Person p1, Person p2) {
  float total_weight = p1.get_weight() + p2.get_weight();
  if (total_weight > max_weight) {
    cout << "Over Capacity!";
  } else {
    int next_floor;
    next_floor = p1.get_current_floor() + 1;
    p1.set_current_floor(next_floor);
    cout << "Bring " << p1.get_name() << " to floor " << next_floor << endl;
    next_floor = p2.get_current_floor() + 1;
    p2.set_current_floor(next_floor);
    cout << "Bring " << p2.get_name() << " to floor " << next_floor << endl;
  }
};

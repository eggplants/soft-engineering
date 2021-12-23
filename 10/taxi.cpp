#include <iostream>
#include <string>

using namespace std;

class Passenger {
 public:
  int current_position;
  string name;
  Passenger(string _n, int _cp) {
    name = _n;
    current_position = _cp;
  };
};

class taxi {
 public:
  taxi(){};
  void carry(Passenger &p, int distance) { p.current_position += distance; };
};

int main() {
  Passenger p("Taro Yamada", 0);
  taxi t;
  cout << p.name << " is now at " << p.current_position << endl;
  t.carry(p, 50);
  cout << p.name << " is now at " << p.current_position << endl;
};

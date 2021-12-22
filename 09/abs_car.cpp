#include <iostream>
using namespace std;

class Car {
 protected:
  string owner;

 public:
  Car(){};
  void setOwner(string _owner) { owner = _owner; }
  virtual void run() = 0;
};

class SportsCar : public Car {
 protected:
  string boost_pressure;

 public:
  SportsCar(){};
  void set_boost_pressure(int _pressure) { boost_pressure = _pressure; }
};

class GTR : public SportsCar {
 public:
  void run() {
    cout << owner << "'s GTR ran at 120km/h on pressure " << boost_pressure
         << endl;
  };
};

class RX7 : public SportsCar {
 public:
  void run() {
    cout << owner << "'s RX7 ran at 130km/h on pressure " << boost_pressure
         << endl;
  };
};

int main() {
  // Car a; // -> err
  // SportsCar a; // -> err
  GTR sasaki_car;
  sasaki_car.setOwner("Sasaki");
  sasaki_car.set_boost_pressure(2);
  sasaki_car.run();
  RX7 yamada_car;
  yamada_car.setOwner("Yamada");
  yamada_car.set_boost_pressure(3);
  yamada_car.run();
}

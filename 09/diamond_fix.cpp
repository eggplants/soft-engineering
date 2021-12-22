#include <iostream>
using namespace std;

class Car {
 public:
  virtual void run() = 0;
};

class SportCar : virtual public Car {
 public:
  void run() { cout << "run with eco" << endl; }
};

class HybridCar : virtual public Car {
 public:
  void run() { cout << "run cheaply" << endl; }
};

class CRZ : public SportCar, public HybridCar {
  void run() { HybridCar::run(); }
};

int main() {
  CRZ mycar;
  // mycar.run();  // ambiguous
  mycar.HybridCar::run();
}
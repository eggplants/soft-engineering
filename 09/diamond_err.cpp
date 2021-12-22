#include <iostream>
using namespace std;

class Car {
 public:
  virtual void run() = 0;
};

class SportCar : public Car {
 public:
  void run() { cout << "run with eco"; }
};

class HybridCar : public Car {
 public:
  void run() { cout << "run cheaply"; }
};

class CRZ : public SportCar, public HybridCar {};

int main() {
  CRZ mycar;
  mycar.run();  // error: request for member ‘run’ is ambiguous
}
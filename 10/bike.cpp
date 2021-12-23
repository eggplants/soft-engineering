#include <iostream>
#include <sstream>
#include <stdexcept>
#include <typeinfo>

using namespace std;

class Vehicle {
 public:
  virtual void set_number(int n) { number = n; };

 private:
  int number;
  static const int num_wheels;
};

class Bike : public Vehicle {
 public:
  static const int num_wheels = 2;
  static int num_sold;
  static const int num_remain = 3;
  static int register_numbers[num_remain];
  Bike(int n) {
    if (num_remain == num_sold) {
      throw overflow_error("not remain");
    }
    set_number(n);
    register_numbers[num_sold] = n;
    num_sold++;
  }
};
int Bike::num_sold = 0;
int Bike::register_numbers[];

class Bikecycle : public Vehicle {
 public:
  static const int num_wheels = 2;
  static int num_sold;
  static const int num_remain = 3;
  static int register_numbers[num_remain];
  Bikecycle(int n) {
    if (num_remain == num_sold) {
      throw overflow_error("not remain");
    }
    set_number(n);
    register_numbers[num_sold] = n;
    num_sold++;
  }
};
int Bikecycle::num_sold = 0;
int Bikecycle::register_numbers[];

class Trike : public Vehicle {
 public:
  static const int num_wheels = 3;
  static int num_sold;
  static const int num_remain = 3;
  static int register_numbers[num_remain];
  Trike(int n) {
    if (num_remain == num_sold) {
      throw overflow_error("not remain");
    }
    set_number(n);
    register_numbers[num_sold] = n;
    num_sold++;
  }
};
int Trike::num_sold = 0;
int Trike::register_numbers[];

string itos(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

string iatos(int is[], int length) {
  string s = "[";
  for (int i = 0; i < length; i++) {
    if (is[i] == 0) {
      s += "-";
    } else {
      s += itos(is[i]);
    }
    if (i != length - 1) s += ", ";
  }
  s += "]";
  return s;
}

string rmnum(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (isdigit(s[i])) {
      s.erase(i, 1);
      i--;
    }
  }

  return s;
}

template <typename T>
void test(T x) {
  cout << "- " << rmnum(typeid(x).name()) << "(" << T::num_wheels
       << " wheels): " << T::num_sold << ""
       << iatos(T::register_numbers, T::num_sold) << endl;
}

int main() {
  cout << "Sales:" << endl;
  test(Bike(1));
  Bikecycle(2);
  test(Bikecycle(3));
  Trike(4), Trike(5);
  test(Trike(6));
  // Trike(7);  // -> std::overflow_error: not remain
}

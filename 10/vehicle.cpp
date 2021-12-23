#include <iostream>
using namespace std;

// staticはインスタンス不要
// constは再代入不可

class Vehicle {
 public:
  void run();
  int get_number() { return number; };
  void set_number(int n) { number = n; };

  int get_num_wheels() { return num_wheels; };

 private:
  int number;                   // 車体番号
  static const int num_wheels;  // タイヤの数
};

class Bike : public Vehicle {
 public:
  static const int num_wheels = 2;
  static int num_sold;
  // バイクの売れた数は個体とは無関係なので
  // クラス変数としてバイクの総数を定義

  Bike(int n) {
    set_number(n);
    num_sold += 1;
  }
};

// staticメンバの初期化はクラス外で
int Bike::num_sold = 0;

int main() {
  Bike b1 = Bike(1234);
  Bike b2 = Bike(5678);
  Bike b3 = Bike(9012);

  // static const via instance
  cout << "number of b1's wheel is " << b1.num_wheels << endl;
  // static const without instance
  cout << "number of bike's wheel is " << Bike::num_wheels << endl;
  // static via instance
  cout << "the total number of vehicle similar to b1 sold is " << b1.num_sold
       << endl;
  // static without instance
  cout << "the total number of bike sold is " << Bike::num_sold << endl;
}

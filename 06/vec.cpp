#include <cmath>
#include <iostream>

using namespace std;

class Vector {
 public:
  float x, y;
  Vector(float x_, float y_);

  void print();
  float manhattan();
  float manhattan(Vector v);
  float euclidean();
  float euclidean(Vector v);
  float inner_product(Vector v);
  float outer_product(Vector v);
  Vector add(Vector v);
  Vector sub(Vector v);
  Vector reverse();
  Vector normalize();
};

// constructor
Vector::Vector(float x_, float y_) {
  x = x_;
  y = y_;
}

void Vector::print() { cout << "x: " << x << ", y: " << y << endl; }

// マンハッタン距離
float Vector::manhattan() { return abs(x) + abs(y); };
float Vector::manhattan(Vector v) { return abs(x - v.x) + abs(y - v.y); };

// ユークリッド距離
float Vector::euclidean() { return sqrt(x * x + y * y); };
float Vector::euclidean(Vector v) {
  return sqrt(pow(x - v.x, 2.0) + pow(y - v.y, 2.0));
};

// 内積
float Vector::inner_product(Vector v) { return x * v.x + y * v.y; };
// 外積
float Vector::outer_product(Vector v) { return x * v.y - y * v.x; };

// 加法
Vector Vector::add(Vector v) {
  Vector r(x + v.x, y + v.y);
  return r;
};
// 減法
Vector Vector::sub(Vector v) {
  Vector r(x - v.x, y - v.y);
  return r;
};

// 逆ベクトル
Vector Vector::reverse() {
  Vector r(-x, -y);
  return r;
};

// 正規化
Vector Vector::normalize() {
  float norm = Vector::euclidean();
  Vector r(x / norm, y / norm);
  return r;
};

int main() {
  Vector v1(1.5, 0.5), v2(-1.5, 0.5), v3(-1.5, -0.5);
  cout << v1.manhattan() << endl;
  cout << v2.manhattan() << endl;
  cout << v3.manhattan() << endl;
  return 0;
};

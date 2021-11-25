#include <cmath>
#include <iostream>
#include <stdexcept>

using namespace std;

class Time {
 private:
  int hour;
  int minute;
  void set_time(int hm, int diff);
  void set_time(int h, int m, int diff);
  int get_time(int diff);

 public:
  // 内部的にはutcで管理
  void set_utc(int hm);
  void set_utc(int h, int m);
  void set_jst(int hm);
  void set_jst(int h, int m);
  void set_est(int hm);
  void set_est(int h, int m);
  int get_utc();
  int get_jst();
  int get_est();
};

void Time::set_time(int hm, int diff) {
  if (not(100 <= hm <= 2459)) {
    throw std::invalid_argument("error: should be 100 <= time <= 2459");
  } else if (59 < hm % 100) {
    throw std::invalid_argument("error: should be 00 <= minute <= 59");
  } else {
    int h = floor(hm / 100) - diff;
    h = h < 0 ? h + 24 : h > 23 ? h - 24 : h;
    hour = h == 24 ? 0 : h;
    minute = hm % 100;
  }
};

void Time::set_time(int h, int m, int diff) {
  if (not(0 <= h <= 23)) {
    throw std::invalid_argument("error: should be 0 <= hour <= 23");
  } else if (not(0 <= m <= 59)) {
    throw std::invalid_argument("error: should be 0 <= minute <= 59");
  } else {
    h -= diff;
    hour = h < 0 ? h + 24 : h > 23 ? h - 24 : h;
    minute = m;
  }
};

int Time::get_time(int diff) {
  if (not(0 <= hour <= 24)) {
    throw std::invalid_argument("error: should be 0 <= hour <= 23");
  } else if (not(0 <= minute <= 59)) {
    throw std::invalid_argument("error: should be 0 <= minute <= 59");
  } else {
    int h = hour + diff;
    h = h < 0 ? h + 24 : h > 23 ? h - 24 : h;
    return 100 * h + minute;
  }
};

void Time::set_utc(int hm) { set_time(hm, 0); };
void Time::set_utc(int h, int m) { set_time(h, m, 0); };
void Time::set_jst(int hm) { set_time(hm, 9); };
void Time::set_jst(int h, int m) { set_time(h, m, 9); };
void Time::set_est(int hm) { set_time(hm, -5); };
void Time::set_est(int h, int m) { set_time(h, m, -5); };
int Time::get_utc() { return get_time(0); };
int Time::get_jst() { return get_time(9); };
int Time::get_est() { return get_time(-5); };

void test(Time *t) {
  cout << t->get_jst() << "(JST) == ";
  cout << t->get_utc() << "(UTC) == ";
  cout << t->get_est() << "(EST)" << endl;
}

int main() {
  Time t1, t2, t3, t4;
  t1.set_jst(1800);
  test(&t1);
  t2.set_utc(11, 30);
  test(&t2);
  t3.set_jst(6, 15);
  test(&t3);
  t4.set_est(1234);
  test(&t4);
}
#include <iostream>
using namespace std;

class Watch {
 public:
  int hour, minute;
  Watch(int h, int m) {
    hour = h;
    minute = m;
  };
};

class Messenger {
 public:
  string message;
  Messenger(string msg) { message = msg; }
};

// 親クラスを複数指定
class SmartWatch : public Watch, public Messenger {
 public:
  SmartWatch(int h, int m, string msg) : Watch(h, m), Messenger(msg){};
};

int main() {
  SmartWatch sw(15, 30, "Hello user!");
  cout << sw.message << " (It's now " << sw.hour << ":" << sw.minute << ")"
       << endl;
};
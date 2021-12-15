#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class Person {
 public:
  string name;
};

class Clock {
 public:
  int hour;
  int minute;
};

class Ticket {
 public:
  int id;
  Person* user;
  Ticket() { user = new Person; }
};

class TransTicket : public Ticket {
 public:
  string origin;
  string destination;
  TransTicket() : Ticket(){};
};

class PlaneTicket : public TransTicket {
 public:
  Clock* departureTime;
  Clock* arrivalTime;
  PlaneTicket() : TransTicket() {
    departureTime = new Clock();
    arrivalTime = new Clock();
  };
};

void set_time_from_stdin(Clock* p) {
  string s;
  cin >> s;
  istringstream f;
  f.str(s);
  char delim;
  f >> p->hour >> delim >> p->minute;
}

int main() {
  int ticketNum;
  cout << "チケットを何枚購入しますか？> ";
  cin >> ticketNum;
  cout << endl;
  PlaneTicket* tickets = new PlaneTicket[ticketNum];
  for (int i = 0; i < ticketNum; i++) {
    tickets[i].id = i + 1;
    cout << i + 1 << "人目の利用者の名前を入力してください> ";
    cin >> tickets[i].user->name;
    cout << "出発地を入力してください> ";
    cin >> tickets[i].origin;
    cout << "出発時刻を入力してください(hh:mm)> ";
    set_time_from_stdin(tickets[i].departureTime);
    cout << "到着地を入力してください> ";
    cin >> tickets[i].destination;
    cout << "到着時刻を入力してください(hh:mm)> ";
    set_time_from_stdin(tickets[i].arrivalTime);
    cout << endl;
  }
  cout << "チケット利用者一覧:" << endl;
  for (int i = 0; i < ticketNum; i++) {
    PlaneTicket t = tickets[i];
    cout << "- No. " << t.id << ": " << t.user->name;
    cout << ": [" << t.origin;
    cout << "<" << setw(2) << setfill('0') << t.departureTime->hour << ":"
         << setw(2) << setfill('0') << t.departureTime->minute;
    cout << "> => " << t.destination;
    cout << "<" << setw(2) << setfill('0') << t.arrivalTime->hour << ":"
         << setw(2) << setfill('0') << t.arrivalTime->minute;
    cout << ">]" << endl;
  }
  return 0;
}
#include <iostream>
using namespace std;

class Movie {
 public:
  string title;
  Movie(string _title) { title = _title; }
};

class CopyProtection {
 public:
  string code;
  CopyProtection(string _code) { code = _code; }
};

class ProtectedMovie : public Movie, public CopyProtection {
 public:
  ProtectedMovie(string _title, string _code)
      : Movie(_title), CopyProtection(_code){};
};

int main() {
  ProtectedMovie Totoro = ProtectedMovie("totoro", "HDCP");
  cout << Totoro.title << ", coded by " << Totoro.code << endl;
};
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool is_number(const string& s) {
  string::const_iterator it = s.begin();
  while (it != s.end() && isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "usage: " << argv[0] << " <numfile> <outfile>" << endl;
    return 0;
  } else if (argc != 3) {
    cerr << "usage: " << argv[0] << " <numfile> <outfile>" << endl;
    cerr << "numfile must be a file with only one int number per line." << endl;
    return 1;
  }
  string iname = argv[1];
  string oname = argv[2];
  if (!filesystem::exists(iname)) {
    cerr << "err: file not found: " << iname << endl;
    return 1;
  }
  if (filesystem::exists(oname)) {
    cerr << "err: outfile exists: " << oname << endl;
    return 1;
  }

  ifstream fi(iname);
  int ln = 0;
  int sum = 0;
  string s;

  while (getline(fi, s)) {
    ln++;
    if (is_number(s)) {
      cerr << "err: invalid line " << ln << endl;
      cerr << "numfile must be a file with only one int number per line."
           << endl;
      fi.close();
      return 1;
    } else {
      sum += stoi(s);
    }
  }
  fi.close();
  ofstream fo(oname);
  float avg = (float)sum / (float)ln;
  fo << avg << endl;
  fo.close();
  cout << "output: " << oname << endl;
  return 0;
}
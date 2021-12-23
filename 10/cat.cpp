#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "usage: cat <file> [<file> ...]" << endl;
    return 1;
  }
  for (int i = 1; i < argc; i++) {
    if (!filesystem::exists(argv[i])) {
      cerr << "err: file not found: " << argv[i] << endl;
      return 1;
    }
  }
  int lineno;
  string s;
  for (int i = 1; i < argc; i++) {
    ifstream f(argv[i]);
    while (getline(f, s)) {
      cout << ++lineno << "\t" << s << endl;
    }
    f.close();
  }
  return 0;
}
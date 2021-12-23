#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc < 3) {
    cerr << "usage: " << argv[0] << " <file> [<file> ...] <outfile>" << endl;
    return 1;
  }
  string outname = argv[argc - 1];
  for (int i = 1; i < argc - 1; i++) {
    if (!filesystem::exists(argv[i])) {
      cerr << "err: file not found: " << argv[i] << endl;
      return 1;
    }
  }
  if (filesystem::exists(outname)) {
    cerr << "err: outfile exists: " << outname << endl;
    return 1;
  }
  ofstream fo(outname);
  int ln = 1;
  string s;
  for (int i = 1; i < argc - 1; i++) {
    ifstream f(argv[i]);
    while (getline(f, s)) {
      fo << ln << "\t" << s << endl;
      ln++;
    }
    f.close();
  }
  fo.close();
  cout << "output: " << outname << endl;
  return 0;
}
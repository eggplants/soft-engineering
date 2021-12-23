#include <iostream>
using namespace std;

class Person {
 protected:
  string name;

 public:
  string getName() { return name; }
  string setName(string n) { name = n; }
  Person(string n) { name = n; };
  virtual void introduction() {}
};

class Customer : public Person {
 public:
  Customer(string n) : Person(n) {}
  void introduction() { cout << "I'm" << name << ". I'm a guest" << endl; }
};

class Shef : public Person {
 public:
  string getFeature() { return feature; }
  string getGrade() { return grade; }
  void setFeature(string d) { feature = d; };
  void setGrade(string g) { grade = g; };
  void introduction() {
    string dish = getFeature();
    if (dish != "") {
      cout << "Today's featured dish is " << dish << "." << endl;
    } else {
      cout << "There is no featured dish today. Sorry!" << endl;
    }
  }
  Shef(string n, string g) : Person(n) { grade = g; }

 protected:
  string feature;
  string grade;
};

class Manager : public Person {
 public:
  Manager(string n) : Person(n) {}
  void introduction() { cout << "I am a manager!" << endl; }
};

class Staff : public Person {
 public:
  Staff(string n) : Person(n) {}
  void introduction() { cout << "Hello, may I help you?" << endl; }
};

class Sommelier : public Person {
 public:
  Sommelier(string n) : Person(n) {}
  void introduction() { cout << "I am a sommelier!" << endl; }
};

#include <stdio.h>

#include <iostream>
#include <string>

using namespace std;

class Animal {
 protected:
  string name;
  int height;
  int weight;
  float calc_demand_oxygen(int air_volume);

 public:
  Animal(string _name, int _height, int _weight);
  void breath(int air_volume);
  void sleep();
  void make_sound();
};

Animal::Animal(string _name, int _height, int _weight) {
  name = _name;
  height = _height;
  weight = _weight;
}

float Animal::calc_demand_oxygen(int air_volume) {
  return air_volume * 0.1 * weight;
}

void Animal::breath(int air_volume) {
  cout << name << " took in " << Animal::calc_demand_oxygen(air_volume)
       << " cc of oxygen." << endl;
}

void Animal::sleep() { cout << "zzz..." << endl; }

void Animal::make_sound() { cout << "..." << endl; }

class Cat : public Animal {
 public:
  void sleep();
  void make_sound();
  Cat(string _name, int _height, int _weight)
      : Animal(_name, _height, _weight){};
};

void Cat::sleep() {
  cout << "　　　　　 ＿＿"
       << "　　　　／＞　　フ"
       << "　　　　|  _　 _ l"
       << " 　　　／` ミ＿xノ"
       << "　 　 /　　　 　 |"
       << "　　 /　 ヽ　　 ﾉ"
       << " 　 │　　|　|　|"
       << "／￣|　　 |　|　|"
       << "| (￣ヽ＿_ヽ_)__)"
       << "＼二つ" << endl;
}

void Cat::make_sound() { cout << "*Meow* *Meow*" << endl; }

class Dog : public Animal {
 public:
  void sleep();
  void make_sound();
  Dog(string _name, int _height, int _weight)
      : Animal(_name, _height, _weight){};
};

void Dog::sleep() {
  cout << "　＜⌒／ヽ＿＿"
       << "／＜_/＿＿＿／"
       << "￣￣￣￣￣￣" << endl;
}

void Dog::make_sound() { cout << "Bow!! Bow!!" << endl; }

class Fish : public Animal {
 public:
  Fish(string _name, int _height, int _weight)
      : Animal(_name, _height, _weight){};
};

class Human : public Animal {
 public:
  string job;
  void sleep();
  void make_sound();
  void self_introduction();
  Human(string _name, int _height, int _weight, string _job)
      : Animal(_name, _height, _weight) {
    job = _job;
  }
};

void Human::sleep() { cout << "😴" << endl; }

void Human::make_sound() { Human::self_introduction(); }

void Human::self_introduction() {
  cout << "Hi! I'm " << Human::name << "! I'm " << Human::weight
       << "kg! my job is " << Human::job << "." << endl;
}
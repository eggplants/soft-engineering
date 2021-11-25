#include <cmath>
#include <iostream>

using namespace std;

class Person {
  private:
    //プライベートなメンバ変数を定義
    string name;
    float weight;
    int current_floor;

  public:
    //外部から呼び出せるメソッドを定義
    Person(string n, float w, int f);
    //セッタとゲッタを定義
    string get_name(){
      return name;
    }
    void set_name(string n){
      name = n;
    }
    float get_weight(){
      return weight;
    }
    void set_weight(float w){
      weight = w;
    }
    int get_current_floor(){
      return current_floor;
    }
    void set_current_floor(int cf){
      current_floor = cf;
    }
    //自己紹介機能を追加
    void self_introduce(){
      cout << "I'm " << name << ".\n"
      "Now I'm on floor " << current_floor << "!\n";
    }
};

Person::Person(string n, float w, int f){
  name = n;
  weight = w;
  current_floor = f;
}

int main(){
  Person taro("Taro YAMADA", 58.0, 1);
  // taro.set_name("TaroYAMADA");
  // taro.set_weight(58.0);
  // taro.set_current_floor(1);
  taro.self_introduce();
  return 0;
}

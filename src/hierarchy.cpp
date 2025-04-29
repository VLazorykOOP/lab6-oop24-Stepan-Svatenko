#include <iostream>
#include <string>
#include <map>
#include "tasks.h"

using namespace std;

// Задача 3.6. Ієрархія типів складається з сутностей: особа, жінка, працівник та
// працівник-жінка.

class Person{
  protected:
    int age;
    string PIB;
  public:
    Person(int a = 0, string name = "noname"): age(a), PIB(name) {}
    virtual void print() const {
      cout << "Age: " << age << " PIB: " << PIB << endl;
    }
    friend ostream& operator<<(ostream& os, const Person& a){
      os << "Age: "<< a.age << " PIB: " << a.PIB;
      return os;
    }
    friend istream& operator>>(istream& is, Person& a){
      cout << "Enter name: ";
      is >> a.PIB;
      cout << "Enter age: ";
      is >> a.age;
      return is;
    }
};
class Woman: virtual public Person{
  protected:
    bool hasChildren;
  public:
    Woman(int a = 0, string name = "noname", bool ch = false): Person(a, name), hasChildren(ch) {}
    void print() const override  {
      Person::print();
      cout << "hasChildren: " <<hasChildren << endl;
    }
    friend ostream& operator<<(ostream& os, const Woman& a){
      os << static_cast<const Person&>(a) << "hasChildren: " << a.hasChildren << endl;
      return os;
    }
    friend istream& operator>>(istream& is, Woman& a){
      is >> static_cast<Person&>(a);
      cout << "hasChildren\n";
      is >> a.hasChildren;
      return is;
    }
};
class Employe: virtual public Person{
  protected:
    float salary;
    string position;
  public:
    Employe(int a = 0, string name = "noname", float s = 0.0, string pos = "noname"): Person(a, name), salary(s), position(pos) {}
    void recheckSalary(){
      float baseSalary = 4000;
      int index = 1;
      this->salary = baseSalary * index;
    }
    void print() const override{
      Person::print();
      cout << "salary: "<< salary << " position: "<< position << endl;
    }
    friend ostream& operator<<(ostream& os, Employe& a ){
      os << static_cast<const Person&>(a) << "salary: "<< a.salary << " position: "<< a.position << endl;
    return os;
    }
    friend istream& operator>>(istream& is, Employe& a){
      cout << "Enter salary: ";
      is >> a.salary;
      cout << "Enter position: ";
      is >> a.position;
      return is;    
    }
};
class WomanEmploye: public Woman, public Employe{
  public:
    WomanEmploye(int a = 0, string name = "noname", float s = 0.0, string pos = "noname", bool ch = false): Person(a, name), Employe(a, name, s, pos), Woman(a, name, ch) {}
    void print() const override{
      Employe::print();
      Woman::print();
    }
    friend ostream& operator<<(ostream& os, WomanEmploye& a){
      os << static_cast<const Employe&>(a) << static_cast<const Woman&>(a);
      return os;
    }
    friend istream& operator>>(istream& is, WomanEmploye& a){
      is >> static_cast<Employe&>(a) >> static_cast<Woman&>(a);
      return is;    
    }
};


void hierarchy_unit() {
  WomanEmploye we;
  we.print();
  cin >> we;
  cout << we;

}

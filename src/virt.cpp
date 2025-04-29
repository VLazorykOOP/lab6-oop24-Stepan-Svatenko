#include <iostream>
#include <string>
#include <algorithm>
#include "tasks.h"
using namespace std;


// Задача. Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з
// елементами даних класів у кожному класі. Схема успадкування на рисунку за варіантами.
// Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. Вивести
// розміри об’єктів даних класів

class Base{
  public:
    int dat;
    Base() : dat(1) {}
    Base(int d) : dat(d) {}
};

class D1 : public Base{
  public:
    int d1;
    D1() : d1(1), Base() {}
    D1(int d) : d1(d), Base(d) {}
};
class D2 : public Base{
  public:
    int d2;
    D2() : d2(1), Base() {}
    D2(int d) : d2(d), Base(d) {}
};
class D3 : public D1, public Base{
  public:
    int d3;
    D3() : d3(1), D1(), Base() {}
    D3(int d) : d3(d), D1(d), Base(d) {}
};
class D4 : public D3{
  public:
    int d4;
    D4() : d4(1), D3() {}
    D4(int d) : d4(d), D3(d) {}
};
class D5: public D3, public Base{
  public:
    int d5;
    D5() : d5(1), D3(), Base() {}
    D5(int d) : d5(d), D3(d), Base(d) {}
};



class virtBase{
  public:
    int dat;
    virtBase() : dat(1) {}
    virtBase(int d) : dat(d) {}
};

class vD1 : virtual public virtBase{
  public:
    int d1;
    vD1() : d1(1), virtBase() {}
    vD1(int d) : d1(d), virtBase(d) {}
};
class vD2 : virtual public virtBase{
  public:
    int d2;
    vD2() : d2(1), virtBase() {}
    vD2(int d) : d2(d), virtBase(d) {}
};
class vD3 : virtual public vD1, virtual public virtBase{
  public:
    int d3;
    vD3() : d3(1), vD1(), virtBase() {}
    vD3(int d) : d3(d), vD1(d), virtBase(d) {}
};
class vD4 : virtual public vD3{
  public:
    int d4;
    vD4() : d4(1), vD3() {}
    vD4(int d) : d4(d), vD3(d) {}
};
class vD5: virtual public vD3, virtual public virtBase{
  public:
    int d5;
    vD5() : d5(1), vD3(), virtBase() {}
    vD5(int d) : d5(d), vD3(d), virtBase(d) {}
};


void virt_unit() {
  cout << "Sizes of non-virtual hierarchy:\n";
    cout << "Base  : " << sizeof(Base) << '\n';
    cout << "D1    : " << sizeof(D1) << '\n';
    cout << "D2    : " << sizeof(D2) << '\n';
    cout << "D3    : " << sizeof(D3) << '\n';
    cout << "D4    : " << sizeof(D4) << '\n';
    cout << "D5    : " << sizeof(D5) << '\n';

    cout << "\nSizes of virtual inheritance hierarchy:\n";
    cout << "virtBase : " << sizeof(virtBase) << '\n';
    cout << "vD1      : " << sizeof(vD1) << '\n';
    cout << "vD2      : " << sizeof(vD2) << '\n';
    cout << "vD3      : " << sizeof(vD3) << '\n';
    cout << "vD4      : " << sizeof(vD4) << '\n';
    cout << "vD5      : " << sizeof(vD5) << '\n';
}

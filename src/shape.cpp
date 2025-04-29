#include <iostream>
#include <vector>
#include <stdexcept>

// Задача 2.6. Створити абстрактний базовий клас фігура із віртуальною функцією
// периметр. Створити похідні класи: прямокутник, коло, прямокутний трикутник,
//   трапеція зі своїми функціями обчислення периметру.
using namespace std;

class Shape{
public:
  virtual double perimeter() const = 0;
};

class Rectangle : public Shape{
  protected:
    int a,b;
public:

  double perimeter() const override{
    return 2 * (a + b);
  }
  Rectangle(int a, int b) : a(a), b(b) {}
};
class Circle : public Shape{
  protected:
    int r;

public:
  double perimeter() const override{
    return 2 * 3.14 * r;
  }
  Circle(int r) : r(r) {}
};
class RightTriangle : public Shape{
protected:
    int a,b,c;

  public:
  double perimeter() const override{
    return a + b + c;
  }
  RightTriangle(int a, int b, int c) : a(a), b(b), c(c) {}
};
class Trapezoid : public Shape{
  protected:
    int a,b,c,d;

  public:
    double perimeter() const override{
      return a + b + c + d;
    }
    Trapezoid(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
};
void shape_unit(){
  
  Shape* shapes[] = {
        new Rectangle(3, 4),
        new Circle(5),
        new RightTriangle(3, 4, 5),
        new Trapezoid(3, 4, 5, 6)
    };

    for (int i = 0; i < 4; ++i) {
        cout << "Perimeter of shape " << i + 1 << ": " << shapes[i]->perimeter() << endl;
        delete shapes[i];
    }
}


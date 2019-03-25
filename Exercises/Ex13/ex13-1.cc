#include <iostream>
#include <cmath>

using namespace std;

/* class definition */
class Point{
protected:
  double x, y;
  virtual double size(void) = 0;
  virtual double size(double) = 0;
public:
  Point(void);
};

class Line : public Point{
private:
  double x2, y2;
public:
  Line(void);
  double size(void);
  double size(double);
};

class Rect : public Point{
private:
  double x2, y2;
public:
  Rect(void);
  double size(void);
  double size(double);
};

class Circle : public Point{
private:
  double rad;
public:
  Circle(void);
  double size(void);
  double size(double);
}; 


int main(){
 //Point a;
 Line b;
 Rect c;
 Circle d;
 
 cout << "L = " << b.size() << ", L*10 = " << b.size(10) << endl;
 cout << "S = " << c.size() << ", L*10 = " << c.size(10) << endl;
 cout << "S = " << d.size() << ", L*10 = " << d.size(10) << endl; 
 
 return 0;
}


Point::Point(){
  x = 3.0;
  y = 5.0;
}

Line::Line(){
  x2 = 7.5;
  y2 = 10.8;
}

double Line::size(){
  double xm = (x2 - x) * (x2 - x);
  double ym = (y2 - y) * (y2 - y);
  return sqrt(xm + ym);
}

double Line::size(double d){
  double xm = (x2 - x) * (x2 - x);
  double ym = (y2 - y) * (y2 - y);
  return d * sqrt(xm + ym);
}

Rect::Rect(){
  x2 = 12.2;
  y2 = 10.5;
}

double Rect::size(){
  double xm = x2 - x;
  double ym = y2 - y;
  return xm * ym;
}

double Rect::size(double d){
  double xm = x2 - x;
  double ym = y2 - y;
  return 2 * d * (xm + ym);
}

Circle::Circle(){
  rad = 10.0;
}

double Circle::size(){
  return rad * rad * M_PI;
}

double Circle::size(double d){
  return 2 * d * M_PI * rad;
}

/*実行結果
bash-4.4$ g++ ex13-1.cc
bash-4.4$ ./a.out
L = 7.34098, L*10 = 73.4098
S = 50.6, L*10 = 294
S = 314.159, L*10 = 628.319
*/

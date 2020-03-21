#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#define M_PI 3.14159265358979323846
using namespace std;

struct Point {
  int x;
  int y;
};

float getLineLength(Point point1,Point point2) {
  return sqrt((point2.x - point1.x)*(point2.x - point1.x) + (point2.y - point1.y)*(point2.y - point1.y));
}

class Figure {
  protected:
    Point *points;
  public:
    Figure (struct Point * _points) {
      points = _points;
    };
    virtual float getPerimeter() = 0;
    virtual float getSquare() = 0;
};

class Rectangle : public Figure{
  public:
    Rectangle(struct Point points [2]) : Figure (points){};
    float getPerimeter() {
      return abs(points[0].x - points[1].x)*2 + abs(points[0].y - points[1].y)*2;
    }
    float getSquare() {
      return abs(points[0].x - points[1].x) * abs(points[0].y - points[1].y);
    }
};

class Circle : public Figure{
  private:
    int getRadius () {
      return sqrt((points[1].x - points[0].x)*(points[1].x - points[0].x) + (points[1].y - points[0].y)*(points[1].y - points[0].y));
    }
  public:
    Circle(struct Point points[2]) : Figure (points){};
    float getPerimeter() {
      return getLineLength(points[0],points[1]) * M_PI * 2;
    }
    float getSquare() {
      return (getLineLength(points[0],points[1]) * M_PI)*(getLineLength(points[0],points[1]) * M_PI);
    }
};

class Triangle : public Figure{
  public:
    Triangle(struct Point points[3]) : Figure (points){};
    float getPerimeter() {
      return getLineLength(points[0],points[1]) + getLineLength(points[1],points[2]) + getLineLength(points[2],points[0]);
    }
    float getSquare() {
      float halfPerimeter = getPerimeter() / 2;
      return sqrt(halfPerimeter*
        (halfPerimeter - getLineLength(points[0],points[1]))*
        (halfPerimeter - getLineLength(points[1],points[2]))*
        (halfPerimeter - getLineLength(points[2],points[0]))
      );
    }
};

int main () {
  srand((int)time(0));
  int figureNumber = 100;
  Figure *figures[figureNumber];
  for (int i = 0; i < 100; i++) {
    if (i % 3 == 0) {
      Point *points = new Point[2];
      points[0].x = rand()%100;
      points[0].y = rand()%100;
      points[1].x = rand()%100;
      points[1].y = rand()%100;
      figures[i] = new Rectangle(points);
    }
    if (i % 3 == 1) {
      Point *points = new Point[2];
      points[0].x = rand()%100;
      points[0].y = rand()%100;
      points[1].x = rand()%100;
      points[1].y = rand()%100;
      figures[i] = new Circle(points);
    }
    if (i % 3 == 2) {
      Point *points = new Point[2];
      points[0].x = rand()%100;
      points[0].y = rand()%100;
      points[1].x = rand()%100;
      points[1].y = rand()%100;
      points[2].x = rand()%100;
      points[2].y = rand()%100;
      figures[i] = new Triangle(points);
    }
  }
  
  for (int i = 0; i < 100; i++) {
    cout<<"####################"<<endl<<endl;
    if (i % 3 == 0) {
      cout<<"Type: Rectangle"<<endl;
    }
    if (i % 3 == 1) {
      cout<<"Type: Circle"<<endl;
    }
    if (i % 3 == 2) {
      cout<<"Type: Triangle"<<endl;
    }
    cout<<"Perimeter: "<<figures[i]->getPerimeter()<<endl;
    cout<<"Square: "<<figures[i]->getSquare()<<endl<<endl;
  }
}

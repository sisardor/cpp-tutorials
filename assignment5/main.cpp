#include <iostream>
#include <vector> // for vectors
#include <iterator> // for iterators

using namespace std;

const double PI = 3.14159265359;

class Point {
  public:
    // constructor - sets the coordinates to be x,y
    Point(int x = 0, int y = 0): x(x), y(y) {}

    // copy constructor - creates a new point with the same coordinates
    Point(const Point & p2) { x = p2.x; y = p2.y; }

    // getters
    int getX() { return x; }
    int getY() { return y; }

    // setters
    void setX(int value) { x = value; }
    void setY(int value) { y = value; }

    void print() { cout << "(" << x << "," << y << ")"; }
  private:
    int x;
    int y;
};


class GeometricShape: public Point {
  public:
    // Constructor: gets a coordinate. The purpose of the
    // coordinate depends on the specific shape
    GeometricShape(Point coord): Point(coord) {}

    // returns the area of the shape
    // returns 0 as default. To be implemented in each concrete shape
    virtual float getArea() { return 0; };

    // returns the perimeter of the shape
    // returns 0 as default. To be implemented in each concrete shape
    virtual float getPerimeter() { return 0; }

    // virtual method. To be implemented in each concrete method
    virtual void print() = 0;
};


class Circle: public GeometricShape {
  public:
    // Constructor
    Circle(Point center, int radius): GeometricShape(center), radius(radius) {}

    // returns the area of the circle
    float getArea() {
      return (PI * (radius * radius));
    }

    // returns the perimeter of the circle
    float getPerimeter() {
      return (2 * PI * radius);
    }

    // prints the center of the circle and its radius
    virtual void print() {
      cout << "Center: ";
      Point::print();
      cout << ", Radius: " << radius << '\n';
    }

  private:
    int radius;
};


class Rectangle: public GeometricShape {
  public:
    // Constructor
    Rectangle(Point topLeftPoint, int length, int width)
      : GeometricShape(topLeftPoint), length(length), width(width) {}

    // returns the area of the rectangle
    float getArea() {
      return (length * width);
    }

    // returns the perimeter of the rectangle
    float getPerimeter() {
      return (2 * (length + width));
    }

    // prints the top left point of the rectangle, its length and width
    virtual void print() {
      cout << "Top-left point: ";
      Point::print();
      cout << ", Length: " << length << ", Width: " << width << '\n';
    }
  private:
    int length;
    int width;
};


class CollectionOfShape {
  public:
    // Default constructor
    CollectionOfShape() {}

    // adds the shape to the list
    void add(GeometricShape * shape) { shapes.push_back(shape); }

    // iterates through all the shapes and prints them
    void print() {
      // Declaring iterator to a vector
      vector < GeometricShape * > ::iterator ptr;

      // Displaying vector elements using begin() and end()
      cout << "The vector elements are : \n";
      for (ptr = shapes.begin(); ptr < shapes.end(); ptr++)
        ( * ptr) -> print();
    }

    // returns the number of circles in the container
    int countCicles() {
      int count = 0;
      // Declaring iterator to a vector
      vector < GeometricShape * > ::iterator ptr;

      // Using dynamic_cast to count Circle shape
      for (ptr = shapes.begin(); ptr < shapes.end(); ptr++) {
        if (dynamic_cast < Rectangle * > ( * ptr) == nullptr) {
          count++;
        }
      }
      return count;
    }
  private:
    // List of shapes
    vector < GeometricShape * > shapes;
};

void test() {
  cout << "----------- Test Point class -----------\n";
  Point p1(10, 15); // Normal constructor is called here
  Point p2 = p1; // Copy constructor is called here

  // Let us access values assigned by constructors
  cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY();
  cout << "\np2.x = " << p2.getX() << ", p2.y = " << p2.getY();
  p1.print();
  cout << "\n\n";

  cout << "----------- Test Circle class -----------\n";
  Circle circle(p2, 10);
  circle.print();
  cout << "Area: " << circle.getArea();
  cout << "\nPerimeter: " << circle.getPerimeter();
  cout << "\n\n";

  cout << "----------- Test Rectangle class -----------\n";
  Rectangle rect(p1, 10, 50);
  rect.print();
  cout << "Area: " << rect.getArea();
  cout << "\nPerimeter: " << rect.getPerimeter();
  cout << "\n\n";

  cout << "----------- Test CollectionOfShape class -----------\n";
  CollectionOfShape cs;
  cs.add(new Circle(p2, 10));
  cs.add(new Circle(p2, 10));
  cs.add(new Circle(p2, 10));
  cs.add(new Circle(p2, 10));
  cs.add(new Circle(p2, 10));
  cs.add(new Circle(p2, 10));
  cs.add(new Rectangle(p2, 10, 30));
  cs.add(new Rectangle(p2, 10, 45));
  cs.add(new Rectangle(p2, 10, 56));

  cs.print();

  cout << "\nTotal circles: " << cs.countCicles() << "\n";
}

int main( int argc, char* argv[] ) {
  test();
  return 0;
}

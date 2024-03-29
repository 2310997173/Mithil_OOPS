#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    virtual float area() const = 0;
    virtual float perimeter() const = 0;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(float r) : radius(r) {}

    float area() const override {
        return M_PI * radius * radius;
    }

    float perimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float area() const override {
        return length * width;
    }

    float perimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    float side1;
    float side2;
    float side3;

public:
    Triangle(float s1, float s2, float s3) : side1(s1), side2(s2), side3(s3) {}

    float area() const override {
        float s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    float perimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 4, 5);

    cout << "Circle Area: " << circle.area() << ", Perimeter: " << circle.perimeter() << endl;
    cout << "Rectangle Area: " << rectangle.area() << ", Perimeter: " << rectangle.perimeter() << endl;
    cout << "Triangle Area: " << triangle.area() << ", Perimeter: " << triangle.perimeter() << endl;

    return 0;
}

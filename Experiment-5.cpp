#include<iostream>

class Rectangle {
    private:
        int length;
        int breadth;

    public:
        Rectangle(int l, int b) : length(l), breadth(b) {}

        int area(); // Declare the area function
};

// Define the area function outside the class declaration
int Rectangle::area() {
    return length * breadth;
}

int main() {
    Rectangle rect(5, 10);
    std::cout << "Area of the rectangle: " << rect.area() << std::endl;
    return 0;
}

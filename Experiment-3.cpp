#include<iostream>

class Room {
    private:
        double length;
        double breadth;

    public:
        Room(double l = 0, double b = 0) : length(l), breadth(b) {}

        void get() {
            std::cout << "Enter length: ";
            std::cin >> length;
            std::cout << "Enter breadth: ";
            std::cin >> breadth;
        }

        void display() {
            std::cout << "Length: " << length << std::endl;
            std::cout << "Breadth: " << breadth << std::endl;
        }

        double area() {
        return length * breadth;
        }

        double perimeter() {
        return 2 * (length + breadth);
        }
};

int main() {
    Room rooms[5];

    for(int i = 0; i < 5; i++) {
        std::cout << "Room " << i + 1 << ":" << std::endl;
        rooms[i].get();
        std::cout << "Area: " << rooms[i].area() << std::endl;
        std::cout << "Perimeter: " << rooms[i].perimeter() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

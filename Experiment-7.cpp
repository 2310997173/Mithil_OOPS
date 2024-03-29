#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);

    void display() const {
        cout << real << " + " << imag << "i";
    }
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex operator-(const Complex& c1, const Complex& c2) {
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

int main() {
    Complex num1(2, 3);
    Complex num2(4, 5);

    Complex sum = num1 + num2;
    Complex diff = num1 - num2;

    cout << "Sum: ";
    sum.display();
    cout << endl;

    cout << "Difference: ";
    diff.display();
    cout << endl;

    return 0;
}

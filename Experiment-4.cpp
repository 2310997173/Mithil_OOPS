#include<iostream>
#include<bitset>

class Number {
    private:
        int decimal;

    public:
        Number(int d = 0) : decimal(d) {}

        std::string toBinary() {
            std::bitset<32> b(decimal);
            return b.to_string();
        }

        void display() {
            std::cout << "Decimal: " << decimal << std::endl;
            std::cout << "Binary: " << toBinary() << std::endl;
        }
};

int main() {
    Number nums[5];

    for(int i = 0; i < 5; i++) {
        std::cout << "Number " << i + 1 << ":" << std::endl;
        std::cout << "Enter a decimal number: ";
        int decimal;
        std::cin >> decimal;
        nums[i] = Number(decimal);
        nums[i].display();
        std::cout << std::endl;
    }

    return 0;
}

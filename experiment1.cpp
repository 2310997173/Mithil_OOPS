#include <iostream>

int main() {
    int num, validCount = 0;
    bool validInput;

    do {
        std::cout << "Enter a number: ";
        std::cin >> num;
        validInput = std::cin && (num % 8 == 0);

        if (validInput) {
            validCount++;
            std::cout << "Valid number. Total valid numbers: " << validCount << std::endl;
        } else {
            std::cout << "Invalid number. Please enter a number divisible by 8." << std::endl;
        }
    } while (validInput);

    std::cout << "Exiting the program." << std::endl;

    return 0;
}

#include <iostream>

using namespace std;

class StringOperation {
private:
    char* str;

public:
    StringOperation(const char* s) {
        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        str = new char[len + 1];
        for (int i = 0; i < len; i++) {
            str[i] = s[i];
        }
        str[len] = '\0';
    }

    ~StringOperation() {
        delete[] str;
    }

    int length() const {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    char* reverse() const {
        int len = length();
        char* rev = new char[len + 1];
        for (int i = 0; i < len; i++) {
            rev[i] = str[len - 1 - i];
        }
        rev[len] = '\0';
        return rev;
    }

    StringOperation concatenate(const StringOperation& other) const {
        int len1 = length();
        int len2 = other.length();
        char* result = new char[len1 + len2 + 1];
        int i = 0;
        for (; i < len1; i++) {
            result[i] = str[i];
        }
        for (int j = 0; j < len2; j++, i++) {
            result[i] = other.str[j];
        }
        result[len1 + len2] = '\0';
        return StringOperation(result);
    }

    bool compare(const StringOperation& other) const {
        int len1 = length();
        int len2 = other.length();
        if (len1 != len2) {
            return false;
        }
        for (int i = 0; i < len1; i++) {
            if (str[i] != other.str[i]) {
                return false;
            }
        }
        return true;
    }

    void display() const {
        cout << str;
    }
};

int main() {
    StringOperation str1("Hello");
    StringOperation str2("World");

    cout << "String 1: ";
    str1.display();
    cout << endl;
    cout << "String 2: ";
    str2.display();
    cout << endl;

    cout << "Length of String 1: " << str1.length() << endl;
    cout << "Reverse of String 1: ";
    StringOperation rev = str1.reverse();
    rev.display();
    cout << endl;

    StringOperation concat = str1.concatenate(str2);
    cout << "Concatenation of String 1 and String 2: ";
    concat.display();
    cout << endl;

    if (str1.compare(str2)) {
        cout << "String 1 and String 2 are equal." << endl;
    } else {
        cout << "String 1 and String 2 are not equal." << endl;
    }

    return 0;
}

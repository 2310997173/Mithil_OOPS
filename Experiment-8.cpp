#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    static int totalTransactions;
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initBalance) : accountNumber(accNum), balance(initBalance) {}

    static int getTotalTransactions() {
        return totalTransactions;
    }

    void performTransaction(double amount) {
        totalTransactions++;
        if (amount > 0) {
            balance += amount;
        } else if (amount < 0 && balance >= -amount) {
            balance += amount;
        } else {
            cout << "Insufficient funds for withdrawal." << endl;
        }
    }

    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int BankAccount::totalTransactions = 0;

int main() {
    BankAccount acc1("1001", 1000);
    BankAccount acc2("1002", 500);

    acc1.performTransaction(200);
    acc2.performTransaction(-100);

    acc1.display();
    acc2.display();

    cout << "Total Transactions: " << BankAccount::getTotalTransactions() << endl;

    return 0;
}

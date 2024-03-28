#include<iostream>
using namespace std;

int sum_of_series(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int term = (i * (i + 1)) / 2;
        sum += term;
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "Sum of the series: " << sum_of_series(n) << endl;
    return 0;
}

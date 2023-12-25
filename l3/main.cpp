#include <iostream>

using namespace std;

unsigned long long doubleFactorial(int N) {
    if (N == 1 || N == 2) {
        return N;
    }
    unsigned long long tmp_1 =  static_cast<unsigned long long>(N);
    unsigned long long tmp_2 = doubleFactorial(N - 2);
    return tmp_1 * tmp_2;
}

int main() {
    int number = 0;
    cout << "Number two factorial:";
    cin >> number;
    unsigned long long result = doubleFactorial(number);

    std::cout << "Double factorial of " << number << " is: " << result << std::endl;

    return 0;
}
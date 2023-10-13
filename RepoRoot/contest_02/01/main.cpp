#include <iostream>
#include <cmath>

int is_prime(int n) {
    for (int i = 2; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << (is_prime(number) ? "YES" : "NO") << std::endl;
}

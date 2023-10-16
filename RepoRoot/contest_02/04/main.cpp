#include <iostream>
#include <tuple>
#include <utility> // для tuple и квадраных скобок
#include <numeric> // gcd/lcm мои плохо считали
#include <algorithm> // все из-за чего не работает может быть там

std::tuple<long int, long int> reduce(int m, int n) {
    int divisor = std::gcd(m, n); // наименьший общий множитель
    return std::make_tuple(m / divisor, n / divisor); // нашла gcd сократила числитель и знаменатель
}

std::tuple<long int, long int, long int> find_lcm(int a, int b) {
    long int lcm = std::lcm(a, b); // наименьшее общее кратное
    long int c = lcm / a; // кэфы для числителей
    long int d = lcm / b;
    return std::make_tuple(lcm, c, d);
}

int main() {
    int m1, n1, m2, n2;
    char _;
    std::cin >> m1 >> _ >> n1
             >> m2 >> _ >> n2;
    std::tie(m1, n1) = reduce(m1, n1);
    std::tie(m2, n2) = reduce(m2, n2);

    auto [lcm, c1, c2] = find_lcm(n1, n2); // приняла два знаменателя, вернула наименьший общий кратный и кэфы для числителя
    auto [m, n] = reduce(m1 * c1 + m2 * c2, lcm);

    std::cout << m << '/' << n << std::endl;
    return 0;
}


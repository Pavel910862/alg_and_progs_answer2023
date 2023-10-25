#include <iostream>
#include <unordered_map> // хэш-таблица
#include <string>
#include <sstream> // строковые потоки

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // Пропускаем символ новой строки

    std::unordered_map<std::string, int> users; // хэш-таблица

    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string login;
        int balance;
        std::getline(iss, login, ';'); // читает поток iss до ; записывает в логин 
        iss >> balance;  // остатки в баланс
        users[login] = balance; // записывает в хэш к ключу логин
    }

    int m;
    std::cin >> m; //количество запросов
    std::cin.ignore(); // Пропускаем символ новой строки

    for (int i = 0; i < m; ++i) {
        std::string line;
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string login;
        while (iss >> login) {                  // пока есть логин..
            std::cout << users[login] << " ";   // ... выводи через пробел значение этого ключа
        }
    }

    return 0;
}

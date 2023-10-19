#include <iostream>
#include <set>

int main() {
    int n, m;

    std::cin >> n;
    std::set<std::string> s1;
    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        s1.insert(word);
    }

    std::cin >> m;
    std::set<std::string> s2;
    for (int i = 0; i < m; i++) {
        std::string word;
        std::cin >> word;
        if (s1.count(word))    // если слово повторяется (count возвращает 1 или 0)
            s2.insert(word);   // пиши его во второе множество
    }

    if (s2.empty()) {
        std::cout << "-1" << std::endl;
        return 0;
    }

    for (std::string w: s2) {
        std::cout << w << " ";
    }
    
    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int count_underscores(std::string s); // возвращает количество единиц

bool compare(const std::string& left, const std::string& right){ //сравнивает левый с правым возвращает true / false
    if (count_underscores(left) == count_underscores(right))
       return stoi(left) < stoi(right); // string to int
    return count_underscores(left) > count_underscores(right);
}

int main() {
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for (auto& line : nums) std::cin >> line; // запись в вектор строк
        
    std::sort(nums.begin(), nums.end(), compare);

    for (auto& line : nums) std::cout << line << ' '; // вывод вектора чз пробел
}

int count_underscores(std::string s) { // возвращает количество единиц
    int cnt = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1') cnt++;
       
    return cnt;
}

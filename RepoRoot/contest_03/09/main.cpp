#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

std::pair<int, int> findPair(std::vector<int>& numbers, int target) {
    std::unordered_set<int> numSet;

    for (int num : numbers) {
        int complement = target - num; // вычислили разницу (каким должен быть второй элемент)...
        if (numSet.find(complement) != numSet.end()) {  //...является ли его комплементарное значение уже присутствующим в хэш-таблице...
            return std::make_pair(std::min(num, complement), std::max(num, complement)); //...пара найдена возвращай по возрастанию
        }
        numSet.insert(num);
    }

    return std::make_pair(0, 0);
}

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::pair<int, int> result = findPair(numbers, x);
    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}

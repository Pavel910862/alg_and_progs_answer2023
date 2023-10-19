#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> wordCount;

    for (int i = 0; i < n; i++) {
        std::string word;
        std::cin >> word;
        wordCount[word]++; // в first (key) записалось word, а second (value) увеличился на количество повторяющихся слов записанных в этот ключ
    }

    int max_word_Count = 0;

    for (const auto& pair : wordCount) {                // забили самые большие вхождения повторяющихся слов в maxCount
        max_word_Count = std::max(max_word_Count, pair.second);
    }

    std::vector<std::string> max_repet_Words;

    for (const auto& pair : wordCount) {                // в вектор записали ключи этих значений (собственно слова, которые чаще всего повторяются)
        if (pair.second == max_word_Count) {
            max_repet_Words.push_back(pair.first);
        }
    }

    std::sort(max_repet_Words.begin(), max_repet_Words.end());        // отсортировали

    for (const auto& word : max_repet_Words) {                 // вывели
        std::cout << word << " ";
    }

    return 0;
}

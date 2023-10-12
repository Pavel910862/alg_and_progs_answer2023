#include<iostream>
#include <vector>
#include <iomanip>
#include <string>
#include<algorithm>

using namespace std;

int main() {

    vector<string>w1;
    vector<string>ww2;
    string word;


    //заполняем вектор словами
    /*while (cin >> word) {
        w1.push_back(word);
    }*/

    while (true) {
        cin >> word;
        if (word == "end") break;
        w1.push_back(word);
    }

    for (int i = 0; i < w1.size(); i++) { //вложенные циклы, кот. ищут совпадения 
        for (int j = i + 1; j < w1.size(); j++) {
            if (w1[i] == w1[j]) {
                int f = 0;
                for (int k = 0; k < i; k++) { // условие что элементы уже проверены и те которые перед текущим(который уже определен как повторяющийся)
                    if (w1[k] == w1[i]) { // и которые повторяются несколько раз на экран не выведутся
                        f = 1;
                    }
                }
                if (f == 0) {
                    ww2.push_back(w1[i]);
                }
                break;
            }
        }
    }
    sort(begin(ww2), end(ww2));

    for (int j = 0; j < ww2.size(); ++j)
        cout << ww2[j] << " ";

    cout << "\n";

    return 0;
}


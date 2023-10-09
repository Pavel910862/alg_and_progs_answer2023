#include<iostream>
#include <string>

using namespace std;
int main() {
    string a;

    cin >> a; // ввели стороку

    for (int i = 0; i < a.length(); i++) { //берем каждый элемент строки
        int count = 1;

        while (a[i] == a[i + 1] && i < a.length() - 1) { // пока текущий элемент равен следующему и индекс элемента меньше длины строки(-1 т.к. индексы с нуля)
            count++; // счетчик добавляй
            i++; // переходи к следующему
        }
        if (count > 1) cout << a[i] << count; // вывод названия элемента и его колисества
        else cout << a[i]; // если элемент единственный его количество не указываем
    }
    return 0;
}

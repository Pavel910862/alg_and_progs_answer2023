#include <iostream>
#include <stack>
#include <string>

// Функция для проверки, является ли символ оператором
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

// Функция для определения приоритета оператора
int getPriority(char ch) {
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

std::string opn(std::string s) {
    std::stack<char> oper; // стек с операторами
    std::string out_str; 
    bool prevIsNumber = false; // флаг для пробелов в out_str

    for (char ch : s) {
        if (ch >= '0' && ch <= '9') { // если цифра
            out_str.push_back(ch); // кидаем ее в выходную строку
            }
        else if (isOperator(ch)) { //если оператор...
            if (prevIsNumber) { // ...и если флаг отрицательный значит пробел уже есть 
                out_str.push_back(' '); // флаг 1 значит пробела не было, ставим пробел
                prevIsNumber = false; // переключаем флаг
            }
            // пока текущий ch не ) и его преоритет не больше извлеченного их стека
            while (!oper.empty() && oper.top() != '(' && getPriority(oper.top()) >= getPriority(ch)) { 
                if (oper.top() == '^' && ch == '^')// если с высшим приоритетом - выходим (пробелы не добавляем)
                    break;
                out_str.push_back(' '); // если нет - пробел...
                out_str.push_back(oper.top());// ...за ним извлеченный оператор
                oper.pop(); // и удаляем его
            }
            out_str.push_back(' ');// пробел за извлеченным оператором из 40 или после ^ из 37
            oper.push(ch); //добавили в стек изначальный ch из 31
        }
        else if (ch == '(') { // если левая скобка - в стек
            oper.push(ch);
        }
        else if (ch == ')') { // если правая ...
            while (!oper.empty() && oper.top() != '(') {//пока стек не пустой и в стеке не дошли до левой
                out_str.push_back(' '); // в out_str - пробел...
                out_str.push_back(oper.top());//...оператор из стека...
                oper.pop();//...удаляем оператор из стека
            }
            if (!oper.empty() && oper.top() == '(') // если дошли в стеке до левой...
                oper.pop();//... удаляем ее никуда не добавляя
        }
    }

    while (!oper.empty()) { // пока стек не опустел...
        out_str.push_back(' ');//...через пробел...
        out_str.push_back(oper.top());//...выкидваем в строку операторы из стека...
        oper.pop();// ... и удаляем их
    }

    return out_str;
}

int main() {
    std::string in_str;
    std::getline(std::cin, in_str);

    std::cout << opn(in_str) << std::endl;

    return 0;
}

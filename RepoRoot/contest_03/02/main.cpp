#include <iostream>
#include <stack> // последний зашел - первый вышел LIFO
#include <string>

bool fff(std::string s) {
    std::stack<char> br;
    for (char ch : s) {                             // если в левая скобка - то в стек 
        if (ch == '(' || ch == '[' || ch == '{') 
            br.push(ch);
        else if (ch == ')' || ch == ']' || ch == '}') { // если правая и стек не пустой
            if (br.empty()) 
                return false;
            char ext = br.top(); // извлекаем из стека левую
            br.pop(); // и удаляем ее
            if ((ext == '(' && ch != ')') || (ext == '[' && ch != ']') || (ext == '{' && ch != '}')) // если не равны фолс
                return false;
        }
    }
    return br.empty();
}
  
int main() {
    std::string s;
    std::getline(std::cin, s, '!'); // принимаем s до !

    (fff(s)) ? std::cout << "YES" : std::cout << "NO";
}

#include<iostream>
#include<string>
using namespace std;

string Column(int n);

int main() {
    int a; cin >> a;
    
    Column(a);
}

string Column(int n) {
    string name = "";
    while (n > 0) {
        --n;
        name = (char)('A' + n % 26) + name; // в ASCII А - 65 (прибавили к остатку 65 получили код из аски для буквы
        n /= 26; // и записали в конец строки столько раз сколько раз делится число на 26
    }
    cout << name << endl;
    return name;
}

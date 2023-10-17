#include <iostream>
#include <sstream>
#include <string>

struct Complex {
    double re;  // Действительная часть
    double im;  // Мнимая часть
};

Complex make_complex(const std::string& str) {
    std::istringstream iss(str); //считывет строку
    Complex complex;

    iss >> complex.re; // часть до пробела в re

    char plusMinus;
    iss >> plusMinus; // считываем знак

    double imaginary; // временнея переменная
    if (plusMinus == '+') { // если прлюс пропускаем и записываем im
        iss >> imaginary;
    }
    else if (plusMinus == '-') { // если минус пропускаем но im умножаем на -1
        iss >> imaginary;
        imaginary = -imaginary;
    }
    complex.im = imaginary; // записываем в im

    return complex;
}

Complex sum(const Complex& c1, const Complex& c2) { 
    Complex result;
    result.re = c1.re + c2.re;
    result.im = c1.im + c2.im;
    return result;
}

Complex sub(const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re - c2.re;
    result.im = c1.im - c2.im;
    return result;
}

Complex mul(const Complex& c1, const Complex& c2) {
    Complex result;
    result.re = c1.re * c2.re - c1.im * c2.im;
    result.im = c1.re * c2.im + c1.im * c2.re;
    return result;
}

Complex div(const Complex& c1, const Complex& c2) {
    Complex result;
    double den = c2.re * c2.re + c2.im * c2.im;
    result.re = (c1.re * c2.re + c1.im * c2.im) / den;
    result.im = (c1.im * c2.re - c1.re * c2.im) / den;
    return result;
}

void print(const Complex& complex) {
    std::cout << complex.re;
    if (complex.im != 0) {
        std::cout << (complex.im > 0 ? '+' : '-') << std::abs(complex.im) << 'j';
    }
    else {
        std::cout << "+0j";
    }
    std::cout << std::endl;
}

int main() {
    std::string num;
    std::getline(std::cin, num, 'j');
    Complex c1 = make_complex(num);

    std::getline(std::cin, num, 'j');
    Complex c2 = make_complex(num);

    print(sum(c1, c2));
    print(sub(c1, c2));
    print(mul(c1, c2));
    print(div(c1, c2));

    return 0;
}

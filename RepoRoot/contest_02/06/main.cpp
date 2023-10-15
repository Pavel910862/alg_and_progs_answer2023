#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Student {
    std::string name;
    std::string group;
};

////////////////////////////////////////////начало написанного кода/////////////////////////////////////////////

Student make_student(std::string line) {
    Student student;
    int ind = line.find(';'); //находим индекс пробела
    // substr Первый параметр - индекс, с которого начинается подстрока.
    // Второй - количество символов извлекаемой подстроки.
    student.name = line.substr(0, ind); // здесь считывается строка от 0 до ковычек
    student.group = line.substr(ind + 1); // сюда надо записывается подстрока содержащая группу от ковычек до конца т.к. группа может быть разной длины
    return student;
}

bool is_upper(Student& s1, Student& s2) { // компроматор (условия сравнения)
    if (s1.group < s2.group) return 1; // если левая меньше правой (лексикграф) - true (оставляй так, нет - меняй местами)
    if (s1.group > s2.group) return 0; // если левая меньше - 0
    return s1.name < s2.name; // выполняется при равенстве групп
 }

void print(std::vector<Student> students) { //принимает вектор из структур студентов
    if (students.empty()) std::cout << "Empty list!" << std:: endl; // вывод при пустом векторе
    else {
        std::string cur_group = students[0].group; // задали текущую группу (первая отсортированная)
        std::cout << cur_group << std::endl; //вывели 
        for (const auto& student : students) { //перебираем вектор
            if (student.group != cur_group) { // если группа поменялась (не равна начальной)
                cur_group = student.group; // записываем в начальную новую грппу 
                std::cout << cur_group << std::endl; // выводим ее на экран
            }
            std::cout << "- " << student.name << std::endl; // и проводлжаем выводить имена студентов
        }
    }       
}

////////////////////////////////////////////конец написанного кода/////////////////////////////////////////////

int main()
{
    int count;
    std::cin >> count;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline

    std::vector<Student> students(count);
    for (auto& student : students) { //записывает значения в вектор чз getline игнорируя пробелы
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line); //принимает на вход строку с именем студента и номером группы, извлеает подстороки с именем и группой, записывает в структуру
    }
  
    std::sort(students.begin(), students.end(), is_upper);

    print(students);
}


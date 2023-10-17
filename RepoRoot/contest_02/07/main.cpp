#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

struct Course {
    std::string name;
    int semester;
    bool finished;
};

struct Student {
    std::string name;
    std::string group;
    std::vector<Course> courses;
};

Student make_student(const std::string& line) { // здесь все берем до ковычек, считываем, остаток строки снова в обработку
    std::string name, group, current_line;      // с предметами через while работаем
    std::vector<Course> courses;

    size_t name_pos = line.find(';');
    name = line.substr(0, name_pos);
    current_line = line.substr(name_pos + 1);

    size_t group_pos = current_line.find(';');
    group = current_line.substr(0, group_pos);
    current_line = current_line.substr(group_pos + 1);

    while (current_line != "0" && current_line != "1") { //в конце строки то 0 то 1 выходят из-за этого в бесконечность
        Course course;
        size_t sub_pos = current_line.find(';');
        std::string course_name = current_line.substr(0, sub_pos);
        current_line = current_line.substr(sub_pos + 1);

        size_t sem_pos = current_line.find(';');
        std::string sem_num = current_line.substr(0, sem_pos);
        current_line = current_line.substr(sem_pos + 1);

        size_t fin_pos = current_line.find(';');
        std::string finsh_y_n = current_line.substr(0, fin_pos);
        current_line = current_line.substr(fin_pos + 1);

        int semester = std::atoi(sem_num.c_str());
        int finished = std::atoi(finsh_y_n.c_str());

        course.name = course_name;
        course.semester = semester;
        course.finished = finished;

        courses.push_back(course);
    }
    return { name, group, courses };
}

bool is_upper(Student& s1, Student& s2) { // компроматор (условия сравнения)
    if (s1.group < s2.group) return 1; // если левая меньше правой (лексикграф) - true (оставляй так, нет - меняй местами)
    if (s1.group > s2.group) return 0; // если левая меньше - 0
    return s1.name < s2.name; // выполняется при равенстве групп
}

bool is_debtor(const Student& student, int cur_semester, int max_debt) {
    int debt_count = 0; // текущий долг накопительным итогом
    for (const Course& course : student.courses) {//обращаеся к вектору courses напрямую подставляя объект класса Student (не через конкретный объект класса Student)
        if (course.semester < cur_semester && !course.finished) { // если семестр меньше текущего (который читатется) и не 1 ( не завершен)
            debt_count++; // прибавляй в текущйи долг
        }
    }
    return debt_count > max_debt;
}

void print(std::vector<Student> students) { //принимает вектор из структур студентов
    if (students.empty()) std::cout << "Empty list!" << std::endl; // вывод при пустом векторе
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

int main()
{
    int cur_semester, max_debt, stud_count;
    std::cin >> stud_count >> cur_semester >> max_debt;
    std::cin.ignore(1);  // Убираем из потока символ \n для корректной работы getline 

    std::vector<Student> students(stud_count);
    for (auto& student : students) {
        std::string line;
        std::getline(std::cin, line);
        student = make_student(line);
    }

    std::vector<Student> expulsion_candidates;
    std::copy_if(students.begin(),
        students.end(),
        std::back_inserter(expulsion_candidates),
        [cur_semester, max_debt](const Student& student) {
            return is_debtor(student, cur_semester, max_debt);
        });

    std::sort(expulsion_candidates.begin(), expulsion_candidates.end(), is_upper);
    print(expulsion_candidates);
}

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int n, m; 
    
    std::cin >> n; // ввели размер массива, считали в первый массив последовательность
    std::vector <int> v1(n);
    for (int i = 0; i < n; ++i)
        std::cin >> v1[i];

    std::cin >> m;// ввели размер массива, считали вв второй массив последовательность
    std::vector <int> v2(m);
    for (int i = 0; i < m; ++i)
        std::cin >> v2[i];

    v1.insert(v1.end(), v2.begin(), v2.end()); // объеденили вектора

    sort(v1.begin(), v1.end());

    for (int j = 0; j < n + m; ++j) // вывели
        std::cout << v1[j] << " ";

}

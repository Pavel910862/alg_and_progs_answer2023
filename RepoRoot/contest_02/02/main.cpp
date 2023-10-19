#include <iostream>
#include <vector>
#include <string>
#include <queue> // очередь FIFO

// Функция, проверяющая, достижим ли выход из лабиринта из заданной точки старта, 
// получили на вход вектор со строками лабиринта и координаты положения точки
bool is_can_exit_from_maze(const std::vector<std::string>& maze, int row, int col)
{
    int rows = maze.size(); // в количество строк записали количество элементов массива
    int cols = maze[0].size(); // каждый размером по количеству столбуов

    // Создаем двумерный массив visited для отслеживания посещенных вершин
    // 
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // Создаем очередь для BFS (алгоритм поиска в ширину)
    std::queue<std::pair<int, int>> q; 

    // Добавляем точку старта в очередь и отмечаем ее как посещенную
    q.push({ row, col }); // координаты старта
    visited[row][col] = true; // в векторе для отслеживания посещенных вершин пометили элементы c индексами row и col что мы там были

    while (!q.empty()) // пока очередь не опустеет ( по принципу FIFO элементы вставляются сзади (end) и удаляются спереди)
    {
        int x = q.front().first; // в x - первый элемент пары
        int y = q.front().second; // в y - второй
        q.pop(); // удаляем элеиент по приципу LIFO

        // Проверяем, является ли текущая вершина выходом
        if (maze[x][y] == 'E')
        {
            return true;
        }

        // Добавляем смежные непосещенные вершины в очередь и отмечаем их как посещенные
        if (x > 0 && maze[x - 1][y] != '#' && !visited[x - 1][y]) // слева
        {
            q.push({ x - 1, y });
            visited[x - 1][y] = true;
        }
        if (x < rows - 1 && maze[x + 1][y] != '#' && !visited[x + 1][y]) // справа
        {
            q.push({ x + 1, y });
            visited[x + 1][y] = true;
        }
        if (y > 0 && maze[x][y - 1] != '#' && !visited[x][y - 1]) // сверху
        {
            q.push({ x, y - 1 });
            visited[x][y - 1] = true;
        }
        if (y < cols - 1 && maze[x][y + 1] != '#' && !visited[x][y + 1]) // снизу
        {
            q.push({ x, y + 1 });
            visited[x][y + 1] = true;
        }
    }

    return false;
}

int main() {
    int row, col, rows, cols;
    std::cin >> row >> col >> rows >> cols;
    std::cin.ignore(1); // Игнорируем перевод строки, застрявший в потоке ввода

    std::vector<std::string> maze(rows);
    for (auto& line : maze) std::getline(std::cin, line);

    std::cout << (is_can_exit_from_maze(maze, row, col) ? "YES" : "NO") << std::endl;
}

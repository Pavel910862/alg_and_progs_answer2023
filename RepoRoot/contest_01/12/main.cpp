#include <iostream>

int main() {
    
    using namespace std;

    int end_of_range; 
    cin >> end_of_range;
    int start = 1, right = 3, dx = 1, trans = 1;

    while (start <= end_of_range) {
        for (int i = 0; i < trans && start <= end_of_range; ++i)
            cout << start++ << ' ';
        cout << endl;
        trans += dx;
        if (trans < 1) {
            dx = 1;
            trans = 2;
            ++right;
        }
        else if (trans >= right) {
            dx = -1;
            trans -= 2;
        }
    }
}

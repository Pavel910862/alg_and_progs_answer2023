#include <iostream>
using namespace std;

int64_t w_vol(int64_t h[], int64_t n);

int main() {
    int max; cin >> max;
    int64_t* arr = new int64_t[max];
    int count = 0;

    while (count < max) {
        cin >> arr[count];
        ++count;
    }

    cout << w_vol(arr, max) << endl;
    return 0;
}

int64_t w_vol(int64_t h[], int64_t n) {
    int64_t wtr = 0;
    int64_t lvl = 0;
    int64_t lf = 0;
    int64_t rt = n - 1;

    while (lf < rt) {
        if (h[lf] < h[rt]) {
            lvl = max(h[lf], lvl);
            wtr += lvl - h[lf];
            ++lf;
        }
        else {
            lvl = max(h[rt], lvl);
            wtr += lvl - h[rt];
            --rt;
        }
    }
    return wtr;
}

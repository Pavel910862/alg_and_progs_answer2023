#include <iostream>
#include<cmath>
#include <iomanip>

int main()
{
    using namespace std;

    long double a, b, c;

    cin >> a;
    cin >> b;

    c = sqrt(pow(a, 2) + pow(b, 2));

    cout << setprecision(17) << c << endl;
}

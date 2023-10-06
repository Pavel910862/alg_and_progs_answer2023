#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    double a = sqrt(12);
    double b = 1;
    double c = b / (3 * 3);
    double d = b / (5 * pow(3, 2));
    double e = b / (7 * pow(3, 3));
    double f = b / (9 * pow(3, 4));
    double g = b / (11 * pow(3, 5));
    
    double pi = a * (b - c + d - e + f - g);

    cout << pi << endl;

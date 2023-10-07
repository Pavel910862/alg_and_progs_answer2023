#include <iostream>
#include<cmath>
#include <iomanip>

int main()
{
    using namespace std;

    int a, b, c, d1, d2;

    cin >> a >> b >> c;
    
    d1 = abs(c - a);
    d2 = abs(b - a);

    if (d1 > d2) cout << "B " << d2;
    else cout << "C " << d1;
}

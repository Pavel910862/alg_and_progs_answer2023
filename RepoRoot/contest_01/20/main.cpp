#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int64_t a, b; cin >> a >> b;
    string sa, sb;

    sa = to_string(a);
    sb = to_string(b);

    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    if (sa == sb) cout << "YES";
    else cout << "NO";
    
}

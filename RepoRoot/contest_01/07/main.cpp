#include <iostream>

int main(){
	
  using namespace std;
	
  int a, b;

  cin >> a >> b;
	if (a > b) cout << a << endl;
	else if (b > a) cout << b << endl;
	else cout << "Error!\n";
}

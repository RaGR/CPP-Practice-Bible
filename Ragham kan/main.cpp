#include <iostream>
#include <conio.h>
using namespace std;
int main() {
	int a , m = 1;
	cin >> a;
	while( a + 9 >= 10 ){
		cout <<" ragham "<< m <<":"<< a % 10 << endl;
		m++;
		a /= 10;
	}
	return 0;
}

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
	char ch;
	int t_A = 0, t_Star = 0, t_dot = 0;
	for(int i =1; i <= 100; i++){
		cin>>ch;
		switch (ch){
			case ('A'):
				t_A++;
				break;
			
			case ('*'):
				t_Star++;
				break;
				
			case ('.'):
				t_dot++;
				break;		
		}
	}
	cout<<"tedade 'A' : "<<t_A<<endl;
	cout<<"tedade '*' : "<<t_Star<<endl;
	cout<<"tedade '.' : "<<t_dot<<endl;
	getch ();
	return 0;
}

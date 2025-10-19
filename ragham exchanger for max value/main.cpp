#include <iostream>
#include <conio.h>
using namespace std;

void swipe(int &first, int &second){
	int swap = first;
	first = second;
	second = swap;
}


/*void revers_arr(int* &arr[10] ,int &lengh){
		int down_counter = 0 , upper_counter = lengh;
		while(down_counter <= upper_counter){
				swipe(arr[down_counter] , arr[upper_counter]);
				down_counter ++;
				upper_counter --;	
		}
}*/


int main() {
	int a , m = 0, new_Max, max_indext, swap;
	int ragham[100] = {0};
	int sorted[100] = {0}; 
	cin >> a;
	while(a+9 >= 10){
		cout <<" ragham "<< m + 1 <<":"<< a % 10 << endl;
		ragham[m] = a % 10;
		m++;
		a /= 10;
	}
	m--;
	cout << endl;
	for(int i = m; i >= 0; i--){
		new_Max = ragham[i];
		max_indext = i;
		for(int j = 0; j <= i; j++)
			if (ragham[j] >= new_Max){
				new_Max = ragham[j];
				max_indext = j;
			}
		swipe(ragham[max_indext] , ragham[i]);	
	}
	cout << "min value:";
	for(int i = 0; i <= m; i++)
		cout<<ragham[i];
	cout<< endl << "max value:";
	//revers_arr(ragham ,  m);
	int down_counter = 0 , upper_counter = m;
	while(down_counter <= upper_counter){
			swipe(ragham[down_counter] , ragham[upper_counter]);
			down_counter ++;
			upper_counter --;	
	}
	for(int i = 0; i <= m; i++)
		cout<<ragham[i];	
	return 0;
}

#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main() {
	int P, play = true , t=0;
	char winerindex;
	char H[9] = {'0' , '1' , '2' , 
				 '3' , '4' , '5' , 
				 '6' , '7' , '8'};			 
	//int point[9] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};		 
	while (play){
		t++;
		cout<< H[0] << "  |  " << H[1] << "  |  " << H[2] <<endl;
		cout<<"-------------"<<endl;
		cout<< H[3] << "  |  " << H[4] << "  |  " << H[5] <<endl;
		cout<<"-------------"<<endl;
		cout<< H[6] << "  |  " << H[7] << "  |  " << H[8] <<endl<<"================"<<endl;
		//if(t % 2 == 1)
			cin>>P;
		/*else{
			for(int i = 0; i < 9; i++)
				if (H[i] != 'X' && H[i] != 'O'){
					P = i;
					break;
				}	
		}*/
		cout<<endl;
		if(H[P] != 'X' && H[P] != 'O'){
			if(t % 2 == 0)
				H[P] = 'O';
			else	
				H[P] = 'X';
		}
		else{
			cout<<"column you enterd already occupied!, please enter an empty room. _TNX ;)"<<endl;
			t--;
		}
		if(H[0] == H[1] && H[1] == H[2]){
			winerindex = H[0];
			play = false;
		}
		if(H[3] == H[4] && H[4] == H[5]){
			winerindex = H[3];
			play = false;
		}
		if(H[6] == H[7] && H[7] == H[8]){
			winerindex = H[6];
			play = false;
		}
		if(H[0] == H[3] && H[3] == H[6]){
			winerindex = H[0];
			play = false;
		}
		if(H[1] == H[4] && H[4] == H[7]){
			winerindex = H[1];
			play = false;
		}
		if(H[2] == H[5] && H[5] == H[8]){
			winerindex = H[2];
			play = false;
		}
		if(H[0] == H[4] && H[4] == H[8]){
			winerindex = H[0];
			play = false;
		}
		if(H[2] == H[4] && H[4] == H[6]){
			winerindex = H[2];
			play = false;
		}	
	}
	cout<<winerindex<<" WON!";
	return 0;
}

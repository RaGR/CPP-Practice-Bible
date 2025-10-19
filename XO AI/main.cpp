#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;
int main() {
	
	int i = 0 , j = 0 , P , play = true , t=0;
	char winerindex;
	char H[9] = {'0' , '1' , '2' , 
				 '3' , '4' , '5' , 
				 '6' , '7' , '8'};			 
	int point[9] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
	int maxPoint, maxPoint_index;
		
			 
	while (play){
		t++;
		//print the board
		cout<< H[0] << "  |  " << H[1] << "  |  " << H[2] <<endl;
		cout<<"-------------"<<endl;
		cout<< H[3] << "  |  " << H[4] << "  |  " << H[5] <<endl;
		cout<<"-------------"<<endl;
		cout<< H[6] << "  |  " << H[7] << "  |  " << H[8] <<endl<<"================"<<endl<<endl;
		
		
		
		if(t % 2 == 1){
			cout << "YOUR TURN! => please select a colum    " ;  
			cin >> P;
		}
			
		if(t % 2 == 0){ //(AI part) _machine choosing
			cout<<"MY_TURN!=>";
			// corners(0,2,6,8) = 2pt, middle(4) = 3pt, another 'O' in winnig position = 1pt, 2 'o' in winnig pos = 1000, 2 'x' in winig position = 100pt(shure move)
			if(H[0] != 'X' && H[0] != 'O')
				point[0] += 2;
			if(H[2] != 'X' && H[2] != 'O')
				point[2] += 2;
			if(H[6] != 'X' && H[6] != 'O')
				point[6] += 2;
			if(H[8] != 'X' && H[8] != 'O')
				point[8] += 2;
				
			if(H[4] != 'X' && H[4] != 'O')
				point[4] += 3;	
			maxPoint = point[0];					  
			for(i = 0; i < 9; i++)
				if(point[i] >= maxPoint){
					maxPoint = point[i];
					maxPoint_index = i;
				}	
			P = maxPoint_index;
			maxPoint_index = 0;
			for(i = 0; i < 9; i++)
				point[i] = 0;
		} 
		cout<<endl;
		if(H[P] != 'X' && H[P] != 'O'){//apply the choice in boar
			if(t % 2 == 0)
				H[P] = 'O';
			else	
				H[P] = 'X';
		}
		else{
			cout<<"colum you enterd already occupied!, please enter an empty room. _TNX ;)"<<endl;
			t--;
		}
		
		
		
		//WIN checker
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

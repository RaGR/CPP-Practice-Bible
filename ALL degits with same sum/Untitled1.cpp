#include <bits/stdc++.h> 
#include <math.h>
using namespace std; 


int MAX = 0;
int MIN = 0;


void findNDigitNumsUtil(int , int , int&, int &, char* , int); 
void findNDigitNums(int , int);
  
int main() 
{ 
	int len , sum;
    cin >> len >> sum;
  
    findNDigitNums(len, sum); 
    cout << MIN << endl << MAX << endl;
  
    return 0; 
} 



void findNDigitNumsUtil(int n, int sum, int &max, int &min, char* out, int index) 
{ 

	int outNUM;
	
    // Base case 
    if (index > n || sum < 0) 
        return; 
 
    if (index == n) 
    { 

        if(sum == 0) 
        { 
            //out[index] = NULL;
            
            for (int i = 0; i < index; i++)
            	outNUM += ( (int)out[i] - '0' ) * pow(10 , i);
            
            cout << outNUM << endl;
            cout << out <<endl;
            if (outNUM > max)
            	max = outNUM;
            if (outNUM < min && min != 0)
            	min = outNUM;	
            //cout << out <<endl;
        } 
        return; 
    } 
  

    for (int i = 0; i <= 9; i++) 
    { 

        out[index] = i + '0'; 
  

        findNDigitNumsUtil(n, sum - i, ::MAX, ::MIN, out, index + 1); 
    } 
} 

void findNDigitNums(int n, int sum) 
{ 

    char out[n + 1]; 
  
    for (int i = 1; i <= 9; i++) 
    { 
        out[0] = i + '0'; 
        findNDigitNumsUtil(n, sum - i, MAX, MIN, out, 1); 
    } 
} 
  

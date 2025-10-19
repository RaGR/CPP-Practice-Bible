#include <iostream>
using namespace std;
struct Time{
  int start[5],end[5];	
};                  
int main()
{   
  Time T;
  int total=0;
  for(int i=0; i<5; i++)
    cin>>T.start[i]>>T.end[i];
  for(int i=0; i<5; i++)
  {
  	total+=T.end[i]-T.start[i];
  }  
  cout<<total;
  return 0;	
}



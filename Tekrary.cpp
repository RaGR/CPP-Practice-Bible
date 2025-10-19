#include <iostream>
using namespace std;
int main()
{
  int k=0,arr1[10],arr2[10];
  for(int i=0; i<10; i++)
    cin>>arr1[i];
  for(int i=0; i<10; i++)
    cin>>arr2[i];  
  for(int i=0; i<10; i++)
  {
  	k=0;
    for(int n=0; n<10; n++)
	  if(arr1[i]==arr2[n])
	    k++;
	if(k==0) 
	  cout<<arr1[i]<<endl;    
  }
  return 0;	
}

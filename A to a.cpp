#include <iostream>
using namespace std;
int main()
{
  int i=0,ch=0;	
  char world[50];
  cin>>world;
  while(world[i] != '\0')
    i++;
  for(int n=0; n<i; n++)
  {
  	ch=world[n];
  	if(ch>=97)
  	  ch = ch-32;
  	else if(ch<97)
	  ch = ch+32;  
	world[n]=(char)ch;  
  }		
  cout<<world;
  return 0;	
}

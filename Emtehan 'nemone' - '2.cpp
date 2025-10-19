#include <iostream>
using namespace std;
int main ()
{
  int a=0,b=0,i=0,j=0,m=0,n=0;
  cin>>a; 
  for (i=1;i<=a;i++)
  {
    if (a%i==0)
    {
      m=i;
      while (m>0)
      {
        b=m%10;
        m=m/10;
        if ( (b==5) || (b==7) ) n=1;
      } 
    } 
  }
  if (n==1) cout<<"Yes";
  else cout<<"No";
  return 0;
}

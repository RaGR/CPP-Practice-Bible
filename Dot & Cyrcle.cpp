#include <iostream>
using namespace std;
int main()
{
  float x,y,r,dx,dy,xtaf,ytaf;
  cin>>x>>y>>r>>dx>>dy;
  xtaf=x-dx;
  if(xtaf<0)
    xtaf=xtaf*-1;
  ytaf=y-dy;
  if(ytaf<0)
    ytaf=ytaf*-1;	
  if(ytaf<r && xtaf<r)
    cout<<"YES";
  else cout<<"NO";		  
  return 0;	
}

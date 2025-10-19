#include <iostream>
#include <string>
using namespace std;
struct P{
	string Name;
	int Hp,Wp;
};
int main()
{
  P g[100];	
  int k,h,w,num,m=-1,me[100];
  cin>>h>>w>>num;
  for(int i=0; i<num; i++)
  {
  	cin>>g[i].Name>>g[i].Hp>>g[i].Wp;
  	if(g[i].Hp>h && g[i].Wp<w)
  	{
  	  m++;
	  me[m]=i;	
  	}  
  }
  cout<<m+1<<endl;
  for(int i=0; i<=m; i++)
  {
  	k=me[i];
    cout<<g[k].Name<<endl;
  }
  return 0;	
}

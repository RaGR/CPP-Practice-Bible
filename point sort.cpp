#include <iostream>
using namespace std;
int main()
{
  int num[2][5],dev,sum,pos_min,temp,n;
  float avreg[5];
  for(int k=0; k<5; k++)//baraye 10 danesh amuz :|
  {
  	cout<<"danesh amuz=>"<<k+1<<endl<<"enter nomre ha"<<endl<<endl;
    for(int i=0; i<5; i++)
    {
      cout<<"nomre?"<<endl;	
      cin>>num[0][i];
	  cout<<"zarib?"<<endl;
	  cin>>num[1][i];
	  sum=sum+(num[1][i]*num[0][i]);
	  dev=dev+num[1][i];
	  cout<<endl;
    }
    avreg[k]=sum/dev;
  }
  for (int i=0; i < 4; i++)
  {
    pos_min = i;
	for (int j=i+1; j < 5; j++)
	{
	  if(avreg[j] < avreg[pos_min])
	    pos_min=j;
	}	
    if (pos_min != i)
    {
      temp = avreg[i];
      avreg[i] = avreg[pos_min];
      avreg[pos_min] = temp;
    }
  }  
  for(int i=0; i<5; i++)
    cout<<avreg[i]<<endl;
  return 0;	
}

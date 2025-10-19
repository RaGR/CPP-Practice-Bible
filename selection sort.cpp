#include <iostream>
using namespace std;
int main()
{
  int pos_min,temp,arr[10],n;
  cout<<"ba 5 adad:"<<endl;
  for (n=0; n < 5; n++)
    cin>>arr[n];
  for (int i=0; i < n-1; i++)
  {
    pos_min = i;
	for (int j=i+1; j < n; j++)
	{
	  if(arr[j] < arr[pos_min])
	    pos_min=j;
	}	
    if (pos_min != i)
    {
      temp = arr[i];
      arr[i] = arr[pos_min];
      arr[pos_min] = temp;
    }
  }
  cout<<"================================================"<<endl;
  for (int i=0; i < 5; i++)
    cout<<arr[i]<<" , ";
  return 0;
}

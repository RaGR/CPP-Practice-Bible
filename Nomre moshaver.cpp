#include <iostream>
using namespace std;
struct Stu{
    string name,obj;
	float math,fizik,shimi,mn;	
};	 
int main()
{
  Stu S[5];
  for(int i=0; i<5; i++)
  { 
    cin>>S[i].name>>S[i].math>>S[i].fizik>>S[i].shimi;
    S[i].mn=S[i].math;
    S[i].obj="riazi";
    if(S[i].mn>S[i].fizik)
    {
      S[i].mn=S[i].fizik;
      S[i].obj="fizik";
    }
    if(S[i].mn>S[i].shimi)
    {
      S[i].mn=S[i].shimi;
      S[i].obj="shimi";
    }
  }	
  for(int i=0; i<5; i++)
  	cout<<S[i].name<<" "<<S[i].obj<<" "<<S[i].mn<<endl;
  return 0;	
}

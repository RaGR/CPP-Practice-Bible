#include <iostream>
using namespace std;
int main ()
{
    int n,i,j,m=1,q=1,w;
    
    cin>>n;
    
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
        cout<<q;
        q++;
        if(q==10)
          q=1;
        }  
        cout<<endl;
        m=m+1;
    } 
    return 0;
}

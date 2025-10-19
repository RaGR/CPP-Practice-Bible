#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
    int a[10];
    cout<<"adad haye arraye?(khodesh sort mikone)"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-1;j++)
        {
            if(a[j+1]>a[j])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    
    cout<<"sorted: "<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl<<"search ?"<<endl; 
     
    int f;
    cin>>f;
    int start=0;
    int end=10-1;
    while(start<=end)        
    {
        int mid=(start+end)/2;
        if(a[mid]==f)
        {
            cout<<"found at "<<mid+1;
            break;
        }
        if(a[mid]<f)
            end=mid-1;
        else if(a[mid]>f)
            start=mid+1;
    }
    if(start>end)
        cout<<"NO"; 
}

#include <iostream>
using namespace std;
float inter(char a[])
{
  float fl=0,fi=0;
  int ch=0,k=1,ktemp=0,k1=0,k2=0,i=0,ret[25],ash[25];
  while(a[i]!='.' && a[i]!='\0')
  {
	ch=a[i];	
    ret[i]=ch-48;
    i++;
    ch=0;
  }   
  for(int n=0; n<i; n++)
    k=k*10;
  ret[i++]=10;
  i=0;
  while(ret[i]!=10)
  {
    fi+=ret[i]*k;
	i++;	
    k=k/10;	
  }
  k2=k2+i+1;
  if(a[i]=='.')
    while(a[k2]!='\0')
	{ 	
	  ch=a[k2];	  
	  ash[k1]=ch-48;
	  k1++;
	  k2++;
	  ch=0;
    }
  i=0;  
  k=1;
  ash[k1]=10;
  for(int n=0; n<k1; n++)
    k=k*10;  
  ktemp=k*10;  
  while(ash[i]!=10)
  {
    fl+=ash[i]*k;
	i++;	
    k=k/10;	
  }  
  fl=fl/ktemp;
  fi=fi/10;
  fi+=fl;
  return fi; 
}
int main()
{
  float no1=0,no2=0;	
  int k=0,i=0;
  char sing,full[50],num1[10],num2[10];
  cin>>full;
  while(full[i]>'/' || full[i]=='.')
  {
  	num1[i]=full[i];
  	i++;
  }	
  num1[i]='\0';
  sing=full[i++];
  i--;
  while(full[i]!='\0')
  {
  	i++;
  	num2[k]=full[i];
  	k++;
  }	
  no1=inter(num1);
  no2=inter(num2);
  if(sing=='+')
    cout<<no1+no2;
  if(sing=='-')
    cout<<no1-no2; 
  if(sing=='*')
    cout<<no1*no2;  
  if(sing=='/')
    cout<<(float)no1/no2;
  return 0; 
}

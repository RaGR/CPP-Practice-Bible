#include <string>
#include <fstream>
#include <iostream>
using namespace std;
struct Stu{
	string name,num;
	int no;
};

float inter(string a){
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
int main(){
  int k=0,s=0;
  float max=0;
  string call;
  Stu S[100]; 
  ifstream in("input.txt");
  ofstream out("output.txt");
  while(!in.eof()){
  	in>>call;
  	S[k].name=call;
  	in>>call;
  	S[k].num=call;
  	k++;
  }
  for(int i=0; i<k; i++)
    S[i].no=inter(S[i].num);
    
  for(int n=0; n<k; n++){
    for(int i=0; i<k; i++){
      if(S[i].no>max){
        max=S[i].no;	
        s=i;  	
      }   
    }
    out<<S[s].name<<" "<<S[s].num<<endl;
	S[s].no=0;
	max=0;  
  }
  out.flush();
  out.close();
  
  return 0;
}

#include <iostream>
using namespace std;
struct Stu{
	string name;
	float avg;
	Stu* link;
};

Stu pop(Stu* & top){
	Stu returnValio;
	returnValio.name=top->name;
	returnValio.avg=top->avg;
	returnValio.link=NULL;
	Stu* badTop = top->link;
	delete top;
	top=badTop;
}
void push(Stu s,Stu* & top)
{
	Stu* jadid= new Stu;
	jadid->name= s.name;
	jadid->avg= s.avg;
	jadid->link= top;
	top = jadid;
}
void print(Stu* top){
	while(top){
		cout<< endl << top->name<< endl << top->avg<< endl;
		top=top->link;
	}
}
Stu top(Stu* top){
	Stu topstu;
	topstu.name=top->name;
	topstu.avg=top->avg;
	topstu.link=NULL;
	
	return topstu;
}
Stu popIndex(Stu* top,int i){
	for(int n=0; n<=i-2; n++)
	{
	  top=top->link;
	  
	}
}
int main()
{
  Stu* s=new Stu;
  Stu* top;
  
  s->name="Ali";
  s->avg=20;
  s->link=NULL;
  
  top=s;
  
  for(int i=0; i<4; i++)
  {
    Stu tem;
	cin>>tem.name>>tem.avg;
	
	push(tem,top);
	cout<< endl<<"---------------------"<<endl;	
	print(top);
  }	
  return 0;	
}

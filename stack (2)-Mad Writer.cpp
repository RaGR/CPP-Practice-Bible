#include <iostream>
using namespace std;

struct TypeStu{
	string name;
	float avg;
	TypeStu* link;
};

TypeStu pop (TypeStu* & stacktop) {
	//Deghat konid be & k mizarim!
	TypeStu returnValue;
	returnValue.name = stacktop->name;
	returnValue.avg = stacktop->avg;
	returnValue.link = NULL;
	//chera?!

	TypeStu * afterStackTop = stacktop->link;
	delete stacktop;
	stacktop = afterStackTop;

	return returnValue;
}
void push(TypeStu s, TypeStu* & stacktop){
	//baz ham b & deghat konid
	TypeStu* jadid= new TypeStu;
	jadid->name = s.name;
	jadid->avg = s.avg;
	jadid->link = stacktop;
	stacktop = jadid;
}

TypeStu popIndex (TypeStu * & stacktop, int i) {
    TypeStu * tmpStack = new TypeStu;
    for (int j = 0; j < i; ++j) {
        TypeStu tmp;
        tmp = pop (stacktop);
        push(tmp, tmpStack);
    }
    TypeStu returnValue = pop (stacktop);
    for (int j = 0; j < i; ++j) {
        TypeStu tmp;
        tmp = pop (tmpStack);
        push(tmp, stacktop);
    }
    return returnValue;
}

void print(TypeStu* stacktop){
	TypeStu * tmp = stacktop;
	while (tmp) {
		cout << tmp->name << endl << tmp->avg << endl << endl;
		tmp = tmp->link;
	}
}
TypeStu top(TypeStu * stacktop){
	TypeStu topStu;
	topStu.name = stacktop -> name;
	topStu.avg = stacktop -> avg;
	topStu.link = NULL;

	return topStu;
}
int main() {
	TypeStu* s= new TypeStu;
	TypeStu* stacktop;
	int mod;
	
	s->name = "Ali";
	s->avg = 17.5;
	s->link = NULL;

	stacktop = s;

	for (int i = 0; i < 3; ++i)
	{
		TypeStu tmp;
		cin >> tmp.name;
		cin >> tmp.avg;

		push(tmp, stacktop);

		cout << endl << "-------------------" << endl;

		print(stacktop);
	}
	TypeStu poped = pop(stacktop);
	cout << "poped val = " << poped.name << endl;

	print (stacktop);
    
    poped = popIndex(stacktop, 1);
    cout << "poped value at index 1 was: " << poped.name << endl;
    
    print(stacktop);
	return 0;
}

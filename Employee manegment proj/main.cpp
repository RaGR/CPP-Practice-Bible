#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


class Time{
	public:
	int hours;  
	int minutes; 
	int seconds = 0;
	void setTime(int h, int m){
		hours = h;
		minutes = m;
	}
	void printTime(){
		cout << hours << ":" << minutes;
	}
};

void SubtractTime(Time t1, Time t2, Time *difference){
    
    if(t2.seconds > t1.seconds)
    {
        t1.minutes --;
        t1.seconds += 60;
    }

    difference->seconds = t1.seconds - t2.seconds;
    if(t2.minutes > t1.minutes)
    {
        t1.hours --;
        t1.minutes += 60;
    }
    difference->minutes = t1.minutes-t2.minutes;
    difference->hours = t1.hours-t2.hours;
}


bool isBiggerThan(Time t1 , Time t2){ //if (t1 > t2) -> returns true

	if (t1.hours < t2.hours)
		return false;
		
	if (t1.hours > t2.hours)
		return true;
		
		
	if (t1.hours == t2.hours){
		if ( t1.minutes > t2.minutes)
			return true;
		if ( t1.minutes < t2.minutes)
			return false;		
	}
	
}

class Employee{
	public:
	string name;
	Time BeginWorkTime , EndWorkTime; 
	Time TotalTime, LessTime , ExtraTime, delay;
	Time LglTime;
	int pay;
	
	void print(){
		cout << name << " begin at ";
		BeginWorkTime.printTime();
		cout << " to ";
		EndWorkTime.printTime();
		cout << " and has ";
		ExtraTime.printTime();
		cout << " extra time and ";
		delay.printTime();
		cout << " latency";
	}
};

Employee Eobj[10];
int lengh = 0;


vector<string> split(string str, char delimiter) {//masalan space be space joda kone mohtavaye string ro(baraye rahat khondan az .txt)
  vector<string> internal;
  stringstream ss(str); // string -> stream.
  string tok;
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  return internal;
}

Time START_OF_DAY , END_OF_DAY, MAX_EXTRA, StoE;

void getDATA(){
	
	ifstream inFile;
	char x;
	int i = 0;
	string line;
	inFile.open("DATA.txt");
	while ( getline (inFile,line) )
	{
  		vector<string> sep = split(line , ' ');
  		Eobj[i].name = sep[0];
  		istringstream(sep[1]) >> Eobj[i].BeginWorkTime.hours;
  		istringstream(sep[2]) >> Eobj[i].BeginWorkTime.minutes;
  		istringstream(sep[3]) >> Eobj[i].EndWorkTime.hours;
  		istringstream(sep[4]) >> Eobj[i].EndWorkTime.minutes;
  		i ++;
	}
	lengh = i;
	inFile.close();
	
}

void printDATA(){
	ifstream inFile;
	string line;
	inFile.open("DATA.txt");
	while ( getline (inFile,line) )
	{
		cout << line << "\n";
	}
	inFile.close();
}


void calculate(){
	for (int i = 0; i < lengh; i++){
		
		SubtractTime(Eobj[i].EndWorkTime, Eobj[i].BeginWorkTime, &Eobj[i].TotalTime);
		
		if ( isBiggerThan(Eobj[i].BeginWorkTime , START_OF_DAY))
				SubtractTime(Eobj[i].BeginWorkTime , START_OF_DAY, &Eobj[i].delay);

			
		if ( isBiggerThan(Eobj[i].EndWorkTime , END_OF_DAY) ){
			if (isBiggerThan( MAX_EXTRA , Eobj[i].EndWorkTime) )
		  		SubtractTime(Eobj[i].EndWorkTime, END_OF_DAY, &Eobj[i].ExtraTime);
		  	else Eobj[i].ExtraTime.setTime(4,0); // extra = max(20) - endOfDay(16) = 4 | aka SubtractTime(MAX_EXTRA, END_OF_DAY, &Eobj[i].ExtraTime)
		  	
			if ( isBiggerThan(Eobj[i].BeginWorkTime , START_OF_DAY))
				SubtractTime(Eobj[i].ExtraTime , Eobj[i].delay, &Eobj[i].ExtraTime);
	}
}
}
int main( ) {
	
	/****************************************************************************************/
	START_OF_DAY.setTime(7,30);
	END_OF_DAY.setTime(16,0);
	MAX_EXTRA.setTime(20,0);
	SubtractTime(END_OF_DAY, START_OF_DAY, &StoE); //meghdar saat haye ghanoni moshakhas mishe = 8:30
	/***************************************************************************************/
	
	getDATA();
	calculate();
	
	Eobj[0].print();
	cout << endl;
	Eobj[1].print();
	cout << endl; 
	
	return 0;
}

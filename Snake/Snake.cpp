#include <iostream>
#include <fstream> 
#include <string>
#include <conio.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>   
using namespace std;

struct Snake{
	int x_space=0,y_enter=0;
	bool visible=true;
};

void gotoxy(int x,int y){//Tu"dev c++",dastor"gotoxy(x,y)"nadarim =>>*az net gir ovordam!
    HANDLE hConsole = GetStdHandle ( STD_OUTPUT_HANDLE );
    if (INVALID_HANDLE_VALUE != hConsole)
    {
        COORD pos = {x, y};
        SetConsoleCursorPosition( hConsole, pos );
    }
} 
bool play(Snake S[20],Snake Wall[300],int lengh){//shart bakht
  bool play=true;
  for(int i=1; i<=lengh; i++)
    if(S[0].x_space==S[i].x_space && S[0].y_enter==S[i].y_enter)//kdordan be khodash
	  play=false;
  for(int i=0; i<300; i++)
    if(S[0].x_space==Wall[i].x_space && S[0].y_enter==Wall[i].y_enter)//khordan be divar
	  play=false;
  return play;   
}
bool foodv(Snake food,Snake wall[300]){//ghaza roye divar hast?*bool*
  bool foodv=false;//false-> roye divar nist
  for(int i=0; i<300; i++)
    if(food.x_space==wall[i].x_space && food.y_enter==wall[i].y_enter)//ghaza roye  divar
	  foodv=true;//true->roye divar
  return foodv;	  
}
bool feed(Snake f,Snake p){//ghaza khorde shode ya na?*bool*
  bool feed=false;
  if(p.x_space==f.x_space && p.y_enter==f.y_enter)
    feed=true;  
  return feed;
}
void show(Snake S[20],Snake Wall[300],Snake food,int score){//chap kardan safe	
  system("cls");//pack kardan safe
  for(int n=0; n<80; n++)//chap marr
    if(S[n].visible==true){
      gotoxy(S[n].x_space,S[n].y_enter);
      if(n==0)cout<<"X";
	  else cout<<"#";	  
    } 
  gotoxy(0,22);//chap emtiazz
  cout<<"score: "<<score;
   
  gotoxy(food.x_space,food.y_enter);
  cout<<"$";
  for(int i=0; i<300; i++){
 	gotoxy(Wall[i].x_space,Wall[i].y_enter);
    cout<<"#";
  } 
}


int main(){
	
  int score=0/*emtiaz*/,lengh=2/*tool mar*/,m=0,z=0;	
  char save='d'/*jahat harekat mar*/,ch='d';
  string  backgrund[22];	
  bool khit=true;		
  Snake p[80],n[80],wall[1760],food;
  ifstream map("map.txt");
      
  for(int y=0; y<22; y++)
    map>>backgrund[y];
  for(int y=0; y<22; y++)
    for(int x=0; x<80; x++)
	  if(backgrund[y][x]=='1'){
	  	wall[m].x_space=x;
	  	wall[m].y_enter=y;
	  	m++;
	  }
  m=0;	        	     	
  for(int i=79; i>=0; i--)
    p[i].y_enter=1;
  p[0].visible=true;
  p[0].x_space=1;
  
  srand((unsigned)time(0));
  while(foodv(food,wall)){
    food.x_space=(rand()%78)+1;
    food.y_enter=(rand()%20)+1;
  }
  show(p,wall,food,score);//keshidan mar
  		
  while(play(p,wall,lengh)){//hanoz nabakhte	
    for(int i=0; i<80; i++)
      n[i]=p[i];
    if(feed(food,p[0])){//ghaza khorde shode!
      score++;
	  lengh++; 
      do{
        food.x_space=(rand()%78)+1;
        food.y_enter=(rand()%20)+1;
      }while(foodv(food,wall));
    }
    if(kbhit()){
      khit=false;	
      ch=getch();
	  save=ch;//dar"save"->akharin key ke karbar zade ast 
	  	
      if(ch=='w')//UP
        p[0].y_enter=p[0].y_enter-1;	
      if(ch=='s')//Down
        p[0].y_enter=p[0].y_enter+1;
      if(ch=='a')//Left
        p[0].x_space=p[0].x_space-1;
      if(ch=='d')//Right  
        p[0].x_space=p[0].x_space+1;  
	}
	
	if(khit){	
	  if(save=='w')//UP
        p[0].y_enter=p[0].y_enter-1;	
      if(save=='s')//Down
        p[0].y_enter=p[0].y_enter+1;
      if(save=='a')//Left
        p[0].x_space=p[0].x_space-1;
      if(save=='d')//Right  
        p[0].x_space=p[0].x_space+1;
    }
    
    for(int i=1; i<80; i++)//Swap
	  p[i]=n[i-1];
	  
    for(int i=0; i<80; i++)//Andaze mar
	  p[i].visible=false;
	for(int i=0; i<lengh; i++)//Anadze mar
	 p[i].visible=true;   
	  
	cout.flush(); 
    usleep(1);//Takhir(Deley) 
    cout.flush(); 
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);
    usleep(1);

w
    if(play(p,wall,lengh))	
	  show(p,wall,food,score);
	khit=true;//key zade nashode	
  }
  
  system("cls");//pack kardan safe
  cout<<"sorry"<<endl<<"You lose....              Score:           You lose...."<<endl<<"                            "<<score;                                                                 
  return 0;	
}


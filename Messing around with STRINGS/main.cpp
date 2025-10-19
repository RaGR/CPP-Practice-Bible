#include <iostream>

using namespace std;


int main() {
		
	string str = "184 3 45";
	
	//spacing:
	string spacedstr = " ";
	spacedstr.resize(str.length() + 1);
	for (int i = 1; i <= str.length(); i++)
		spacedstr[i] = str[i - 1];
		
	int currentXd = 0, cellSTART, cellLength = 0, wk;
	
	int x = 3;
	
	
	
	for (int i = 0; i < spacedstr.length(); i++){
		
		if(spacedstr [i] == ' '){
			currentXd ++;
			if(currentXd == x){
				wk = i + 1;
				cellSTART = wk;
				while((spacedstr [wk] != ' ') && (wk <= spacedstr.length() - 1)){
					cellLength ++;
					wk ++;
				}
				break;
			}
		}
		
	}
	
	string cell;
	cell.resize (cellLength);
	for(int i = 0; i < cellLength; i++)
		cell[i] = spacedstr[i + cellSTART];
	cout << "'" << cell << "'";		
	
	/*end*/
	return 0;
}

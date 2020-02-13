#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(){
ifstream ifs;
ifs.open("words.txt");
string each_word;
string userInput;
int occurInt = 0; //important to assign to 0
int flag;
char each_char;

cin >> userInput;

while(ifs>>each_word){
flag = 1;

for(int i = 0; i < userInput.length(); i++){
if(!(tolower(each_word[i]) == tolower(userInput[i]))){

flag = 0;
break;
}
}
if(flag == 1)
occurInt++;
}

cout << occurInt <<endl;
return 0;
}

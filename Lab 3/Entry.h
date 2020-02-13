#include <iostream>
#include <string>
using namespace std;




struct Entry{
string name;
string lastName;
string email;
//string print;
void setName(const string fName){
name = fName;
}
void setLastname(const string lName){

lastName = lName;
}
void setEmail(const string pEmail){
email = pEmail;
}
void print(){
cout << "First Name: " << name << endl;
cout << "Last Name: " << lastName << endl;
cout << "Email: " << email << endl;
}

};

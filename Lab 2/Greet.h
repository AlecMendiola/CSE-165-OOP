#ifndef Greet_h
#define Greet_h
// We should include <string> here
#include <string>

using namespace std;

typedef void (*callback_function)(string);

void greet(string name, callback_function greet){

greet(name);
}
// Implement your "greet" function below


#endif /* Greet_h */

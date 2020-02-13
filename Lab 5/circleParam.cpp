#include <iostream>
#include <vector>
#include <cmath>
#include "GenerateCircleData.h"

using namespace std;


int main() {
    // A vector of Vec pointers to hold the data
    vector<Vec*> data;
    
    // Generate the data
    // Unit circle at the origin, with resolution 10
    generateCircleData(data, Vec(0,0), 1, 10);
    
    // Print out the vertex coordinates
    for (vector<Vec*>::iterator i = data.begin(); i != data.end(); i++) {
        cout << "(" << (*i)->getX() << ", " << (*i)->getY() << ")" << endl;
    }
 
    // Free up the memory that we have used
    for (vector<Vec*>::iterator i = data.begin(); i != data.end(); i++) {
        delete *i;
    }
    
    return 0;
}

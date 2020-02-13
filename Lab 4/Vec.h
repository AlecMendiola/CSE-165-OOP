#include <iostream>

using namespace std;

class Vec {

public:
    float x;
    float y;

    const static Vec null;

    Vec(){
    x=y=0.0f;

    }

    Vec(float x1, float y1){
    x = x1;
    y = y1;

    }



    void setX(int x1){

x = x1;
    }
    void setY(int y1){
y = y1;
    }
float getX() const{

return x;
}



float getY() const{

return y;
}



    void add(Vec v){
    x += v.x;
    y += v.y;


    }

    void print(){

    cout << "(" << x << "," << y << ")";



    }





};

const Vec Vec::null(0.0f,0.0f);




/*
Instructions

Design a 2D vector class called Vec. This class should contain two float data members x, and y, a default constructor, a constructor from two coordinates, an add method, and appropriate getters and setters.

Your Vec class should allow the following vectors.cpp file to run without generating any error messages.
Instructions

Design a 2D vector class called Vec. This class should contain two float data members x, and y, a default constructor, a constructor from two coordinates, an add method, and appropriate getters and setters.

Your Vec class should allow the following vectors.cpp file to run without generating any error messages.

You are specifically not told what file to upload, but you can figure out what it must be, by reading the vectors.cpp file.
You are specifically not told what file to upload, but you can figure out what it must be, by reading the vectors.cpp file.
*/

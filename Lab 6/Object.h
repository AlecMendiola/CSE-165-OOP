#ifndef Object_h
#define Object_h


#include <iostream>


class Object {
int data;


public:
    static int count;

    Object(){
    data = 0;
    count++;

    }


    Object(const Object &someObject){

    count++;

    }







};








#endif // Object_h

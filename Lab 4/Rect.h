#include <iostream>
#include "Vec.h"

struct Rect {
float x;
float y;
float width;
float height;

Rect(float x1, float y1, float w1, float h1){
x = x1;
y = y1;
width = w1;
height = h1;


}


int contains (Vec v){
int success = 0;

if ((v.x <= width - x) && (v.y <= 1 + y))
    success = 1;
return success;



}







};



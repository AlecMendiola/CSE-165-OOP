//
//  Rect.hpp
//  glutapp
//
//  Created by Alec Mendiola on 2/23/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#ifndef Rect_hpp
#define Rect_hpp

#include <iostream>
#include <stdio.h>
#include "GlutApp.h"


class Rect {
private:
    float x,y,w,h;
public:
    bool color;
    
    Rect(){
        x=0; y=0; w=0; h=0;
    }
    
    Rect(float x, float y, float w, float h){
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
        color = false;
    }
    
    
    void build(){
        if(color == true){
            glColor3f(0.0,1.0,0.0); 
        }
        else {
            glColor3f(1.0, 1.0, 1.0); 
        }
        glBegin(GL_POLYGON);
        glVertex2f(x, y);
        glVertex2f(x, y-h);
        glVertex2f(x+w,y-h);
        glVertex2f(x+w, y);
        glEnd();
        
    }
    
    bool contains(float x, float y){
        if(x>=this->x && x<=(this->x+w) && y <= this->y && y>=(this->y-h))
            return true;
        else {
            return false;
        }
    }
    ~Rect();
};

#endif /* Rect_hpp */

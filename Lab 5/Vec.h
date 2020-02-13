#ifndef Vec_h
#define Vec_h

class Vec {
    float x;
    float y;
    
public:
    Vec (){
        x = 0;
        y = 0;
    }
    
    Vec (double x, double y){
        this->x = x;
        this->y = y;
    }
    
    void add (Vec u){
        x += u.x;
        y += u.y;
    }
    
    float getX() const {
        return x;
    }
    
    float getY() const {
        return y;
    }
    
    void setX(float x) {
        this->x = x;
    }
    
    void setY(float y) {
        this->y = y;
    }
    
};

#endif


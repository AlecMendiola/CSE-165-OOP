#ifndef Circle_h
#define Circle_h


class Circle {

private:
    double x;
    double y;
    //double r = 1;
    double r;






public:
    //double area = 3.14159 * r * r;
    double area;


    Circle(){
    x = 0;
    y = 0;
    r = 1;
area = 3.14159 * r * r;


    }


    Circle (double x1, double y1, double r1){
x = x1;
y = y1;
r = r1;


    }
    void setX(double x1){
    x = x1;

    }
        void setY(double y1){
    y = y1;

    }
        void setR(double r1){
    r = r1;
    area = 3.14159 * r * r;

    }

    int getX(){
    return x;
    }
    int getY(){
    return y;
    }

    int getR(){
    return r;
    }


   // double area

//double area = 3.14159;



};






#endif // Circle_h

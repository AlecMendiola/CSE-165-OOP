#ifndef Generic_h
#define Generic_h

class Generic {
    int data;

public:
    static int count;
    Generic() {
        data = 0;
        count++;
    }

    Generic(int d) {
        data = d;
        count++;
    }
};



int Generic::count = 0;
#endif

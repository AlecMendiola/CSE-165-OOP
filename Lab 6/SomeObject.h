#ifndef SomeObject_h
#define SomeObject_h

class SomeObject {
    int data;

public:
    SomeObject() {
        data = 0;
    }

    SomeObject(int d) {
        data = d;
    }

    int getData() const{
        return data;
    }

    void setData (int d) {
        data = d;
    }
};

#endif

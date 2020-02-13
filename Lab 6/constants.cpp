#include <iostream>
#include "SomeObject.h"

using namespace std;

int getData(const SomeObject& x){
    return x.getData();
}

int main(int argc, const char * argv[]) {
    int num = getData(SomeObject(53));
    
    cout << num << endl;
    
    return 0;
}

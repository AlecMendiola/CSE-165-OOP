#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include <iostream>
#include "Rect.h"
#include <vector>
#include "Vec.h"

using namespace std;

class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
public:
	vector<Rect *> rVec;
	vector<Vec *> pPos;


    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);
	//void print(bool x);
	int checkVict(int dA[]);
	int addSquare(int a);
	int three(int a, int b, int c);


	bool singlePlayer = true;
	bool gameEnd = false;
	int displayArr[9];
	int playerArr[9];
	int playerTurn = 1;


};

#endif

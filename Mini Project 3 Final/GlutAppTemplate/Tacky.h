#ifndef Tacky_h
#define Tacky_h

#include <vector>
#include "GlutApp.h"
#include "Circle.h"

using namespace std;

class Tacky {

private:
	bool circle = false;


public:
	vector<Vec*> info;
	Tacky(bool circle, Vec * v, int victory) {

		info.clear();

		glClearColor(0.0, 0.0, 0.0, 1.0);

		if (victory)
			glColor3f(0.0, 1.0, 0.0);

		else
			glColor3f(1.0, 1.0, 1.0);
		glLineWidth(50);

		//makes circle

		if (circle) {
			generateCircleData(info, *v, .23, 100);
			glBegin(GL_LINE_STRIP);
	for (int i = 0; i < info.size()-1; i++) {
glVertex2f(info[i]->getX(), info[i]->getY());


			}
			glEnd();
		}


		//makes x
		else {
			float dis = 0.2;
			glBegin(GL_LINE_STRIP);
			glVertex2f(v->getX() - dis, v->getY() - dis);
			glVertex2f(v->getX() + dis, v->getY() + dis);
			glEnd(); 
			glBegin(GL_LINE_STRIP);
			glVertex2f(v->getX() - dis, v->getY() + dis);
			glVertex2f(v->getX() + dis, v->getY() - dis);
			glEnd();
		} 




	}

};



#endif

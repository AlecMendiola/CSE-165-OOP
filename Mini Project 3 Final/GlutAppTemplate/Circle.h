#ifndef Circle_h
#define Circle_h
#define _USE_MATH_DEFINES
#include "Vec.h"
#include <vector>


#include <math.h>

using namespace std;

void generateCircleData(vector<Vec*>& points, Vec& center, float radius, int resolution){

	points.clear();


	Vec * temp;

	for (int i = -1; i < 360; i++) {

		double xCoord = center.getX() + cos(i) * radius ;
		double yCoord = center.getY() + sin(i) * radius ;

		temp = new Vec(xCoord, yCoord);
		points.push_back(temp);



	}

	delete temp;


}

#endif
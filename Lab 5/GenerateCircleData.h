#ifndef GenerateCircleData_h
#define GenerateCircleData_h

#include "Vec.h"

void generateCircleData(std::vector<Vec*>& points, const Vec& center, float radius, int resolution){
    // Clear the points vector to make sure it's empty before you start
    points.clear();

    // Provide the rest of the code here...
    	for (double i = 0; i < 2*M_PI; i += 2*M_PI/resolution) {

        double xVal = center.getX() + radius*cos(i);

        double yVal = center.getY() + radius*sin(i);

        points.push_back(new Vec(xVal, yVal));

    	}

}

#endif

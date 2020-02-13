#ifndef TexRect_h
#define TexRect_h

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include "RgbImage.h"


class TexRect {
    float x;
    float y;
    float w;
    float h;
	
	
    GLuint texture_id;
	GLuint texture_id1;
    int rows;
    int cols;
    
    int curr_row;
    int curr_col;
    
    bool complete;
public:
    TexRect (const char*, const char*, int, int, float, float, float, float);
    
    bool done();
    
    void draw();
    
    void advance();
    
    void incY();

	void setMush(bool);
	


	bool rectContains(float, float);
    
    void reset();


};

#endif

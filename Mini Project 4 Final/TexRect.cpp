#include "TexRect.hpp"




bool mush = true;



TexRect::TexRect (const char* filename, const char* filename1,int rows, int cols, float x=0, float y=0, float w=0.5, float h=0.5){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
	RgbImage theTexMap(filename);

	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap.GetNumCols(), theTexMap.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData());
	this->texture_id = texture_id;


	//for fireballs, yum ^

	//For mushroom
	
	RgbImage theTexMap1(filename1);

	glGenTextures(1, &texture_id1);
	glBindTexture(GL_TEXTURE_2D, texture_id1);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, theTexMap1.GetNumCols(), theTexMap1.GetNumRows(),
		GL_RGB, GL_UNSIGNED_BYTE, theTexMap1.ImageData());
	this->texture_id1 = texture_id1;
    
    this->rows = rows;
    this->cols = cols;
    
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    curr_row = 1;
    curr_col = 1;
    
    complete = false;
}

bool TexRect::done() {
    return complete;
}


void TexRect::draw(){
	if (mush) {


		glBindTexture(GL_TEXTURE_2D, texture_id1);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		glBegin(GL_QUADS);

		glTexCoord2f(0, 0);
		glVertex2f(x, y - h);

		glTexCoord2f(0, 1);
		glVertex2f(x, y);

		glTexCoord2f(1, 1);
		glVertex2f(x + w, y);

		glTexCoord2f(1, 0);
		glVertex2f(x + w, y - h);

		glEnd();

	}
	else {
		glBindTexture(GL_TEXTURE_2D, texture_id);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


		float xinc = 1.0 / cols;
		float yinc = 1.0 / rows;


		float top = 1 - yinc * (curr_row - 1);
		float bottom = 1 - yinc * curr_row;

		float left = xinc * (curr_col - 1);
		float right = xinc * curr_col;


		glBegin(GL_QUADS);

		glTexCoord2f(left, bottom);
		glVertex2f(x, y - h);

		glTexCoord2f(left, top);
		glVertex2f(x, y);

		glTexCoord2f(right, top);
		glVertex2f(x + w, y);

		glTexCoord2f(right, bottom);
		glVertex2f(x + w, y - h);

		glEnd();

		glDisable(GL_TEXTURE_2D);
	}
}

void TexRect::incY(){
    y+=0.01;
}

void TexRect::advance(){
    if (curr_col < cols){
        curr_col++;
    }
    else {
        if (curr_row < rows){
            curr_row++;
            curr_col = 1;
        }
        else{
            curr_row = 1;
            curr_col = 1;
        }
    }
    
    if (curr_row == rows && curr_col == cols){
        complete = true;
    }
}



void TexRect::reset(){
    complete = false;
}

void TexRect::setMush(bool mushy) {
	mush = mushy;
}

bool TexRect::rectContains(float x, float y) {
	if (x >= this->x && x <= (this->x + w) && y <= this->y && y >= (this->y - h))
		return true;
	else {
		return false;
	}
}




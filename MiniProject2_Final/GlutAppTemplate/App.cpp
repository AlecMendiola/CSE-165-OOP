#include "App.h"

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables
	mx = 0.0;
	my = 0.0;

	r1 = new Rect(.6, .6, .2, .2);
	r2 = new Rect(.3, .3, .1, .1);
	
}

void App::draw() {

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Set Color
	glColor3d(1.0, 1.0, 1.0);

	r1->build();
	r2->build();

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}
void App::recContains(Rect * r, float x, float y) {
	if (r->contains(x, y)) {
		r->color = true;
		r->build();
	}
	else
		r->color = false;
}

void App::mouseDown(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	recContains(r1, x, y);
	recContains(r2, x, y);
	

	// Redraw the scene
	redraw();
}

void App::mouseDrag(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::keyPress(unsigned char key) {
	if (key == 27) {
		// Exit the app when Esc key is pressed
		exit(0);
	}
}

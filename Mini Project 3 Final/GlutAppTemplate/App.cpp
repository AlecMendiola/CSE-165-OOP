#include "App.h"
#include <iostream>
#include <vector>
#include "Tacky.h"

using namespace std;



App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;

	for (int i = 0; i < 9; i++) { 
		displayArr[i] = 0; 
	}
	for (int i = 0; i < 9; i++) { 
		playerArr[i] = 1; 
	}
	



	rVec.push_back(new Rect(-1, 1, .6, .6)); // 1
	rVec.push_back(new Rect(-.3, 1, .6, .6)); // 2
	rVec.push_back(new Rect(.4, 1, .6, .6)); // 3

	rVec.push_back(new Rect(-1, .3, .6, .6)); // 4
	rVec.push_back(new Rect(-.3, .3, .6, .6)); // 5
	rVec.push_back(new Rect(.4, .3, .6, .6)); // 6

	rVec.push_back(new Rect(-1, -.4, .6, .6)); // 7
	rVec.push_back(new Rect(-.3, -.4, .6, .6)); // 8
	rVec.push_back(new Rect(.4, -.4, .6, .6)); // 9


	pPos.push_back(new Vec(-.7, .7)); // 1
	pPos.push_back(new Vec(0, .7)); // 2
	pPos.push_back(new Vec(.7, .7)); // 3

	pPos.push_back(new Vec(-.7, 0)); // 4
	pPos.push_back(new Vec(0, 0)); // 5
	pPos.push_back(new Vec(.7, 0)); // 6

	pPos.push_back(new Vec(-.7, -.7)); // 7
	pPos.push_back(new Vec(0, -.7)); // 8
	pPos.push_back(new Vec(.7, -.7)); // 9




}







void defaultRect(float x, float y, float w, float h) {


	glColor3d(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x, y - h);
	glVertex2f(x + w, y - h);
	glVertex2f(x + w, y);
	glEnd();

}




int App::addSquare(int a) {
	int magSq[9] = { 8,1,6,3,5,7,4,9,2 };
	return displayArr[a] * magSq[a];
}




int App::three(int a, int b, int c) {
	int sum = 0;
	sum = addSquare(a) + addSquare(b) + addSquare(c);
	if (sum == 15) {
		displayArr[a] = 3; displayArr[b] = 3; displayArr[c] = 3;
		return 1;
	}

	if (sum == 30) {
		displayArr[a] = 4; displayArr[b] = 4; displayArr[c] = 4;
			return 2;
	}
	return 0;
}

int App::checkVict(int dA[]) {
	if (gameEnd) return 0;

	int returnedVal = 0;
	
	for (int i = 0; i < 10; i += 3)
		if (!returnedVal)
			returnedVal = three(i, i + 1, i + 2);

	for (int i = 0; i < 10; i++)
		if (!returnedVal)
			returnedVal = three(i, i + 3,i + 6);

	if (!returnedVal) 
		returnedVal = three(0, 4, 8);
	if (!returnedVal) 
		returnedVal = three(2, 4, 6);


	return returnedVal;
}







void App::draw() {



    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    */
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    
	//color of the gameboard
	glColor3f(1.0, 1.0, 1.0);

	//gameboard composition
	//first 2 vertical lines
	defaultRect(-.4, 1, .1, 2);
	defaultRect(.3, 1, .1, 2);
	//last 2 horizontal lines
	defaultRect(-1, .4, 2, .1);
	defaultRect(-1, -.3, 2, .1);




	printf("displayArr[] {");

	for (int j = 0; j < 9; j++) {

		printf("%d, ", displayArr[j]);
	}

	printf("}\n");


	if (!(pPos.empty())) {

		for (int n = 0; n < 9; n++) {

			if (displayArr[n] == 1) {

				Tacky(0, pPos[n], 0);
				//this draws the x
			}
			
			
			if (displayArr[n] == 2) {
				Tacky(1, pPos[n], 0);
				//this draws the O
			}

			//endstate colors
			
			if (displayArr[n] == 3) {
				Tacky(0, pPos[n], 1);
				//break;
			}
			//green x

			if (displayArr[n] == 4) {
				Tacky(1, pPos[n], 1);
				//break;
			}
			//green o



		}





	}


	int winState = checkVict(displayArr);

	if (winState != 0 && gameEnd == false) {
		printf("%d wins! \n", winState);

		gameEnd = true;

		redraw();
	}


	for (int b = 0; b < rVec.size(); b++)
		rVec[b]->create();



    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;

	for (int i = 0; i < 9; i++){


		if (!singlePlayer) {

			if (rVec[i]->includes(x, y) && !gameEnd) {

				if (playerTurn && playerArr[i] == 1) {
					printf("We're on rVec[%d]\n", i);
					displayArr[i] = 1;
				}
				else if (!playerTurn && playerArr[i] == 1) {
					displayArr[i] = 2;
				}
				playerArr[i] = 0;
				playerTurn = !playerTurn;
			}
		}

		//with the AI

		if (singlePlayer) {
			if (rVec[i]->includes(x, y) && !gameEnd && playerArr[i] == 1) {
					displayArr[i] = 1;
				playerArr[i] = 0;



				int count = 0;

				for (int k = 0; k < 9; k++) {
					if (playerArr[k] == 1)
						count++;
				}

				if (count > 1) {
					for (int k = 0; k < 9; k++) {
						if (playerArr[k] == 1 && rand() % 2 == 0) {


							displayArr[k] = 2;
							playerArr[k] = 0;
							break;
						}

						if (playerArr[8] == 0 && k == 8) {
							displayArr[8] = 2;
							playerArr[8] = 0;
						}

					}
				}


			}
		}



	}










    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}




void App::keyPress(unsigned char key) {
    if (key == 27){
		singlePlayer = !singlePlayer;
        // Exit the app when Esc key is pressed
      exit(0);
    }
}




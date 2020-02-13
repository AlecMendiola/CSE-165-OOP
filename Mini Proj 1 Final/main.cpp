

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */


void appDrawScene(){ //from line 29 to 139
glClear( GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(2.0, 2.0); //x1, y1 //2,2
  glVertex2f(10.0, 2.0); //x2, y1 //10, 2
  glVertex2f(10.0, 80.0); //x2, y2 //10, 80
  glVertex2f(2.0, 80.0); //x1, y2 //2, 80
 glEnd();

  glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(10.0, 2.0);
  glVertex2f(60.0, 2.0);
  glVertex2f(60.0, 10.0);
  glVertex2f(2.0, 10.0);
 glEnd();

   glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(60.0, 2.0);
  glVertex2f(68.0, 2.0);
  glVertex2f(68.0, 80.0);
  glVertex2f(60.0, 80.0);
 glEnd();

    glColor3f(0.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(2.0, 40.0);
  glVertex2f(60.0, 40.0);
  glVertex2f(60.0, 45.0);
  glVertex2f(2.0, 45.0);
 glEnd(); //middle of A

     glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(80.0, 2.0);
  glVertex2f(88.0, 2.0);
  glVertex2f(88.0, 80.0);
  glVertex2f(80.0, 80.0);
 glEnd();

      glColor3f(1.0, 0.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(80.0, 75.0);
  glVertex2f(120.0, 75.0);
  glVertex2f(120.0, 80.0);
  glVertex2f(80.0, 80.0);
 glEnd();

       glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_POLYGON);
  glVertex2f(140.0, 2.0);
  glVertex2f(148.0, 2.0);
  glVertex2f(148.0, 80.0);
  glVertex2f(140.0, 80.0);
 glEnd();

    glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_POLYGON);
  glVertex2f(140.0, 2.0);
  glVertex2f(180.0, 2.0);
  glVertex2f(180.0, 7.0);
  glVertex2f(140.0, 7.0);
 glEnd();

        glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_POLYGON);
  glVertex2f(140.0, 75.0);
  glVertex2f(180.0, 75.0);
  glVertex2f(180.0, 80.0);
  glVertex2f(140.0, 80.0);
 glEnd();

        glColor3f(0.0, 0.0, 1.0);
 glBegin(GL_POLYGON);
  glVertex2f(140.0, 35.0);
  glVertex2f(180.0, 35.0);
  glVertex2f(180.0, 40.0);
  glVertex2f(140.0, 40.0);
 glEnd();

         glColor3f(1.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(200.0, 2.0);
  glVertex2f(208.0, 2.0);
  glVertex2f(208.0, 80.0);
  glVertex2f(200.0, 80.0);
 glEnd();

          glColor3f(1.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(200.0, 2.0);
  glVertex2f(240.0, 2.0);
  glVertex2f(240.0, 7.0);
  glVertex2f(200.0, 7.0);
 glEnd();

           glColor3f(1.0, 1.0, 0.0);
 glBegin(GL_POLYGON);
  glVertex2f(200.0, 75.0);
  glVertex2f(240.0, 75.0);
  glVertex2f(240.0, 80.0);
  glVertex2f(200.0, 80.0);
 glEnd();




 glFlush();
glutSwapBuffers();
}








int main (int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

glutInitWindowPosition( 20, 60 );
glutInitWindowSize( 640, 640 );
glutCreateWindow( "it me name!" );

glMatrixMode ( GL_PROJECTION );
glLoadIdentity ();
glOrtho ( 0, 640, 640, 0, -1, 1 );






glutDisplayFunc(appDrawScene);


glutMainLoop();
}

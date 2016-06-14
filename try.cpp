#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int is_depth=1;

GLuint theTorus;
void init() {
   
 if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
	
}
GLUquadricObj *quadratic;
void display(void){   
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glMatrixMode(GL_MODELVIEW);
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_LINE);
	gluQuadricOrientation(quadratic, GLU_OUTSIDE);
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    
	glBegin(GL_LINES);
    	gluDisk(quadratic, 0.4f, 0.7f, 15, 15);
		gluCylinder(quadratic, 0.7f,0.7f, 1.3f, 15, 15);
	glEnd();
	glutSwapBuffers();
} 

int main(int argc,char* argv[]){
	glutInit(&argc, argv); 
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (700, 700);
	glutInitWindowPosition (100, 100); 
	glutCreateWindow (argv[0]); 
	init (); 
	glutDisplayFunc(display); 
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,1,10);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0,5.0,6.0,-2.0,2.0,-3.0,-10.0,-15.0,2.0);
	//glutReshapeFunc(reshape);
	//glutKeyboardFunc(keyboard); 
	glutMainLoop(); 
	return 0;
}

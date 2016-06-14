/*#include <GL/gl.h>
#include <GL/glu.h>*/
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



#ifndef CALLBACK
#define CALLBACK
#endif

#define BASE 1.0f
#define BODY_LENGTH BASE*1.0f
#define BODY_RADIUS BASE*0.3f
#define LEG_UPPER_LENGTH BASE*0.65f
#define LEG_LOWER_LENGTH BASE*0.4f
#define LEG_RADIUS BASE*0.06f
#define NECK_LENGTH BASE*0.65f
#define NECK_RADIUS 0.06f
#define HEAD_LENGTH BASE*0.4f
#define HEAD_RADIUS BASE*0.15f
#define SLICES 10
#define STACKS 10

int is_depth = 1;
float m_neck_angle=45.0f;
float m_head_angle=90.0f;
int movePos=0;
int front_left_leg[2]={0,0};
int front_right_leg[2]={0,0};
int back_left_leg[2]={0,0};
int back_right_leg[2]={0,0};

GLfloat gAngle=90.0;

void drawClosedCylinder(GLUquadricObj *q,float r1,float r2,float l){
	glBegin(GL_LINES);
	glPushMatrix();
		gluDisk(q, 0.0f, r1, SLICES, STACKS);
		gluCylinder(q, r1, r2, l, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,l);
		gluDisk(q, 0.0f, r2, SLICES, STACKS);
	glPopMatrix();
	glEnd();
}

void drawAleg(GLUquadricObj *q,int* v){
	glBegin(GL_LINES);
	glPushMatrix();
		glRotatef(180.0f+v[0], 0.0f, 1.0f, 0.0f);
    	drawClosedCylinder(q,LEG_RADIUS,LEG_RADIUS, LEG_UPPER_LENGTH);
    	glTranslatef(0.0f, 0.0f, LEG_UPPER_LENGTH);
    	glRotatef(v[1], 0.0f, 1.0f, 0.0f);
    	drawClosedCylinder(q,LEG_RADIUS,LEG_RADIUS, LEG_LOWER_LENGTH);
    glPopMatrix();
    glEnd();
}
GLuint startList ;	

void drawAnimal(){
	GLUquadricObj *quadratic; 
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_LINE);
	gluQuadricOrientation(quadratic, GLU_OUTSIDE);
    gluQuadricNormals(quadratic, GLU_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();	
    //glBegin(GL_LINES);
    glNewList(startList, GL_COMPILE);
    //Body
    //glPushMatrix();
    	glColor3f(0.05f, 0.09f, 0.77f);
    	glTranslatef(-BODY_LENGTH/2.0f, 00.0f, 00.0f);
    	//glRotatef(150.0f, 0.0f, 0.0f, 1.0f);
    	glRotatef(40.0f, 1.0f, 1.0f, 1.0f);
    	//glutWireTeapot(10);
    	gluCylinder(quadratic, BODY_RADIUS,BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    	//glTranslatef(-BODY_LENGTH/2.0f, 00.0f, 00.0f);
    	//glRotatef(137.0f, 0.0f, 0.0f, 1.0f);
    	
    	//glutSolidCube(5);
    	//drawClosedCylinder(quadratic,BODY_RADIUS,BODY_RADIUS, BODY_LENGTH);
    //glPopMatrix();

    // //Head
    // glPushMatrix();
    // 	glTranslatef(BODY_LENGTH*0.45f, 0.0f, BODY_RADIUS*0.1f);
    // 	glRotatef(m_neck_angle, 0.0f, 1.0f, 0.0f);
    // 	drawClosedCylinder(quadratic,NECK_RADIUS,NECK_RADIUS, NECK_LENGTH);
    // 	glTranslatef(0.0f, 0.0f, NECK_LENGTH);
    // 	glRotatef(m_head_angle, 0.0f, 1.0f, 0.0f);
    //     glTranslatef(0.0f, 0.0f, -HEAD_LENGTH*0.3f);
    //     drawClosedCylinder(quadratic,HEAD_RADIUS,HEAD_RADIUS, HEAD_LENGTH);
    // glPopMatrix();

    // //Left Front Leg
    // glPushMatrix();
    // 	glTranslatef(BODY_LENGTH*0.3f,BODY_RADIUS*0.55f, -BODY_RADIUS*0.25f);
    //     drawAleg(quadratic,front_left_leg);
    // glPopMatrix();

    //  // draw right-front leg
    // glPushMatrix();
    //     glTranslatef(BODY_LENGTH*0.3f,-BODY_RADIUS*0.55f, -BODY_RADIUS*0.25f);
    //     drawAleg(quadratic,front_right_leg);
    // glPopMatrix();
    //     // draw left-back leg
    // glPushMatrix();
    //     glTranslatef(-BODY_LENGTH*0.3f,BODY_RADIUS*0.20f, -BODY_RADIUS*0.25f);
    //     drawAleg(quadratic,back_left_leg);
    // glPopMatrix();
    //     // draw right-back leg
    // glPushMatrix();
    //     glTranslatef(-BODY_LENGTH*0.3f,-BODY_RADIUS*0.20f, -BODY_RADIUS*0.25f);
    //     drawAleg(quadratic,back_right_leg);
    // glPopMatrix();
    glEndList();
    //glEnd();
    gluDeleteQuadric(quadratic);
    glutSwapBuffers();
}

void init(){ 
	GLUquadricObj *quadratic; 
	glClearColor (0.0, 0.0, 0.0, 0.0); 


	//glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_NORMALIZE);

   
	
	
    startList = glGenLists(10);
	quadratic = gluNewQuadric();
	gluQuadricDrawStyle(quadratic, GLU_FILL);
    gluQuadricNormals(quadratic, GLU_SMOOTH);
	//gluQuadricOrientation(quadratic, GLU_OUTSIDE);
    //glMatrixMode(GL_PROJECTION);
    
    //Torso
    glNewList(startList, GL_COMPILE);
    	glColor3f(0.05f, 0.09f, 0.77f);
    	glTranslatef(-BODY_LENGTH/2.0f, 00.0f, 0.0f);
    	//glRotatef(40.0f, 1.0f, 1.0f, 1.0f);
    	glRotatef(90.0f,0.0f,1.0f,0.0f);

    	drawClosedCylinder(quadratic,BODY_RADIUS,BODY_RADIUS, BODY_LENGTH);
    	//gluCylinder(quadratic, BODY_RADIUS,BODY_RADIUS, BODY_LENGTH, SLICES, STACKS);
    	//gluCylinder(quadratic, 0.5, 0.3, 1.0, 15, 5);
    glEndList();

    // Head
    glNewList(startList+1,GL_COMPILE);
    	glColor3f(0.05f, 0.09f, 0.77f);
    	glTranslatef(BODY_LENGTH*0.48f, BODY_RADIUS*0.8f, BODY_RADIUS*0.1f);
    	//glRotatef(m_neck_angle, -1.0f, 0.0f, 0.0f);
    	glRotatef(-90.0f, 1.0f, .0f, .0f);
    	glRotatef(45.0f, .0f, 1.0f, .0f);
    	
    	//drawClosedCylinder(quadratic,NECK_RADIUS,NECK_RADIUS, NECK_LENGTH);
    	
    	gluDisk(quadratic, 0.0f, NECK_RADIUS, SLICES, STACKS);
		gluCylinder(quadratic, NECK_RADIUS, NECK_RADIUS, NECK_LENGTH/2, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,NECK_LENGTH/2);
		gluDisk(quadratic, 0.0f, NECK_RADIUS, SLICES, STACKS);

    	glTranslatef(-0.17f, 0.0f, NECK_LENGTH/6);
    	glRotatef(m_head_angle, .0f, 1.0f, 0.0f);
        //glTranslatef(0.0f, -0.5f, -HEAD_LENGTH*0.3f);
        //drawClosedCylinder(quadratic,HEAD_RADIUS,HEAD_RADIUS, HEAD_LENGTH);
        gluDisk(quadratic, 0.0f, HEAD_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, HEAD_RADIUS/2, HEAD_RADIUS/2, HEAD_LENGTH, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,HEAD_LENGTH);
		gluDisk(quadratic, 0.0f, HEAD_RADIUS/2, SLICES, STACKS);

    glEndList();

    //Left Front Leg
    glNewList(startList+2,GL_COMPILE);
		glTranslatef(BODY_LENGTH*0.3f,-BODY_RADIUS*0.85f, -BODY_RADIUS*0.25f);
        glRotatef(90.0f,1.0f,0.0f,0.0f);
        //glRotatef(-180.0f+front_left_leg[0], 0.0f, 1.0f, 0.0f);
    	//drawClosedCylinder(quadratic,LEG_RADIUS,LEG_RADIUS, LEG_UPPER_LENGTH);
		
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_UPPER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_UPPER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	
    	//glTranslatef(0.0f, 0.0f, LEG_UPPER_LENGTH);
    	//glRotatef(front_left_leg[1], 0.0f, 1.0f, 0.0f);
    	//drawClosedCylinder(quadratic,LEG_RADIUS,LEG_RADIUS, LEG_LOWER_LENGTH);
    	gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_LOWER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_LOWER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	

    glEndList();

    //Right Front Foot
    glNewList(startList+3,GL_COMPILE);
		glTranslatef(BODY_LENGTH*0.3f,-BODY_RADIUS*0.85f, +BODY_RADIUS*0.25f);
        glRotatef(90.0f,1.0f,0.0f,0.0f);
        
        //drawAleg(quadratic,front_right_leg);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_UPPER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_UPPER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	
    	//glTranslatef(0.0f, 0.0f, LEG_UPPER_LENGTH);
    	//glRotatef(front_left_leg[1], 0.0f, 1.0f, 0.0f);
    	//drawClosedCylinder(quadratic,LEG_RADIUS,LEG_RADIUS, LEG_LOWER_LENGTH);
    	gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_LOWER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_LOWER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	
    glEndList();
	
	//Back Left Leg
	glNewList(startList+4,GL_COMPILE);
		glTranslatef(-BODY_LENGTH*0.3f,-BODY_RADIUS*0.85f, -BODY_RADIUS*0.25f);
    	glRotatef(90.0f,1.0f,0.0f,0.0f);
    	//drawAleg(quadratic,back_left_leg);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_UPPER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_UPPER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	
    	//glTranslatef(0.0f, 0.0f, LEG_UPPER_LENGTH);
    	//glRotatef(front_left_leg[1], 0.0f, 1.0f, 0.0f);
    	//drawClosedCylinder(quadratic,LEG_RADIUS,LEG_RADIUS, LEG_LOWER_LENGTH);
    	gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_LOWER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_LOWER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	


	glEndList();

	//Back Right Leg
	glNewList(startList+5,GL_COMPILE);
		glTranslatef(-BODY_LENGTH*0.3f,-BODY_RADIUS*0.85f, +BODY_RADIUS*0.25f);
    	glRotatef(90.0f,1.0f,0.0f,0.0f);

    	//drawAleg(quadratic,back_right_leg);
	
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_UPPER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_UPPER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	
    	//glTranslatef(0.0f, 0.0f, LEG_UPPER_LENGTH);
    	//glRotatef(front_left_leg[1], 0.0f, 1.0f, 0.0f);
    	//drawClosedCylinder(quadratic,LEG_RADIUS,LEG_RADIUS, LEG_LOWER_LENGTH);
    	gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, LEG_RADIUS/2, LEG_RADIUS/2, LEG_LOWER_LENGTH/1.25, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,LEG_LOWER_LENGTH/1.25);
		gluDisk(quadratic, 0.0f, LEG_RADIUS/2, SLICES, STACKS);
    	
	glEndList();

	//Tail

    glNewList(startList+6,GL_COMPILE);
    	glColor3f(0.05f, 0.09f, 0.77f);
    	glTranslatef(-BODY_LENGTH*0.48f, BODY_RADIUS*0.8f, BODY_RADIUS*0.1f);
    	//glRotatef(m_neck_angle, -1.0f, 0.0f, 0.0f);
    	glRotatef(-90.0f, 1.0f, .0f, .0f);
    	glRotatef(-45.0f, .0f, 1.0f, .0f);
    	
    	//drawClosedCylinder(quadratic,NECK_RADIUS,NECK_RADIUS, NECK_LENGTH);
    	
    	gluDisk(quadratic, 0.0f, NECK_RADIUS/2, SLICES, STACKS);
		gluCylinder(quadratic, NECK_RADIUS/2, NECK_RADIUS/2, NECK_LENGTH/3, SLICES, STACKS);
		glTranslatef(0.0f,0.0f,NECK_LENGTH/3);
		gluDisk(quadratic, 0.0f, NECK_RADIUS/2, SLICES, STACKS);

	glEndList();

	glNewList(startList+7,GL_COMPILE);

	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex3f(-100.0, 0.0, -100.0);
		glColor3f(0.4f, 0.4f, 0.4f);
		glVertex3f(-100.0, 0.0, 100.0);
		glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(100.0, 0.0, 100.0);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex3f(100.0, 0.0, -100.0);		
	glEnd();

	glEndList();

	//glShadeModel (GL_FLAT); 
		//glMatrixMode(GL_MODELVIEW);
} 

void reshape (int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
         2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho(-2.5*(GLfloat)w/(GLfloat)h,
         2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void display(void){   
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	 glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,1,1,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,-2,0,0.0,0.0,0.0,1.0,0.0);


   	// Torso
   	glPushMatrix();

   //glEnable(GL_LIGHTING);
   //glShadeModel (GL_SMOOTH);
   //glTranslatef(-1.0, -1.0, 0.0);
   	glCallList(startList);
   	glPopMatrix();
   
   	//Head
   	glPushMatrix();
   	glCallList(startList+1);
   	glPopMatrix();

	//Left Front Leg
	glPushMatrix();
   	glCallList(startList+2);
   	glPopMatrix();

	//Right Front Leg
	glPushMatrix();
   	glCallList(startList+3);
   	glPopMatrix();
	
	//Left Back Leg
	glPushMatrix();
   	glCallList(startList+4);
   	glPopMatrix();
	
	//Right Front Leg
	glPushMatrix();
   	glCallList(startList+5);
   	glPopMatrix();

	//
	glPushMatrix();
   	glCallList(startList+6);
   	glPopMatrix();
    	glPushMatrix();
    	glCallList(startList+7);
	 glPopMatrix();


	glBegin(GL_QUADS);
		glColor3f(0.2f, 0.2f, 0.2f);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glColor3f(0.4f, 0.4f, 0.4f);
		glVertex3f(-100.0f, 0.0f, 100.0f);
		glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(100.0f, 0.0f, 100.0f);
		glColor3f(0.8f, 0.8f, 0.8f);
		glVertex3f(100.0f, 0.0f, -100.0f);		
	glEnd();

   glFlush();
} 
int flag = 1;
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   	  case 't':
		if(flag){
			gluLookAt(0,0,-2,0,0.0,0.0,0.0,1.0,0.0);   	  	
			flag=0;glFlush();
		}else{gluLookAt(-2,0,0,0,0.0,0.0,0.0,1.0,0.0);
			flag =1;glFlush();}
   	  	break;
      case 27:
         exit(0);
         break;
   }
}


int main(int argc,char* argv[]){
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   	glutInitWindowSize (1000, 550);
	glutInitWindowPosition (100, 100); 
	glutCreateWindow (argv[0]); 
	init (); 
	glutDisplayFunc(display); 

	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard); 
	glutMainLoop(); 
	return 0;
}


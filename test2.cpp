/********************************
Computer Graphics Assignment - 3
FILE - test2.cpp
-----------------------------------
|Name               | ID          |
|---------------------------------|
|Varun Wachaspati J | 2013A7PS166P|
|Saurabh Anand      | 2013A7PS139P|
-----------------------------------
*********************************/

/*NOTE -
This file does not support Window Resizing but has a lot of movement features which are useful for exploration of the environment.
Executable Produced is "drawWithoutResize"
*/
//Header Files to included

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h> 
#include <stdio.h>
#include <stdlib.h>

//Function Definitions
void init(void);
void drawAnimal(float x,float y,float z,int mode);
//void drawLeftFrontUpperLeg(float x,float y,float z);
void keyboard(unsigned char, int, int);
//void drawLeftFrontLowerLeg(float x,float y,float z);
void resize(int, int);
//void drawLeftFrontFeet();
void Cube_Draw(int, int,int, int);
void display(void);
//void drawTorso(float x,float y,float z);

//Variable Declarartions
int mode=1;
int is_depth; /* depth testing flag */
float x=0.0,y=-10.0,z=0.0;
int k=0,i=0;
GLuint texid;
GLuint texwidth=2;
GLuint texheight=2;
// GLuint texdepth=1;
static float gangle;
GLubyte texData[16] =
{
	0xFF,0x0C,0x0A,0xFF, // red 
	0x00,0xFF,0xD0,0xFF, // rgreen
	0xA0,0x0D,0xFF,0xFF, // blue
	0xFF,0xFF,0xFE,0xFF  // black 
};

int want_one(int param1)
{
	if(param1==1)
	{return 1;}
	else if(param1==0)
	{return 0;}
}


int flag=0;
void update(int time){
	//printf("\ngangle1st -%f\n",gangle);
	//printf("flag1st - %d\n",flag);
	z+=0.2;
	if(want_one(k)== 0){
		//printf("here\n");
		if(!(gangle<13.0f)){

			k = 1;
			//printf("flag2nd - %d\n",flag);
		}
		else{
			//printf("ok\n");
			gangle+=1.00f;
			//printf("\ngangle2nd -%f\n",gangle);
		}
	}
	else if(want_one(k)==1){
		gangle-=1.00f;
		//flag=0;
		if(gangle<=-13.0){
			k=0;
			//printf("flag3rd - %d\n",flag);
		}
	}
	if(gangle<0.1&&gangle>-1.1){
		i++;
	}
	
	if(i%2==0&&i!=0){
		return;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);

}


void update2(int time){
	//printf("\ngangle1st -%f\n",gangle);
	//printf("flag1st - %d\n",flag);
	z-=0.2;
	if(want_one(k)== 0){
		//printf("here\n");
		if(!(gangle<13.0f)){

			k = 1;
			//printf("flag2nd - %d\n",flag);
		}
		else{
			//printf("ok\n");
			gangle+=1.00f;
			//printf("\ngangle2nd -%f\n",gangle);
		}
	}
	else if(want_one(k)==1){
		gangle-=1.00f;
		//flag=0;
		if(gangle<=-13.0){
			k=0;
			//printf("flag3rd - %d\n",flag);
		}
	}
	if(gangle<0.1&&gangle>-1.1){
		i++;
	}
	
	if(i%2==0&&i!=0){
		return;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update2, 0);

}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_ALPHA| GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(40, 40);
	glutCreateWindow("The Cube World");
	//flag=0;
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(resize);  
	glutMainLoop();
	return 0;
}

void drawAnimal(float x,float y,float z,int mode){
	
	glPushMatrix();
		glTranslatef(0.0f+x,40.0f+y,0.0f+z);
		glColor4f(0.15,0.4,0.75,1);
		mode?glutSolidCube(30):glutWireCube(30);
	
	glPopMatrix();

	//Front Left Leg
	
	glPushMatrix();
		glColor4f(0.5,0.5,0.5,1);
	
		glTranslatef(10.0f+x,25.0f+y,10.0f+z);
		glRotatef(gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-4.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(10.0f+x,25.0f+y,10.0f+z);
		glRotatef(gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-12.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(10.0f+x,25.00f+y,10.0f+z);
		glRotatef(gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-20.5f,0.0f);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();
	
	//Rear Left Leg
	glPushMatrix();
		glColor3f(0.5,0.5,0.5);
	
		glTranslatef(10.0f+x,25.0f+y,-10.0f+z);
		glRotatef(gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-4.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(10.0f+x,25.0f+y,-10.0f+z);
		glRotatef(gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-12.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(10.0f+x,25.0f+y,-10.0f+z);
		glRotatef(gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-20.5f,0.0f);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();

	//Front Right Leg
	glPushMatrix();
		glColor3f(0.5,0.5,0.5);
		
		glTranslatef(-10.0f+x,25.0f+y,10.0f+z);
		glRotatef(-gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-4.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(-10.0f+x,25.0f+y,10.0f+z);
		glRotatef(-gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-12.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(-10.0f+x,25.0f+y,10.0f+z);
		glRotatef(-gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-20.5f,0.0f);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();


	//Rear Right Leg
	glPushMatrix();
		glColor3f(0.5,0.5,0.5);
	
		glTranslatef(-10.0f+x,25.0f+y,-10.0f+z);
		glRotatef(-gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-4.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(-10.0f+x,25.0f+y,-10.0f+z);
		glRotatef(-gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-12.0f,0.0f);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(-10.0f+x,25.0f+y,-10.0f+z);
		glRotatef(-gangle,-1.0f,0.0f,0.0f);
		glTranslatef(0.0f,-20.5f,0.0f);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();
	
	//Head
	glPushMatrix();
		glColor3f(0.2,0.3,0.5);
		glTranslatef(0.0f+x,59.0f+y,11.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	//Horns
	glPushMatrix();
		glColor3f(0.5,0,0.2);
		glTranslatef(-1.5f+x,63.0f+y,12.0f+z);
		glRotatef(90,-1.0f,0.0f,0.0f);
		mode?glutSolidCone(1.5f,4.0f,10,10):glutWireCone(1.5f,4.0f,10,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.5,0,0.2);
		glTranslatef(1.5f+x,63.0f+y,12.0f+z);
		glRotatef(90,-1.0f,0.0f,0.0f);
		mode?glutSolidCone(1.5f,4.0f,10,10):glutWireCone(1.5f,4.0f,10,10);
	glPopMatrix();

	//Eyes
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(2.0f+x,61.0f+y,15.0f+z);
		mode?glutSolidSphere(1.5,10,10):glutWireSphere(1.5,10,10);
		glColor3f(0,0,0);
		glTranslatef(0.0f,0.0f,2.0f);
		mode?glutSolidSphere(0.5,4,4):glutWireSphere(0.5,4,4);
	glPopMatrix();
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(-2.0f+x,61.0f+y,15.0f+z);
		mode?glutSolidSphere(1.5,10,10):glutWireSphere(1.5,10,10);
		glColor3f(0,0,0);
		glTranslatef(0.0f,0.0f,2.0f);
		mode?glutSolidSphere(0.5,4,4):glutWireSphere(0.5,4,4);
	glPopMatrix();

	//Nose
	glPushMatrix();
		glColor3f(0.6,0.2,0.3);
		glTranslatef(0.0f+x,58.0f+y,14.0f+z);
		glRotatef(90.0f,1.0,0.0,0.0);
		glRotatef(90.0f,-1.0,0.0,0.0);
		mode?glutSolidCone(1.0f,3.0f,10,10):glutWireCone(1.0f,3.0f,10,10);
		
	glPopMatrix();

	//Tail
	glPushMatrix();
		glColor3f(0.2,0.3,0.7);
		glTranslatef(0.0f+x,35.0f+y,-15.0f+z);
		glRotatef(180.0f,1.0,0.0,0.0);
		//glRotatef(90.0f,-1.0,0.0,0.0);
		mode?glutSolidCone(5.0f,9.0f,10,10):glutWireCone(5.0f,9.0f,10,10);
		
	glPopMatrix();
}
void drawAnimalStatic(float x,float y,float z,int mode){
	
	glPushMatrix();
		glTranslatef(0.0f+x,40.0f+y,0.0f+z);
		glColor4f(0.15,0.4,0.75,1);
		mode?glutSolidCube(30):glutWireCube(30);
	
	glPopMatrix();

	//Front Left Leg
	
	glPushMatrix();
		glColor4f(0.5,0.5,0.5,1);
	
		glTranslatef(10.0f+x,21.0f+y,10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(10.0f+x,13.0f+y,10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(10.0f+x,4.50f+y,10.0f+z);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();
	
	//Rear Left Leg
	glPushMatrix();
		glColor3f(0.5,0.5,0.5);
	
		glTranslatef(10.0f+x,21.0f+y,-10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(10.0f+x,13.0f+y,-10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(10.0f+x,4.50f+y,-10.0f+z);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();

	//Front Right Leg
	glPushMatrix();
		glColor3f(0.5,0.5,0.5);
	
		glTranslatef(-10.0f+x,21.0f+y,10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(-10.0f+x,13.0f+y,10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(-10.0f+x,4.50f+y,10.0f+z);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();


	//Rear Right Leg
	glPushMatrix();
		glColor3f(0.5,0.5,0.5);
	
		glTranslatef(-10.0f+x,21.0f+y,-10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();		
	
	glPushMatrix();
		glColor3f(0.6,0.6,0.6);
		glTranslatef(-10.0f+x,13.0f+y,-10.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	glPushMatrix();
		glColor3f(0.7,0.7,0.7);
		glTranslatef(-10.0f+x,4.50f+y,-10.0f+z);
		mode?glutSolidCube(9):glutWireCube(9);
	glPopMatrix();
	
	//Head
	glPushMatrix();
		glColor3f(0.2,0.3,0.5);
		glTranslatef(0.0f+x,59.0f+y,11.0f+z);
		mode?glutSolidCube(8):glutWireCube(8);
	glPopMatrix();

	//Horns
	glPushMatrix();
		glColor3f(0.5,0,0.2);
		glTranslatef(-1.5f+x,63.0f+y,12.0f+z);
		glRotatef(90,-1.0f,0.0f,0.0f);
		mode?glutSolidCone(1.5f,4.0f,10,10):glutWireCone(1.5f,4.0f,10,10);
	glPopMatrix();
	
	glPushMatrix();
		glColor3f(0.5,0,0.2);
		glTranslatef(1.5f+x,63.0f+y,12.0f+z);
		glRotatef(90,-1.0f,0.0f,0.0f);
		mode?glutSolidCone(1.5f,4.0f,10,10):glutWireCone(1.5f,4.0f,10,10);
	glPopMatrix();

	//Eyes
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(2.0f+x,61.0f+y,15.0f+z);
		mode?glutSolidSphere(1.5,10,10):glutWireSphere(1.5,10,10);
		glColor3f(0,0,0);
		glTranslatef(0.0f,0.0f,2.0f);
		mode?glutSolidSphere(0.5,4,4):glutWireSphere(0.5,4,4);
	glPopMatrix();
	glPushMatrix();
		glColor3f(1.0,1.0,1.0);
		glTranslatef(-2.0f+x,61.0f+y,15.0f+z);
		mode?glutSolidSphere(1.5,10,10):glutWireSphere(1.5,10,10);
		glColor3f(0,0,0);
		glTranslatef(0.0f,0.0f,2.0f);
		mode?glutSolidSphere(0.5,4,4):glutWireSphere(0.5,4,4);
	glPopMatrix();

	//Nose
	glPushMatrix();
		glColor3f(0.6,0.2,0.3);
		glTranslatef(0.0f+x,58.0f+y,14.0f+z);
		glRotatef(90.0f,1.0,0.0,0.0);
		glRotatef(90.0f,-1.0,0.0,0.0);
		mode?glutSolidCone(1.0f,3.0f,10,10):glutWireCone(1.0f,3.0f,10,10);
		
	glPopMatrix();

	//Tail
	glPushMatrix();
		glColor3f(0.2,0.3,0.7);
		glTranslatef(0.0f+x,35.0f+y,-15.0f+z);
		glRotatef(180.0f,1.0,0.0,0.0);
		//glRotatef(90.0f,-1.0,0.0,0.0);
		mode?glutSolidCone(5.0f,9.0f,10,10):glutWireCone(5.0f,9.0f,10,10);
		
	glPopMatrix();
}
void InitTexture()
{
 
   // Bind the texture
   glEnable(GL_TEXTURE_2D);
   glGenTextures(2,&texid);
   glBindTexture(GL_TEXTURE_2D,texid); 
   glTexImage2D (
	GL_TEXTURE_2D, 	
	0, 	
	4, 	
	texwidth, 	
	texheight, 	
	0, 
	GL_RGBA, 	
	GL_UNSIGNED_BYTE,
	texData 	
   ); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
   //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
   //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
}

void init(void)
{	//gangle=0.0f;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable (GL_BLEND);
//glPolygonMode(GL_FRONT, GL_FILL);
	glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_CULL_FACE); 
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	//InitTexture();
}



void display(void)
{	
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
	//glTexParameter(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// GLint port[4];
	// glGetIntegerv(GL_VIEWPORT,port);
	// double aspect = double (port[2])/double (port[3]);
	// gluPerspective(100.0, aspect, 1.0, 400.0);
	// glMatrixMode(GL_MODELVIEW);
	// glLoadIdentity();	

	// gluLookAt(110,40,100,0,0.0,0.0,0.0,1.0,0.0);

	//The Wall
	glBegin(GL_QUADS);
		glPushMatrix();
		glTexCoord2f(0.0f, 1.0f);glColor3f(0.4f, 0.2f, 0.2f);
		glVertex3f(-200.0, -10.0, -200.0);
		glTexCoord2f(1.0f, 1.0f);glColor3f(0.6f, 0.4f, 0.4f);
		glVertex3f(-200.0, 200.0, -200.0);
		glTexCoord2f(0.0f, 0.0f);glColor3f(0.8f, 0.6f, 0.6f);
		glVertex3f(200.0, 200.0, -200.0);
		glTexCoord2f(1.0f, 0.0f);glColor3f(0.0f, 0.8f, 0.8f);
		glVertex3f(200.0, -10.0, -200.0);

		glTexCoord2f(1.0f, 1.0f);glColor3f(0.4f, 0.2f, 0.3f);
		glVertex3f(-200.0, -10.0, -200.0);
		glTexCoord2f(0.0f, 0.0f);glColor3f(0.6f, 0.4f, 0.5f);
		glVertex3f(-200.0, 200.0, -200.0);
		glTexCoord2f(1.0f, 0.0f);glColor3f(0.8f, 0.6f, 0.7f);
		glVertex3f(-200.0, 200.0, 200.0);
		glTexCoord2f(0.0f, 1.0f);glColor3f(0.0f, 0.8f, 0.9f);
		glVertex3f(-200.0, -10.0, 200.0);		
	
		glColor3f(0.4f, 0.2f, 0.3f);
		glVertex3f(200.0, -10.0, -200.0);
		glColor3f(0.6f, 0.4f, 0.5f);
		glVertex3f(200.0, 200.0, -200.0);
		glColor3f(0.8f, 0.6f, 0.7f);
		glVertex3f(200.0, 200.0, 200.0);
		glColor3f(0.0f, 0.8f, 0.9f);
		glVertex3f(200.0, -10.0, 200.0);

	// //glEnd();
//The Floor
	//glBegin(GL_QUADS);
		glColor3f(0.1f, 0.1f, 0.2f);
		glVertex3f(-200.0, -10.0, -200.0);
		glColor3f(0.5f, 0.5f, 0.2f);
		glVertex3f(-200.0, -10.0, 200.0);
		glColor3f(0.4f, 0.6f, 0.6f);
		glVertex3f(200.0, -10.0, 200.0);
		glColor3f(0.3f, 0.9f, 0.7f);
		glVertex3f(200.0, -10.0, -200.0);		

		glColor3f(0.3f, 0.1f, 0.4f);
		glVertex3f(-200.0, 200.0, -200.0);
		glColor3f(0.5f, 0.7f, 0.2f);
		glVertex3f(-200.0, 200.0, 200.0);
		glColor3f(0.8f, 0.3f, 0.6f);
		glVertex3f(200.0, 200.0, 200.0);
		glColor3f(0.3f, 0.8f, 0.8f);
		glVertex3f(200.0, 200.0, -200.0);		

		glPopMatrix();
	glEnd();

//The Animal
	//Animal Torso
	drawAnimal(x,y,z,mode);
	drawAnimalStatic(100,-10,-50,1);
	//glBegin(GL_QUADS);
	//Body at (0,40,0)
	//glTranslatef(0.0f,40.0f,0.0f);
	
	//glutSolidCube(30);
	//glTranslatef(4.0f,0.0f,4.0f);
	
	//glEnd();
// Icosohedrans
	glPushMatrix();
		glColor3f(0.5,0.4,0.2);
		glTranslatef(-90,10,-73);
		glScalef(30,30,30);
		glutSolidIcosahedron();
	glPopMatrix();
// Teapot
	glPushMatrix();
		glColor3f(0.3,0.6,0.4);
		glTranslatef(60,0,-23);
		glutSolidTeapot(10);
		
	glPopMatrix();



	/* Random Objects */
	
	Cube_Draw(175,0 ,157, 2);
	Cube_Draw(-165,0 ,-112, 3);
	Cube_Draw(150, 0,-150, 1);
	Cube_Draw(-86,0 ,117, 2);
	Cube_Draw(107, 0,112, 3);
	Cube_Draw(-87, 0,132, 1);
	Cube_Draw(-126,0 ,175, 2);
	Cube_Draw(157, 0,182, 3);
	Cube_Draw(-43,0 ,52, 1);
	Cube_Draw(146, 0,135, 2);
	Cube_Draw(137, 0,-112, 3);
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
	 
	// "a": move left
	// "d": move right
	// "w": Toggle Wireframe and Solid of Animal
	// "s": backwards move 
	// "q": move forward	
	// "l": rotate left
	// "j": rotate right
	// "i": rotate Up
	// "k": rotate Down
	switch (key)
	{
	case 'b':
	case 'B':
		glutTimerFunc(25,update2,0);
		glutDisplayFunc(display);
		break;
	case 'f':
	case 'F':
		//z++;
		glutTimerFunc(25,update,0);
		glutDisplayFunc(display);
		break;
	case 'w':
	case 'W':
		if(mode)
			mode=0;
		else
			mode=1;
		glutDisplayFunc(display);
		break;
	case 'i':
	case 'I':
		glRotatef(5.0f,1.0f,0.0f,0.0f);
		break;
	case 'k':
	case 'K':
		glRotatef(5.0f,-1.0f,0.0f,0.0f);
		break;		
	case 'l':
	case 'L':
		glRotatef(5.0f,0.0f,-1.0f,0.0f);
		break;
	case 'j':
	case 'J':
		glRotatef(5.0f,0.0f,1.0f,0.0f);
		break;	
	case 'q':
	case 'Q':
		glTranslatef(0.0, 0.0, 5.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(5.0, 0.0, 0.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(-5.0, 0.0, 0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -5.0);
		break;
	
	}
	display();
}

void resize(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	// if (height == 0) height = 1;
 //    	double ratio = width / height;
 // glViewport(0, 0, (height-(width/ratio))>0? width:(int)(height*ratio),(width-(height*ratio))>0? height:(int)(width/ratio));
   	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	// if (width <= height)
 //      glOrtho(-2.5, 2.5, -2.5*(GLfloat)height/(GLfloat)width,
 //         2.5*(GLfloat)height/(GLfloat)width, -10.0, 10.0);
 //   else
 //      glOrtho(-2.5*(GLfloat)width/(GLfloat)height,
 //         2.5*(GLfloat)width/(GLfloat)height, -2.5, 2.5, -10.0, 10.0);
	gluPerspective(90.0, width / height, 1.0, 400.0);

	//glTranslatef(0.0, -5.0, -150.0);

	glMatrixMode(GL_MODELVIEW);
	gluLookAt(0,10,100,0,0.0,0.0,0.0,1.0,0.0);
}

void Cube_Draw(int x_offset,int y_offset ,int z_offset, int color)
{
	float x_big = (float)x_offset + 10;
	float z_big = (float)z_offset + 10;
	float y_big = (float)y_offset + 10;
	float x_small = (float)x_offset - 10;
	float z_small = (float)z_offset - 10;
	float y_small = (float)y_offset - 10;
	switch(color)
	{
	case 1:
		glColor3f(1.0,0.0,0.0);
		break;
	case 2:
		glColor3f(0.0,1.0,0.0);
		break;
	case 3:
		glColor3f(0.0,0.0,1.0);
		break;
	}
	InitTexture();
	
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(x_small,y_big,z_big); // front
		
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_small,y_small,z_big);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x_big,y_small,z_big);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(x_big,y_big,z_big);

		glTexCoord2f(0.0f, 1.0f);glVertex3f(x_big,y_big,z_small); //back 
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_big,y_small,z_small);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x_small,y_small,z_small);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(x_small,y_big,z_small);

		glTexCoord2f(0.0f, 1.0f);glVertex3f(x_big,y_big,z_big); // right
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x_big,y_small,z_big);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_big,y_small,z_small);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(x_big,y_big,z_small);

		glTexCoord2f(0.0f, 1.0f);glVertex3f(x_small,y_big,z_small); //left
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_small,y_small,z_small);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x_small,y_small,z_big);
		glTexCoord2f(1.0f, 1.0f);glVertex3f(x_small,y_big,z_big);

		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_small,y_big,z_big); //top
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x_big,y_big,z_big);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_big,y_big,z_small);
		glTexCoord2f(0.0f, 1.0f);glVertex3f(x_small,y_big,z_small);

		glTexCoord2f(1.0f, 1.0f);glVertex3f(x_small,y_small,z_small); // bottom
		glTexCoord2f(0.0f, 1.0f);glVertex3f(x_big,y_small,z_small);
		glTexCoord2f(0.0f, 0.0f);glVertex3f(x_big,y_small,z_big);
		glTexCoord2f(1.0f, 0.0f);glVertex3f(x_small,y_small,z_big);
	glEnd();
}

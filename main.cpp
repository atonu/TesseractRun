#include<windows.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include<GL/glu.h>
#include <GL/glut.h>
#define UP 1
#define DOWN 2
#define RIGHT -1
#define LEFT -2
using namespace std;
//using namespace std;
int sd ;
int c = 0;
int x, y;
bool gameover = false;
float random;
int score;

string b = "Score";

string a=" ";

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}



float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float angx = 1;
float angy = 0;
float angz = 0;
float zoom = 1;
int countkey = 0;
float rl = 0.0;
float ud = -2.3;
float ab = 5;
float boxlr = 0.0;
float speed = 0.12;
int red = 255;
int green = 0;
int blue = 0;
string Result;
int shape = 1;
int obstacle =1;
int decider_1=1;
int decider_2=1;
float currentspeed = 0.12;

////////////////////////////////////////////////////////////

void drawText(char ch[],float xpos, float ypos,float zpos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos3f( xpos , ypos, zpos);
    for (int i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }
}

///////////////////END//////////////////////////////////////
//Draws the 3D scene
void game() //last black screen with gameover text
{
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-5,-3.9,2);
    glVertex3f(5,-3.9,2);
    glVertex3f(5,4.1,2);
    glVertex3f(-5,4.1,2);
    glEnd();
    glFlush();

}
void text() //gameover text
{
    glColor3f(1.0, 1.0, 1.0);
    drawText("GAME OVER. Press SPACE to Play Again. ESC to Quit.", -0.1,0,-1);
    glRasterPos3d(-5,2.5,0.0);
    glColor3f(0.000, 1.000, 1.000);
	for(int i=0;b[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,b[i]);

	glRasterPos3d(-4.5,2.5,0.0);

	for(int i=0;Result[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,Result[i]);

}
void drawScene() {



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective

	glLoadIdentity(); //Reset the drawing perspective
	//
	glTranslatef(1.0, 0.0, -7.0); //Move forward 5 units



glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1,1,1,0 );




glPushMatrix(); //Save the transformations performed thus far
///the cube starts




glPushMatrix();

glTranslatef( ab,-2.3, 0.0);//down up -(a+i)

glScalef(.5,0.5,0.5);
glColor3ub(255,160,160);
//glutSolidCube(1);


if (decider_1 % 2 == 0){
    if(decider_2%2==0)
    {
        glutSolidCube(1.2);
        obstacle=2;
    }
    else
    {
        glutSolidSphere(.7,20,20);
        obstacle =1;

    }
}
else
{
    if(decider_2%2==0)
    {
        glutSolidTorus(.25,.55,20,40);
        obstacle=3;
    }
    else
    {
        glPushMatrix();
        glScalef(.3,.26,0);
        glTranslatef(0,-3.5,0);
        glLineWidth(20);
        glBegin(GL_LINE_LOOP);
        glVertex3i(1.0,1.0,0);
        glVertex3i(5,5,0);
        glVertex3i(1.0,5,0);
        glVertex3i(5,1.0,0);
        glVertex3i(3,7,0);
        glEnd();
        glPopMatrix();
        obstacle=4;
    }
}





///the cube ends


glPopMatrix();
///the cube ends


///the dot starts

glTranslatef(-4, ud, 0.0); //Move to the center of the trapezoid
glScalef(zoom,zoom,zoom);
glRotated(angx,1.0, 0.0, 0.0);
glRotated(angy,0.0, 1.0, 0.0);
glRotated(angz,0.0, 0.0, 1.0);

glPushMatrix();

glColor3ub(145, 187, 228);

if(shape == 1){
        glutSolidSphere(0.32,30,30);
}
else if(shape == 2){
        glutSolidCube(0.5);
}
else if(shape == 3){
        glutSolidTorus(.06,.28,20,40);
}


else if(shape == 4){
        glPushMatrix();
        glScalef(.15,.12,0);
        glTranslatef(-3,-3.5,0);
        glLineWidth(20);
        glBegin(GL_LINE_LOOP);
        glVertex3i(1.0,1.0,0);
        glVertex3i(5,5,0);
        glVertex3i(1.0,5,0);
        glVertex3i(5,1.0,0);
        glVertex3i(3,7,0);
        glEnd();
        glPopMatrix();
}


switch (sd)
			{

			case RIGHT:
				 glutSolidSphere(.2+2,50+1,50);
				break;
			case LEFT:

				break;
			}


glPopMatrix();


///the dot ends



glPopMatrix();
glColor3ub(120, 0, 220);

	glRasterPos3d(-5,-2.0,0.0);

	for(int i=0;a[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,a[i]);
        if(gameover)
            {
                game();
                text();
            }
stringstream convert; // stringstream used for the conversion

convert << score;//add the value of Number to the characters in the stream

Result = convert.str();//set Result to the content of the stream




	glRasterPos3d(-1.3,0,0.0);

	for(int i=0;b[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,b[i]);

	glRasterPos3d(-0.80,0,0.0);

	for(int i=0;Result[i] != '\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,Result[i]);


glutSwapBuffers();



}



void update(int value)
{
    ab -=speed;
    if(ab < -4 && ab > -4.3)
    {
        if(shape != obstacle)
        {
            gameover = true;
        }
    }
    if (ab < -8) {
        ab = 6;

        speed +=0.005;
        currentspeed = speed;

		score = score +1;
        decider_1 = rand();
        decider_2 = rand();

    }

	if((boxlr != rl && (rl > boxlr+.6 || rl < boxlr-.6) && ab <= -3.2 ))
    {
        //gameover = true;
    }



	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(1, update, 0);

}

void keyboard(unsigned char key, int x, int y)
{


	switch (key)
	{
	    case 'a':
        case 'A':
	    shape =1;
        break;

        case 'd':
        case 'D':
	    shape =2;
        break;

        case 'w':
        case 'W':
	    shape =3;
        break;

        case 's':
        case 'S':
	    shape =4;
        break;


        case 32:

        ab =6;
        speed=0.12;
        score =0;
	    gameover=false;
        break;


        case 'p':
        case 'P':
	    speed = 0;
        break;

        case 'r':
        case 'R':
	    speed = currentspeed;
        break;

        case 27:
        exit(0);
        break;

	}
}
void input(int key, int x, int y)
{
	switch (key)
	{

	case GLUT_KEY_RIGHT:
		if (sd != RIGHT)
            shape = 2;
			if(rl <5)
	rl = rl + 0.8;

		break;
	case GLUT_KEY_LEFT:
		if (sd != LEFT)
            shape = 1;
		break;

		case GLUT_KEY_UP:
		if (sd != UP)
            shape = 3;
		break;

		case GLUT_KEY_DOWN:
		if (sd != DOWN)
            shape = 4;



	}

}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(1360, 760);
	//glColor3f(1.0,0.0,0.0);
	//glColor3f(1.0,0.0,0.0);

	//Create the window

	glutCreateWindow("3d");
	//gluOrtho2D(-800, 800, -800,800);
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

    glutKeyboardFunc(keyboard);


	glutSpecialFunc(input);

	glutTimerFunc(10, update, 0); //Add a timer
    glutFullScreen();
	glutMainLoop();
	return 0;
}

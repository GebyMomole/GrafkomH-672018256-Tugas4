#include <iostream>
#include <glut.h>

float x_pos = 0.0;
float y_pos = 0.0;
float deltaX = 0.030;
float deltaY = 0.056;
float delta = 0.025;
bool jalan = true;
void display() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(x_pos, sin(y_pos));
	glVertex2f(0.0, sin(y_pos));
	glVertex2f( x_pos, 0.0);

	glEnd();

	glutSwapBuffers();
}


void myinit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(2000 / 30, timer, 0);
	
	if (x_pos >= 1.0f || x_pos <= -1.0f)
				deltaX = -deltaX;
			y_pos += deltaY;
			x_pos += deltaX;

	

	
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Tugas4");
	glutDisplayFunc(display);

	myinit();

	glutTimerFunc(0, timer, 0);

	glutMainLoop();

	return 0;
}
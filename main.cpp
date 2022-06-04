#include <iostream>
//#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

void displayCB();
void changeColor();
void reshape(int w, int h);

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(650, 250);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Hi");

    glutDisplayFunc(displayCB);
    glutReshapeFunc(reshape);
    changeColor();

    glutMainLoop();

    return 0;
}

void displayCB() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(10);
    /*glBegin(GL_POINTS);
    for (int i = -10; i <= 10; ++i) {
        for (int j = -10; j <= 10; ++j) {
            if (i == j) glVertex2i(i * 5, j * 5);
//            if ((i + j) == 10) glVertex2i(i * 5, j * 5);
//            if ((i + j) == -10) glVertex2i(i * 5, j * 5);
            if ((i + j) == 0) glVertex2i(i * 5, j * 5);
        }
    }*/
    glBegin(GL_TRIANGLES);
    glVertex2i(100, 100);
    glVertex2i(100, -100);
    glVertex2i(0, 0);
    glEnd();
    glFlush();
}

void changeColor() {
    glClearColor(0.0, 1.0, 1.0, 1.0);
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
    glMatrixMode(GL_MODELVIEW);
}

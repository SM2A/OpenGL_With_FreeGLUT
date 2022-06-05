#include <iostream>
#include <GL/glut.h>

using namespace std;

void displayCB();
void changeColor();
void reshape(int w, int h);
void animation(int pram);

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(650, 250);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Sample Animation");

    glutDisplayFunc(displayCB);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, animation, 0);
    changeColor();

    glutMainLoop();

    return 0;
}

int step = 0;

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

    if ((step % 4) == 0) {
        glVertex2i(0, 0);
        glVertex2i(100, 0);
        glVertex2i(50, 50);

        glVertex2i(0, 0);
        glVertex2i(-100, 0);
        glVertex2i(-50, -50);

    } else if ((step % 4) == 1) {
        glVertex2i(0, 0);
        glVertex2i(80, 80);
        glVertex2i(30, 75);

        glVertex2i(0, 0);
        glVertex2i(-80, -80);
        glVertex2i(-30, -75);
    } else if ((step % 4) == 2) {
        glVertex2i(0, 0);
        glVertex2i(0, 100);
        glVertex2i(-50, 50);

        glVertex2i(0, 0);
        glVertex2i(0, -100);
        glVertex2i(50, -50);
    } else if ((step % 4) == 3) {
        glVertex2i(0, 0);
        glVertex2i(-80, 80);
        glVertex2i(-30, 25);

        glVertex2i(0, 0);
        glVertex2i(80, -80);
        glVertex2i(30, -25);
    }

    step++;

    glEnd();

//    glFlush();
    glutSwapBuffers();
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

void animation(int pram) {
    glutPostRedisplay();
    glutTimerFunc(100, animation, 0);
}

#include <GL/glut.h>

#define WINDOW_SIZE 500
#define WINDOW_POSITION_X 650
#define WINDOW_POSITION_Y 250
#define WINDOW_NAME "Computer Graphics"

using namespace std;

void displayCB();
void changeColor();
void reshape(int w, int h);

int main(int argc, char *argv[]) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(WINDOW_POSITION_X, WINDOW_POSITION_Y);
    glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);

    glutCreateWindow(WINDOW_NAME);

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

    glBegin(GL_POINTS);
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
    gluOrtho2D(-WINDOW_SIZE / 2, WINDOW_SIZE / 2, -WINDOW_SIZE / 2, WINDOW_SIZE / 2);
    glMatrixMode(GL_MODELVIEW);
}

#include <iostream>
#include <GL/freeglut.h>
#include <GL/glut.h>

using namespace std;

int main( int argc, char** argv ) {

    glutInit( &argc, argv );
    auto window = glutCreateWindow("Hi");


    glViewport(0,0,300,300);

    while (true);

    return 0;
}

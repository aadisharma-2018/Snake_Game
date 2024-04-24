#include <GL/gl.h>
#include <GL/glut.h>
#include "gamelog.h"

#define COLUMNS 30
#define ROWS 30

void display_callback();
void init();
void reshape_callback(int, int);

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Snake");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    init();
    glutMainLoop();
    return 0;
}

void display_callback(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glutSwapBuffers();
}

void init(){

    glClearColor(0.3, 0.3, 0.3, 1.0);
    initGrid(COLUMNS, ROWS);
}

void reshape_callback(int w, int h){

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

#include <GL/gl.h>
#include <GL/glut.h>
#include "gamelog.h"

#define COLUMNS 30
#define ROWS 30
#define FPS 8

void display_callback();
void init();
void reshape_callback(int, int);
void timer_callback(int);

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Snake");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0, timer_callback, 0);
    init();
    glutMainLoop();
    return 0;
}

int INDEX = 0;
void display_callback(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    glRectd(INDEX, 20, (INDEX + 2), 21);
    INDEX++;
    if(INDEX > 30){
        INDEX = 0;
    }
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

void timer_callback(int){

    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer_callback, 0);
}

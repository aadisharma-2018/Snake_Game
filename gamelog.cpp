#include <GL/gl.h>
#include <GL/glut.h>
#include "gamelog.h"

int gridX;
int gridY;

void initGrid(int x, int y){

    gridX = x;
    gridY = y;

}

void drawGrid(){

    for (int i = 0; i < gridX; i++){
        for (int j = 0; j < gridY; j++){
            unit(i, j);
        }
    }

}

void unit(int x, int y){


    if (x == 0 || y == 0 || x == (gridX - 1) || y == (gridY - 1)){
        glLineWidth(3.0);
        glColor3f(1.0, 0.0, 0.0);
    }
    else{
        glLineWidth(1.0);
        glColor3f(1.0, 1.0, 1.0);
    }

    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x+1, y);
        glVertex2f(x+1, y+1);
        glVertex2f(x, y+1);
    glEnd();
}
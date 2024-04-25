#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "gamelog.h"

int gridX;
int gridY;
int posX;
int posY;
int foodX;
int foodY;
int snakeDir = RIGHT;
bool food = true;
extern bool gameOver;


void initGrid(int x, int y){

    gridX = x;
    gridY = y;
    posX = (x/2);
    posY = (y/2);

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

void drawFood(){

    if (food){
        random(foodX, foodY);
    }

    food = false;
    glColor3f(1.0, 0.0, 0.0);
    glRectf(foodX, foodY, (foodX+1), (foodY+1));

}

void drawSnake(){

    if(snakeDir == UP){
        posY++;
    }
    else if (snakeDir == DOWN){
        posY--;
    }
    else if (snakeDir == LEFT){
        posX--;
    }
    else if (snakeDir == RIGHT){
        posX++;
    }

    glColor3f(0.0, 1.0, 0.0);
    glRectd(posX, posY, (posX + 1), (posY + 1));

    if (posX == 0 || posX == (gridX - 1) || posY == 0 || posY == (gridY - 1)){
        gameOver = true;
    }
    if (posX == foodX && posY == foodY){
        food = true;
    }
}

void random(int &x, int &y){

    int _maxX = (gridX-2);
    int _maxY = (gridY-2);
    int _min = 1;

    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() % (_maxY - _min);
}

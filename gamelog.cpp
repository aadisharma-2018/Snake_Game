#include <GL/gl.h>
#include <GL/glut.h>
#include <ctime>
#include "gamelog.h"

int gridX;
int gridY;
int snake_length = 5;
int posX[60] = {20, 20, 20, 20, 20};
int posY[60] = {20, 19, 18, 17, 16};
int foodX;
int foodY;
int snakeDir = RIGHT;
bool food = true;
extern bool gameOver;
extern int score;

void initGrid(int x, int y){

    gridX = x;
    gridY = y;
    //posX = (x/2);
    //posY = (y/2);

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

    for(int i = (snake_length - 1); i > 0; i--){

        posX[i] = posX[i-1];
        posY[i] = posY[i-1];
    }
    if(snakeDir == UP){
        posY[0]++;
    }
    else if (snakeDir == DOWN){
        posY[0]--;
    }
    else if (snakeDir == LEFT){
        posX[0]--;
    }
    else if (snakeDir == RIGHT){
        posX[0]++;
    }

    for (int i = 0; i < snake_length; i++){

        if (i == 0){
            glColor3f(0.0, 0.0, 1.0);
        }
        else{
            glColor3f(0.0, 1.0, 0.0);
        }
        glRectd(posX[i], posY[i], (posX[i] + 1), (posY[i] + 1));

    }
    if (posX[0] == 0 || posX[0] == (gridX - 1) || posY[0] == 0 || posY[0] == (gridY - 1)){
        gameOver = true;
    }
    for (int i = 1; i < snake_length; i++){
        if (posX[i] == posX[0] && posY[i] == posY[0]){
            gameOver = true;
        }
    }
    if (posX[0] == foodX && posY[0] == foodY){
        score++;
        snake_length++;
        if (snake_length > MAX){
            snake_length = MAX;
        }
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

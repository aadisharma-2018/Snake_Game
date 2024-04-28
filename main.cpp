#include <GL/gl.h>
#include <GL/glut.h>
#include "gamelog.h"

#include <stdlib.h>

#define COLUMNS 30
#define ROWS 30
#define FPS 8

Grid grid;
Snake snake;
Food objfood;

extern int snakeDir;
bool gameOver = false;
bool gameStarted = false;
int score = 0;

void display_callback();
void init();
void reshape_callback(int, int);
void timer_callback(int);
void keyboard_callback(int, int, int);
void mouse(int, int, int, int);
void drawStartScreen();

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Snake");
    glutMouseFunc(mouse);
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0, timer_callback, 0);
    glutSpecialFunc(keyboard_callback);
    init();
    glutMainLoop();
    return 0;
}

void display_callback(){

    glClear(GL_COLOR_BUFFER_BIT);
    if (!gameStarted){
        drawStartScreen();
    }
    else{
        grid.drawGrid();
        snake.drawSnake();
        objfood.drawFood();
        glutSwapBuffers();
        if (gameOver == true){

            char _score[10];
            itoa(score, _score, 10);
            char text[50] = "Your score: ";
            strcat(text, _score);
            MessageBox(NULL, text, "GAME OVER", 0);
            exit(0);
        }
    }
}

void init(){

    glClearColor(0.3, 0.3, 0.3, 1.0);
    grid.initGrid(COLUMNS, ROWS);
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

void keyboard_callback(int key, int, int){

    switch(key){
        case GLUT_KEY_UP:
            if(snakeDir != DOWN){
                snakeDir = UP;
                break;
            }
        case GLUT_KEY_DOWN:
            if(snakeDir != UP){
                snakeDir = DOWN;
                break;
            }
        case GLUT_KEY_RIGHT:
            if(snakeDir != LEFT){
                snakeDir = RIGHT;
                break;
            }
        case GLUT_KEY_LEFT:
            if(snakeDir != RIGHT){
                snakeDir = LEFT;
                break;
            }
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        gameStarted = true;
    }
}

void drawStartScreen() {
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
}

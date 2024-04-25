#ifndef GAMELOG_H_INCLUDED
#define GAMELOG_H_INCLUDED

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

#define MAX 60

void initGrid(int, int);
void drawGrid();
void unit(int, int);
void drawSnake();
void drawFood();
void random(int&, int&);

#endif

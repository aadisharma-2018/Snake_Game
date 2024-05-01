#ifndef GAMELOG_H_INCLUDED
#define GAMELOG_H_INCLUDED

#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4

#define MAX 60

class DrawObject {
public:
    virtual void draw() const = 0;

    ~DrawObject(){}
};

class Grid : DrawObject{
public:
    void draw() const override;
    void initGrid(int width, int height);
    void drawGrid();
    void unit(int, int);

    void setWidth(int setWidth){
        width = setWidth;
    }

    void setHeight(int setHeight){
        height = setHeight;
    }

    int getWidth() const{
        return width;
    }
    int getHeight() const{
        return height;
    }

    ~Grid(){}

private:
    int width;
    int height;
};

class Snake : public DrawObject {
public:
    void draw() const override;
    void drawSnake();

    void setLength(int setLength){
        length = setLength;
    }

    int getLength() const {
        return length;
    }

    ~Snake(){}
private:
    int length;
};

class Food : public DrawObject {
public:
    void draw() const override;
    void drawFood();

    ~Food(){}
};

//void initGrid(int, int);
//void drawGrid();
//void unit(int, int);
//void drawSnake();
//void drawFood();
void random(int&, int&);

#endif

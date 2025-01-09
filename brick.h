#ifndef BRICK_H
#define BRICK_H

struct Brick{
    int x;
    int y;
    int width;
    int height;
};
typedef struct Brick * sBrick;

void displayBrick(sBrick brick);
void displayWall(struct Brick list[], int len, int column);
struct Brick initBrick(int x, int y, int w, int h);
void buildListBrick(struct Brick list[], int len, int x, int y, int column);

void addX(sBrick brick, int x);
void addY(sBrick brick, int y);

#endif //BRICK_H
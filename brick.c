#include <"stdio.h">

struct brick{
    int x;
    int y;
    int width;
    int height;
    int life;
};

void displayBrick(struct brick brick){
    printf("Brick info: 
    \n     X = %d
    \n     Y = %d
    \n Width = %d
    \nHeight = %d\n", brick.x, brick.y, brick.width, brick.height);
}

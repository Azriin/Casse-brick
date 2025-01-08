#include <stdio.h>
#include <stdlib.h>
#include "brick.h"

struct Brick{
    int x;
    int y;
    int width;
    int height;
};

void displayBrick(sBrick brick){
    printf("Brick info:\n"); 
    printf("X      = %d\n", brick -> x);
    printf("Y      = %d\n", brick -> y);
    printf("Width  = %d\n", brick -> width);
    printf("Height = %d\n", brick -> height);
}

sBrick initBrick(int x, int y, int w, int h){
    sBrick brick;
    brick = malloc(sizeof(sBrick));
    if (brick == NULL){
        return NULL;
    }
    brick -> x = x;
    brick -> y = y;
    brick -> width = w;
    brick -> height = h;
    return brick;
}

void remBrick(sBrick brick){
    free(brick);
}
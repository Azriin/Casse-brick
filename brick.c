#include <stdio.h>
#include <stdlib.h>
#include "brick.h"


void displayBrick(sBrick brick){
    printf("Brick info:\n"); 
    printf("X      = %d\n", brick -> x);
    printf("Y      = %d\n", brick -> y);
    printf("Width  = %d\n", brick -> width);
    printf("Height = %d\n", brick -> height);
}

void displayWall(struct Brick list[], int len, int column){
    int i = 0;
    while (i < len){
        printf("X:%3d|Y:%3d     ", list[i].x, list[i].y);
        i++;
        if (i%column == 0){
            printf("\n");
        }
    }
    printf("\n");
}

struct Brick initBrick(int x, int y, int w, int h){
    struct Brick brick;
    brick.x = x;
    brick.y = y;
    brick.width = w;
    brick.height = h;
    return brick;
}

void buildListBrick(struct Brick list[], int len, int x, int y, int column){
    int curentX = x;
    int curentY = y;
    int i = 0;
    while (i < len){
        list[i] = initBrick(curentX, curentY, 10, 5);
        i++;
        curentX += 10;
        if (i%column == 0){
            curentY += 5;
            curentX = x;
        }
    }
}

void addX(sBrick brick, int x){
    brick -> x += x;
}

void addY(sBrick brick, int y){
    brick -> y += y;
}


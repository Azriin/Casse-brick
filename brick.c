#include <stdio.h>
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

void displayMatrice(int matrice[LAR][LON]){
    for (int i = 0; i < LAR; i ++){
        for (int j = 0; j < LON; j ++){
            printf("%d", matrice[i][j]);
        }
        printf("\n");
    }
}

struct Brick initBrick(int x, int y, int width, int height){
    struct Brick brick;
    brick.x = x;
    brick.y = y;
    brick.width = width;
    brick.height = height;
    return brick;
}

void buildListBrick(struct Brick list[], int len, int x, int y, int column){
    int curentX = x;
    int curentY = y;
    int i = 0;
    while (i < len){
        list[i] = initBrick(curentX, curentY, W, H);
        i++;
        curentX += W;
        if (i%column == 0){
            curentY += H;
            curentX = x;
        }
    }
}


// collide with brick
// 0000000000000000000000000000000000000000
// 0000544444465444444654444446544444460000
// 00003      23      23      23      20000
// 00003      23      23      23      20000
// 0000711111187111111871111118711111180000
// 0000544444465444444654444446544444460000
// 00003      23      23      23      20000
// 00003      23      23      23      20000
// 0000711111187111111871111118711111180000
// 0000000000000000000000000000000000000000

void buildCollideList(int collideList[LAR][LON], struct Brick lBrick[], int lenB){
    int x, y;
    for (int i = 0; i < LAR; i ++){
        for (int j = 0; j < LON; j ++){
            if (i == 0){
                collideList[i][j] = 1;
            } else if (j == 0){
                collideList[i][j] = 2;
            } else if (j == LON-1){
                collideList[i][j] = 3;
            } else {
                collideList[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < lenB; i ++){
        x = (lBrick[i].x)/H;
        y = (lBrick[i].y)/H;
        for (int j = 0; j < W/H; j++){
            collideList[y][x+j] = 4;
        }
    }
}
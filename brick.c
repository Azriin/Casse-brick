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

void displayMatrice(unsigned char matrice[LAR][LON]){
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

static void addCollideBrick(unsigned char collideList[LAR][LON], struct Brick lBrick[], int lenB){
    int x, y;
    for (int i = 0; i < lenB; i ++){
        x = (lBrick[i].x);
        y = (lBrick[i].y);
        for (int j = 0; j < H; j ++){
            for (int k = 0; k < W; k ++){
                if (j == 0){
                    collideList[y+j][x+k] = 4;
                } else if (j == H-1){
                    collideList[y+j][x+k] = 1;
                } else if (k == 0){
                    collideList[y+j][x+k] = 3;
                } else if (k == W-1) {
                    collideList[y+j][x+k] = 2;
                } 
            }
        }
        collideList[y][x] = 5;
        collideList[y][x+W-1] = 6;
        collideList[y+H-1][x] = 7;
        collideList[y+H-1][x+W-1] = 8;
    }
}

void buildCollideList(unsigned char collideList[LAR][LON], struct Brick lBrick[], int lenB){
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
    addCollideBrick(collideList, lBrick, lenB);
}
#include <stdio.h>
#include "constant.h"
#include "brick.h"
#include "chainLink.h"


void displayBrick(sBrick brick){
    printf("Brick info:\n"); 
    printf("X      = %d\n", brick -> x);
    printf("Y      = %d\n", brick -> y);
    printf("Width  = %d\n", brick -> width);
    printf("Height = %d\n", brick -> height);
}

void displayWall(struct ListLink * list){
    struct Link * link = list -> first;
    int i = 0;
    while (link != NULL){
        printf("i:%2d|X:%3d|Y:%3d     ", i, link -> brick.x, link -> brick.y);
        link = link -> next;
        i++;
        if (i%COLUMN == 0){
            printf("\n");
        }
    }
    printf("\n");
}

void displayMatrice(unsigned char matrice[LAR][LON]){
    for (int i = 0; i < LAR; i ++){
        printf("%2d |", i);
        for (int j = 0; j < LON; j ++){
            if (matrice[i][j] != 0){
                printf("%d", matrice[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

struct Brick initBrick(int x, int y, int width, int height){
    struct Brick brick = {x, y, width, height};
    return brick;
}

int brickEqual(sBrick b1, sBrick b2){
    return (b1 -> x == b2 -> x) && (b1 -> y == b2 -> y);
}

void brickMove(sBrick brick, unsigned char collideList[LAR][LON], int vx){
    int x = brick -> x;
    int y = brick -> y;
    int w = brick -> width;
    int h = brick -> height;
    for (int i = 1; i < h; i ++){
            collideList[y+i][x+vx] = 3;
            collideList[y+i][x+vx+w-1] = 2;
            collideList[y+i][x] = 0;
            collideList[y+i][x+w-1] = 0;
        }
    if (vx > 0){
        collideList[y][x] = 0;
        collideList[y][x+w-1] = 4;
        collideList[y+h-1][x] = 0;
        collideList[y+h-1][x+w-1] = 1;
    } else {
        collideList[y][x] = 4;
        collideList[y][x+w-1] = 0;
        collideList[y+h-1][x] = 1;
        collideList[y+h-1][x+w-1] = 0;
    }
    brick -> x += vx;
    x += vx;
    collideList[y][x] = 5;
    collideList[y][x+w-1] = 6;
    collideList[y+h-1][x] = 7;
    collideList[y+h-1][x+w-1] = 8;
}

void buildListBrick(struct ListLink * list, int len, int x, int y, int column){
    int curentX = x;
    int curentY = y;
    int i = 0;
    while (i < len){
        addLink(list, initLink(curentX, curentY, W, H));
        i++;
        curentX += W;
        if (i%column == 0){
            curentY += H;
            curentX = x;
        }
    }
}

void delBrick(unsigned char collideList[LAR][LON], struct ListLink * list, sBalle balle){
    int x = balle -> x + balle -> vx;
    int y = balle -> y + balle -> vy;
    struct Link * link = findByCoordinate(list, x, y);
    if (link != NULL){
        x = link -> brick.x;
        y = link -> brick.y;
        for (int i = 0; i < link -> brick.height; i ++){
            for (int j = 0; j < link -> brick.width; j ++){
                collideList[y+i][x+j] = 0;                
            }
        }
        remLink(list, link);
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

void addCollideBrick(unsigned char collideList[LAR][LON], sBrick brick){
    int x = brick -> x;
    int y = brick -> y;
    int w = brick -> width;
    int h = brick -> height;
    for (int i = 1; i < w; i ++){
        collideList[y][x+i] = 4;
        collideList[y+h-1][x+i] = 1;
    }
    for (int j = 1; j < h; j ++){
        collideList[y+j][x] = 3;
        collideList[y+j][x+w-1] = 2;
    }
    collideList[y][x] = 5;
    collideList[y][x+w-1] = 6;
    collideList[y+h-1][x] = 7;
    collideList[y+h-1][x+w-1] = 8;
}

void buildCollideList(unsigned char collideList[LAR][LON], struct ListLink * lBrick, sBalle balle){
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
    collideList[0][0] = 8;
    collideList[0][LON-1] = 7;
    struct Link * link = lBrick -> first;
    while(link != NULL){
        addCollideBrick(collideList, &(link -> brick));
        link = link -> next;
    }
    collideList[(int)(balle -> y)][(int)(balle -> x)] = 9;
}

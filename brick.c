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

void displayWall(struct ListLink * list, int column){
    struct Link * link = list -> first;
    int i;
    while (link != NULL){
        printf("X:%3d|Y:%3d     ", link -> brick.x, link -> brick.y);
        if (i%column == 0){
            printf("\n");
        }
        link = link -> next;
        i++;
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
    struct Brick brick = {x, y, width, height};
    return brick;
}

int brickEqual(sBrick b1, sBrick b2){
    return (b1 -> x == b2 -> x) && (b1 -> y == b2 -> y);
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

static void addCollideBrick(unsigned char collideList[LAR][LON], struct ListLink * lBrick){
    int x, y;
    struct Link * current;
    current = lBrick -> first;
    while (current != NULL){
        x = (current -> brick.x);
        y = (current -> brick.y);
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
        current = current -> next;
    }
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
    addCollideBrick(collideList, lBrick);
    collideList[(int)(balle -> y)][(int)(balle -> x)] = 9;
}

void delBrick(unsigned char collideList[LAR][LON], struct ListLink * list, int indice){
    int x, y;
    struct Link * link = findByIndice(list, indice);
    x = link -> brick.x;
    y = link -> brick.y;
    for (int i = 0; i < H; i ++){
        for (int j = 0; j < W; j ++){
            collideList[y+i][x+j] = 0;                
        }
    }
    remLink(list, link);
}
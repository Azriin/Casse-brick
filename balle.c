#include <stdio.h>
#include <math.h>
#include "constant.h"
#include "balle.h"
#include "reflect.h"
#include "brick.h"

void displayBalle(sBalle balle){
    printf("+-----------------+\n");
    printf("|Balle info:      |\n");
    printf("+-----+-----+-----+-----+-----+-----+-----+-----+\n");
    printf("|  X  |  Y  | VX  | VY  |BASE |REMAI|DEVIA|AREA |\n");
    printf("|%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|%.3f|%5d|\n", balle -> x, balle -> y,
    balle -> vx, balle -> vy, balle -> base, balle -> remainder, balle -> deviation, 
    balle -> area);
    printf("+-----+-----+-----+-----+-----+-----+-----+-----+\n");
}

struct Balle initBalle(double x, double y, double vx, double vy){
    struct Balle balle = {x, y, vx, vy, 0.0, 0.0, 0.0, 0};
    return balle;
}

void setVelocity(sBalle balle, double vecteurX, double vecteurY){
    float orientation[] = {vecteurX, vecteurY};
    float direction[] = {balle -> vx, balle -> vy};
    float reflected[2];
    simple2DReflect(orientation, direction, reflected);
    balle -> vx = reflected[0];
    balle -> vy = reflected[1];
}

static void getNext(sBalle balle) {
    balle -> x += balle -> vx;
    if (balle -> remainder < balle -> base) {
        balle -> remainder += (balle -> deviation);
    } else {
        balle -> y += balle -> vy;
        balle -> remainder -= (balle -> base);
    }
}

static void setBaseDeviation(sBalle balle){
    switch (balle -> area){
        case 1:
            balle -> base = fabs(balle -> vx) - fabs(balle -> vy);
            balle -> deviation = fabs(balle -> vy);
            break;
        case 2:
            balle -> base = fabs(balle -> vy) - fabs(balle -> vx);
            balle -> deviation = fabs(balle -> vx);
            break;
    }
}

void collideBall(sBalle balle, unsigned char matrice[LAR][LON], struct ListLink * list){
    int futurX = balle -> x + balle -> vx;
    int futurY = balle -> y + balle -> vy;
    switch (matrice[futurY][futurX]){
        case 1:
            delBrick(matrice, list, balle);
            setVelocity(balle, 0, 1);
            setBaseDeviation(balle);
            balle -> area = 2;
            break;
        case 2:
            delBrick(matrice, list, balle);
            setVelocity(balle, 1, 0);
            setBaseDeviation(balle);
            balle -> area = 1;
            break;
        case 3:
            delBrick(matrice, list, balle);
            setVelocity(balle, -1, 0);
            setBaseDeviation(balle);
            balle -> area = 1;
            break;
        case 4:
            delBrick(matrice, list, balle);
            setVelocity(balle, 0, -1);
            setBaseDeviation(balle);
            balle -> area = 2;
            break;
        case 5:
            delBrick(matrice, list, balle);
            setVelocity(balle, -1, -1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
        case 6:
            delBrick(matrice, list, balle);
            setVelocity(balle, 1, -1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
        case 7:
            delBrick(matrice, list, balle);
            setVelocity(balle, -1, 1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
        case 8:
            delBrick(matrice, list, balle);
            setVelocity(balle, 1, 1);
            setBaseDeviation(balle);
            balle -> area = 0;
            break;
    }
}

void move(sBalle balle, unsigned char matrice[LAR][LON], struct ListLink * list){
    matrice[(int)(balle -> y)][(int)(balle -> x)] = 0;
    collideBall(balle, matrice, list);
    switch (balle -> area) {
        case 0 :
            balle -> x += balle -> vx;
            balle -> y += balle -> vy;
            break;
        case 1 :
            getNext(balle);
            break;
        case 2 :
            getNext(balle);
            break;
    }
    matrice[(int)(balle -> y)][(int)(balle -> x)] = 9;
}
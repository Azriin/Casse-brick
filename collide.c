#include "collide.h"
#include "balle.h"
#include "brick.h"

int getHit(sBalle balle, sBrick birck){
    if ((birck->x <= balle->x && balle->x <= birck->x + brick->width) &&
        (birck->y <= balle->y && balle->y <= birck->y + brick->height)){
            return 1;
    }
    return 0;
}

int normal(){
    return 42;
}

void interact(sBalle balle, struct Brick list[], int len){
    for (int i = 0; i < len; i++){
        if (getHit(balle, list[i]) == 1){

        }
    }
}
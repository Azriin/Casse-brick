#ifndef BRICK_H
#define BRICK_H

typedef struct Brick * sBrick;

void displayBrick(sBrick brick);
sBrick initBrick(int x, int y, int w, int h);
void remBrick(sBrick brick);


#endif //BRICK_H
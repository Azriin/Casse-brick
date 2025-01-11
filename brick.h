#ifndef BRICK_H
#define BRICK_H

#define W 8
#define H 4
#define LON 16
#define LAR 16

struct Brick{
    int x;
    int y;
    int width;
    int height;
};
typedef struct Brick * sBrick;

void displayBrick(sBrick brick);
void displayWall(struct Brick list[], int len, int column);
void displayMatrice(unsigned char matrice[LAR][LON]);
struct Brick initBrick(int x, int y, int width, int height);
void buildListBrick(struct Brick list[], int len, int x, int y, int column);
void buildCollideList(unsigned char collideList[LAR][LON], struct Brick lBrick[], int lenB);

#endif //BRICK_H
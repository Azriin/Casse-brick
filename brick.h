#ifndef BRICK_H
#define BRICK_H

void displayBrick(sBrick brick);
void displayWall(struct ListLink * list);
void displayMatrice(unsigned char matrice[LAR][LON]);

struct Brick initBrick(int x, int y, int width, int height);
int brickEqual(sBrick b1, sBrick b2);
void brickMove(sBrick brick, unsigned char collideList[LAR][LON], int vx);
void buildListBrick(struct ListLink * list, int len, int x, int y, int column);
void delBrick(unsigned char collideList[LAR][LON], struct ListLink * list, sBalle balle);

void addCollideBrick(unsigned char collideList[LAR][LON], sBrick brick);
void buildCollideList(unsigned char collideList[LAR][LON], struct ListLink * lBrick, sBalle balle);

#endif //BRICK_H
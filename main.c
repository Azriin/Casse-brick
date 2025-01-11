#include "brick.h"
#include "balle.h"

#define NBBRICK 2
#define COLUMN 1

int main(void){
  struct Brick list[NBBRICK];
  unsigned char collideList[16][16];
  buildListBrick(list, NBBRICK, 4, 4, COLUMN);
  displayWall(list, NBBRICK, COLUMN);
  buildCollideList(collideList, list, NBBRICK);
  displayMatrice(collideList);
  return 0;
}

#include "brick.h"
#include "balle.h"

#define NBBRICK 23
#define COLUMN 5

int main(void){
  struct Brick list[NBBRICK];
  int collideList[16][16];
  buildListBrick(list, NBBRICK, 12, 12, COLUMN);
  displayWall(list, NBBRICK, COLUMN);
  buildCollideList(collideList, list, NBBRICK);
  displayMatrice(collideList);
  return 0;
}

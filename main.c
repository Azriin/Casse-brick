#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"


int main(void){
  struct ListLink * list;
  unsigned char collideList[LAR][LON];
  struct Balle balle;
  balle = initBalle(15, 13, -1, -1);
  list = initListLink();
  buildListBrick(list, NBBRICK, 4, 4, COLUMN);
  buildCollideList(collideList, list, &balle);
  
  displayBalle(&balle);
  displayWall(list, COLUMN);
  displayMatrice(collideList);
  delBrick(collideList, list, 1);
  move(&balle, collideList);
  displayBalle(&balle);
  displayWall(list, COLUMN);
  displayMatrice(collideList);
  delBrick(collideList, list, 1);
  move(&balle, collideList);
  displayBalle(&balle);
  displayWall(list, COLUMN);
  displayMatrice(collideList);
  
  freeListLink(list);
  return 0;
}

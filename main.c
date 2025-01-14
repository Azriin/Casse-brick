#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"

int main(void){
  struct ListLink * list;
  unsigned char collideList[LAR][LON];
  struct Balle balle;
  balle = initBalle(2, 12, -1, -1);
  list = initListLink();
  buildListBrick(list, NBBRICK, 4, 4, COLUMN);
  buildCollideList(collideList, list, &balle);
  delBrick(collideList, list, 0);
  delBrick(collideList, list, 4);
  delBrick(collideList, list, 1);
  displayWall(list, COLUMN);
  
  // displayBalle(&balle);
  displayMatrice(collideList);
  for (int i = 0; i < 10; i++){
    move(&balle, collideList);
    displayMatrice(collideList);
  }
  
  freeListLink(list);
  return 0;
}

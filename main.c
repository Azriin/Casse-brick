#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"

int main(void){
  struct ListLink * list;
  unsigned char collideList[LAR][LON];
  struct Balle balle;
  // balle = initBalle(19, 15, -1, -1); // collision avec 8 fonctionne
  // balle = initBalle(6, 13, 1, -1); // collision avec 7 fonctionne
  balle = initBalle(13, 13, -1, 0); // collision avec 2
  // balle = initBalle(13, 13, -1, -1);
  // balle = initBalle(13, 13, -1, -1);
  // balle = initBalle(13, 13, -1, -1);
  list = initListLink();
  buildListBrick(list, NBBRICK, 8, 8, COLUMN);
  buildCollideList(collideList, list, &balle);
  // delBrick(collideList, list, 0);
  // delBrick(collideList, list, 4);
  // delBrick(collideList, list, 1);
  displayWall(list, COLUMN);

  displayBalle(&balle);
  displayMatrice(collideList);
  for (int i = 0; i < 10; i++){
    displayBalle(&balle);
    move(&balle, collideList);
    displayMatrice(collideList);
  }

  freeListLink(list);
  return 0;
}

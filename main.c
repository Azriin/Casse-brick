#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"

int main(void){
  struct ListLink * list;
  unsigned char collideList[LAR][LON];
  struct Balle balle;
  balle = initBalle(1, 1, 1, 1);
  list = initListLink();
  buildListBrick(list, NBBRICK, 4, 4, COLUMN);
  buildCollideList(collideList, list, &balle);
  displayWall(list, COLUMN);

  displayBalle(&balle);
  displayMatrice(collideList);
  int i = 0;
  while (i < 100 && balle.y < LAR && list -> len > 0){
    move(&balle, collideList, list);
    displayBalle(&balle);
    displayMatrice(collideList);
    i++;
  }

  freeListLink(list);
  return 0;
}

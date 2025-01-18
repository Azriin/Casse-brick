#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"

int iMoveRacket(int i, int period){
  if (i % period > period/2){
    return -1;
  } return 1;
}

int main(void){
  unsigned char collideList[LAR][LON];
  struct ListLink * list = initListLink();
  struct Balle balle = initBalle(2, 1, 1, 1);
  struct Brick raquette = initBrick(4, 13, 12, 3);
  buildListBrick(list, NBBRICK, 4, 3, COLUMN);
  buildCollideList(collideList, list, &balle);
  addCollideBrick(collideList, &raquette);

  displayWall(list);
  displayBalle(&balle);
  displayMatrice(collideList);
  int i = 0;
  while (i < 100 && balle.y < LAR-1 && list -> len > 0){
    brickMove(&raquette, collideList, iMoveRacket(i, 12));
    move(&balle, collideList, list);
    displayBalle(&balle);
    displayMatrice(collideList);
    i++;
  }
  freeListLink(list);
  return 0;
}

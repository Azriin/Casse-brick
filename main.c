#include "brick.h"
#include "balle.h"

int main(void){
  sBrick brick;
  brick = initBrick(10, 10, 10, 5);
  displayBrick(brick);
  remBrick(brick);
  sBalle balle;
  balle = initBalle(0, 0, 5, 10, 0);
  addDegre(balle, 0.26);
  move(balle);
  displayBalle(balle);
  remBalle(balle);
  return 0;
}

#include "brick.h"
#include "balle.h"

int main(void){
  // Test init single brick
  // struct Brick brick;
  // brick = initBrick(10, 10, 10, 5);
  // sBrick pBrick = &brick;
  // displayBrick(pBrick);
  
  // Test init ball
  // struct Balle balle;
  // balle = initBalle(0, 0, 5, 10, 0);
  // sBalle pBalle = &balle; 
  // addDegre(pBalle, 0.26);
  // move(pBalle);
  // displayBalle(pBalle);

  // Test list of birck
  struct Brick list[23];
  buildListBrick(list, 23, 0, 0, 5);
  displayWall(list, 23, 5);
  return 0;
}

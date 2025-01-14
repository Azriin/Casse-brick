#ifndef BALLE_H
#define BALLE_H

;void displayBalle(sBalle balle);
struct Balle initBalle(double x, double y, double vx, double vy);

void setVelocity(sBalle balle, double vecteurX, double vecteurY);
void collideBall(sBalle balle, unsigned char matrice[LAR][LON]);
void move(sBalle balle, unsigned char matrice[LAR][LON]);

#endif //BALLE_H
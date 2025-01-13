#ifndef BALLE_H
#define BALLE_H

;void displayBalle(sBalle balle);
struct Balle initBalle(double x, double y, double vx, double vy);

double distance(int x, int y);
void setVelocity(sBalle balle, int vecteurX, int vecteurY);
void move(sBalle balle, unsigned char matrice[LAR][LON]);
void collideBall(sBalle balle, unsigned char matrice[LAR][LON]);

#endif //BALLE_H
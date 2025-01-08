#ifndef BALLE_H
#define BALLE_H

typedef struct Balle * sBalle;

void displayBalle(sBalle balle);
sBalle initBalle(double x, double y, int radius, int speed, double degre);
void remBalle(sBalle balle);

void addDegre(sBalle balle, double degre);
void move(sBalle balle);


#endif //BALLE_H
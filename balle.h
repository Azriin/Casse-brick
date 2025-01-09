#ifndef BALLE_H
#define BALLE_H

struct Balle{
    double x;
    double y;
    int radius;
    int speed;
    double degre;
};
typedef struct Balle * sBalle;

void displayBalle(sBalle balle);
struct Balle initBalle(double x, double y, int radius, int speed, double degre);

void addDegre(sBalle balle, double degre);
void move(sBalle balle);


#endif //BALLE_H
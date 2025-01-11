#ifndef BALLE_H
#define BALLE_H

struct Balle{
    double x;
    double y;
    double vx;
    double vy;
    int speed;
    int radius;
};
typedef struct Balle * sBalle;

void displayBalle(sBalle balle);
struct Balle initBalle(double x, double y, double vx, double vy, int speed, int radius);

double distance(int x, int y);
void setVelocity(sBalle balle, int vecteurX, int vecteurY);
void move(sBalle balle);


#endif //BALLE_H
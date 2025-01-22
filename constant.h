#ifndef CONSTANT_H
#define CONSTANT_H

#define NBBRICK 63 //nb total of brick
#define COLUMN 9 //nb brick per column

#define W 8 //width of a brick
#define H 4 //height of a brick
#define LON 80 //width of the screen
#define LAR 60 //height of the screen
#define SCALE 8 //size of picture

struct Balle{
    double x;
    double y;
    double vx;
    double vy;
    double base;
    double remainder;
    double deviation;
    unsigned char area;
};
typedef struct Balle * sBalle;

struct Brick{
    int x;
    int y;
    int width;
    int height;
};
typedef struct Brick * sBrick;

struct Link{
    struct Brick brick;
    struct Link * next;
};

struct ListLink{
    int len;
    struct Link * first;
    struct Link * last;
};

#endif //CONSTANT_H
#ifndef CONSTANT_H
#define CONSTANT_H

#define NBBRICK 6 //nb total of brick
#define COLUMN 3 //nb brick per column

#define W 8 //width of a brick
#define H 4 //height of a brick
#define LON 32 //width of the screen
#define LAR 16 //height of the screen

struct Balle{
    double x;
    double y;
    double vx;
    double vy;
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
}

#endif //CONSTANT_H
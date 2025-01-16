#ifndef CHAINLINK_H
#define CHAINLINK_H

;struct ListLink * initListLink(void);
struct Link * initLink(int x, int y, int width, int height);
void addLink(struct ListLink * list, struct Link * link);
void freeLink(struct Link * link);
void freeListLink(struct ListLink * list);
void remLink(struct ListLink * list, struct Link * link);
// struct Link * findByIndice(struct ListLink * list, int indice);
struct Link * findByCoordinate(struct ListLink * list, double x, double y);

#endif //CHAINLINK_H
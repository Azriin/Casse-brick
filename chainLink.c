#include <stdlib.h> 
#include "constant.h"
#include "chainLink.h"
#include "brick.h"

struct ListLink * initListLink(void){
    struct ListLink * list;
    list = malloc(sizeof(struct ListLink));
    if (list == NULL){
        return NULL;
    }
    list -> len = 0;
    list -> first = NULL;
    list -> last = NULL;
    return list;
}

struct Link * initLink(int x, int y, int width, int height){
    struct Brick brick = {x, y, width, height};
    struct Link * link;
    link = malloc(sizeof(struct Link *));
    if (link == NULL){
        return NULL;
    }
    link -> brick = brick;
    link -> next = NULL;
    return link;
}

void addLink(struct ListLink * list, struct Link * link){
    list -> len ++;
    if (list -> first == NULL){
        list -> first = link;
        list -> last = link;
    } else {
        list -> last -> next = link;
        list -> last = link;
    }
}

void freeLink(struct Link * link){
    free(link);
}

void freeListLink(struct ListLink * list){
    struct Link * toDel;
    struct Link * current;
    current = list -> first;
    while (current != NULL){
        toDel = current;
        current = current ->next;
        freeLink(toDel);
    }
    free(list);
}

void remLink(struct ListLink * list, struct Link * link){
    struct Link * toDel;
    struct Link * current;
    if (link == list -> first){
        toDel = list -> first;
        list -> first = list -> first -> next;
    } else {
        current = list -> first;
        while (current -> next != NULL && !brickEqual(&(current -> next -> brick), &(link -> brick))){
            current = current -> next;
        }
        toDel = current -> next;
        current -> next = toDel -> next;
        if (current -> next == NULL){
            list -> last = current;
        }
    }
    list -> len --;
    freeLink(toDel);
}

struct Link * findByIndice(struct ListLink * list, int indice){
    struct Link * current;
    current = list -> first;
    while (indice > 0){
        current = current -> next;
        indice --;
    }
    return current;
}
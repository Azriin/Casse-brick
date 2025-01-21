#include <SDL.h> 
#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"

#define FPS_LIMIT 1000/30
//Casse brique version ascci
int iMoveRacket(int i, int period){
  if (i % period > period/2){
    return -1;
  } return 1;
}

void casseBriqueAscci(struct ListLink * list, sBalle balle, unsigned char collideList[LAR][LON], sBrick raquette){
  displayWall(list);
  displayBalle(balle);
  displayMatrice(collideList);
  int i = 0;
  while (i < 100 && balle -> y < LAR-1 && list -> len > 0){
    brickMove(raquette, collideList, iMoveRacket(i, 12));
    move(balle, collideList, list);
    displayBalle(balle);
    displayMatrice(collideList);
    i++;
  }
}
//fin casse brique version ascci

//casse brique version graphique
void SDL_ExitWithError(char * message, SDL_Window * window, SDL_Renderer * renderer){
  if (window != NULL)
    SDL_DestroyWindow(window);
  if (renderer != NULL)
    SDL_DestroyRenderer(renderer);
  SDL_Log("ERREUR creation %s sld %s\n", message, SDL_GetError());
  SDL_Quit();
  exit(EXIT_FAILURE);
}

void SDL_LimitFPS(unsigned int limit){
  unsigned int ticks = SDL_GetTicks();
  if (limit < ticks) 
    return;
  else if (limit > ticks) 
    SDL_Delay(FPS_LIMIT);
  else 
    SDL_Delay(limit - ticks);
}

void SDL_DisplayTexture(SDL_Window * window, SDL_Renderer * renderer, unsigned char collideList[LAR][LON]){
  SDL_Texture * texture;
  SDL_Surface * image[10];
  image[0] = SDL_LoadBMP("./images/void.bmp");
  image[1] = SDL_LoadBMP("./images/brique1.bmp");
  image[2] = SDL_LoadBMP("./images/brique2.bmp");
  image[3] = SDL_LoadBMP("./images/brique3.bmp");
  image[4] = SDL_LoadBMP("./images/brique4.bmp");
  image[5] = SDL_LoadBMP("./images/brique5.bmp");
  image[6] = SDL_LoadBMP("./images/brique6.bmp");
  image[7] = SDL_LoadBMP("./images/brique7.bmp");
  image[8] = SDL_LoadBMP("./images/brique8.bmp");
  image[9] = SDL_LoadBMP("./images/balle.bmp");
  for (int i = 0; i < 10; i++){
    if (image[i] == NULL){
      SDL_ExitWithError("image", window, renderer);
    }
  }
  SDL_Rect rectangle;
  for (int h = 1; h < 10; h++){
    texture = SDL_CreateTextureFromSurface(renderer, image[h]); //cree la texture avec l'image
    SDL_FreeSurface(image[h]);
    if (texture == NULL)
      SDL_ExitWithError("texture", window, renderer);
    for (int i = 0; i < LAR; i++){
      for (int j = 0; j < LON; j++){
        if (collideList[i][j] == h){
          if (SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0) //charge l'image en memoire
            SDL_ExitWithError("cahrger la texture", window, renderer);
          rectangle.x = j*SCALE; 
          rectangle.y = i*SCALE;
      
          if (SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0)
            SDL_ExitWithError("affichage texture", window, renderer);
        }
      }
    }
  }
  
  SDL_RenderPresent(renderer); //affiche la texture    
}

SDL_bool SDL_CoreLoop(void){
  SDL_bool program_lunched = SDL_TRUE;
  SDL_Event event;
  while(SDL_PollEvent(&event)){//lit tout les event sans bloquer le programme
    switch (event.type){
      case SDL_QUIT: //si tu appuis sur la crois pour fermer
        program_lunched = SDL_FALSE;
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
          default:
            continue;
          case SDLK_b:
            printf("hello wrold!\n");
            continue;
        }
      case SDL_MOUSEMOTION:
        printf("%d / %d \n", event.motion.x, event.motion.y); // affiche les coo de la souris
        break;
      case SDL_MOUSEBUTTONDOWN:
        printf("clic en %d / %d \n", event.button.x, event.button.y); // affiche les coo du clic de la souris
        if (event.button.clicks >= 2)
          printf("double clic\n");    
        break;
      default:
        break;
    }
  }
  return program_lunched;
}

int main(void){
  //variable jeu
  unsigned char collideList[LAR][LON];
  struct ListLink * list = initListLink();
  struct Balle balle = initBalle(2, 1, 1, 1);
  struct Brick raquette = initBrick(4, 13, 12, 3);
  buildListBrick(list, NBBRICK, 4, 3, COLUMN);
  buildCollideList(collideList, list, &balle);
  addCollideBrick(collideList, &raquette);
  //variable graphique
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_bool program_lunched = SDL_TRUE;
  unsigned int frame_limit = 0;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    SDL_ExitWithError("init", NULL, NULL);
  if (SDL_CreateWindowAndRenderer(LON*SCALE, LAR*SCALE, 0, &window, &renderer) != 0)
    SDL_ExitWithError("fenetre et render", NULL, NULL);
  SDL_DisplayTexture(window, renderer, collideList);
  //coeur du jeu graphique
  while (program_lunched){
    frame_limit = SDL_GetTicks() + FPS_LIMIT;
    SDL_LimitFPS(frame_limit);
    program_lunched = SDL_CoreLoop();
    frame_limit = SDL_GetTicks() + FPS_LIMIT;
  }
  // casseBriqueAscci(list, &balle, collideList, &raquette);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  freeListLink(list);
  return 0;
}

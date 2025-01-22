#include <SDL.h> 
#include "constant.h"
#include "brick.h"
#include "balle.h"
#include "chainLink.h"

#define FPS_LIMIT 1000/50
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

void SDL_LoadTexture(SDL_Window * window, SDL_Renderer * renderer, SDL_Texture * textures[]){
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
    textures[i] = SDL_CreateTextureFromSurface(renderer, image[i]); //cree la texture avec l'image
    SDL_FreeSurface(image[i]);
    if (textures[i] == NULL){
      for (int j = i+1; j < 10; j++){
        SDL_FreeSurface(image[j]);
      }
      SDL_ExitWithError("texture", window, renderer);
    }
  }
}

void SDL_DisplayTexture(SDL_Window * window, SDL_Renderer * renderer, unsigned char collideList[LAR][LON], SDL_Texture * textures[]){
  SDL_Rect rectangle;
  for (int i = 0; i < LAR; i++){
    for (int j = 0; j < LON; j++){
      if (SDL_QueryTexture(textures[collideList[i][j]], NULL, NULL, &rectangle.w, &rectangle.h) != 0)
        SDL_ExitWithError("cahrger la texture", window, renderer);
      rectangle.x = j*SCALE; 
      rectangle.y = i*SCALE;
      if (SDL_RenderCopy(renderer, textures[collideList[i][j]], NULL, &rectangle) != 0)
        SDL_ExitWithError("affichage texture", window, renderer);
    }
  }
  SDL_RenderPresent(renderer); //affiche la texture    
}

SDL_bool SDL_CoreLoop(unsigned char collideList[LAR][LON], sBrick raquette){
  SDL_bool program_lunched = SDL_TRUE;
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    switch (event.type){
      case SDL_QUIT:
        program_lunched = SDL_FALSE;
        break;
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym){
          case SDLK_RIGHT:
            brickMove(raquette, collideList, 1);
            continue;
          case SDLK_LEFT:
            brickMove(raquette, collideList, -1);
            continue;
          case SDLK_RETURN:
            continue;
          case SDLK_ESCAPE:
            program_lunched = SDL_FALSE;
            break;
          default:
            continue;
        }
      default:
        break;
    }
  }
  return program_lunched;
}

void casseBriqueGraphique(struct ListLink * list, sBalle balle, unsigned char collideList[LAR][LON], sBrick raquette){
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_bool program_lunched = SDL_TRUE;
  SDL_Texture * textures[10];
  unsigned int frame_limit = 0;
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
    SDL_ExitWithError("init", NULL, NULL);
  if (SDL_CreateWindowAndRenderer(LON*SCALE, LAR*SCALE, 0, &window, &renderer) != 0)
    SDL_ExitWithError("fenetre et render", NULL, NULL);
  SDL_LoadTexture(window, renderer, textures);
  //coeur du jeu graphique
  while (program_lunched && balle -> y < LAR-1 && list -> len > 0){
    frame_limit = SDL_GetTicks() + FPS_LIMIT;
    move(balle, collideList, list);
    program_lunched = SDL_CoreLoop(collideList, raquette);
    SDL_DisplayTexture(window, renderer, collideList, textures);
    SDL_LimitFPS(frame_limit);
    frame_limit = SDL_GetTicks() + FPS_LIMIT;
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int main(void){
  //variable jeu
  unsigned char collideList[LAR][LON];
  struct ListLink * list = initListLink();
  struct Balle balle = initBalle((LON-1)/2, 50, -1, -1);
  struct Brick raquette = initBrick((LON-2)/2, 55, 2*W, H);
  buildListBrick(list, NBBRICK, 4, 4, COLUMN);
  buildCollideList(collideList, list, &balle);
  addCollideBrick(collideList, &raquette);
  
  casseBriqueGraphique(list, &balle, collideList, &raquette);
  // casseBriqueAscci(list, &balle, collideList, &raquette);
  
  freeListLink(list);
  return 0;
}

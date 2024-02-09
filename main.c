/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/
#include"pers.h"

int main(int argc,char** argv)
{  
    int continuer=1;
  
   SDL_Event event; 

    SDL_Surface* screen;
    SDL_Surface *backg;// background 
    
   
    int dep=0;
    int numkeys;
    Uint8 * keys;
    
    personne S ;
    /**/ personne St ;
    
    
    Uint32 tprev,dt;
    
    SDL_Init(SDL_INIT_VIDEO);
    
  screen = SDL_SetVideoMode(1300,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
  

  int score=2;
  int a,b;
 initperso(&S);
  /**/initperso1(&St);


  backg=IMG_Load("menu.png");
   
  while(continuer)
 {
     SDL_PollEvent(&event);
     switch(event.type)
     { 
        case SDL_QUIT:
            continuer = 0;
         break;
  
     }
    
 tprev = SDL_GetTicks();
     
     /*SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
     SDL_PumpEvents();*/
 
      
       afficherperso(&S,screen);
      /**/ afficherperso(&St,screen);
       
      keys = SDL_GetKeyState(&numkeys);
       Updateperso(&S,keys);
       /**/Updateperso1(&St,keys);
       
       Miseajour(&S,screen);
       /**/Miseajour(&St,screen);
       
    SDL_Flip(screen);
    SDL_BlitSurface(backg,NULL,screen,NULL);//background
       
   dt = SDL_GetTicks() - tprev;
   if (dt<20)
   {
     SDL_Delay(20-dt);
   }   
            
 }
    
    SDL_Quit();
    return 0;
}

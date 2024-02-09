#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

#define STAT_SOL 0
#define STAT_AIR 1

typedef struct
{
    int status,num,dr,vi;
    float x,y;
    float vx,vy;
 
 SDL_Rect posperso,vie;
 SDL_Surface *tab[20],*tabvie[3]; 
 
    int dep,acc,vitesse;
    int vieper;

} personne;



////////////////////////////////////// LES FONCTIONS :

//1
void initperso(personne* p); 
void Miseajour(personne* p,SDL_Surface* screen);

//2
void afficherperso(personne* p,SDL_Surface *ecran);

//3
void deplacerperso(personne *p);

//4
void Saute(personne* p,float impulsion);
void ControleSol(personne* p);
void Gravite(personne* p,float factgravite,float factsautmaintenu,Uint8* keys);

//5
void animerperso(personne* p);
void Updateperso(personne* p,Uint8* keys);


////////////// TACHE BLANCHE //////////////
void Updateperso1(personne* p1,Uint8* keys);
void initperso1(personne* p1);



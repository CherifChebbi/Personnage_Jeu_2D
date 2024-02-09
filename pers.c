/**
* @file pers.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for background scrollilng
*
*/

#include"pers.h"


/////////////////////////////////////////////////////////
void initperso(personne* p)
{
    p->x = 150.0f;
    p->y = 400.0f;
    p->status = STAT_SOL;
    p->vx = p->vy = 0.0f;

    p->vitesse=5;
    p->acc=0;

    p->num=1;
    p->dr=-1;

    p->vi=0;
    p->vie.x=500;
    p->vie.y=0;

    

  char nomFich[20];
  int i;
  for(i=0;i<20;i++)
  {
    sprintf(nomFich,"perssonne%d.png",i);
    p->tab[i]=IMG_Load(nomFich);
  }

  char nomvie[20];
  int j;
  for(j=0;j<4;j++)
  {
    sprintf(nomvie,"v%d.png",j);
    p->tabvie[j]=IMG_Load(nomvie);
  }

}
 

/////////////////////////////////////////////////////////
void Miseajour(personne* p,SDL_Surface* screen)
{
   
   p->posperso.x = (Sint16)p->x;
   p->posperso.y = (Sint16)p->y;
   p->posperso.w = 20;
   p->posperso.h = 40;
  
}
 

/////////////////////////////////////////////////////////
void afficherperso(personne* p,SDL_Surface *ecran)
{  
   SDL_BlitSurface(p->tab[p->num],NULL,ecran,&(p->posperso));
   SDL_BlitSurface(p->tabvie[p->vi],NULL,ecran,&(p->vie));
}
 

/////////////////////////////////////////////////////////
void Saute(personne* p,float impulsion)
{
    p->vy = -impulsion;
    p->status = STAT_AIR;
}



/////////////////////////////////////////////////////////
void deplacerperso(personne *p)
{
   if(p->dep==1)
   {
     p->x+=((0.5*p->acc)+(p->vitesse));
   }
   else if(p->dep==0)
   {
     p->x-=((0.5*p->acc)+(p->vitesse));
   }

}


/////////////////////////////////////////////////////////
void ControleSol(personne* p)
{
    if (p->y >400.0f)
    {
        p->y = 400.0f;
        if (p->vy>0)
            p->vy = 0.0f;
        p->status = STAT_SOL;
    }
}


/////////////////////////////////////////////////////////
void Gravite(personne* p,float factgravite,float factsautmaintenu,Uint8* keys)
{

    if (p->status == STAT_AIR &&( keys[SDLK_UP]||keys[SDLK_z]))
        factgravite/=factsautmaintenu;
    p->vy += factgravite;
    
}


/////////////////////////////////////////////////////////
void animerperso(personne* p)
 {  
 
     if(p->dr==0)
     {
        if(p->num >=5)
        {
          p->num=1;
        }
        else 
        {
          p->num++;
        }
     }
     
     else if(p->dr==1)
     {
        if(p->num==10||p->num<6||p->num>11)
        {
          p->num=6;     
        }
        else
        {
          p->num++;
        } 
     }
     
     else if(p->dr==2)
     {
        if(p->num==13||p->num<11||p->num>14)
        {
          p->num=11;
        }
        else 
        {
          p->num++;
        }
     }
 
     else if(p->dr==3)
     {
        p->num=16;
     }
     
     else if(p->dr==4)
     {
        p->num=17;
     }
     else 
     {
         if(p->num==15||p->num<14||p->num>16)
         {
            p->num=14;
         }
         else
         {
            p->num++;
         } 
     }
 
}


/////////////////////////////////////////////////////////
void Updateperso(personne* p,Uint8* keys)
{ 

    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
    
    if (keys[SDLK_RIGHT]==0 && keys[SDLK_LEFT]==0 && keys[SDLK_j]==0 && keys[SDLK_UP]==0 && keys[SDLK_w]==0)
    { 
      p->dr=-1;
       animerperso(p);
    }

    if (keys[SDLK_RIGHT]==1)
    { 
      p->dep=1;
       deplacerperso(p);
       p->dr=0;
       animerperso(p);
    }
    
    if (keys[SDLK_j])
    { 
      p->dr=2;
       animerperso(p);
       
    }
    
    if (keys[SDLK_w])
    {
       p->acc=20;
       p->dr=4;
       animerperso(p);
    }
    
    if (keys[SDLK_a])
    {
       p->acc=0;
    }
       
    if (keys[SDLK_f])
    { 
       p->vi=1;
    }
 
    if (keys[SDLK_LEFT])
    { 
       p->dep=0;
       deplacerperso(p);
       p->dr=1;
       animerperso(p);
    }
    
    if (keys[SDLK_UP] && p->status == STAT_SOL)
    {  
       Saute(p,impulsion);
       p->dr=3;
       animerperso(p);
    }
    
    
    Gravite(p,factgravite,factsautmaintenu,keys);
    ControleSol(p);
      
    p->x +=p->vx;
    p->y +=p->vy;


}

/////////////////////////////////////////////////////////
void initperso1(personne* p1)
{
    p1->x = 100.0f;
    p1->y = 350.0f;
    p1->status = STAT_SOL;
    p1->vx = p1->vy = 0.0f;

    p1->vitesse=5;
    p1->acc=0;

    p1->num=1;
    p1->dr=-1;

    p1->vi=0;
    p1->vie.x=500;
    p1->vie.y=0;

    

  char nomFich[20];
  int i;
  for(i=0;i<20;i++)
  {
    sprintf(nomFich,"perssonnee%d.png",i);
    p1->tab[i]=IMG_Load(nomFich);
  }

  char nomvie[20];
  int j;
  for(j=0;j<4;j++)
  {
    sprintf(nomvie,"v%d.png",j);
    p1->tabvie[j]=IMG_Load(nomvie);
  }

}

/////////////////////////////////////////////////////////
void Updateperso1(personne* p1,Uint8* keys)
{ 

    float impulsion = 6.0f;
    float factgravite = 0.5f;
    float factsautmaintenu = 3.0f;
    
    if (keys[SDLK_d]==0 && keys[SDLK_q]==0 && keys[SDLK_h]==0 && keys[SDLK_z]==0 )
    { 
      p1->dr=-1;
       animerperso(p1);
    }

    if (keys[SDLK_d]==1)
    { 
      p1->dep=1;
       deplacerperso(p1);
       p1->dr=0;
       animerperso(p1);
    }
    
    if (keys[SDLK_h])
    { 
      p1->dr=2;
       animerperso(p1);
       
    }
    
    if (keys[SDLK_w])
    {
       p1->acc=20;
       p1->dr=4;
       animerperso(p1);
    }
    
    if (keys[SDLK_a])
    {
       p1->acc=0;
    }
       
    if (keys[SDLK_f])
    { 
       p1->vi=1;
    }
 
    if (keys[SDLK_q])
    { 
       p1->dep=0;
       deplacerperso(p1);
       p1->dr=1;
       animerperso(p1);
    }
    
    if (keys[SDLK_z] && p1->status == STAT_SOL)
    {  
       Saute(p1,impulsion);
       p1->dr=3;
       animerperso(p1);
    }
    
    
    Gravite(p1,factgravite,factsautmaintenu,keys);
    ControleSol(p1);
      
    p1->x +=p1->vx;
    p1->y +=p1->vy;


}


/////////////////////////////////////////////////////////


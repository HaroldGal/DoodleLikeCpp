#pragma once
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <list>
#include <time.h>
using namespace std;


class Jeu{
protected:
  list<Plateforme> liste_plateforme;
  Personnage* perso;
  Fond* ecran;
public:
  Jeu(){
    srand(time(NULL));
    SDL_Rect* p;

    //init du fond
    p = new(SDL_Rect);
    p->x = 0;
    p->y = 0;
    ecran = new Fond(640,480,p, "Img/sky.bmp");
    ecran->init();

    //init du perso
    p = new(SDL_Rect);
    p->x = 300;
    p->y = 300;
    perso = new Personnage(50,50, p, "Img/perso2.bmp",ecran);

    //init des plate forme de depart
    p = new(SDL_Rect);
    p->x = 200;
    p->y = 250;
    liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));
    int nb_p = rand()%6 + 3;
    for(int i=0; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = rand()%480;
      liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));
    }
  }

  Personnage* get_perso(){return perso;}
  
  void maj(){
    ecran->maj(); 
    for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)
     {
      if(it->touche(perso) == 1)  perso->rebond();
        it->coller();
     }
    perso->coller();
    SDL_Flip(ecran->get());
  }
  
};
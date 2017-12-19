#pragma once
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <list>
#include <time.h>
using namespace std;


class Jeu{
protected:
  list<Monstre> liste_monstre;
  list<Plateforme> liste_plateforme;
  Personnage* perso;
  Fond* ecran;
  int hauteur_relative_personnage;

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
    hauteur_relative_personnage = 480;

    //init des plate forme de depart
    p = new(SDL_Rect);
    p->x = 200;
    p->y = 350;
    liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));

    int nb_p = rand()%2 + 3; // plateformes basses
    for(int i=1; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = 300 + rand()%180;
      liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));
    }

    nb_p = rand()%2 + 3; // plateformes moyennes
    for(int i=1; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = 200 + rand()%100;
      liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));
    }

    nb_p = rand()%2 + 3; // plateformes hautes
    for(int i=1; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = 50 + rand()%200;
      liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));
    }

     int nb_m;

     for (int i=1; i<10; i++){
      nb_m = rand()%3;
      if(nb_m==0)
      {
      	p=new(SDL_Rect);
      	p->x = rand()%640;
      	p->y = i*48;
      	liste_monstre.push_back(Monstre(200,50, p, "Img/mechant.bmp",ecran));
      }

     } 
 }

  Personnage* get_perso(){return perso;}
  
  void maj(){
    ecran->maj(); 
    for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)
     {
      if(it->touche(perso) == 1){
        perso->rebond();
        hauteur_relative_personnage = perso->get_pos()->y; // on a touché une plateforme on change la position du perso
      }
      if(it->get_pos()->y >0 && it->get_pos()->x >0)
        it->coller();
     }

     for(list<Monstre>::iterator it=liste_monstre.begin(); it!=liste_monstre.end(); it++)
     {
     	it->coller();
     }

   // on decale tout par rapport a notre perso (scrollling)
   if(hauteur_relative_personnage < 350)  decaller_plateforme();
  
    // suppression des plateforme inutiles
   delete_elem();

   // on ajoute tjrs une plate forme en rab au dessus
   if(hauteur_max_plateforme()>0) ajouter_plateforme(hauteur_max_plateforme()-100);
    perso->coller();
    SDL_Flip(ecran->get());
  }

int hauteur_max_plateforme(){
  int z = 480;
  for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)
     {
      if(it->get_pos()->y<z) z = it->get_pos()->y;
     }
     return z;
}

// ajouter une plate forme à la hauteur y
void ajouter_plateforme(int hauteur)
{ 
  //srand(time(NULL));
  SDL_Rect* p = new(SDL_Rect);
  p->x = rand()%640;
  p->y = hauteur;
  liste_plateforme.push_back(Plateforme(200,50, p, "Img/plateforme.bmp",ecran));


}

void decaller_monstre()
{
  for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)   it->deplacement(2);

  hauteur_relative_personnage += 2;
}

void decaller_plateforme()
{
  for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)   it->deplacement(2);

  hauteur_relative_personnage += 2;
}

void delete_elem(){
  list<Plateforme>::iterator it, itdel;
  it = liste_plateforme.begin();
  while(it!=liste_plateforme.end()){
    if( it->get_pos()->y > 480){
      itdel=it;
      it++;
      liste_plateforme.erase(itdel);
    }
    else{
      it++;
    }
  }
}

};

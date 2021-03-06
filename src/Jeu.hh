#pragma once
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <list>
#include <time.h>
using namespace std;


class Jeu{
protected:
  //list<Monstre> liste_monstre;
  list<Plateforme> liste_plateforme;
  Personnage* perso;
  Fond* ecran;
  int hauteur_relative_personnage;
  int score;
  Score* display_score;

public:
  Jeu(){
    score = 0;
    srand(time(NULL));
    SDL_Rect* p;

    //init du fond
    p = new(SDL_Rect);
    p->x = 0;
    p->y = 0;
    ecran = new Fond(640,480,p, "../Img/sky.bmp");
    ecran->init();

    // init du score
    p = new(SDL_Rect);
    p->x = 400;
    p->y = 20;
    display_score = new Score(100,50, p, "../data/angelina.TTF", ecran);

    //init du perso
    p = new(SDL_Rect);
    p->x = 300;
    p->y = 300;
    perso = new Personnage(50,50, p, "../Img/perso2.bmp",ecran);
    hauteur_relative_personnage = 480;

    //init des plate forme de depart
    p = new(SDL_Rect);
    p->x = 200;
    p->y = 350;
    liste_plateforme.push_back(Plateforme(200,50, p, "../Img/plateforme2.bmp",ecran));

    int nb_p = rand()%2 + 3; // plateformes basses
    for(int i=1; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = 300 + rand()%180;
      liste_plateforme.push_back(Plateforme(200,50, p, "../Img/plateforme2.bmp",ecran));
    }

    nb_p = rand()%2 + 3; // plateformes moyennes
    for(int i=1; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = 200 + rand()%100;
      liste_plateforme.push_back(Plateforme(200,50, p, "../Img/plateforme2.bmp",ecran));
    }

    nb_p = rand()%2 + 3; // plateformes hautes
    for(int i=1; i< nb_p; i++){
      p = new(SDL_Rect);
      p->x = rand()%640;
      p->y = 50 + rand()%200;
      liste_plateforme.push_back(Plateforme(200,50, p, "../Img/plateforme2.bmp",ecran));
    }
 }

 ~Jeu(){
    delete ecran;
    delete display_score;
    delete perso;
 }
  Personnage* get_perso(){return perso;}
  
  int maj(){
    delete_elem();
    ecran->maj(); 
    for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)
     {
      if(it->touche(perso) == 1 && perso->chute()==1){
        perso->rebond();
        score += hauteur_relative_personnage - (*perso)()->y;
        hauteur_relative_personnage = (*perso)()->y; // on a touché une plateforme on change la position du perso
      }

      it->deplacement(2,0);
      if((*it)()->y >0 && (*it)()->x >0) (*it)>>ecran;
     }

    score = (hauteur_relative_personnage - (*perso)()->y > score)? score + hauteur_relative_personnage - (*perso)()->y : score;
/*
     for(list<Monstre>::iterator it=liste_monstre.begin(); it!=liste_monstre.end(); it++)
     {
     	it->coller();
     }
*/
   // on decale tout par rapport a notre perso (scrollling)
   if(hauteur_relative_personnage < 350)  decaler_elements();
  
    // suppression des plateforme inutiles
   display_score->donner_score(score);
   (*display_score)>>ecran;

   // on ajoute tjrs une plate forme en rab au dessus
   if(hauteur_max_plateforme()>0) ajouter_plateforme(hauteur_max_plateforme()-100, (score<20000)? score/1000 : 20);
    (*perso)>>ecran;
    SDL_Flip(ecran->get());
  if((*perso)()->y > ecran->get_taille_y()) return 0;
    return 1;
  }

int hauteur_max_plateforme(){
  int z = 480;
  for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)
     {
      if((*it)()->y<z) z = (*it)()->y;
     }
     return z;
}

// ajouter une plate forme à la hauteur y
void ajouter_plateforme(int hauteur, int difficulte=0)
{ 
  SDL_Rect* p = new(SDL_Rect);
  p->x = rand()%(640-100);
  p->y = hauteur;
  int type = rand()%20;
  if(type > difficulte)
  liste_plateforme.push_back(Plateforme(200,50, p, "../Img/plateforme2.bmp",ecran,(difficulte<10)?difficulte:10));
  else  if(type>difficulte - 5)
    liste_plateforme.push_back(Plateforme(100,50, p, "../Img/moyenneplateforme2.bmp",ecran,(difficulte<10)?difficulte:10));
  else{
    if(rand()%2 == 0)
      liste_plateforme.push_back(Plateforme(50,50, p, "../Img/miniplateforme2.bmp",ecran,(difficulte<10)?difficulte:10));
    else liste_plateforme.push_back(Plateforme(100,50, p, "../Img/moyenneplateforme2.bmp",ecran,(difficulte<10)?difficulte:10));
}


}

void decaler_elements()
{
  for(list<Plateforme>::iterator it=liste_plateforme.begin(); it!=liste_plateforme.end(); it++)   it->deplacement(0,2);
  //for(list<Monstre>::iterator it=liste_monstre.begin(); it!=liste_monstre.end(); it++)   it->deplacement(0,3);
  perso->deplacement(0,2);

  hauteur_relative_personnage += 2;
}

void delete_elem(){
  list<Plateforme>::iterator it, itdel;
  it = liste_plateforme.begin();
  while(it!=liste_plateforme.end()){
    if( (*it)()->y > 480){
      itdel=it;
      it++;
      liste_plateforme.erase(itdel);
    }
    else{
      it++;
    }
  }
  
}

void cheatscore(int i)
{
  score = score + i ;
}
int game_over()
{
  SDL_Surface* over;
  over = SDL_LoadBMP("../Img/gameover.bmp");
  SDL_SetAlpha(over, SDL_SRCALPHA, 150);
  SDL_Rect pos;
  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(over, NULL, ecran->get(), &pos);
  SDL_Flip(ecran->get());
  SDL_Event event;
  int continuer = 1;
  while (continuer)
  {
      SDL_WaitEvent(&event);
      switch(event.type)
      {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
              case SDLK_q: 
                    continuer = 0;
                    break;
              case SDLK_r: 
                    delete over;
                    return 1;
                    break;
              default:
              break;
            }
          break;  

      default:
        break;   
    }
  }
  delete over;
  return 0;
}

void quitter_jeu()
{
  SDL_Quit();
}

};

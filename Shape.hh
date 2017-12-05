#pragma once
#include <iostream>
#include <string>
#include <SDL/SDL.h>
using namespace std;


class Shape{
protected:
  SDL_Surface* rectangle;
  int taille_x;
  int taille_y;
  int pix; // bits par pixel
  SDL_Rect* position_init;
  const string image;
public:
  SDL_Surface* get(){return rectangle;}
  Shape():rectangle(NULL), taille_y(0), taille_x(0),pix(32), position_init(NULL),image(""){}
  Shape(int x, int y, SDL_Rect* pos, string im): rectangle(NULL), taille_y(y), taille_x(x),pix(32), position_init(pos),image(im){}
   //void coller(SDL_Surface* ecran, SDL_Rect* pos) =0;
  
};
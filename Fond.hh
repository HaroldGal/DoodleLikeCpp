#include "Shape.hh"
#pragma once

class Fond : public Shape
{
protected:
	SDL_Surface* fenetre;
public:
	Fond():Shape(){}
	Fond(int x, int y, SDL_Rect* pos,const string im):Shape(x, y, pos, im){}
	~Fond(){}
	void init()
	{
		SDL_Init(SDL_INIT_VIDEO);
		fenetre = SDL_SetVideoMode(taille_x, taille_y, pix, SDL_HWSURFACE | SDL_DOUBLEBUF);
		rectangle = SDL_LoadBMP(image.c_str());
	}
	
	SDL_Surface* get(){return fenetre;}

	void maj()
	{
		SDL_BlitSurface(rectangle, NULL, fenetre, position_init);
	}
};
#include "Shape.hh"
#pragma once

class Fond : public Shape
{
public:
	Fond():Shape(){}
	Fond(int x, int y, SDL_Rect* pos,const string im):Shape(x, y, pos, im){}

	void init()
	{
		SDL_Init(SDL_INIT_VIDEO);
		rectangle = SDL_SetVideoMode(taille_x, taille_y, pix, SDL_HWSURFACE | SDL_DOUBLEBUF);
	}
	void maj()
	{
		SDL_Surface* decor;
		decor = SDL_LoadBMP(image.c_str());
		SDL_BlitSurface(decor, NULL, rectangle, position_init);
		SDL_Flip(rectangle);
	}
};
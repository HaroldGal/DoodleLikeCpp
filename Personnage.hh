#include "Element.hh"
#pragma once 

class Personnage: public Element {

public:
	Personnage():Element(){}
	Personnage(int x, int y, SDL_Rect* pos, const string im, Fond _dec):Element(x,y,pos,im,_dec){}
	void deplacement(){}
	void coller()
	{
		rectangle = SDL_LoadBMP(image.c_str());
		SDL_BlitSurface(rectangle, NULL, decor.get(), position_init);
		SDL_Flip(decor.get());
	}

};
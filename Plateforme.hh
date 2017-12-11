#include "Element.hh"
#pragma once 

class Plateforme: public Element {
public:
	Plateforme():Element(){}
	Plateforme(int x, int y, SDL_Rect* pos, const string im, Fond _dec):Element(x,y,pos,im,_dec){
		rectangle = SDL_LoadBMP(image.c_str());
	}
	void deplacement(int i){}
	void coller()
	{
		SDL_SetColorKey(rectangle, SDL_SRCCOLORKEY, SDL_MapRGB(rectangle->format, 0, 0, 255));
		SDL_BlitSurface(rectangle, NULL, decor.get(), position_init);
	}

};
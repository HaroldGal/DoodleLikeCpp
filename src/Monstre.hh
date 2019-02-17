#include "Element.hh"
#pragma once 

class Monstre : public Element{
public:
	 Monstre():Element(){}
	 ~Monstre(){};
	 Monstre(int x, int y, SDL_Rect* pos, const string im, Fond* _dec):Element(x,y,pos,im,_dec){
		rectangle = SDL_LoadBMP(image.c_str());
	}
	
	void deplacement(int i, int j){
		position_init->y += j;
	}
	void coller()
	{
		SDL_SetColorKey(rectangle, SDL_SRCCOLORKEY, SDL_MapRGB(rectangle->format, 255,0,0));
		SDL_BlitSurface(rectangle, NULL, decor->get(), position_init);
	}
};

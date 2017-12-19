#include "Element.hh"
#pragma once 

class Plateforme: public Element {
public:
	Plateforme():Element(){}
	Plateforme(int x, int y, SDL_Rect* pos, const string im, Fond* _dec):Element(x,y,pos,im,_dec){
		rectangle = SDL_LoadBMP(image.c_str());
	}
	void deplacement(int i){
		position_init->y += i;
	}
	void coller()
	{
		SDL_SetColorKey(rectangle, SDL_SRCCOLORKEY, SDL_MapRGB(rectangle->format, 0, 0, 255));
		SDL_BlitSurface(rectangle, NULL, decor->get(), position_init);
	}
	int touche(Personnage* perso){
		SDL_Rect* perso_pos = perso->get_pos();
		if( perso_pos->y+55 > position_init->y &&  perso_pos->y+45 < position_init->y ){ // hit box
			if( perso_pos->x < position_init->x + taille_x +5 &&  perso_pos->x > position_init->x -45 )
				return 1;
		}
		return 0;
	}

};
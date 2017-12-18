#include "Element.hh"
#pragma once 

class Personnage: public Element {
protected:
	int poids;
	int impulsion;
	int vitesse;
public:
	Personnage():Element(){}
	Personnage(int x, int y, SDL_Rect* pos, const string im, Fond* _dec):Element(x,y,pos,im,_dec), poids(1), impulsion(20), vitesse(20){
		rectangle = SDL_LoadBMP(image.c_str());
	}
	void deplacement(int i){ 
		position_init->x = (decor->get_taille_x() + position_init->x+i)%decor->get_taille_x();
		position_init->y = (position_init->y - vitesse);
		vitesse -= poids;
		}
	void coller()
	{
		SDL_SetColorKey(rectangle, SDL_SRCCOLORKEY, SDL_MapRGB(rectangle->format, 0, 0, 255));
		SDL_BlitSurface(rectangle, NULL, decor->get(), position_init);
	}

	void rebond()
	{
		vitesse = impulsion;
	}

};
#include "Element.hh"
#pragma once 

class Personnage: public Element {
protected:
	float poids;
	float impulsion;
	float vitesse;
public:
	Personnage():Element(){}
	Personnage(int x, int y, SDL_Rect* pos, const string im, Fond* _dec):Element(x,y,pos,im,_dec), poids(0.1), impulsion(5), vitesse(5){
		rectangle = SDL_LoadBMP(image.c_str());
	}
	~Personnage(){};
	void deplacement(int i, int j){ 
		position_init->x = (decor->get_taille_x() + position_init->x+i)%decor->get_taille_x();
		if(j==0){
		position_init->y = (position_init->y - vitesse);
		vitesse -= poids;
	}
		else position_init->y +=j; // cas du simple decalage
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

	int chute() // retourne 1 si le perso est en chute 0 si il monte
	{
		if(vitesse>0) return 0;
		return 1;
	}

};
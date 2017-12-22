#include "Element.hh"
#pragma once 

class Bonus: public Plateforme {
	int type_bonus;
	SDL_Surface* motif;
	int pris;
public:
	Bonus():Plateforme(){}
	Bonus(int x, int y, SDL_Rect* pos, const string im, Fond* _dec, int proba_mouvante = 0):Plateforme(x,y,pos,im,_dec, 0){
		type_bonus = rand()%2;
		pris = 1;
	}
	~Bonus(){};

	void coller()
	{
		SDL_SetColorKey(rectangle, SDL_SRCCOLORKEY, SDL_MapRGB(rectangle->format, 0, 0, 255));
		SDL_BlitSurface(rectangle, NULL, decor->get(), position_init);
		if(pris){
			motif = SDL_LoadBMP("Img/bonus1.bmp");
			SDL_SetColorKey(motif, SDL_SRCCOLORKEY, SDL_MapRGB(motif->format, 0, 0, 255));
			SDL_BlitSurface(motif, NULL, decor->get(), position_init);

	}
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
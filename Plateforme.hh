#include "Element.hh"
#pragma once 

class Plateforme: public Element {
	bool mouvante;
	int sens; // 0 gauche 1 droite
	int limite;
public:
	Plateforme():Element(){}
	Plateforme(int x, int y, SDL_Rect* pos, const string im, Fond* _dec, int proba_mouvante = 0):Element(x,y,pos,im){
		limite=_dec->get_taille_x();
		rectangle = SDL_LoadBMP(image.c_str());
		if(rand()%10<proba_mouvante){ 
			mouvante =true; 
			sens = rand()%2;
		}
		else mouvante=false;
	}
	~Plateforme(){};
	void deplacement(int i, int j){
		position_init->y += j;
		if(mouvante){
			if(sens == 1) position_init->x += i;
			else position_init->x -= i;
		if((position_init->x+taille_x) > limite) sens = 0;
		else if((position_init->x) < 20) sens = 1;
	}
	}

	void operator>>(Fond* decor)
	{
		SDL_SetColorKey(rectangle, SDL_SRCCOLORKEY, SDL_MapRGB(rectangle->format, 0, 0, 255));
		SDL_BlitSurface(rectangle, NULL, decor->get(), position_init);
	}
	int touche(Personnage* perso){
		SDL_Rect* perso_pos = (*perso)();
		if( perso_pos->y+55 > position_init->y &&  perso_pos->y+45 < position_init->y ){ // hit box
			if( perso_pos->x < position_init->x + taille_x +5 &&  perso_pos->x > position_init->x -45 )
				return 1;
		}
		return 0;
	}

};
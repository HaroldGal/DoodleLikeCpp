#include "Element.hh"
#pragma once 

class Score : public Element{
protected:
	 TTF_Font *police;
	 string score_actuel;
	 SDL_Color couleur;
public:
	 Score():Element(){}
	 Score(int x, int y, SDL_Rect* pos, const string im, Fond* _dec):Element(x,y,pos,im,_dec){
		police = TTF_OpenFont(image.c_str(), 30);
		TTF_SetFontStyle(police, TTF_STYLE_BOLD);
		score_actuel ="";
		couleur = {0, 0, 0};

	}
	
	void deplacement(int i, int j){}
	void coller()
	{
	    rectangle = TTF_RenderText_Blended(police, score_actuel.c_str(), couleur);
		SDL_BlitSurface(rectangle, NULL, decor->get(), position_init);
	}

	void donner_score(int i)
	{	
		score_actuel = "Score = " + to_string(i);
	}
};

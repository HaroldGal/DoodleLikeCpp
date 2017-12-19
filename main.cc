#include "Shape.hh"
#include "Fond.hh"
#include "Personnage.hh"
#include "Element.hh"
#include "Plateforme.hh"
#include <list>
#include <time.h>
#include "Jeu.hh"

void lancer_jeu(/*Fond ecran*/)
{
	Jeu partie;

	SDL_Event event;
	SDL_EnableKeyRepeat(10, 5); //1. delai de depart, 2. delai entre 2 activ avec touche enfonce
	int continuer = 1;
	while (continuer)
	{
    	SDL_PollEvent(&event);
    	switch(event.type)
    	{
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arrête le programme */
                    continuer = 0;
                    break;
	            case SDLK_RIGHT: // Flèche droite
	            	partie.get_perso()->deplacement(3); // on se deplace de 3 à droite
	                break;
	            case SDLK_LEFT: // Flèche gauche
	            	partie.get_perso()->deplacement(-3);
	                break;
	            default:
     				//p1.deplacement(0);
	            	partie.get_perso()->deplacement(0);
     				break;
     		break;  
            }
            break;

     	default:
     		partie.get_perso()->deplacement(0);
     		break;   
    }
    partie.maj();
    SDL_Delay(2);

}
}

int main()
{
	lancer_jeu();
	return 0;
}
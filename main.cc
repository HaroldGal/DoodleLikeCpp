#include "Shape.hh"
#include "Fond.hh"
#include "Personnage.hh"
#include "Element.hh"
#include "Plateforme.hh"
#include "Monstre.hh"
#include "Score.hh"
#include "Jeu.hh"
#include "Bonus.hh"

int lancer_jeu(/*Fond ecran*/)
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
	            	partie.get_perso()->deplacement(3,0); // on se deplace de 3 à droite
	                break;
	            case SDLK_LEFT: // Flèche gauche
	            	partie.get_perso()->deplacement(-3,0);
	                break;
                case SDLK_w: // Flèche gauche
                    partie.get_perso()->deplacement(0,-5);
                    break;
	            default:
	            	partie.get_perso()->deplacement(0,0);
     				break;
     		break;  
            }
            break;

     	default:
     		partie.get_perso()->deplacement(0,0);
     		break;   
    }
    if(partie.maj()==0) return partie.game_over();
    SDL_Delay(2);

}
    partie.quitter_jeu();
    return 0;
}

int main()
{
    int i = 1;
    while(i)    i = lancer_jeu(); 
	return 0;
}
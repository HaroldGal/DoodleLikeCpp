#include "Shape.hh"
#include "Fond.hh"
#include "Personnage.hh"
#include "Element.hh"

void pause(Fond ecran)
{

	SDL_Rect pos1;
	pos1.x = 300;
	pos1.y = 300;
	Personnage p1(50,50, &pos1, "Img/perso2.bmp",ecran); // initialisation du personnage

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
	                p1.deplacement(3); // on se déplace de 3 à droite
	                break;
	            case SDLK_LEFT: // Flèche gauche
	                p1.deplacement(-3); // on se déplace de 3 à gauche
	                break;
            }
            break;

     	default:
     		p1.deplacement(0);
     		break;   
    }
    ecran.maj(); 
    p1.coller();
    SDL_Flip(ecran.get());
    SDL_Delay(10);
}
}
int main()
{
	SDL_Rect pos;
	pos.x=0;
	pos.y=0;
	Fond ecran(640,480,&pos, "Img/sky.bmp");
	ecran.init();
	ecran.maj();
	pause(ecran);
	SDL_Quit();
	return 0;
}
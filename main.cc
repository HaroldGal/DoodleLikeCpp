#include "Shape.hh"
#include "Fond.hh"
#include "Personnage.hh"
#include "Element.hh"

void pause(Fond ecran)
{

	SDL_Rect pos1;
	pos1.x = 100;
	pos1.y = 100;
	Personnage p1(50,50, &pos1, "Img/perso2.bmp",ecran);

	SDL_Event event;
	SDL_EnableKeyRepeat(10, 5); //1. delai de depart, 2. delai entre 2 activ avec touche enfonce
	int continuer = 1;
	while (continuer)
	{
    	SDL_WaitEvent(&event);
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
	                p1.deplacement(3);
	                break;
	            case SDLK_LEFT: // Flèche gauche
	                p1.deplacement(-3);
	                break;
            }
            break;
        
    }
    ecran.maj();
    p1.coller();
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
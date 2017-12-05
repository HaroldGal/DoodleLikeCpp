#include "Shape.hh"
#include "Fond.hh"
#include "Personnage.hh"
#include "Element.hh"

void pause()
{
	SDL_Event event;
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
            }
            break;
    }
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
	pause();
	SDL_Rect pos1;
	pos1.x = 100;
	pos1.y = 100;
	Personnage p1(50,50, pos1, "Img/perso.bmp",ecran);
	SDL_Quit();
	return 0;
}
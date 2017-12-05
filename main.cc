#include "Shape.hh"
#include "Fond.hh"

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
	Fond ecran(640,480,&pos, "sky.bmp");
	ecran.init();
	ecran.maj();
	pause();
	SDL_Quit();
	return 0;
}
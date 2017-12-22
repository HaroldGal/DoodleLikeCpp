#include "Shape.hh"
#pragma once

class Element: public Shape{
protected:
	Fond* decor;
public:
	Element():Shape(){}
	Element(Fond* _dec):Shape(), decor(_dec){}
	Element(int x, int y, SDL_Rect* pos, const string im, Fond* _dec):Shape(x,y,pos,im), decor(_dec){}
	virtual void deplacement(int i, int j)=0;
	virtual void coller() =0;
};
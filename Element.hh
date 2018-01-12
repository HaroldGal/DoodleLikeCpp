#include "Shape.hh"
#pragma once

class Element: public Shape{
protected:

public:
	Element():Shape(){}
	~Element(){}
	Element(int x, int y, SDL_Rect* pos, const string im):Shape(x,y,pos,im){}
	virtual void deplacement(int i, int j)=0;
	virtual void operator>>(Fond* decor)=0;
};
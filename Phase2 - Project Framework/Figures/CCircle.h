#ifndef CCircle_H
#define CCircle_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif
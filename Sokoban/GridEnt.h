#ifndef GRIDENT_H
#define GRIDENT_H

#include "Entity.h"

class GridEnt : public Entity
{
public:

	GridEnt(Level* lvl);

	void		Update(float dt);
	void		Draw(sf::RenderWindow* rw);

	bool		Move(int dx, int dy);
	bool		MoveTo(int x, int y);

	PairInt&	GetGridPos();

private:

	PairInt		_GridPos;

};

#endif
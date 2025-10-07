#pragma once

#include "Entity.h"

class GridEnt : public Entity
{
public:

	GridEnt(Level* lvl);

	virtual void		Update(float dt);
	virtual void		Draw(sf::RenderWindow* rw);

	bool		Move(int dx, int dy);
	bool		MoveTo(int x, int y);

	PairInt&	GetGridPos();

private:

	PairInt		_GridPos;

};

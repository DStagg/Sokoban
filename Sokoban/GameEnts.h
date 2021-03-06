#ifndef GAMEENTS_H
#define GAMEENTS_H

#include "GridEnt.h"

class PlayerEnt : public GridEnt
{
public:

	PlayerEnt(Level* lvl);

	void Update(float dt);

private:

	bool TryMove(int dx, int dy);

	float _Timer = 0.f;
};

class BlockEnt : public GridEnt
{
public:

	BlockEnt(Level* lvl);

	void Update(float dt);

private:


};

#endif
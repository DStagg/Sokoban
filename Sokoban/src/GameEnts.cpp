#include "GameEnts.h"
#include "Level.h"

PlayerEnt::PlayerEnt(Level* lvl) : GridEnt(lvl)
{

};

void PlayerEnt::Update(float dt)
{
	_Timer += dt;
	if (_Timer >= 0.1f)
	{
		_Timer = 0.f;
		//	Movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			TryMove(0, -1);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			TryMove(0, 1);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			TryMove(-1, 0);
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			TryMove(1, 0);
	}

	GridEnt::Update(dt);
};

bool PlayerEnt::TryMove(int dx, int dy)
{
	if ((GetLevel()->GetBlock()->GetGridPos()._X == GetGridPos()._X + dx) && (GetLevel()->GetBlock()->GetGridPos()._Y == GetGridPos()._Y + dy))
	{
		if (GetLevel()->GetBlock()->Move(dx, dy))
			return Move(dx, dy);
		return false;
	}
	return Move(dx, dy);
}


///

BlockEnt::BlockEnt(Level* lvl) : GridEnt(lvl)
{

};

void BlockEnt::Update(float dt)
{


};
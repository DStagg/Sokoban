#include "GridEnt.h"
#include "Level.h"

GridEnt::GridEnt(Level* lvl) : Entity(lvl)
{

};

void GridEnt::Update(float dt)
{
	GetGraphic().Play(dt);
	GetSize().Set((float)GetGraphic().GetCurrentFrame()._Width, (float)GetGraphic().GetCurrentFrame()._Height);
	GetPosition().Set((float)GetGridPos()._X * GetLevel()->GetTileSize()._X, (float)GetGridPos()._Y * GetLevel()->GetTileSize()._Y);
};

void GridEnt::Draw(sf::RenderWindow* rw)
{
	GetGraphic().GetSprPntr()->setPosition(GetPosition()._X, GetPosition()._Y);
	rw->draw(*GetGraphic().GetSprPntr());
};

PairInt& GridEnt::GetGridPos()
{
	return _GridPos;
};
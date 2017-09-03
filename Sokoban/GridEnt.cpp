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

bool GridEnt::Move(int dx, int dy)
{
	return MoveTo( GetGridPos()._X + dx, GetGridPos()._Y + dy);
};
bool GridEnt::MoveTo(int x, int y)
{
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= GetLevel()->GetTileGrid().GetWidth())
		x = GetLevel()->GetTileGrid().GetWidth() - 1;
	if (y >= GetLevel()->GetTileGrid().GetHeight())
		y = GetLevel()->GetTileGrid().GetHeight() - 1;

	if (GetLevel()->GetTile(x, y)._Solid)
		return false;
	
	GetGridPos().Set(x, y);
	return true;
};

PairInt& GridEnt::GetGridPos()
{
	return _GridPos;
};
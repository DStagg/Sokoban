#include "Level.h"

Level::Level()
{

};
Level::~Level()
{

};

Grid& Level::GetTileGrid()
{
	return _TileGrid;
};
std::vector<Tile>& Level::GetTileList()
{
	return _TileList;
};
int Level::GetTileID(int x, int y)
{
	return GetTileGrid().GetCell(x, y);
};
Tile Level::GetTile(int id)
{
	return _TileList[id];
};
Tile Level::GetTile(int x, int y)
{
	return GetTile(GetTileID(x, y));
};

void Level::GenBoxMap(int w, int h)
{
	GetTileList().clear();

	GetTileList().push_back(Tile("Default", 0, 0, false, false));
	GetTileList().push_back(Tile("Floor", 1, 0, false, false));
	GetTileList().push_back(Tile("Wall", 2, 0, true, true));

	if (w < 3)
		w = 3;
	if (h < 3)
		h = 3;

	GetTileGrid().Resize(w, h);

	for (int x = 0; x < GetTileGrid().GetWidth(); x++)
	{
		for (int y = 0; y < GetTileGrid().GetHeight(); y++)
		{
			if ((x == 0) || (y == 0) || (x == GetTileGrid().GetWidth() - 1) || (y == GetTileGrid().GetHeight() - 1))
				GetTileGrid().SetCell(x, y, 2);
			else
				GetTileGrid().SetCell(x, y, 1);
		}
	}
};
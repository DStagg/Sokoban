#include "Level.h"

Level::Level()
{

};
Level::~Level()
{

};

void Level::SetPlayer(GridEnt* ge)
{
	_Player = ge;
};
GridEnt* Level::GetPlayer()
{
	return _Player;
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

PairInt& Level::GetTileSize()
{
	return _TileSize;
};

sf::Texture& Level::GetMapTexture()
{
	return _MapTexture;
};

void Level::RefreshMapTexture(sf::Texture* tilesheet)
{
	sf::Image img;
	img.create(GetTileSize()._X * GetTileGrid().GetWidth(), GetTileSize()._Y * GetTileGrid().GetHeight());
	sf::Image source = tilesheet->copyToImage();

	for (int x = 0; x < GetTileGrid().GetWidth(); x++)
	{
		for (int y = 0; y < GetTileGrid().GetHeight(); y++)
		{
			Tile tile = GetTile(x, y);
			img.copy(source, x * GetTileSize()._X, y * GetTileSize()._Y, sf::IntRect(tile._SheetColumn * GetTileSize()._X, tile._SheetRow * GetTileSize()._Y, GetTileSize()._X, GetTileSize()._Y));
		}
	}

	_MapTexture.loadFromImage(img);
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
#ifndef LEVEL_H
#define LEVEL_H

#include "Tile.h"
#include "Grid.h"
#include "SFML\Graphics.hpp"
#include "GridEnt.h"

class Level
{
public:

	Level();
	~Level();

	void				SetPlayer(GridEnt* ge);
	GridEnt*			GetPlayer();

	Grid&				GetTileGrid();
	std::vector<Tile>&	GetTileList();
	int					GetTileID(int x, int y);
	Tile				GetTile(int id);
	Tile				GetTile(int x, int y);

	PairInt&			GetTileSize();

	sf::Texture&		GetMapTexture();
	void				RefreshMapTexture(sf::Texture* tilesheet);

	void				GenBoxMap(int w, int h);

private:

	GridEnt*			_Player;

	Grid				_TileGrid;
	std::vector<Tile>	_TileList;

	PairInt				_TileSize = PairInt(32, 32);

	sf::Texture			_MapTexture;
};

#endif
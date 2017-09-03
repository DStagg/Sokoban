#ifndef LEVEL_H
#define LEVEL_H

#include "Tile.h"
#include "Grid.h"
#include "SFML\Graphics.hpp"

class Level
{
public:

	Level();
	~Level();

	Grid&				GetTileGrid();
	std::vector<Tile>&	GetTileList();
	int					GetTileID(int x, int y);
	Tile				GetTile(int id);
	Tile				GetTile(int x, int y);

	sf::Texture&		GetMapTexture();
	void				RefreshMapTexture(sf::Texture* tilesheet);

	void				GenBoxMap(int w, int h);

private:

	Grid				_TileGrid;
	std::vector<Tile>	_TileList;
	int					_TileWidth = 32;
	int					_TileHeight = 32;

	sf::Texture			_MapTexture;
};

#endif
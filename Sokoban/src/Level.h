#pragma once

#include "Tile.h"
#include "core/Grid.h"
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "GridEnt.h"

class Level
{
public:

	Level();
	~Level();

	void				SetPlayer(GridEnt* ge);
	GridEnt*			GetPlayer();

	void				SetBlock(GridEnt* ge);
	GridEnt*			GetBlock();

	Grid&				GetTileGrid();
	std::vector<Tile>&	GetTileList();
	int					GetTileID(int x, int y);
	Tile				GetTile(int id);
	Tile				GetTile(int x, int y);

	PairInt&			GetTileSize();

	SDL_Texture*		GetMapTexture();
	void				RefreshMapTexture(SDL_Renderer* renderer);

	void				GenBoxMap(int w, int h);

private:

	GridEnt*			_Player;
	GridEnt*			_Block;

	Grid				_TileGrid;
	std::vector<Tile>	_TileList;

	PairInt				_TileSize = PairInt(32, 32);

	SDL_Texture*		_MapTexture;
	SDL_Surface*		_Tilesheet;
};

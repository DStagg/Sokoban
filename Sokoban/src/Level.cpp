#include "Level.h"

Level::Level()
{
	_Tilesheet = IMG_Load("res/Tilesheet.png");
	if (!_Tilesheet) std::cout << "Failed to load tilesheet." << std::endl;
};
Level::~Level()
{
	SDL_DestroySurface(_Tilesheet);
};

void Level::SetPlayer(GridEnt* ge)
{
	_Player = ge;
};
GridEnt* Level::GetPlayer()
{
	return _Player;
};

void Level::SetBlock(GridEnt* ge)
{
	_Block = ge;
};
GridEnt* Level::GetBlock()
{
	return _Block;
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

SDL_Texture* Level::GetMapTexture()
{
	return _MapTexture;
};

void Level::RefreshMapTexture(SDL_Renderer* renderer)
{
	SDL_DestroyTexture(_MapTexture);
	SDL_Surface* canvas = SDL_CreateSurface(GetTileSize()._X * GetTileGrid().GetWidth(), GetTileSize()._Y * GetTileGrid().GetHeight(), SDL_PIXELFORMAT_RGBA8888);
	
	for (int x = 0; x < GetTileGrid().GetWidth(); x++)
	{
		for (int y = 0; y < GetTileGrid().GetHeight(); y++)
		{
			Tile tile = GetTile(x, y);
			SDL_Rect dstrect;
			dstrect.x = x * GetTileSize()._X;
			dstrect.y = y * GetTileSize()._Y;
			dstrect.w = GetTileSize()._X;
			dstrect.h = GetTileSize()._Y;
			SDL_Rect srcrect;
			srcrect.x = tile._SheetColumn * GetTileSize()._X;
			srcrect.y = tile._SheetRow * GetTileSize()._Y;
			srcrect.w = GetTileSize()._X;
			srcrect.h = GetTileSize()._Y;
			SDL_BlitSurface(_Tilesheet, &srcrect, canvas, &dstrect);
		}
	}

	_MapTexture = SDL_CreateTextureFromSurface(renderer, canvas);
	SDL_DestroySurface(canvas);
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
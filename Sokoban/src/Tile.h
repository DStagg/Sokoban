#ifndef TILE_H
#define TILE_H

#include <string>

struct Tile
{
	Tile() {};
	Tile(std::string id, int col, int row, bool solid, bool opaque)
	{
		_ID = id;
		_SheetColumn = col;
		_SheetRow = row;
		_Solid = solid;
		_Opaque = opaque;
	};
	
	std::string _ID = "";		//	Identifying string e.g. "Lava_Bottom_Left"
	int _SheetColumn = 0;		//	The column of the terrain sheet to get the graphic from	i.e. x-coordinate
	int _SheetRow = 0;			//	The row of the terrain sheet to get the graphic from	i.e. y-coordinate
	bool _Solid = false;		//	Does it let objects through?
	bool _Opaque = false;		//	Does it let light through?
};

#endif
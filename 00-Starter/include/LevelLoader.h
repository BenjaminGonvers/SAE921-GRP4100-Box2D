#pragma once
#include "LevelLoader.h"
#include "Game.h"

#include <map>
#include <string>


class LevelLoader
{
private:
	enum class name_tile
	{
		blockerMad=0,
		box,
		castleHalf,
		castleMid,
		grass,
		grassCenter,
		grassHillLeft,
		grassHillLeft2,
		grassHillRight,
		grassHillRight2,
		grassMid
		
	};

	std::map<name_tile, std::string> tile_map_
	{
		{name_tile::blockerMad, "./data/blockerMad"},
		{name_tile::box, "./data/box"}
	};

	Game* game_;

public:

	LevelLoader(*Game);

	void Load_Level(std::string);

};

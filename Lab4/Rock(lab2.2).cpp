#include "Rock(lab2.2).h"
#include <string>
Rock nextOne(Rock rockVal)
{
	switch (rockVal)
	{
	case BASALT: return DOLOMITE;
	case DOLOMITE: return GRANITE;
	case GRANITE: return GYPSUM;
	case GYPSUM: return LIMESTONE;
	case LIMESTONE: return MARBLE;
	case MARBLE: return OBSIDIAN;
	case OBSIDIAN: return QUARTZITE;
	case QUARTZITE: return SANDSTONE;
	case SANDSTONE: return SHALE;
	case SHALE: return ROCK_OVERFLOW;
	default: return ROCK_OVERFLOW;

	}
}


string kind(Rock rockVal)
{
	switch (rockVal)
	{
	case BASALT: return "Igneous";
	case DOLOMITE: return "Sedimentary";
	case GRANITE: return "Igneous";
	case GYPSUM: return "Sedimentary";
	case LIMESTONE: return "Metamorphic";
	case MARBLE: return "Metamorphic";
	case OBSIDIAN: return "Igneous";
	case QUARTZITE: return "Sedimentary";
	case SANDSTONE: return "Sedimentary";
	case SHALE: return "Sedimentary";
	default: return "Unknown";
	}
}
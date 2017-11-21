#include "Rock.h"
using namespace std;
istream &operator >>(istream &in, Rock &rockVal)
{
	rockVal.read(in);
	return in;
}
//matcher function to read inputs
void Rock::read(istream &in)
{
	void stringToUpper(string &s);
	string allowedRock[] = { "BASALT","DOLOMITE","GRANITE","GYPSUM","LIMESTONE","MARBLE","OBSIDIAN","QUARTZITE","SANDSTONE","SHALE" };
	string rock;
	int location = 0;
	bool found = false;
	in >> rock;
	stringToUpper(rock);
	for (; !found && location < 10; location++)
		found = rock == allowedRock[location];
	location--;

	if (found)
		myName = static_cast<RockName>(location);
}
//capitalizes user input to read
void stringToUpper(string &s)
{
	for (unsigned i = 0; i < s.length(); i++)
		s.at(i) = toupper(s.at(i));
}

void Rock::display(ostream &) const
{
	switch (myName)
	{
	case BASALT: cout << "BASALT";
		break;
	case DOLOMITE: cout << "DOLOMITE";
		break;
	case GRANITE: cout << "GRANITE";
		break;
	case GYPSUM: cout << "GYPSUM";
		break;
	case LIMESTONE: cout << "LIMESTONE";
		break;
	case MARBLE: cout << "MARBLE";
		break;
	case OBSIDIAN: cout << "OBSIDIAN";
		break;
	case QUARTZITE: cout << "QUARTZITE";
		break;
	case SANDSTONE: cout << "SANDSTONE";
		break;
	case SHALE: cout << "SHALE";
		break;
	default: cout << "Unknown";
	}
}
bool operator<(const Rock &rock1, const Rock &rock2) 
{

	if (&rock1 < &rock2)
	{
		return true;
	}
	return false;
}
bool operator==(const Rock &rock1, const Rock &rock2)
{
	if (&rock1 == &rock2)
	{
		return true;
	}
	return false;
}

ostream &operator<<(ostream &out, const Rock &rockVal)
{
	rockVal.display(out);
	return out;
}
ostream &operator<<(ostream &out, RockName &myName)
{
	switch (myName)
	{
	case BASALT: cout << "BASALT";
		break;
	case DOLOMITE: cout << "DOLOMITE";
		break;
	case GRANITE: cout << "GRANITE";
		break;
	case GYPSUM: cout << "GYPSUM";
		break;
	case LIMESTONE: cout << "LIMESTONE";
		break;
	case MARBLE: cout << "MARBLE";
		break;
	case OBSIDIAN: cout << "OBSIDIAN";
		break;
	case QUARTZITE: cout << "QUARTZITE";
		break;
	case SANDSTONE: cout << "SANDSTONE";
		break;
	case SHALE: cout << "SHALE";
		break;
	default: cout << "Unknown";
	}
	return out;
}
Rock::Rock() 
{
	myName = GRANITE;
}
Rock::Rock(RockName rockVal)
{
	myName = GRANITE;
}
string Rock::kind()
{
	switch (myName)
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
string Rock::texture()
{
	switch (myName)
	{
	case BASALT: return "Intermediate";
	case DOLOMITE: return "Coarse";
	case GRANITE: return "Coarse";
	case GYPSUM: return "Coarse";
	case LIMESTONE: return "Coarse";
	case MARBLE: return "Fine";
	case OBSIDIAN: return "Fine";
	case QUARTZITE: return "Intermediate";
	case SANDSTONE: return "Coarse";
	case SHALE: return "Fine";
	default: return "Unknown";
	}
}
RockName Rock::name() 
{
	switch (myName)
	{
	case BASALT: return BASALT;
	case DOLOMITE: return DOLOMITE;
	case GRANITE: return GRANITE;
	case GYPSUM: return GYPSUM;
	case LIMESTONE: return LIMESTONE;
	case MARBLE: return MARBLE;
	case OBSIDIAN: return OBSIDIAN;
	case QUARTZITE: return QUARTZITE;
	case SANDSTONE: return SANDSTONE;
	case SHALE: return SHALE;
	default: return ROCK_OVERFLOW;
	}
}
Rock Rock::next()
{
		switch (myName)
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

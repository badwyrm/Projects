#include <iostream>
using namespace std;
#include <string>
#include "Rock.h"
// overloaded output operator
ostream &operator<<(ostream &out, Rock rockVal)
{
	switch (rockVal)
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

//overloaded input operator
istream &operator>>(istream &in, Rock &rockVal)
{
	getRock(in, rockVal);
	return in;
}

//matcher function to read inputs
void getRock(istream &in, Rock &z)
{
	void stringToUpper(string &s);
	string allowedRock[] = { "BASALT","DOLOMITE","GRANITE","GYPSUM","LIMESTONE","MARBLE","OBSIDIAN","QUARTZITE","SANDSTONE","SHALE"};
	string rock;
	int location = 0;
	bool found = false;
	in >> rock;
	stringToUpper(rock);
	for (; !found && location < 10; location++)
		found = rock == allowedRock[location];
	location--;

	if (found)
		z = static_cast<Rock>(location);
}
//capitalizes user input to read
void stringToUpper(string &s) 
{
	for (unsigned i = 0; i < s.length(); i++)
		s.at(i) = toupper(s.at(i));
}



Rock next(Rock rockVal)
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

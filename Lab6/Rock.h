#ifndef ROCK
#define ROCK
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
enum RockName { BASALT = 0, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE, OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW };

class Rock
{
public:
	Rock();
	Rock(RockName sample);
	void display(ostream &) const;
	void read(istream &);
	string kind();
	string texture();
	RockName name();
	Rock next();
private:
	RockName myName;
};

ostream &operator<<(ostream &out, const Rock &rockVal);
ostream &operator<<(ostream &out, RockName &myName);
istream &operator>> (istream &in, Rock &rockVal);
bool operator<(const Rock &rock1, const Rock &rock2);
bool operator==(const Rock &rock1, const Rock &rock2);
void stringToUpper(string &s);
#endif
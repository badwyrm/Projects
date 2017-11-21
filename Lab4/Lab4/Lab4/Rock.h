using namespace std;
#include <string>
#include <fstream>
#include <iomanip>
enum Rock { BASALT = 0, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE, OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW};
Rock next(Rock rockVal);
string kind(Rock rockVal);
ostream & operator<<(ostream &out, Rock rockVal);
istream &operator >> (istream &in, Rock &rockVal);
void stringToUpper(string &s);
void getRock(istream &in, Rock &z);



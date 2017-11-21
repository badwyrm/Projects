#include <string>
using namespace std;
enum Rock { BASALT = 0, DOLOMITE, GRANITE, GYPSUM, LIMESTONE, MARBLE, OBSIDIAN, QUARTZITE, SANDSTONE, SHALE, ROCK_OVERFLOW };
Rock nextOne(Rock rockVal);
string kind(Rock rockVal);


#include <iostream>
#include <streambuf>
#include <string>

#include <nlohmann/json.hpp>

#include "ps2tt.h"

using nlohmann::json;
using std::string;

void Cubic2Quad(json &font)
{
	font["glyf"] = Ps2Tt(font["glyf"], 1);
	font["maxp"]["version"] = 1.0;
	font.erase("CFF_");
}

int main(int, char **)
{
	std::ios_base::sync_with_stdio(false);
	json font;
	std::cin >> font;
	Cubic2Quad(font);
	std::cout << font;
}

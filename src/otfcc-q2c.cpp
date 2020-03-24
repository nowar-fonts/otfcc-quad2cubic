#include <iostream>
#include <streambuf>
#include <string>

#include <nlohmann/json.hpp>
#include "q2c.h"

int main(int, char **)
{
	std::ios_base::sync_with_stdio(false);
	nlohmann::json font;
	std::cin >> font;
	font = Quad2Cubic(font);
	std::cout << font;
}

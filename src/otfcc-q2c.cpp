#include <iostream>
#include <streambuf>
#include <string>

#include <nlohmann/json.hpp>

#include "tt2ps.h"

using nlohmann::json;
using std::string;

enum struct NameId
{
	Copyright = 0,
	Family = 1,
	Subfamily = 2,
	UniqueId = 3,
	FullName = 4,
	Version = 5,
	PostScript = 6,
	Trademark = 7,
	TypoFamily = 16,
	TypoSubfamily = 17,
};

string GetName(NameId id, const json &name)
{
	for (const json &entry : name)
	{
		// Windows, Unicode, English
		if (entry["nameID"] == id && entry["platformID"] == 3 &&
		    (entry["encodingID"] == 1 || entry["encodingID"] == 10) &&
		    entry["languageID"] == 1033)
			return entry["nameString"];
	}
	return {};
}

inline string GetVersionString(double version)
{
	constexpr size_t buffLen = 4096;
	char result[buffLen];
	snprintf(result, buffLen, "%.3f", version);
	return result;
}

void Quad2Cubic(json &font)
{
	font["glyf"] = Tt2Ps(font["glyf"], true);

	const json &head = font["head"];
	const json &name = font["name"];
	const json &post = font["post"];

	json cff{{"isCID", false}};
	string nameString;
	if ((nameString = GetName(NameId::PostScript, name)).size())
		cff["fontName"] = nameString;
	if ((nameString = GetName(NameId::Trademark, name)).size())
		cff["notice"] = nameString;
	if ((nameString = GetName(NameId::Version, name)).size())
		cff["version"] = nameString;
	else
		cff["version"] = GetVersionString(head["fontRevision"]);
	if ((nameString = GetName(NameId::Copyright, name)).size())
		cff["copyright"] = nameString;
	if ((nameString = GetName(NameId::FullName, name)).size())
		cff["fullName"] = nameString;
	if ((nameString = GetName(NameId::TypoFamily, name)).size())
		cff["familyName"] = nameString;
	else if ((nameString = GetName(NameId::Family, name)).size())
		cff["familyName"] = nameString;
	if ((nameString = GetName(NameId::TypoSubfamily, name)).size())
		cff["weight"] = nameString;
	else if ((nameString = GetName(NameId::Subfamily, name)).size())
		cff["weight"] = nameString;
	cff["isFixedPitch"] = post["isFixedPitch"];
	cff["italicAngle"] = post["italicAngle"];
	cff["underlinePosition"] = post["underlinePosition"];
	cff["underlineThickness"] = post["underlineThickness"];
	cff["fontBBoxTop"] = head["yMax"];
	cff["fontBBoxBottom"] = head["yMin"];
	cff["fontBBoxLeft"] = head["xMin"];
	cff["fontBBoxRight"] = head["xMax"];
	font["CFF_"] = cff;
	font["maxp"]["version"] = 0x0.5p0,

	// remove TT instructions
	font.erase("cvt_");
	font.erase("fpgm");
	font.erase("gasp");
	font.erase("prep");
}

int main(int, char **)
{
	std::ios_base::sync_with_stdio(false);
	json font;
	std::cin >> font;
	Quad2Cubic(font);
	std::cout << font;
}

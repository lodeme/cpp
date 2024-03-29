#include "ReplaceString.hpp"

std::string ReplaceString(
	std::string line, 
	const std::string& s1, 
	const std::string& s2
) {
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return line;
}

#include <string>
#include <iostream>
#include <fstream>

std::string ReplaceString(std::string line, const std::string& s1, const std::string& s2) {
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos) {
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos += s2.length();
	}
	return line;
}

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Expected 3 args: filename, find, replace" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		std::cerr << "Could not open input file" << std::endl;
		return 1;
	}

	std::ofstream outputFile(filename + ".replace");
	if (!outputFile.is_open()) {
		std::cerr << "Could not open output file" << std::endl;
		return 1;
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		outputFile << ReplaceString(line, s1, s2) << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
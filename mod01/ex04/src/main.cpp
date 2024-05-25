#include <string>
#include <iostream>
#include <fstream>
#include "ReplaceString.hpp"

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Expected 3 args: filename, find, replace" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Could not open input file" << std::endl;
		return 1;
	}

  std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
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

#include "D5_One.h"
#include "../stdafx.h"

struct Mapping {
	double destination;
	double source;
	double range;
};

void D5_One::main() {
	std::cout << "Day 5, Part 1:" << std::endl;

	std::ifstream file("Input/D5/Example.txt");

	if (!file.is_open()) {
		std::cerr << "Error at opening the File!" << std::endl;
		return;
	}

	std::string line;
	std::vector<double> seeds;
	std::vector<Mapping> currMappingValues;
	
	std::string tempNum = "";
	bool isSeedsLine = true;
	bool alreadySavedSeeds = false;

	while (std::getline(file, line)) {
		if (isSeedsLine && !std::isdigit(line[0])) {
			isSeedsLine = false;
		}
		else if (!isSeedsLine && std::isdigit(line[0]) && !alreadySavedSeeds) {
			alreadySavedSeeds = true;
			for (auto c : line) {
				if (c != ' ') {
					tempNum += c;
				}
				else {
					seeds.push_back(std::stod(tempNum));
				}
			}
		}
		else if (alreadySavedSeeds) {
			if (std::isdigit(line[0])) {
				
			}
			else {

			}
		}
	}
	
}

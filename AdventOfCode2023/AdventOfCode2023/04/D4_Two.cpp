#include "D4_Two.h"
#include "../stdafx.h"
#include <vector>
#include <map>

struct NumbersPair {
	int x = 0;
	int y = 1;
};

void D4_Two::main() {
	std::cout << "Day 4, Part 2:" << std::endl;

	std::ifstream file("Input/D4/02.txt");

	if (!file.is_open()) {
		std::cerr << "Error at opening the File!" << std::endl;
		return;
	}

	std::string line;

	std::vector<int> nrs1;
	std::vector<int> nrs2;

	std::vector<NumbersPair> matchingNrsInLine;

	int nrOfMatches = 0;
	int lineNr = 0;

	std::string nr = "";
	bool isGame = true;
	bool cardSwap = false;
	NumbersPair numPair{};

	line = "";
	while (std::getline(file, line)) {
		nrs1.clear();
		nrs2.clear();
		nr = "";
		isGame = true;
		cardSwap = false;
		line += ' ';
		for (auto c : line) {
			if (c == ':') {
				isGame = false;
			}
			else if (c == '|') {
				cardSwap = true;
			}
			else if (!isGame && c != ' ') {
				nr += c;
			}
			else if (c == ' ') {
				if (!cardSwap) {
					if (nr != "") {
						nrs1.push_back(std::stoi(nr));
						nr = "";
					}
				}
				else {
					if (nr != "") {
						nrs2.push_back(std::stoi(nr));
						nr = "";
					}
				}
			}
		}
		nrOfMatches = 0;
		for (auto i : nrs1) {
			for (auto j : nrs2) {
				if (j == i) {
					// Match
					nrOfMatches++;
				}
			}
		}
		numPair.x = nrOfMatches;
		numPair.y = 1;
		matchingNrsInLine.push_back(numPair);

	}

	for (int i = 0; i < matchingNrsInLine.size(); i++) {
		if (matchingNrsInLine[i].x != 0) {
			for (int k = 0; k < matchingNrsInLine[i].y; k++) {
				for (int j = 1; j <= matchingNrsInLine[i].x; j++) {
					if (i + j < matchingNrsInLine.size()) {
						matchingNrsInLine[i + j].y += 1;
					}
				}
			}
		}
	}

	int sum = 0;
	for (auto& val : matchingNrsInLine) {
		sum += val.y;
	}

	std::cout << "Sum: " << sum << std::endl;
}

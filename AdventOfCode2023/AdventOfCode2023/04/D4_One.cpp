#include "D4_One.h"
#include "../stdafx.h"
#include <vector>

void D4_One::main() {
	std::cout << "Day 4, Part 1:" << std::endl;

	std::ifstream file("Input/D4/01.txt");

	if (!file.is_open()) {
		std::cerr << "Error at opening the File!" << std::endl;
		return;
	}

	std::string line;

	std::vector<int> nrs1;
	std::vector<int> nrs2;

	bool isFirst;
	int sum = 0;
	int smallSum = 0;

	std::string nr = "";
	bool isGame = true;
	bool cardSwap = false;

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

		isFirst = true;
		smallSum = 0;
		for (auto i : nrs1) {
			for (auto j : nrs2) {
				if (j == i) {
					if (isFirst) {
						smallSum += 1;
						isFirst = false;
					}
					else {
						smallSum *= 2;
					}
				}
			}
		}
		sum += smallSum;
	}

	std::cout << "Sum: " << sum << std::endl;
}

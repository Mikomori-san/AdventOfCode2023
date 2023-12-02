#include "D2_Two.h"
#include "../stdafx.h"
#include <vector>

struct Game {
public:
	int id;
	int red = 0;
	int green = 0;
	int blue = 0;
};

void D2_Two::main()
{
	std::cout << "Day 2, Part 2:" << std::endl;

	std::ifstream file("Input/D2/02.txt");

	if (!file.is_open()) {
		std::cerr << "Error at opening the File!" << std::endl;
		return;
	}

	const Game validGame{ 0, 12, 13, 14 };

	std::string line;
	std::vector<Game> games;
	bool isGame;
	std::string curColor = "";
	int curColNr{ 0 };
	std::string curColNrString = "";
	size_t foundSpace;
	bool wasDigit = true;
	std::string gameId = "";
	int sum = 0;

	while (std::getline(file, line)) {
		Game game{ 0, 0, 0, 0 };
		isGame = true;
		gameId = "";
		line += ';';

		for (auto c : line)
		{
			if (c != ':' && isGame && (c != ',' && c != ';')) {
				if (std::isdigit(c)) {
					gameId += c;
				}
			}
			else if (isGame) {
				isGame = false;
				game.id = std::stoi(gameId);
			}
			else if (c != ',' && c != ';') {
				if (std::isdigit(c)) {
					wasDigit = true;
					curColNrString += c;
				}
				else {
					if (wasDigit) {
						curColNr = std::isdigit(curColNrString[0]) ? std::stoi(curColNrString) : 0;
						curColNrString = "";
					}
					wasDigit = false;
					curColor += c;
				}
			}
			else if (c == ',' || c == ';') {
				foundSpace = curColor.find(" ");

				while (foundSpace != std::string::npos) {
					curColor.erase(foundSpace, 1);
					foundSpace = curColor.find(" ");
				}

				if (curColor == "green") {
					if (game.green < curColNr)
						game.green = curColNr;
				}
				else if (curColor == "blue") {
					if (game.blue < curColNr)
						game.blue = curColNr;
				}
				else if (curColor == "red") {
					if (game.red < curColNr)
						game.red = curColNr;
				}
				curColor = "";
			}

		}

		sum += game.red * game.blue * game.green;
	}

	std::cout << "Sum: " << sum << std::endl;
}

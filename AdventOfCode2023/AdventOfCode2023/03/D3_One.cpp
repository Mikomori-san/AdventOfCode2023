#include "D3_One.h"
#include "../stdafx.h"
#include <vector>

int checkAdjacentNr(NrTupel& nr, std::vector<std::string>& lines, int line, int row);
std::string getNrLeft(int i, int j, std::vector<std::string>& lines);
std::string getNrRight(int i, int j, std::vector<std::string>& lines);

void D3_One::main()
{
	std::cout << "Day 3, Part 1:" << std::endl;

	std::ifstream file("Input/D3/01.txt");

	if (!file.is_open()) {
		std::cerr << "Error at opening the File!" << std::endl;
		return;
	}

	std::string line;

	std::vector<std::string> lines;

	char c;
	NrTupel nr{2, 2}; // Numbers to ignore if special case (on frame)
	int sum = 0;

	while (std::getline(file, line)) {
		lines.push_back(line);
	}

	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines[i].size(); j++) {
			c = lines[i][j];
			if (c != '.' && !std::isdigit(c)) {
				if (i == 0 && j == 0) { // If left top
					nr.i = 2; nr.j = 2;
					nr.i = -1; nr.j = -1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (i == 0 && j == lines[i].size() - 1) { // If right top
					nr.i = 2; nr.j = 2;
					nr.i = -1; nr.j = 1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (i == lines.size() - 1 && j == 0) { // If left bottom
					nr.i = 2; nr.j = 2;
					nr.i = 1; nr.j = -1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (i == lines.size() - 1 && j == lines[i].size() - 1) { // If right bottom
					nr.i = 2; nr.j = 2;
					nr.i = 1; nr.j = 1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (i == 0) { // If top
					nr.i = 2; nr.j = 2;
					nr.i = -1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (i == lines.size() - 1) { // If bottom
					nr.i = 2; nr.j = 2;
					nr.i = 1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (j == 0) { // If left
					nr.i = 2; nr.j = 2;
					nr.j = -1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else if (j == lines[i].size() - 1) { // If right
					nr.i = 2; nr.j = 2;
					nr.j = 1;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
				else {
					nr.i = 2; nr.j = 2;
					sum += checkAdjacentNr(nr, lines, i, j);
				}
			}
		}
	}
	std::cout << "Sum: " << sum << std::endl;
}

int checkAdjacentNr(NrTupel &nr, std::vector<std::string> &lines, int line, int row) {
	int nrSum = 0;
	int minI = -1;
	int minJ = -1;
	int maxI = 1;
	int maxJ = 1;

	std::string tempNr = "";

	switch (nr.i) {
		case -1:
			minI = 0;
			break;
		case 1:
			maxI = 0;
			break;
		default:
			break;
	}

	switch (nr.j) {
		case -1:
			minJ = 0;
			break;
		case 1:
			maxJ = 0;
			break;
		default:
			break;
	}

	bool alreadyContinued;

	for (int i = minI; i <= maxI; i++) {
		alreadyContinued = false;
		for (int j = minJ; j <= maxJ; j++) {
			if (std::isdigit(lines[line + i][row + j]) && std::isdigit(lines[line + i][row + j + 1]) && j == -1) {
				continue;
			}
			else if (std::isdigit(lines[line + i][row + j]) && std::isdigit(lines[line + i][row + j + 1]) && j == 0) {
				continue;
			}
			else if (std::isdigit(lines[line + i][row + j])) {
				std::string temp = "";
				temp += getNrLeft(line + i, row + j, lines);
				std::string tempRight = getNrRight(line + i, row + j + 1, lines);
				for (int c = tempRight.size() - 1; c >= 0; c--) {
					temp += tempRight[c];
				}
				nrSum += std::stoi(temp);
			}
		}
	}

	return nrSum;
}

std::string getNrLeft(int i, int j, std::vector<std::string> &lines) {
	std::string temp = "";
	if (!std::isdigit(lines[i][j])) {
		return temp;
	}
	if (j > 0) {
		if (std::isdigit(lines[i][j - 1])) {
			temp += getNrLeft(i, j - 1, lines);
		}
	}

	temp += lines[i][j];
	return temp;
}

std::string getNrRight(int i, int j, std::vector<std::string>& lines) {
	std::string temp = "";
	if (!std::isdigit(lines[i][j])) {
		return temp;
	}
	if (j < lines[i].size() - 1) {
		if (std::isdigit(lines[i][j + 1])) {
			temp += getNrRight(i, j + 1, lines);
		}
	}
	temp += lines[i][j];
	return temp;
}
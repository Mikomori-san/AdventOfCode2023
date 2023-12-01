#include "D1_One.h"
#include "../stdafx.h"

void D1_One::main() {
    std::cout << "Day 1, Part 1:" << std::endl;

    std::ifstream file("Input/D1/01.txt");

    if (!file.is_open()) {
        std::cerr << "Error at opening the File!" << std::endl;
        return;
    }

    std::string line;
    int sum = 0;
    std::string nrInLine;
    std::string nrOnly;

    while (std::getline(file, line)) {
        nrInLine = "";
        nrOnly = "";

        for (char c : line) {
            if (std::isdigit(c)) {
                nrInLine += c;
            }
        }

        if (nrInLine.size() >= 2) {
            nrOnly = nrInLine[0];
            nrOnly += nrInLine[nrInLine.size() - 1];
            sum += std::stoi(nrOnly);
        }
        else if (nrInLine.size() == 1) {
            nrOnly = nrInLine[0];
            nrOnly += nrInLine[0];
            sum += std::stoi(nrOnly);
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    file.close();
}


#include "D1_Two.h"
#include "../stdafx.h"
#include <vector>

void D1_Two::main()
{
	std::cout << "Day 1, Part 2:" << std::endl;

    std::ifstream file("Input/D1/02.txt");

    std::vector<std::string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    if (!file.is_open()) {
        std::cerr << "Error at opening the File!" << std::endl;
        return;
    }

    std::string line;
    std::string nrInLine = "";
    std::string subLineProve = "";
    std::string nrOnly = "";
    int sum = 0;
    size_t index;

    while (std::getline(file, line)) {
        nrInLine = "";
        nrOnly = "";
        subLineProve = "";

        for (char c : line) {           
            if (std::isdigit(c)) {
                
                nrInLine += c;
                subLineProve = "";
            }
            else {
                subLineProve += c;
                for (int j = 0; j < numbers.size(); j++) {
                    if ((index = subLineProve.find(numbers[j])) != std::string::npos) {
                        nrInLine += '0' + j;
                        subLineProve.erase(subLineProve.begin(), subLineProve.begin() + index + 1);
                    }
                }
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

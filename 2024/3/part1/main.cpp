#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

#define INPUT_FILE "./input"
//#define INPUT_FILE "./training"

int main(int argc, char** argv)
{
    std::ifstream input;
    std::string line;
    input.open(INPUT_FILE);

    std::regex pattern(R"(mul\(\s*(-?\d+)\s*,\s*(-?\d+)\s*\))");
    std::smatch matches;
    int res = 0;

    while (std::getline(input,line))
    {
        auto searchStart = line.cbegin();
        while (std::regex_search(searchStart, line.cend(), matches, pattern))
        {
            int x = std::stoi(matches[1].str());
            int y = std::stoi(matches[2].str());

            res += x*y; 

            std::cout << "x=" << x << ", y=" << y << ", res=" << res << std::endl;

            searchStart = matches.suffix().first;
        }   
    }

    input.close();

    std::cout << res << std::endl;
    return 0;
}

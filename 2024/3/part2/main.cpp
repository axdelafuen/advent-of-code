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
    std::regex doPattern(R"(do\(\))");
    std::regex dontPattern(R"(don't\(\))");

    bool doMul = true;
    int res = 0;

    while (std::getline(input,line))
    {
        auto searchStart = line.cbegin();
        while (searchStart != line.cend())
        {
            std::smatch mulMatch, doMatch, dontMatch;

            bool foundMul = std::regex_search(searchStart, line.cend(), mulMatch, pattern);
            bool foundDo = std::regex_search(searchStart, line.cend(), doMatch, doPattern);
            bool foundDont = std::regex_search(searchStart, line.cend(), dontMatch, dontPattern);

            size_t mulPos = foundMul ? mulMatch.position() : std::string::npos;
            size_t doPos = foundDo ? doMatch.position() : std::string::npos;
            size_t dontPos = foundDont ? dontMatch.position() : std::string::npos;

            size_t firstPos = std::min({mulPos, doPos, dontPos});

            if (firstPos == mulPos)
            {
                if (doMul)
                {
                    int x = std::stoi(mulMatch[1].str());
                    int y = std::stoi(mulMatch[2].str());

                    res += x*y; 

                    std::cout << "x=" << x << ", y=" << y << ", res=" << res << std::endl;

                }
                searchStart = mulMatch.suffix().first;
            }
            else if(firstPos == doPos)
            {
                std::cout << "DO" << std::endl;
                doMul = true;
                searchStart = doMatch.suffix().first;
            }
            else if(firstPos == dontPos)
            {
                std::cout << "DONT" << std::endl;
                doMul = false;
                searchStart = dontMatch.suffix().first;
            }
        }   
    }

    input.close();

    std::cout << res << std::endl;
    return 0;
}

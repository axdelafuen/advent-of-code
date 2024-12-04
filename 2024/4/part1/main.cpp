#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

#define INPUT_FILE "./input"
//#define INPUT_FILE "./training"

int checkLineMatch(std::string line, std::regex pattern)
{
    int cpt = 0;
    std::smatch match;
    auto searchStart = line.cbegin();
    while (std::regex_search(searchStart, line.cend(), match, pattern))
    {
        cpt++;
        searchStart = match.suffix().first;
    }
    return cpt;
}

int getSizeOfFirstLineOfFile()
{
    std::ifstream input;
    std::string line;
    input.open(INPUT_FILE);

    getline(input,line);

    input.close();

    return line.size();
}

int main(int argc, char** argv)
{
    std::ifstream input;
    std::string line;
    input.open(INPUT_FILE);
   
    std::regex normalPattern(R"(XMAS)");
    std::regex reversePattern(R"(SAMX)");

    std::vector<std::string> verticalLines;
    std::vector<std::vector<char>> diagonalLines;
    std::vector<std::vector<char>> reverseDiagonalLines;
    
    int size = getSizeOfFirstLineOfFile();

    verticalLines.resize(size);
    diagonalLines.resize(2*size);
    reverseDiagonalLines.resize(2*size);

    for (unsigned int i = 0; i < diagonalLines.size(); i++)
    {
        diagonalLines[i].resize(size);
        reverseDiagonalLines[i].resize(size);
    }

    int res = 0;
    int cptLine = 0;

    // loop by lines
    while (std::getline(input,line))
    {
        res += checkLineMatch(line, normalPattern);
        res += checkLineMatch(line, reversePattern);

        // generate vertical lines & diag lines
        for (unsigned int i = 0; i < line.size(); i++)
        {
            verticalLines[i] = verticalLines[i] + line[i];
            diagonalLines[i+cptLine].push_back(line[i]);
        }
        for (unsigned int i = line.size(); i>0; i--)
        {
            reverseDiagonalLines[((size-i)+cptLine)].push_back(line[i-1]);
        }
        cptLine++;
    }

    input.close();

    // get in horizontal
    for (std::string vLine : verticalLines)
    {
        res += checkLineMatch(vLine, normalPattern);
        res += checkLineMatch(vLine, reversePattern);
    }
    
    // get in diagonal
    std::cout << "DIAG" << std::endl;
    for (std::vector<char> dLine : diagonalLines)
    {
        std::string dString(dLine.begin(), dLine.end());
        res += checkLineMatch(dString, normalPattern);
        res += checkLineMatch(dString, reversePattern);
    }
    std::cout << "REVERSE DIAG" << std::endl;
    for (std::vector<char> dLine : reverseDiagonalLines)
    {
        std::string dString(dLine.begin(), dLine.end());
        res += checkLineMatch(dString, normalPattern);
        res += checkLineMatch(dString, reversePattern);
    }

    std::cout << res << std::endl;
    return 0;
}

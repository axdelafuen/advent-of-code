#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>

#define INPUT_FILE "./input"

int main(int argc, char** argv)
{
    std::ifstream input;
    std::string line;
    input.open(INPUT_FILE);
    
    std::vector<std::vector<int>> inputLines;

    while (std::getline(input,line))
    {
        std::vector<int> tmp;
        size_t start = 0;
        size_t end;
        while ((end = line.find(' ', start)) != std::string::npos) {
            tmp.push_back(std::stoi(line.substr(start, end - start)));
            start = end + 1;
        }
        if (start < line.length()) {
            tmp.push_back(std::stoi(line.substr(start)));
        }

        inputLines.push_back(tmp);
    }

    input.close();

    int res = inputLines.size();
    
    for (unsigned int i = 0; i < inputLines.size(); i++)
    {
        bool increase = false;
        bool decrease = false;
        bool diff = false;
        for (unsigned int j = 0; j < inputLines[i].size()-1; j++)
        {
            if (abs(inputLines[i][j] - inputLines[i][j+1]) > 3 || abs(inputLines[i][j] - inputLines[i][j+1]) < 1)
                diff = true;

            if (inputLines[i][j] < inputLines[i][j+1])
               increase = true; 

            if (inputLines[i][j] > inputLines[i][j+1])
                decrease = true;
        }
        if ((increase && decrease) || diff)
            res--;
    }
    
    std::cout << res << std::endl;
    return 0;
}

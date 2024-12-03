#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>

//#define INPUT_FILE "./training"
#define INPUT_FILE "./input"

bool checkIfSafe(std::vector<int> level)
{
    bool increase = false;
    bool decrease = false;
    for (unsigned int j = 0; j < level.size()-1; j++)
    {
        if (abs(level[j] - level[j+1]) > 3 || abs(level[j] - level[j+1]) < 1 )
            return false;

        if (level[j] < level[j+1])
            increase = true;

        if (level[j] > level[j+1])
            decrease = true;

        if (increase && decrease)
            return false;
    }
    return true;
}

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

    int res = 0;
    
    for (unsigned int i = 0; i < inputLines.size(); i++)
    {
        if(checkIfSafe(inputLines[i]))
            res++;
        else
        {
            int cpt = 0;
            for (unsigned int j = 0; j < inputLines[i].size(); j++)
            {
                std::vector<int> tmp(inputLines[i]);     
                tmp.erase(tmp.begin()+j);

                if (checkIfSafe(tmp))
                    cpt++;
            }
            if (cpt >= 1)
                res++;
        }
    }
    
    std::cout << res << std::endl;
    return 0;
}

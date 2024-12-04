#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define INPUT_FILE "./input"
//#define INPUT_FILE "./training"

int main(int argc, char** argv)
{
    std::ifstream input;
    std::string line;
    input.open(INPUT_FILE);
   
    std::vector<std::string> linesTab;
    
    while (std::getline(input,line))
    {
        linesTab.push_back(line);
    }

    input.close();

    int res = 0;

    for (unsigned int i = 1; i<linesTab.size()-1; i++)
    {
        for (unsigned int j = 1; j<linesTab[i].length()-1; j++)
        {
            std::stringstream left, right; 
            left << linesTab[i-1][j-1] << linesTab[i][j] << linesTab[i+1][j+1];
            right << linesTab[i+1][j-1] << linesTab[i][j] << linesTab[i-1][j+1];

            if ((left.str() == "MAS" || left.str() == "SAM") && (right.str() == "MAS" || right.str() == "SAM"))
                res++;
        }
    }
    
    std::cout << res << std::endl;
    return 0;
}

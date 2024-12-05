#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>

#define INPUT_FILE "./input"
//#define INPUT_FILE "./training"

int main(int argc, char** argv)
{
    std::ifstream input;
    std::string line;
    input.open(INPUT_FILE);
   
    std::vector<std::pair<int, int>> orderingRules;
    std::vector<std::vector<int>> numbersLists;

    int res = 0;

    // loop by lines
    std::getline(input,line);
    while (line.find_first_not_of(' ') != std::string::npos && !line.empty())
    {
        orderingRules.push_back(std::make_pair(stoi(line.substr(0, line.find("|"))), stoi(line.substr(line.find("|")+1))));
        std::getline(input,line);
    }
    
    while(std::getline(input,line))
    {
        std::vector<int> tmp;
        std::string token;
        std::stringstream ss(line);
        while(std::getline(ss,token,','))
        {
            tmp.push_back(stoi(token));
        }
        numbersLists.push_back(tmp);
    }

    input.close();
   
    for (unsigned int i = 0; i < numbersLists.size(); i++)
    {
        bool fail = false;
        for (unsigned int j = 0; j < numbersLists[i].size(); j++)
        {
            bool redo = false;
            for (unsigned int k = 0; k < orderingRules.size(); k++)
            {
                for (unsigned int w = j+1; w < numbersLists[i].size(); w++)
                {
                    if (numbersLists[i][j] == orderingRules[k].second && numbersLists[i][w] == orderingRules[k].first)
                    {
                        int val = numbersLists[i][j];
                        numbersLists[i][j] = numbersLists[i][w];
                        numbersLists[i][w] = val;
                        j=-1;
                        fail = true;
                        redo = true;
                        break;
                    }
                }
                if (redo)
                    break;
            }
        }
        if (fail)
        {
            res += numbersLists[i][numbersLists[i].size()/2];
        }
    }

    std::cout << res << std::endl;
    return 0;
}

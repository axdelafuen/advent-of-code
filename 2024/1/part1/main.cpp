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
    
    std::vector<int> first_list;
    std::vector<int> second_list;

    while (std::getline(input,line))
    {
        first_list.push_back(stoi(line.substr(0, line.find("   "))));
        second_list.push_back(stoi(line.substr(line.find("   ")+1)));
    }

    input.close();

    int res = 0;

    while (first_list.size() && second_list.size())
    {
        int first = *std::min_element(first_list.begin(), first_list.end());
        first_list.erase(std::min_element(first_list.begin(), first_list.end()));
        int second = *std::min_element(second_list.begin(), second_list.end());
        second_list.erase(std::min_element(second_list.begin(), second_list.end()));
        
        res += abs(first - second);
    }

    std::cout << res << std::endl;
    return 0;
}

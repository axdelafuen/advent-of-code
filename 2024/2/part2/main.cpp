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
        auto it = first_list.begin();
        first_list.erase(it);
        res += (*it) * std::count(second_list.begin(), second_list.end(), *it);
    }

    std::cout << res << std::endl;
    return 0;
}

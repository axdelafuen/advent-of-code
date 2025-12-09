#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define SOURCE 'S'
#define SPLIT '^'
#define BEAM '|'

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    long result = 0;

    lines[0][lines[0].find(SOURCE)] = BEAM;
    
    for (int i = 0; i < (int)lines.size() - 1; i++) {
        for (int j = 0; j < (int)lines[i].size(); j++) {
            if (lines[i][j] == BEAM) {
                if (lines[i+1][j] != SPLIT)
                    lines[i+1][j] = BEAM;
                else {
                    bool splitted = false;
                    if (j > 0) {
                        lines[i+1][j-1] = BEAM;
                        splitted = true;
                    }
                    if (j < (int)lines[i].size()) {
                        lines[i+1][j+1] = BEAM;
                        splitted = true;
                    }
                    if (splitted)
                        result++;
                }
            }
        } 
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

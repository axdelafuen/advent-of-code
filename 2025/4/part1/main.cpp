#include <iostream>
#include <vector>
#include <string>

#define PAPER '@'

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    int result = 0;

    std::vector<int> x = {-1, -1, -1,  0,  1,  1,  1,  0};
    std::vector<int> y = {-1,  0,  1,  1,  1,  0, -1, -1};

    int nbLines = lines.size();
    for (int i = 0; i < nbLines; i++) {
        int nbChars = lines[i].length();
        for (int j = 0; j < nbChars; j++) {

            if (lines[i][j] != PAPER)
                continue;

            int cpt = 0;

            for (int k = 0; k < 8; k++) {
                int ni = i + x[k];
                int nj = j + y[k];

                if (ni >= 0 && ni < nbLines && nj >= 0 && nj < nbChars) {
                    if (lines[ni][nj] == PAPER) {
                        cpt++;
                    }
                }
            } 

            if (cpt < 4)
                result++;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

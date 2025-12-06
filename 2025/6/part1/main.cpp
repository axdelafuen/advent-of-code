#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define MULT '*'
#define PLUS '+'

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    long result = 0;

    std::vector<std::vector<std::string>> temp;

    for (auto& l : lines) {
        std::istringstream iss(l);
        std::vector<std::string> row;
        std::string token;

        while (iss >> token)
            row.push_back(token);

        temp.push_back(row);
    }

    std::vector<std::string> transposed(temp[0].size());

    for (int c = 0; c < (int)temp[0].size(); c++) {
        std::string line;
        for (int r = 0; r < (int)temp.size(); ++r) {
            line += temp[r][c];
            if (r + 1 < (int)temp.size()) line += " ";
        }
        transposed[c] = line;
    }

    for (auto& l: transposed) {
        char op = l.back();
        l.pop_back();

        long tempResult = 0;
        if (op == MULT)
            tempResult = 1;

        std::istringstream iss(l);
        int val;

        while (iss >> val) {
            if (op == PLUS)
                tempResult += val;
            else if (op == MULT)
                tempResult *= val;
        }

        result += tempResult;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

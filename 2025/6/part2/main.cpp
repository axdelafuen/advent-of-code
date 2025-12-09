#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define MULT '*'
#define PLUS '+'

int main() {
    std::vector<std::string> lines = {};
    std::string line;

    std::cout << "Input:" << std::endl;
    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    long result = 0;

    std::string opLine = lines.back();
    lines.pop_back();
    
    size_t maxLen = opLine.length();
    for (const auto& l : lines) {
        maxLen = std::max(maxLen, l.length());
    }
    
    int pos = maxLen - 1;
    while (pos >= 0) {
        if (pos >= (int)opLine.length()) {
            pos--;
            continue;
        }
        
        char op = opLine[pos];
        
        if (op != MULT && op != PLUS) {
            pos--;
            continue;
        }
        
        int rightBound = pos + 1;
        while (rightBound < (int)maxLen) {
            if (rightBound < (int)opLine.length() && (opLine[rightBound] == MULT || opLine[rightBound] == PLUS)) break;
            
            bool hasData = false;
            for (const auto& l : lines) {
                if (rightBound < (int)l.length() && l[rightBound] >= '0' && l[rightBound] <= '9') {
                    hasData = true;
                    break;
                }
            }
            if (!hasData) break;
            rightBound++;
        }
        rightBound--;
        
        int leftBound = pos - 1;
        while (leftBound >= 0) {
            if (leftBound < (int)opLine.length() && (opLine[leftBound] == MULT || opLine[leftBound] == PLUS)) break;
            
            bool hasData = false;
            for (const auto& l : lines) {
                if (leftBound < (int)l.length() && l[leftBound] >= '0' && l[leftBound] <= '9') {
                    hasData = true;
                    break;
                }
            }
            if (!hasData) break;
            leftBound--;
        }
        leftBound++;
        
        std::vector<long> numbers;
        for (int p = rightBound; p >= leftBound; --p) {
            std::string digitStr;
            for (int r = (int)lines.size() - 1; r >= 0; --r) {
                if (p < (int)lines[r].length()) {
                    char c = lines[r][p];
                    if (c >= '0' && c <= '9') {
                        digitStr += c;
                    }
                }
            }
            if (!digitStr.empty()) {
                std::reverse(digitStr.begin(), digitStr.end());
                long val = std::stol(digitStr);
                numbers.push_back(val);
            }
        }
        
        long tempResult = (op == MULT) ? 1 : 0;
        for (long num : numbers) {
            if (op == PLUS)
                tempResult += num;
            else if (op == MULT)
                tempResult *= num;
        }
        result += tempResult;
        
        pos = leftBound - 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

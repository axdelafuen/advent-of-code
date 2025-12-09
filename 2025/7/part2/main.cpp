#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

#define SOURCE 'S'
#define SPLIT '^'

std::map<std::pair<int, int>, long long> memo;

long long countTimelines(const std::vector<std::string>& grid, int row, int col) {
    int rows = grid.size();
    int cols = grid[0].size();

    auto key = std::make_pair(row, col);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    int startRow = row;
    while (row < rows) {
        if (grid[row][col] == SPLIT) {
            long long leftTimelines = 0;
            long long rightTimelines = 0;
            
            if (col > 0) {
                leftTimelines = countTimelines(grid, row + 1, col - 1);
            }
            if (col < cols - 1) {
                rightTimelines = countTimelines(grid, row + 1, col + 1);
            }
            
            long long result = leftTimelines + rightTimelines;
            memo[key] = result;
            return result;
        }
        row++;
    }
    
    memo[key] = 1;
    return 1;
}

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    long result = 0;

    int startCol = -1;
    for (int j = 0; j < (int)lines[0].size(); j++) {
        if (lines[0][j] == SOURCE) {
            startCol = j;
            break;
        }
    }
    
    result = countTimelines(lines, 0, startCol);

    std::cout << "Result: " << result << std::endl;

    return 0;
}

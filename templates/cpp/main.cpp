#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    long result = 0;

    // puzzle solver here

    std::cout << "Result: " << result << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines;
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }

    int dial = 50;
    int result = 0;

    for (const auto& l: lines) {
        if (l.empty())
            continue;
        int amount = std::stoi(l.substr(1));
        if (l[0] == 'L') {
            dial -= amount;
            while (dial < 0) {
                dial += 100;
            }
        }
        if (l[0] == 'R') {
            dial += amount;
            while (dial > 99) {
                dial -= 100;
            }
        }
        if (dial == 0)
            result++;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

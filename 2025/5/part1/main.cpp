#include <iostream>
#include <vector>
#include <string>
#include <utility>

#define DASH '-'

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    int result = 0;
    std::vector<std::pair<long, long>> ranges;

    for (auto l = lines.begin(); l != lines.end();) {
        if (l->empty())
            break;

        int dashIndex = l->find(DASH);
        long firstVal = std::stol(l->substr(0, dashIndex));
        long secVal = std::stol(l->substr(dashIndex+1));

        ranges.push_back(std::make_pair(firstVal, secVal));
        lines.erase(l);
    }

    for (const auto& l: lines) {
        if (l.empty())
            continue;

        long val = std::stol(l);
        for (const auto& r: ranges) {
            if (val >= r.first && val <= r.second){
                result++;
                break;
            }
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

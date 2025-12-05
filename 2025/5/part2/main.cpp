#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

#define DASH '-'

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<std::string> lines = {};
    std::string line;

    while (getline(std::cin, line)) {
        lines.push_back(line);
    }
    
    long result = 0;
    std::vector<std::pair<long, long>> ranges = {};

    for (auto l = lines.begin(); l != lines.end();) {
        if (l->empty())
            break;

        int dashIndex = l->find(DASH);
        long firstVal = std::stol(l->substr(0, dashIndex));
        long secVal = std::stol(l->substr(dashIndex+1));

        ranges.push_back(std::make_pair(firstVal, secVal));
        lines.erase(l);
    }

    std::sort(ranges.begin(), ranges.end());

    std::vector<std::pair<long, long>> merged;
    for (const auto& r : ranges) {
        if (merged.empty() || merged.back().second < r.first - 1) {
            merged.push_back(r);
        } else {
            merged.back().second = std::max(merged.back().second, r.second);
        }
    }

    for (const auto& r : merged) {
        result += r.second - r.first + 1;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

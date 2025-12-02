#include <iostream>
#include <vector>
#include <string>

#define DASH "-"
#define COMMA ","

int main() {
    std::cout << "Input:" << std::endl;
    std::string lines;
    std::string line;

    while (getline(std::cin, line)) {
        lines += line;
    }

    std::cout << std::endl;
    long result = 0;

    while (!lines.empty()) {
        std::size_t separationIndex = lines.find(COMMA);
        std::string range;

        if (separationIndex == std::string::npos) {
            range = lines;
            lines = "";
        }
        else {
            range = lines.substr(0, separationIndex);
            lines = lines.substr(separationIndex + 1);
        }
        
        std::size_t rangeIndex = range.find(DASH);     

        if (rangeIndex == std::string::npos)
            return -1;

        long firstVal = std::stol(range.substr(0, rangeIndex));
        long secVal = std::stol(range.substr(rangeIndex + 1));

        for (long i = firstVal; i <= secVal; ++i) {
            std::string iString = std::to_string(i);
            
            if (iString.length() % 2 != 0)
                continue;
            
            long firstIPart = std::stol(
                    iString.substr(0, iString.length()/2));
            long secIPart = std::stol(
                    iString.substr(iString.length()/2));

            if (firstIPart == secIPart)
                result += i;
        }
    }

    std::cout << std::endl << "Result: " << result << std::endl;

    return 0;
}

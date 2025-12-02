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
            int len = iString.length();
            
            if (len == 1)
                continue;
            
            bool isInvalid = false;
            
            for (int blockSize = 1; blockSize <= len / 2; ++blockSize) {
                if (len % blockSize != 0)
                    continue;
                
                std::string pattern = iString.substr(0, blockSize);
                std::string repeated = "";
                int repeatCount = len / blockSize;
                
                for (int r = 0; r < repeatCount; ++r) {
                    repeated += pattern;
                }
                
                if (repeated == iString && repeatCount >= 2) {
                    isInvalid = true;
                    break;
                }
            }
            
            if (isInvalid)
                result += i;
        }
    }

    std::cout << std::endl << "Result: " << result << std::endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<int> x, y;
    std::string line;

    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        int px, py;
        char comma;
        ss >> px >> comma >> py;
        x.push_back(px);
        y.push_back(py);
    }

    long result = 0;

    for (int i = 0; i < (int)x.size(); i++) {
        for (int j = i + 1; j < (int)x.size(); j++) {
            long xMax = std::max(x.at(i), x.at(j)); 
            long xMin = std::min(x.at(i), x.at(j)); 
            long yMax = std::max(y.at(i), y.at(j));
            long yMin = std::min(y.at(i), y.at(j)); 

            long val = (xMax - xMin + 1) * (yMax - yMin + 1);

            if (val > result)
                result = val;
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

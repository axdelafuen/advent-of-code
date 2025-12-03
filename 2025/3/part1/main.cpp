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

    int result = 0;

    for (auto& l: lines) {
        if (l.empty())
            continue;

        int index = 0;
        std::string firstVal = "0";
        for (std::string::size_type i = 0; i < l.size(); ++i) {
            int cVal = l[i] - '0';
            if (cVal > std::stoi(firstVal)) {
                firstVal = l[i];
                index = i;
            }
        }

        int secVal = 0;
        for (std::string::size_type i = 0; i < l.size(); ++i) {
            int cVal = 0;
            if ((int)i < index) {
                cVal = std::stoi(l[i] + firstVal);
            }
            else if ((int)i > index) {
                cVal = std::stoi(firstVal + l[i]);
            }
            else
                continue;

            if (cVal > secVal)
                secVal = cVal;
        }

        result += secVal;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

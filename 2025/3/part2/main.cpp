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

    long long result = 0;

    for (auto& l: lines) {
        if (l.empty())
            continue;

        if (l.length() < 12)
            continue;

        int keepLLength = l.length() - 12; // needed cuz 'l' is
                                           // being modified in the loop 
        for (int i = 0; i < keepLLength; i++) {
            int index = -1;
            for (int j = 0; j < (int)l.length() - 1; j++) {
                if (l[j] < l[j+1]) {
                    index = j;
                    break;
                }
            }

            if (index == -1) {
                index = l.length() - 1;
            }

            l.erase(index, 1);
        }
        
        if (l.length() != 12)
            continue;
        
        result += std::stoll(l);
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

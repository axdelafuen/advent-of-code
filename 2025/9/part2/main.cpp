#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<long> x, y;
    std::string line;

    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        long px, py;
        char comma;
        ss >> px >> comma >> py;
        x.push_back(px);
        y.push_back(py);
    }

    long result = 0;
    long n = x.size();
    
    long minX = x[0], maxX = x[0], minY = y[0], maxY = y[0];
    for (long i = 0; i < n; i++) {
        minX = std::min(minX, x[i]);
        maxX = std::max(maxX, x[i]);
        minY = std::min(minY, y[i]);
        maxY = std::max(maxY, y[i]);
    }

    for (long i = 0; i < n; i++) {
        for (long j = i + 1; j < n; j++) {
            long x1 = x[i], y1 = y[i];
            long x2 = x[j], y2 = y[j];
            long rxMin = std::min(x1, x2);
            long rxMax = std::max(x1, x2);
            long ryMin = std::min(y1, y2);
            long ryMax = std::max(y1, y2);
            
            long area = (rxMax - rxMin + 1) * (ryMax - ryMin + 1);
            if (area <= result) continue;
            
            bool valid = true;
            long sampleStep = std::max(1L, std::max((rxMax - rxMin) / 100, (ryMax - ryMin) / 100));
            
            for (long tx = rxMin; tx <= rxMax && valid; tx += sampleStep) {
                for (long ty = ryMin; ty <= ryMax && valid; ty += sampleStep) {
                    bool isRed = false;
                    for (long k = 0; k < n; k++) {
                        if (x[k] == tx && y[k] == ty) {
                            isRed = true;
                            break;
                        }
                    }
                    if (isRed) continue;
                    
                    bool onGreen = false;
                    for (long k = 0; k < n; k++) {
                        long next = (k + 1) % n;
                        long x1p = x[k], y1p = y[k];
                        long x2p = x[next], y2p = y[next];
                        
                        if (x1p == x2p && x1p == tx) {
                            if (ty > std::min(y1p, y2p) && ty < std::max(y1p, y2p)) {
                                onGreen = true;
                                break;
                            }
                        }
                        if (y1p == y2p && y1p == ty) {
                            if (tx > std::min(x1p, x2p) && tx < std::max(x1p, x2p)) {
                                onGreen = true;
                                break;
                            }
                        }
                    }
                    if (onGreen) continue;
                    
                    long winding = 0;
                    for (long k = 0; k < n; k++) {
                        long next = (k + 1) % n;
                        long x1p = x[k], y1p = y[k];
                        long x2p = x[next], y2p = y[next];
                        
                        if (y1p <= ty && y2p > ty) {
                            long cross = (x2p - x1p) * (ty - y1p) - (y2p - y1p) * (tx - x1p);
                            if (cross > 0) winding++;
                        } else if (y1p > ty && y2p <= ty) {
                            long cross = (x2p - x1p) * (ty - y1p) - (y2p - y1p) * (tx - x1p);
                            if (cross < 0) winding--;
                        }
                    }
                    
                    if (winding == 0) {
                        valid = false;
                    }
                }
            }
            
            if (valid) {
                result = std::max(result, area);
            }
        }
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

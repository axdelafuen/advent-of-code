#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>

int main() {
    std::cout << "Input:" << std::endl;
    std::vector<int> x, y, z;
    std::string line;

    while (getline(std::cin, line)) {
        std::stringstream ss(line);
        int px, py, pz;
        char comma;
        ss >> px >> comma >> py >> comma >> pz;
        x.push_back(px);
        y.push_back(py);
        z.push_back(pz);
    }
    
    long result = 1;

    int n = x.size();
    std::vector<std::tuple<double, int, int>> edges;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = x[i] - x[j];
            long long dy = y[i] - y[j];
            long long dz = z[i] - z[j];
            double dist = std::sqrt(dx*dx + dy*dy + dz*dz);
            edges.push_back({dist, i, j});
        }
    }
    
    std::sort(edges.begin(), edges.end());
    
    std::vector<int> parent(n);
    std::vector<int> rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    for (int idx = 0; idx < 1000 && idx < (int)edges.size(); idx++) {
        int i = std::get<1>(edges[idx]);
        int j = std::get<2>(edges[idx]);
        
        int pi = i;
        while (parent[pi] != pi) {
            parent[pi] = parent[parent[pi]];
            pi = parent[pi];
        }
        
        int pj = j;
        while (parent[pj] != pj) {
            parent[pj] = parent[parent[pj]];
            pj = parent[pj];
        }
        
        if (pi != pj) {
            if (rank[pi] < rank[pj]) {
                parent[pi] = pj;
            } else if (rank[pi] > rank[pj]) {
                parent[pj] = pi;
            } else {
                parent[pj] = pi;
                rank[pi]++;
            }
        }
    }
    
    std::map<int, int> circuit_size;
    for (int i = 0; i < n; i++) {
        int pi = i;
        while (parent[pi] != pi) {
            parent[pi] = parent[parent[pi]];
            pi = parent[pi];
        }
        circuit_size[pi]++;
    }
    
    std::vector<int> sizes;
    for (const auto& p : circuit_size) {
        sizes.push_back(p.second);
    }
    
    std::sort(sizes.begin(), sizes.end(), std::greater<int>());
    
    for (int i = 0; i < 3 && i < (int)sizes.size(); i++) {
        result *= sizes[i];
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}

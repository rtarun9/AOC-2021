#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

int main()
{
    std::vector<int> positions = 
    {
        #include "input.txt"
    };

    uint64_t minimum_cost = INT_MAX;

    for (int i = 0; i < positions.size(); i++)
    {
        uint64_t cost_for_index = 0;
        for (int j = 0; j < positions.size(); j++)
        {
            cost_for_index += std::abs(positions[j] - i); 
        }
    
        minimum_cost = std::min(cost_for_index, minimum_cost);
    }

    std::cout << minimum_cost;
}
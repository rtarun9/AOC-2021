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

    uint64_t minimum_cost = INT64_MAX;

    for (std::size_t i = 1; i < positions.size(); i++)
    {
        uint64_t cost_for_index = 0;
        uint64_t positions_to_move = 0;
        for (std::size_t j = 0; j < positions.size(); j++)
        {
            positions_to_move =  std::abs(positions[(int)j] - (int)i); 
            cost_for_index += positions_to_move * (positions_to_move + 1) / 2;
        }

        minimum_cost = std::min(cost_for_index, minimum_cost);
    }

    std::cout << minimum_cost;
}
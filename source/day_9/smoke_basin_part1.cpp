#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::vector<int>> grid = 
    {
        #include "input.txt"
    };

    std::uint16_t risk_level;

    for (auto i = 1; i < grid.size() - 1; i++)
    {
        for (auto j = 1; j < grid[i].size() - 1; j++)
        {
            if (grid[i][j] < grid[i][j + 1] && grid[i][j] < grid[i + 1][j] && grid[i][j] < grid[i - 1][j] && grid[i][j] < grid[i][j  - 1])
            {
                risk_level += grid[i][j] + 1;
            }
        }
    }

    std::cout << risk_level;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

std::uint64_t is_part_of_basin(std::vector<std::vector<int>> &grid, int i, int j, int current_test_value)
{
    std::uint64_t res = 0;

    if ((grid[i][j] > current_test_value) && grid[i][j] != 9)
    {
        res++;
        grid[i][j] = current_test_value;
        res += is_part_of_basin(grid, i, j - 1, grid[i][j]);
        res += is_part_of_basin(grid, i, j + 1, grid[i][j]);
        res += is_part_of_basin(grid, i - 1, j, grid[i][j]);
        res += is_part_of_basin(grid, i + 1, j, grid[i][j]);
    }

    return res;
}

int main()
{
    std::vector<std::vector<int>> grid =
        {
#include "input.txt"
        };

    std::vector<std::pair<int, int>> low_points;
    for (auto i = 1; i < grid.size() - 1; i++)
    {
        for (auto j = 1; j < grid[i].size() - 1; j++)
        {
            if (grid[i][j] < grid[i][j + 1] && grid[i][j] < grid[i + 1][j] && grid[i][j] < grid[i - 1][j] && grid[i][j] < grid[i][j - 1])
            {
                low_points.push_back({i, j});
            }
        }
    }

    std::vector<int> basins;

    for (auto &lp : low_points)
    {
        std::cout << "FOR : " << grid[lp.first][lp.second]  << " ";
        auto val = is_part_of_basin(grid, lp.first, lp.second, -1);
        basins.push_back(val);
        std::cout << val << "\n";
    }

    std::sort(basins.begin(), basins.end(), [](int a, int b)
              { return a > b; });
    std::cout << basins[0] << ", " << basins[1] << ", " << basins[2] << "\n";
    std::uint64_t result = basins[0] * basins[1] * basins[2];

    std::cout << result;
}
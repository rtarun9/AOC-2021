#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

static inline void flash(std::vector<std::vector<int>>& octopus, std::set<std::pair<int, int>>& flashed, int r, int c)
{
    auto coord = std::make_pair(r, c);
    if (flashed.find(coord) == flashed.end())
    {
        flashed.insert(coord);
    }
    else
    {
        return;
    }

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            // skip currect octopus
            if (i == 0 && j == 0)
            {
                continue;
            }

            int row = r + i;
            int col = c + j;

            // check if in bounds
            if (row < 0 || row + 1 > octopus.size() || col < 0 || col + 1 > octopus.size())
            {
                continue;
            }

            octopus[row][col]++;
            if (octopus[row][col] > 9)
            {
                flash(octopus, flashed, row, col);
            }
        }
    }
}

static inline void display(std::vector<std::vector<int>>& arr)
{
       for (const auto& row : arr)
        {
            for (const auto& elem : row)
            {
                std::cout << elem << " ";
            }

            std::cout << '\n';
        }
}

int main()
{
    std::vector<std::vector<int>> octopus = 
    {
        #include "input.txt"
    };

    constexpr std::uint64_t steps = INT_MAX;
    std::uint64_t flashes = 0;

    for (int s = 0; s < steps; s++)
    {
        std::set<std::pair<int, int>> flashed;

        for (auto& j : octopus)
        {
            for (auto& k : j)
            {
                k++;
            }
        }

        for (std::size_t i = 0; i < octopus.size(); i++)
        {
            for (std::size_t j = 0; j < octopus[i].size(); j++)
            {
                if (octopus[i][j] > 9)
                {
                    flash(octopus, flashed, i, j);
                }
            }
        }

        // make the flashed octopus back to zero
        for (const auto& f : flashed)
        {
            octopus[f.first][f.second] = 0;
        }

        flashes += flashed.size();
        if (flashed.size() == octopus.size() * octopus.size())
        {
            std::cout << "AT STEP " << s + 1 << " ALL FLASH\n";
            return 0;
        }
        std::cout << "AT STEP : " << s << "\n";
    }

    std::cout << "TOTAL FLASHES : " << flashes;
}
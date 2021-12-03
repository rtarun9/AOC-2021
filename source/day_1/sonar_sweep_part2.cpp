#include <fstream>
#include <vector>
#include <iostream>
#include <numeric>

int main()
{
    std::ifstream file("depths.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Failed to read file." << '\n';
        exit(EXIT_FAILURE);
    }

    int depth;
    std::vector<int> depths;

    while (file >> depth)
    {
        depths.push_back(depth);
    }

    // reference used for the logic
    // 0    A
    // 1    A   B
    // 2    A   B
    // 3        B
    int increments = 0;

    int previous_group_sum = std::accumulate(depths.begin(), depths.begin() + 3, 0);
    for (int i = 1; i < depths.size() - 1; i++)
    {
        int current_group_sum = std::accumulate(depths.begin() + i, depths.begin() + i + 3, 0);
        if (previous_group_sum < current_group_sum)
        {
            increments++;
        }

        std::swap(previous_group_sum, current_group_sum);
    }

    std::cout << increments;
}
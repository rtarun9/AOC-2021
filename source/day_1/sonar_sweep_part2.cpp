#include <fstream>
#include <vector>
#include <iostream>

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

    int previous_group_sum = depths[0] + depths[1] + depths[2];
    for (int i = 1; i < depths.size() - 1; i++)
    {
        if (previous_group_sum < previous_group_sum - depths[i - 2] + depths[i + 1])
        {
            increments++;
        }

        previous_group_sum = depths[i - 1] + depths[i + 2];
    }

    std::cout << increments;
}
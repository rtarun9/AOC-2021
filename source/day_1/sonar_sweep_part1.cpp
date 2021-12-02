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


    int increments = 0;
    for (int i = 0; i < depths.size() - 1; i++)
    {
        if (depths[i] < depths[i + 1])
        {
            increments++;
        }
    }

    std::cout << increments;
}
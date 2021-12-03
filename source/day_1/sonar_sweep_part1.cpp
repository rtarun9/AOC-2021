#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

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

    // alternate modern C++ method
    // depth = depths[0];
    // int increments = std::count_if(depths.begin() + 1, depths.end(), [&depth](int current_depth) 
    //                     {
    //                         std::swap(depth, current_depth); 
    //                         return current_depth < depth;
    //                     });

    std::cout << increments;
}
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

int main()
{
    std::ifstream file("instructions.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Failed to read file.";
        return 0;
    }

    std::vector<std::pair<std::string, int>> path;
    
    std::string direction;
    int steps;

    while (file >> direction >> steps)
    {
        path.push_back(std::make_pair(direction, steps));
    }

    struct Point
    {
        long long x;
        long long y;
    };

    Point destination = {};

    for (const auto& dir : path)
    {
        if (dir.first == "forward")
        {
            destination.x += dir.second;        
        }
        else if (dir.first == "up")
        {
            destination.y -= dir.second;
        }
        else if (dir.first == "down")
        {
            destination.y += dir.second;
        }
    }

    std::cout << destination.x * destination.y;
}
#include <iostream>
#include <fstream>
#include <vector>

struct DepthInfo
{
    std::string direction;
    int steps;
};

int main()
{
    std::ifstream file("instructions.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Failed to read file.";
        return 0;
    }

    std::vector<DepthInfo> depthInfos;
    
    std::string direction;
    int steps;

    while (file >> direction >> steps)
    {
        depthInfos.push_back({direction, steps});
    }

    struct Point
    {
        long long x;
        long long y;
    };

    Point destination = {};

    for (const auto& depthInfo : depthInfos)
    {
        if (depthInfo.direction == "forward")
        {
            destination.x += depthInfo.steps;        
        }
        else if (depthInfo.direction == "up")
        {
            destination.y -= depthInfo.steps;
        }
        else if (depthInfo.direction == "down")
        {
            destination.y += depthInfo.steps;
        }
    }

    std::cout << destination.x * destination.y;
}
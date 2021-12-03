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

    long long aim = 0;

    Point final = {};

    for (const auto& depthInfo : depthInfos)
    {
        if (depthInfo.direction == "forward")
        {
            final.x += depthInfo.steps;       
            final.y += depthInfo.steps * aim; 
        }
        else if (depthInfo.direction == "down")
        {
            aim += depthInfo.steps;
        }
        else if (depthInfo.direction == "up")
        {
            aim -= depthInfo.steps;
        }
        else if (depthInfo.direction == "down")
        {
            final.y += depthInfo.steps;
        }
    }

    std::cout << final.x * final.y;
}
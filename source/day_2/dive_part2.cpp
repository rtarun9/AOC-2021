#include <iostream>
#include <fstream>
#include <vector>

struct Instruction
{
    std::string dir;
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

    std::vector<Instruction> path;
    
    std::string direction;
    int steps;

    while (file >> direction >> steps)
    {
        path.push_back({direction, steps});
    }

    struct Point
    {
        long long x;
        long long y;
        long long aim;
    };

    Point final = {};

    for (const auto& direction : path)
    {
        if (direction.dir == "forward")
        {
            final.x += direction.steps;       
            final.y += direction.steps * final.aim; 
        }
        else if (direction.dir == "down")
        {
            final.aim += direction.steps;
        }
        else if (direction.dir == "up")
        {
            final.aim -= direction.steps;
        }
        else if (direction.dir == "down")
        {
            final.y += direction.steps;
        }
    }

    std::cout << final.x * final.y;
}
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    struct LineSegment
    {
        int x1, y1;
        int x2, y2;
    };

    std::vector<LineSegment> line_segments = 
    {
        #include "input.txt"
    };

    int greatest_point_x = 0;
    int greatest_point_y = 0;

    for (const auto& point : line_segments)
    {
        int x = std::max(point.x1, point.x2);
        int y = std::max(point.y1, point.y2);

        greatest_point_x = std::max(greatest_point_x, x);
        greatest_point_y = std::max(greatest_point_y, y);
    }   

    std::cout << "Greatest point x and y : " << greatest_point_x << ", " << greatest_point_y << '\n';

    // generate board
    std::vector<std::vector<int>> graph;

    for (auto i = 0; i <= greatest_point_y; i++)
    {
        std::vector<int> temp;

        for (auto j = 0; j <= greatest_point_x; j++)
        {
            temp.push_back(0);
        }

        graph.push_back(temp);
    }

    // update points in graph
    for (const auto& line_segment : line_segments)
    {
        //std::cout << "Curr segment : " << line_segment.x1 << ", " << line_segment.y1 << " -> " << line_segment.x2 << ", " << line_segment.y2 << '\n';
        // if horizontal line
        if (line_segment.y1 == line_segment.y2)
        {
            int low = std::min(line_segment.x1, line_segment.x2);
            int high = std::max(line_segment.x1, line_segment.x2);

            for (auto i = low; i <= high; i++)
            {
                graph[line_segment.y1][i]++;
            }
        }
        else if (line_segment.x1 == line_segment.x2)
        {
            // if vertical line
            int low = std::min(line_segment.y1, line_segment.y2);
            int high = std::max(line_segment.y1, line_segment.y2);
            for (auto i = low; i <= high; i++)
            {
                graph[i][line_segment.x1]++;
            }
        }
    }

    int overlaps = 0;
    for (const auto& y : graph)
    {
        overlaps += std::count_if(y.begin(), y.end(), [](int point){return point > 1;});
        // for (const auto& x : y)
        // {
        //     std::cout << x;
        // }
        // std::cout << '\n';
    }

    std::cout << "Overlapping points : " << overlaps;
}
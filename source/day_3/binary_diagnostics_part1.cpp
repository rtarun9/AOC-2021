#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>

// BIT_COUNT is currently hardcoded, which should not be the case.
#define BIT_COUNT 12
#define MSB 0
#define LSB 11

int main()
{
    std::ifstream file("input.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Failed to read file.";
        return 0;
    }

    std::vector<std::bitset<BIT_COUNT>> report_values;
    std::string value;
    std::bitset<BIT_COUNT> temp;

    while (file >> value)
    {
        temp = std::bitset<BIT_COUNT>(value);
        report_values.push_back(temp);
    }

    int most_common_bits[BIT_COUNT];
    for (int i = 0; i < BIT_COUNT; i++)
    {
        int zero_count = std::count_if(report_values.begin(), report_values.end(), [&i](auto& value) {return value[i] == 0;});
        int ones_count = report_values.size() - zero_count;
        
        most_common_bits[i] = zero_count > ones_count ? 0 : 1;
    }

    int gamma_rate = 0;
    int epsilon_rate = 0;
    for (int i = 0; i < BIT_COUNT; i++)
    {
        if (most_common_bits[i] == 1)
        {
            gamma_rate += pow(2, i);
        }
        else
        {
            epsilon_rate += pow(2, i);
        }
    }
  
    std::cout << gamma_rate * epsilon_rate << std::endl;
}
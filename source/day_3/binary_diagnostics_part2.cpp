#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define BIT_COUNT 12

std::string generator(std::vector<std::string>& interval, bool o2_gen)
{
    int index = 0;
    
    while (index < BIT_COUNT || interval.size() > 1)
    {
        std::size_t ones_count = std::count_if(interval.begin(), interval.end(), [&index](std::string& value){return value[index] == '1';});
        std::size_t zeros_count = interval.size() - ones_count;

        char significant_bit;
        bool is_one_max_digit = ones_count >= zeros_count;

        significant_bit = o2_gen ?
            (is_one_max_digit ? '1' : '0') : 
            (is_one_max_digit ? '0' : '1');

        interval.erase(std::remove_if(interval.begin(), interval.end(), 
        [&index, &significant_bit](std::string& value){return (value[index] != significant_bit);}), interval.end());

        index++;
    }   

    return interval[0];
}

int main()
{
    std::ifstream file("input.txt", std::ios::in);
    if (!file.is_open())
    {
        std::cout << "Failed to open file\n";
        return 0;
    }

    std::string input;
    std::vector<std::string> inputs;

    while (file >> input)
    {
        inputs.push_back(input);
    }

    // for oxygen generator rating
    std::vector<std::string> interval = inputs;
    int o2_report = std::stoi(generator(interval, true), 0, 2);

    // for carbpn scrapping rating
    interval = inputs;
    int co2_report = std::stoi(generator(interval, false), 0, 2);

    std::cout << "life support : " << o2_report * co2_report << std::endl;
}
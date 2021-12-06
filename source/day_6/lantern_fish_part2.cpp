#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // each fish : number representing number of days until is creates a new one.
    // note : new fish needs two more days for to produce a lanternfish than its first cycle.
    // note :The new lanternfish starts with an internal timer of 8 and does not start counting down until the next day.

    std::vector<int> input = 
    {
        #include "input.txt"
    };

    std::vector<uint64_t> fishes(9);
    for (const auto i : input)
    {
        fishes[i]++;
    }

    std::cout << "Initial condition : ";
    for (const auto f : fishes)
    {
        std::cout << f << " ";
    }
    std::cout << '\n';

    int days = 256;
    uint64_t count = 0;

    while (days--)
    {
        std::rotate(fishes.begin(), fishes.begin() + 1, fishes.end());
        fishes[6] += fishes[8];
    }

    for (const auto f : fishes)
    {
        count += f;
    }

    std::cout << "Number of fishes : " << count << std::endl;
}
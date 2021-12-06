#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // each fish : number representing number of days until is creates a new one.
    // note : new fish needs two more days for to produce a lanternfish than its first cycle.
    // note :The new lanternfish starts with an internal timer of 8 and does not start counting down until the next day.

    std::vector<int> fishes = 
    {
        #include "input.txt"
    };

    for (std::size_t i = 0; i < 16; i++)
    {
        //std::cout << "\nAfter day : " << i << '\n';
        for (int i = 0; i < fishes.size(); i++)
        {
            if (fishes[i] > 0)
            {
                fishes[i]--;
            }
            else
            {
                fishes[i] = 6;
                // 9 since in the current solution I've writen new fishes are also processed on the same day. so, making it 9 means it will become 8 (the desired value) at the end of the day.
                // better solution will have vector of new fishes and append it to fishes vector array at the end of each day.
                fishes.push_back(9);
            }

            //std::cout << fishes[i] << " ";
        }
    }

    std::cout << "Number of fishes : " << fishes.size() << std::endl;
}
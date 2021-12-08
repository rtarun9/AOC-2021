#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <algorithm>

#define LINE_LENGTH 15

int common_chars(std::string &a, std::string &b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int common = 0;
    for (int i = 0; i < b.size(); i++)
    {
        auto it = (std::find(a.begin(), a.end(), b[i]));
        if (it != a.end())
        {
            common++;
        }
    }

    return common;
}

int diff_chars(std::string &a, std::string &b)
{
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int diff  = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            diff++;
        }
    }

    return diff;
}

int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> inputs;

    std::string word;
    while (file >> word)
    {
        inputs.push_back(word);
    }

    uint64_t result = 0;
    for (std::size_t i = 0; i < inputs.size();)
    {
        std::vector<std::string> zero_six_nine;
        std::vector<std::string> two_three_five;

        std::string nums[10];
        for (int j = 0; j < 10; j++)
        {
            std::string input = inputs[i];
            if (input.length() == 7)
            {
                nums[8] = input;
            }
            else if (input.length() == 2)
            {
                nums[1] = input;
            }
            else if (input.length() == 3)
            {
                nums[7] = input;
            }
            else if (input.length() == 4)
            {
                nums[4] = input;
            }

            if (input.length() == 6)
            {
                zero_six_nine.push_back(input);
            }
            else if (input.length() == 5)
            {
                two_three_five.push_back(input);
            }

            i++;
        }       

        // set 0, 6 and 9
        // 0 and 6 have 5 common, so does 0 and 9
        // 6 and 9 have 5 common
        int temp = 0; // store 0 value
        if (common_chars(zero_six_nine[0], nums[4]) == 4) 
        {
            nums[9] = zero_six_nine[0];
            if (common_chars(nums[7], zero_six_nine[1]) == 3)
            {
                nums[0] = zero_six_nine[1];
                nums[6] = zero_six_nine[2];
            }
            else
            {
                nums[0] = zero_six_nine[2];
                nums[6] = zero_six_nine[1];
            }
        }
        else if (common_chars(zero_six_nine[1], nums[4]) == 4) 
        {
            nums[9] = zero_six_nine[1];
             if (common_chars(nums[7], zero_six_nine[2]) == 3)
            {
                nums[0] = zero_six_nine[2];
                nums[6] = zero_six_nine[0];
            }
            else
            {
                nums[0] = zero_six_nine[0];
                nums[6] = zero_six_nine[2];
            }
        }
        else 
        {
            nums[9] = zero_six_nine[2];
             if (common_chars(nums[7], zero_six_nine[1]) == 3)
            {
                nums[0] = zero_six_nine[1];
                nums[6] = zero_six_nine[0];
            }
            else
            {
                nums[0] = zero_six_nine[0];
                nums[6] = zero_six_nine[1];
            }
        }

        // set 2, 3, 5
        if (common_chars(two_three_five[0], nums[1]) == 2) {temp = 0; nums[3] = two_three_five[0];}
        else if (common_chars(two_three_five[1], nums[1]) == 2) {temp = 1; nums[3] = two_three_five[1];}
        else {temp = 2; nums[3] = two_three_five[2];}

        // 4 and 5 have three common
        for (int i = 0; i < 3; i++)
        {
            if (i == temp)
            {
                continue;
            }
            if (common_chars(nums[4], two_three_five[i]) == 3)
            {
                nums[5] = two_three_five[i];
            }
            else
            {
                nums[2] = two_three_five[i];
            }
        }

        for (auto& elem : nums)
        {
            std::sort(elem.begin(), elem.end());
        }

        int num  = 0;
        for (int k = 0; k < 4; k++)
        {
            std::string guess = inputs[i];

            std::sort(guess.begin(), guess.end());
            for (int j = 0; j < 10; j++)
            {
                if (guess.compare(nums[j]) == 0)
                {
                    num = num * 10 + j;

                  //  std::cout << nums[j] << " ";
                }
            }
            i++;
        }
            result += num;
    }

    std::cout << result;
}
#include <algorithm>
#include <fstream>
#include <string>
#include <stack>
#include <iostream>
#include <vector>

int calc_score(char c)
{
    int score = 0;
    switch (c)
    {
        case '(' :
        {
            score = 1;
        }break;

        case '[' :
        {
            score = 2;
        }break;

        case '{':
        {
            score = 3;
        }break;

        case '<':
        {
            score = 4;
        }break;
    }
    return score;
}

int main()
{
    std::ifstream file("input.txt");
    std::string input;

    std::vector<std::string> chunks;
    while (file >> input)
    {
        chunks.push_back(input);
    }

    std::vector<std::uint64_t> scores;
    for (auto& chunk : chunks)
    {
        bool invalid = false;
        std::stack<char> checker;
        for (auto& c : chunk)
        {
            if (c == '(' || c == '{' || c == '[' || c == '<')
            {
                checker.push(c);
            }
            else 
            {
                char opening_brace = checker.top();
                checker.pop();

                if ((opening_brace == '(' && c != ')') || (opening_brace == '{' && c != '}') || (opening_brace == '<' && c != '>') || (opening_brace == '[' && c != ']'))
                {   
                    invalid = true;
                }
            }
        }

        if (!invalid)
        {
            std::uint64_t score = 0;
            std::vector<char> required_to_close;
            while (checker.size() > 0)
            {
                required_to_close.push_back(checker.top());
                checker.pop();
            }

            for (const auto& c : required_to_close)
            {
                score = score * 5 + calc_score(c);
            }

            scores.push_back(score);
        }
    }

    std::sort(scores.begin(), scores.end());
    std::cout << scores[scores.size() / 2];
}
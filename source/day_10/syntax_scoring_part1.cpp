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
        case ')' :
        {
            score = 3;
        }break;

        case ']' :
        {
            score = 57;
        }break;

        case '}':
        {
            score = 1197;
        }break;

        case '>':
        {
            score = 25137;
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

    std::uint64_t syntax_error_score = 0;

    for (auto& chunk : chunks)
    {
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
                    syntax_error_score += calc_score(c);
                }
            }
        }
    }
    
    std::cout << syntax_error_score << '\n';
}
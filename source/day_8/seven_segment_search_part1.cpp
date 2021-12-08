#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<std::string> words;

    std::ifstream file("input.txt");
    std::string word;

    while (file >> word)
    {
        words.push_back(word);
    }

    // count : number of tiems 1, 4, 7 or 8 appear

    std::size_t count = 0;
    for (auto& word : words)
    {
       auto it = std::unique(word.begin(), word.end());
       word.resize(std::distance(word.begin(), it));

       std::size_t unique_char_count = word.size(); 
       if (unique_char_count == 4 || unique_char_count == 7 || unique_char_count == 2 || unique_char_count == 3)
       {
           //std::cout << word << '\n';
           count++;
       }
    }

    std::cout << count;
}

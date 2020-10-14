/*
Given two strings s and t, t is a substring of s if t is contained as a contiguous collection of symbols in s 
(as a result, t must be no longer than s).

The position of a symbol in a string is the total number of symbols found to its left, including itself 
(e.g., the positions of all occurrences of 'U' in "AUGCUUCAGAAAGGUCUUACG" are 2, 5, 6, 15, 17, and 18). 
The symbol at position i of s is denoted by s[i].

A substring of s can be represented as s[j:k], where j and k represent the starting and ending positions of the 
substring in s; for example, if s = "AUGCUUCAGAAAGGUCUUACG", then s[2:5] = "UGCU".

The location of a substring s[j:k] is its beginning position j; note that t will have multiple locations in s if 
it occurs more than once as a substring of s.

Problem:
=======
Given: Two DNA strings s and t (each of length at most 1 kbp).

Return: All locations of t as a substring of s.

Reference: http://rosalind.info/problems/subs/
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::vector<int> getLocations(std::string s, std::string t);

int main()
{
    std::string s = "GATATATGCATATACTT";
    std::string t = "ATAT";

    std::vector<int> locations = getLocations(s, t);

    for (int i = 0; i < locations.size(); ++i)
    {
        std::cout << locations[i] << " ";
    }
    std::cout << '\n';

    return 0;
}

std::vector<int> getLocations(std::string s, std::string t)
{
    auto it_genome = s.begin();
    auto end_genome = s.end();

    auto motif_length = t.size();

    if (motif_length > s.size())
    {
        std::cerr << "Invalid\n";
    }


    std::vector<int> locations;
    for (; it_genome + motif_length != end_genome; ++it_genome)
    {
        if (std::equal(t.begin(), t.end(), it_genome))
        {
            locations.push_back(1 + std::distance(s.begin(), it_genome));
        }
    }
    return locations;
}
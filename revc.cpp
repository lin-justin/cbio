/*
In DNA strings, the symbols 'A' and 'T' are complements of each other, 
as are 'C' and 'G'.

The reverse complement of a DNA string s is the string s^c formed by 
reversing the symbols of s, then taking the complement of each symbol
(e.g. the reverse complement of "GTCA" is "TGAC").

Problem:
=======
Given: A DNA string s of length at most 1000 bp.
Return: The reverse complement s^c of s.

Reference: http://rosalind.info/problems/revc/
*/

#include <iostream>
#include <algorithm>
#include <map>

int main()
{
    std::string s = "AAAACCCGGT";

    std::map<char, char> complements = {{'A', 'T'}, 
                                        {'C', 'G'}, 
                                        {'T', 'A'}, 
                                        {'G', 'C'}};

    std::reverse(s.begin(), s.end());
    std::string sc = "";

    for (char const &c : s)
    {
        for (auto const &x : complements)
        {
            // Match character in reversed DNA string with the
            // key of the complements map
            if (c == x.first)
            {
                // Concatenate to the reversed complement string
                // the value of the complements map
                sc += x.second;
            }
        }
    }

    std::cout << sc << '\n';

    return 0;
}
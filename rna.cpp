/*
A RNA string is a string formed from the alphabet containing 'A', 'C', 'G', and 'U'.

Given a DNA string t corresponding to a coding strand, its transcribed RNA string u
is formed by replacing all occurrences of 'T'in t with 'U' in u.

Problem:
=======
Given: A DNA string t having length at most 1000 nt.
Return: The transcribed RNA string of t.

Reference: http://rosalind.info/problems/rna/
*/

#include <iostream>

int main()
{
    std::string t = "GATGGAACTTGACTACGTAAATT";
    
    std::string u = "";
    for (char const &c : t)
    {
        if (c == 'T')
        {
            u += 'U';
        }
        else
        {
            u += c;
        }
        
    }

    std::cout << u << '\n';

    return 0;
}
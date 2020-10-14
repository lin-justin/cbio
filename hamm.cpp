/*
Given two strings s and t of equal length, the Hamming distance 
between s and t is the number of corresponding symbols that differ 
in s and t.

Problem:
=======
Given: Two DNA strings s and t of equal length
Return: The Hamming distance d_H(s, t)

Reference: http://rosalind.info/problems/hamm/
*/

#include <iostream>

// Function prototype
int hammingDistance(std::string s, std::string t);

int main()
{

    std::string s = "GAGCCTACTAACGGGAT";
    std::string t = "CATCGTAATGACGGCCT";

    int distance = hammingDistance(s, t);

    std::cout << distance << '\n';

    return 0;
}

int hammingDistance(std::string s, std::string t)
{
    if (s.length() != t.length())
    {
        std::cerr << "The sequences are of unequal length\n";
    }

    int i = 0;
    int distance = 0;

    while (s[i] != '\0')
    {
        if (s[i] != t[i])
        {
            ++distance;
        }
        ++i;
    }

    return distance;
}
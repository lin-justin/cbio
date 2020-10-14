/*
A DNA string is a reverse palindrome if it is equal to its reverse complement. For instance, GCATGC is a 
reverse palindrome because its reverse complement is GCATGC. 

Problem:
=======
Given: A DNA string of length at most 1 kbp

Return: The position and length of every reverse palindrome in the string having length between 4 and 12. 
        You may return these pairs in any order.

Reference: http://rosalind.info/problems/revp/
*/

#include <iostream>
#include <string>
#include <algorithm>

char complement(char in);
bool reversePalindrome(std::string instr);

int main()
{
    std::string dna = "TCAATGCATGCGGGTCTATATGCAT";

    for (int i = 0; i < dna.length(); ++i)
    {
        for (int j = 4; j <= 12; ++j)
        {
            if ((i + j) > dna.length())
            {
                break;
            }

            if (reversePalindrome(dna.substr(i, j)))
            {
                std::cout << (i + 1) << " " << j << '\n';
            }
        }
    }

    return 0;
}

char complement(char in)
{
    switch (in)
    {
        case 'A':
            return 'T';
            break;
        case 'T':
            return 'A';
            break;
        case 'G':
            return 'C';
            break;
        case 'C':
            return 'G';
            break;
        default:
            std::cout << "Invalid\n";
            break;
    }
    return -1;
}

bool reversePalindrome(std::string instr)
{
    std::string revComp;
    for (int i = 0; i < instr.length(); ++i)
    {
        revComp += complement(instr[i]);
    }

    std::reverse(revComp.begin(), revComp.end());

    return revComp == instr ? true : false;
}
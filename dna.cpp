/*
A string is simply an ordered collection of symbols selected from some alphabet
and formed into a word.

The length of a string is the number of symbols that it contains.

An example of a length 21 DNA string (whose alphabet contains the symbols 
'A', 'C', 'G', and 'T') is "ATGCTTCAGAAAGGTCTTACG."

Problem:
=======
Given: A DNA string s of length at most 1000 nt.
Return: Four integers (separated by spaces) counting the respective number of 
        times that the symbols 'A', 'C', 'G', and 'T' occur in s.

Reference: http://rosalind.info/problems/dna/
*/

#include <iostream>

int main()
{
    std::string s = "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC";

    int a_count = 0;
    int c_count = 0;
    int g_count = 0;
    int t_count = 0;

    for (char const &c : s)
    {
        switch (c)
        {
            case 'A':
                a_count += 1;
                break;
            case 'C':
                c_count += 1;
                break;
            case 'G':
                g_count += 1;
                break;
            case 'T':
                t_count += 1;
                break;
            default:
                std::cout << "Symbol does not exist in DNA\n";
                break;
        }
    }

    std::cout << a_count << " " << c_count << " " << g_count << " " << t_count << '\n';

    return 0;
}
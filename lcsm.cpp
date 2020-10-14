/*
A common substring of a collection of strings is a substring of every member of the collection. We say that a common 
substring is a longest common substring if there does not exist a longer common substring. For example, "CG" is a 
common substring of "ACGTACGT" and "AACCGTATA", but it is not as long as possible; in this case, "CGTA" is a 
longest common substring of "ACGTACGT" and "AACCGTATA".

Note that the longest common substring is not necessarily unique; for a simple example, "AA" and "CC" are both 
longest common substrings of "AACC" and "CCAA".

Given: A collection of k (k≤100) DNA strings of length at most 1 kbp each in FASTA format.

Return: A longest common substring of the collection. (If multiple solutions exist, you may return any single 
        solution.)

Reference: http://rosalind.info/problems/lcsm/
*/

#include <iostream>
#include <string>
#include <limits>
#include <map>

std::string sharedMotif(std::map<std::string, std::string> dna);

int main()
{
    std::map<std::string, std::string> dna = {{"Rosalind_1", "GATTACA"}, 
                                              {"Rosalind_2", "TAGACCA"}, 
                                              {"Rosalind_3", "ATACA"}};

    std::string lcsm = sharedMotif(dna);

    std::cout << lcsm << '\n';

    return 0;
}

std::string sharedMotif(std::map<std::string, std::string> dna)
{
    int shortest = INT_MAX;
    std::string id;

    for (const auto d : dna)
    {
        int length = d.second.length();
        if (length < shortest)
        {
            shortest = length;
            id = d.first;
        }
    }

    const std::string dna_string = dna[id];
    std::string longest_str;
    int longest_len = 0;

    for (int i = 0; i < shortest; ++i)
    {
        for (int j = shortest - i - 1; j > longest_len; --j)
        {
            const std::string s = dna_string.substr(i, j);
            bool exists = true;
            for (const auto &cur_dna : dna)
            {
                if (cur_dna.first == id)
                {
                    continue;
                }
                if (cur_dna.second.find(s) == std::string::npos)
                {
                    exists = false;
                    break;
                }
            }

            if (exists)
            {
                longest_str = s;
                longest_len = s.length();
            }
        }
    }

    return longest_str;
}
/*
The 20 commonly occurring amino acids are abbreviated by using 20 letters from the English alphabet 
(all letters except for B, J, O, U, X, and Z). Protein strings are constructed from these 20 symbols. 
Henceforth, the term genetic string will incorporate protein strings along with DNA strings and RNA strings.

The RNA codon table dictates the details regarding the encoding of specific codons into the amino acid alphabet.

Problem,
=======
Given, An RNA string s corresponding to a strand of mRNA (of length at most 10 kbp).

Return, The protein string encoded by s.

Reference, http,//rosalind.info/problems/prot/
*/

#include <iostream>
#include <string>
#include <map>

std::string encodeProtein(std::string s);

const std::map<std::string, std::string> rnaCodonTable = {{"UUU", "F"}, {"CUU", "L"}, {"AUU", "I"}, {"GUU", "V"},
                                                          {"UUC", "F"}, {"CUC", "L"}, {"AUC", "I"}, {"GUC", "V"},
                                                          {"UUA", "L"}, {"CUA", "L"}, {"AUA", "I"}, {"GUA", "V"},
                                                          {"UUG", "L"}, {"CUG", "L"}, {"AUG", "M"}, {"GUG", "V"},
                                                          {"UCU", "S"}, {"CCU", "P"}, {"ACU", "T"}, {"GCU", "A"},
                                                          {"UCC", "S"}, {"CCC", "P"}, {"ACC", "T"}, {"GCC", "A"},
                                                          {"UCA", "S"}, {"CCA", "P"}, {"ACA", "T"}, {"GCA", "A"},
                                                          {"UCG", "S"}, {"CCG", "P"}, {"ACG", "T"}, {"GCG", "A"},
                                                          {"UAU", "Y"}, {"CAU", "H"}, {"AAU", "N"}, {"GAU", "D"},
                                                          {"UAC", "Y"}, {"CAC", "H"}, {"AAC", "N"}, {"GAC", "D"},
                                                          {"CAA", "Q"}, {"AAA", "K"}, {"GAA", "E"}, {"CAG", "Q"}, 
                                                          {"AAG", "K"}, {"GAG", "E"}, {"UGU", "C"}, {"CGU", "R"}, 
                                                          {"AGU", "S"}, {"GGU", "G"}, {"UGC", "C"}, {"CGC", "R"}, 
                                                          {"AGC", "S"}, {"GGC", "G"}, {"CGA", "R"}, {"AGA", "R"}, 
                                                          {"GGA", "G"}, {"UGG", "W"}, {"CGG", "R"}, {"AGG", "R"}, 
                                                          {"GGG", "G"}};

int main()
{
    std::string s = "AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA";

    std::string protein = encodeProtein(s);

    std::cout << protein << "\n";

    return 0;
}

std::string encodeProtein(std::string s)
{
    std::string protein = "";
    for (int i = 0; i < s.length(); i += 3)
    {
        std::string match = s.substr(i, 3);

        for (auto const &x : rnaCodonTable)
        {
            if (match == x.first)
            {
                protein += x.second;
            }
        }
    }
    return protein;
}
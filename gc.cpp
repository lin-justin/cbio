/*
The GC-content of a DNA string is given by the percentage of symbols in the string 
that are 'C' or 'G'. For example, the GC-content of "AGCTATAG" is 37.5%.

Problem:
=======
Given: At most 10 DNA strings in FASTA format
Return: The ID of the string having the highest GC-content, followed by the GC-content
        of that string.

Reference: http://rosalind.info/problems/gc/
*/

#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<std::string, std::string> fasta = {{"Rosalind_6404", "CCTGCGGAAGATCGGCACTAGAATAGCCAGAACCGTTTCTCTGAGGCTTCCGGCCTTCCCTCCCACTAATAATTCTGAGG"},
                                                {"Rosalind_5959", "CCATCGGTAGCGCATCCTTAGTCCAATTAAGTCCCTATCCAGGCGCTCCGCCGAAGGTCTATATCCATTTGTCAGCAGACACGC"},
                                                {"Rosalind_0808", "CCACCCTCGTGGTATGGCTAGGCATTCAGGAACCGGAGAACGCTTCAGACCAGCCCGGACTGGGAACCTGCGGGCAGTAGGTGGAAT"}};
    
    double highestGC = 0.0;
    std::string highestGCName = "";

    for (auto const &f : fasta)
    {
        int gc_count = 0;
        for (char const &c : f.second)
        {
            if (c == 'G' || c == 'C')
            {
                gc_count += 1;
            }
        }

        double gc_amount = ((static_cast<double>(gc_count) * 100.0)/ f.second.length());

        if (gc_amount > highestGC)
        {
            highestGC = gc_amount;
            highestGCName = f.first;
        }
    }

    std::cout << highestGCName << '\n';
    std::cout << highestGC << '\n';

    return 0;
}
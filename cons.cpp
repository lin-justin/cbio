/*
A matrix is a rectangular table of values divided into rows and columns. An m×n matrix has m rows and n columns. 
Given a matrix A, we write A_(i,j) to indicate the value found at the intersection of row i and column j.

Say that we have a collection of DNA strings, all having the same length n. Their profile matrix is a 4×n matrix P 
in which P_(1,j) represents the number of times that 'A' occurs in the jth position of one of the strings, 
P_(2,j) represents the number of times that C occurs in the jth position, and so on (see below).

A consensus string c is a string of length n formed from our collection by taking the most common symbol at each 
position; the jth symbol of c therefore corresponds to the symbol having the maximum value in the j-th column of 
the profile matrix. Of course, there may be more than one most common symbol, leading to multiple possible 
consensus strings.


                A T C C A G C T
                G G G C A A C T
                A T G G A T C T
DNA Strings	    A A G C A A C C
                T T G G A A C T
                A T G C C A T T
                A T G G C A C T

            A   5 1 0 0 5 5 0 0
Profile	    C   0 0 1 4 2 0 6 1
            G   1 1 6 3 0 1 0 0
            T   1 5 0 0 0 1 1 6

Consensus	    A T G C A A C T

Problem:
=======
Given: A collection of at most 10 DNA strings of equal length

Return: A consensus string and profile matrix for the collection. (If several possible consensus strings exist,
        then you may return any one of them.)

Reference: http://rosalind.info/problems/cons/
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

static size_t minlen(const std::vector<std::string>& v)
{
    size_t minlen = -1;

    for (auto s : v)
    {
        if (s.length() < minlen)
        {
            minlen = s.length();
        }
    }

    return minlen;
}

typedef std::map<char, std::vector<size_t>> profile_matrix_t;

profile_matrix_t profile_matrix(const std::vector<std::string>& v)
{
    profile_matrix_t r;
    size_t mlen = minlen(v);

    for (int i = 0;  i < mlen; ++i)
    {
        r['A'].push_back(0);
        r['C'].push_back(0);
        r['G'].push_back(0);
        r['T'].push_back(0);

        for (auto s : v)
        {
            switch (toupper(s[i]))
            {
                case 'A':
                    ++r['A'][i];
                    break;
                case 'C':
                    ++r['C'][i];
                    break;
                case 'G':
                    ++r['G'][i];
                    break;
                case 'T':
                    ++r['T'][i];
                    break;
                default:
                    std::cout << "Invalid base\n";
                    break;
            }
        }
    }

    return r;
}

std::string consensus_string(profile_matrix_t& m)
{
    std::string r;

    const size_t len = m['A'].size();
    
    for (int i = 0; i < len; ++i)
    {
        int A = m['A'][i],T = m['T'][i], C = m['C'][i], G = m['G'][i];

        if (A >= T && A >= G) r += 'A';
        else if (T >= A && T >= C && T >= G) r += 'T';
        else if (C >= A && C >= T && C >= G) r += 'C';
        else r += 'G';
    }

    return r;
}

std::ostream& operator << (std::ostream& o, profile_matrix_t& m)
{
    for (auto ch : {'A', 'C', 'G', 'T'})
    {
        o << ch << ": ";

        for (size_t count : m[ch])
        {
            o << count << " ";
        }

        o << '\n';
    }

    return o;
}

int main()
{
    std::vector<std::string> v = {{"ATCCAGCT"}, {"GGGCAACT"}, {"ATGGATCT"}, {"AAGCAACC"},
                                  {"TTGGAACT"}, {"ATGCCATT"}, {"ATGGCACT"}};

    profile_matrix_t m = profile_matrix(v);

    std::cout << consensus_string(m) << '\n';
    std::cout << m << '\n';
    
    return 0;
}
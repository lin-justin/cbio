/*
A random variable for which every one of a number of equally spaced outcomes has the same 
probability is called a uniform random variable (in the die example, this "equal spacing" is equal to 1). We can 
generalize our die example to find that if X is a uniform random variable with minimum possible value a and 
maximum possible value b, then E(X)=a+b2. You may also wish to verify that for the dice example, if Y is the 
random variable associated with the outcome of a second die roll, then E(X+Y)=7.

Given: Six nonnegative integers, each of which does not exceed 20,000. The integers correspond to the number of 
couples in a population possessing each genotype pairing for a given factor. In order, the six given integers 
represent the number of couples having the following genotypes:

        1. AA-AA
        2. AA-Aa
        3. AA-aa
        4. Aa-Aa
        5. Aa-aa
        6. aa-aa

Return: The expected number of offspring displaying the dominant phenotype in the next generation, under the 
assumption that every couple has exactly two offspring.

Reference: http://rosalind.info/problems/iev/
*/

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> data = {1, 0, 0, 1, 0, 1};
    double prob;

    prob = (2 * data[0]) + (2 * data[1]) + (2 * data[2]) + (1.5 * data[3]) + data[4];

    std::cout << prob << '\n';

    return 0;
}